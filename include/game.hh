#if !defined(game_GAME_HH)
#define game_GAME_HH

#include "pch.hh"
#include "wm.hh"

struct game {
  enum class gameState : uint8_t {
    terminating,
    intro,
    gameplay,
    paused,
  };

 private:
 public:
  gameState state = gameState::intro;

  SDL_Rect dispBounds;
  SDL_Window* mainWindow;
  SDL_Renderer* mainRenderer;

  std::array<Mix_Music*, 4> bgm;
  std::array<Mix_Music*, 6> silence;

  TTF_Font* font;

  double pixelSize;

  wm winMan;
  SDL_mutex* mutex;
  SDL_Thread* loadThread;

 public:
  game();

  ~game();

  void gameplay();
};

#endif
