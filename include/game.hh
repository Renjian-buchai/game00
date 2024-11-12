#if !defined(game_GAME_HH)
#define game_GAME_HH

#include <cstdlib>
#include <iostream>
#include <vector>

#include "SDL.h"

struct game {
  enum class gameState : uint8_t {
    terminating,
    gameplay,
  };

 private:
  struct slide {
    slide(size_t _fadeIn, size_t _fadeOut, size_t _duration,
          SDL_Texture* _texture)
        : fadeIn(_fadeIn),
          duration(_duration),
          fadeOut(_fadeOut),
          texture(_texture) {}

    size_t fadeIn;
    size_t duration;
    size_t fadeOut;
    SDL_Texture* texture;
  };

 public:
  gameState state = gameState::gameplay;

  SDL_Rect dispBounds;
  SDL_Window* mainWindow = nullptr;
  SDL_Renderer* mainRenderer = nullptr;
  std::vector<SDL_Texture*> textures{};

 private:
  std::vector<slide> slideQueue;

 public:
  game();

  ~game();

  void gameplay();

  void slideShow(size_t time);
};

#endif
