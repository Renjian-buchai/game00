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

  game() {
    if (int err = SDL_GetDisplayBounds(0, &dispBounds)) {
      std::cerr << SDL_GetError() << "\n";
      exit(err);
    }

    mainWindow =
        SDL_CreateWindow("Game Jam", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, dispBounds.w, dispBounds.h,
                         SDL_WINDOW_BORDERLESS | SDL_WINDOW_MAXIMIZED);
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

    // Testing if it can render
    {
      if (int err = SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00,
                                           SDL_ALPHA_OPAQUE)) {
        std::cerr << SDL_GetError() << "\n";
        this->~game();
        exit(err);
      }

      if (int err = SDL_RenderClear(mainRenderer)) {
        std::cerr << SDL_GetError() << "\n";
        this->~game();
        exit(err);
      }
    }
  }

  ~game() {
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
  }

  void gameplay() {}
};

int main(int argc, char** argv) {
  (void)argc, (void)argv;

  if (int err = SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cerr << SDL_GetError() << "\n";
    exit(err);
  }
  std::atexit(SDL_Quit);

  game game;

  switch (game.state) {
    case game::gameState::gameplay:
      game.gameplay();
      break;
    default:
      break;
  }

  return 0;
}
