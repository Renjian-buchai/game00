#if !defined(game_GAME_HH)
#define game_GAME_HH

#include <cstdlib>
#include <iostream>
#include <vector>

#include "SDL.h"

struct game {
  enum class gameState : uint8_t { gameplay };

  gameState state = gameState::gameplay;

  SDL_Rect dispBounds;
  SDL_Window* mainWindow = nullptr;
  SDL_Renderer* mainRenderer = nullptr;
  std::vector<SDL_Texture*> textures{};

  game();

  ~game();

  void gameplay();
};

#endif
