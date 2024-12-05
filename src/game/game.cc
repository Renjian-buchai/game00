#include "../include/game.hh"

struct wmInitData {
  wm *winMan;
  game *context;

 private:
  SDL_mutex *mutex;

 public:
  wmInitData(wm *_winMan, game *_context, SDL_mutex *_mutex)
      : winMan(_winMan), context(_context), mutex(_mutex) {}
  ~wmInitData() { SDL_DestroyMutex(mutex); }
  void lock() { SDL_LockMutex(mutex); }
  void unlock() { SDL_UnlockMutex(mutex); }
};

int wmInit(void *data) {
  // We only need to copy the addresses.
  wmInitData *initData = reinterpret_cast<wmInitData *>(data);

  initData->lock();
  *initData->winMan = wm(initData->context);
  initData->unlock();

  return 0;
};

game::game() {
  if (int err = SDL_GetDisplayBounds(0, &dispBounds)) {
    std::cerr << SDL_GetError() << "\n";
    exit(err);
  }

  mainWindow = SDL_CreateWindow(
      "Game Jam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dispBounds.w,
      dispBounds.h, SDL_WINDOW_BORDERLESS | SDL_WINDOW_MAXIMIZED);
  if (mainWindow == nullptr) {
    std::cerr << SDL_GetError() << "\n";
    exit(-1);
  }

  mainRenderer = SDL_CreateRenderer(
      mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (mainRenderer == nullptr) {
    std::cerr << SDL_GetError() << "\n";
    this->~game();
    exit(-1);
  }

  font = TTF_OpenFont("res/UI/fonts/arial.ttf", 50);
  if (font == nullptr) {
    std::cerr << TTF_GetError();
    this->~game();
    exit(-1);
  }

  pixelSize = static_cast<double>(dispBounds.w) / 640.0f;

  mutex = SDL_CreateMutex();

  loadThread = SDL_CreateThread(
      wmInit, "WM initialiser",
      (new wmInitData{&this->winMan, this, SDL_CreateMutex()}));

  if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048)) {
    std::cout << Mix_GetError();
    exit(-1);
  }

  bgm[0] = Mix_LoadMUS("res/audio/OST/how.mp3");
  bgm[1] = Mix_LoadMUS("res/audio/OST/what.mp3");
  bgm[2] = Mix_LoadMUS("res/audio/OST/when.mp3");
  bgm[3] = Mix_LoadMUS("res/audio/OST/where.mp3");
  for (uint8_t i = 0; i < 4; ++i) {
    if (bgm[i] == nullptr) {
      std::cout << "BGM " << std::to_string(i) << ": " << Mix_GetError()
                << "\n";
      exit(-1);
    }
  }

  silence[0] = Mix_LoadMUS("res/audio/sfx/silent5.mp3");
  silence[1] = Mix_LoadMUS("res/audio/sfx/silent20.mp3");
  silence[2] = Mix_LoadMUS("res/audio/sfx/silent45.mp3");
  silence[3] = Mix_LoadMUS("res/audio/sfx/silent60.mp3");
  silence[4] = Mix_LoadMUS("res/audio/sfx/silent75.mp3");
  silence[5] = Mix_LoadMUS("res/audio/sfx/silent120.mp3");
  for (uint8_t i = 0; i < 6; ++i) {
    if (silence[i] == nullptr) {
      std::cout << "BGM " << std::to_string(i) << ": " << Mix_GetError()
                << "\n";
      exit(-1);
    }
  }

  Mix_VolumeMusic(48);
}

game::~game() {
  SDL_DestroyRenderer(mainRenderer);
  SDL_DestroyWindow(mainWindow);

  Mix_CloseAudio();
  for (Mix_Music *music : bgm) {
    Mix_FreeMusic(music);
  }

  for (Mix_Music *music : silence) {
    Mix_FreeMusic(music);
  }

  TTF_CloseFont(font);

  return;
}
