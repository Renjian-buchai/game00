#include "../../include/scenes/notepad.hh"

#include "../../include/game.hh"

notepad_t::notepad_t(game* _context)
    : scene(_context),
      lineWrapLength(scale *
                     static_cast<double>(context->dispBounds.w - pix(16))),
      currentData(notepadData::empty) {
  SDL_Surface* surface = IMG_Load("res/images/notepad.png");
  if (surface == nullptr) {
    std::cout << IMG_GetError();
    exit(-1);
  }
  background = SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);
  if (background == nullptr) {
    std::cout << SDL_GetError();
    exit(-1);
  }
}

notepad_t::~notepad_t() {}

std::pair<scenes, sceneData> notepad_t::update() {
  return std::make_pair(scenes::notepad, std::monostate());
}

void notepad_t::render() {
  SDL_RenderCopy(context->mainRenderer, background, nullptr, nullptr);
}

std::pair<scenes, sceneData> notepad_t::handle(SDL_Event& event) {
  return std::make_pair(scenes::notepad, std::monostate());
}
