#if !defined(game_GAME_HH)
#define game_GAME_HH

#include <cstdlib>
#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_ttf.h"

struct game {
  enum class gameState : uint8_t {
    terminating,
    gameplay,
  };

 private:
  struct slide {
    slide(size_t _fadeIn, size_t _fadeOut, size_t _duration,
          SDL_Texture* _texture, SDL_Rect _dest = {});

    size_t fadeIn;
    size_t duration;
    size_t fadeOut;
    SDL_Texture* texture;
    SDL_Rect dest;
  };

 public:
  gameState state = gameState::gameplay;

  SDL_Rect dispBounds;
  SDL_Window* mainWindow = nullptr;
  SDL_Renderer* mainRenderer = nullptr;
  std::vector<SDL_Texture*> textures{};

  TTF_Font* font;

 private:
  std::vector<slide> slideQueue;

 public:
  game();

  ~game();

  void gameplay();

  void slideShow(size_t time, bool& click);
};

#endif
