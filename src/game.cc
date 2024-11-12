#include "../include/game.hh"

#include "SDL_image.h"

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

  return;
}

game::~game() {
  SDL_DestroyRenderer(mainRenderer);
  SDL_DestroyWindow(mainWindow);

  return;
}

void game::gameplay() {
  SDL_Surface* surface = IMG_Load("../res/noose.png");
  textures.emplace_back(SDL_CreateTextureFromSurface(mainRenderer, surface));

  SDL_SetTextureBlendMode(textures[0], SDL_BLENDMODE_BLEND);
  SDL_SetTextureAlphaMod(textures[0], 0);

  size_t startTime = SDL_GetTicks64();

  for (size_t deltaTime = SDL_GetTicks64() - startTime;
       state != gameState::terminating and deltaTime < 5000;
       deltaTime = SDL_GetTicks64() - startTime) {
    SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(mainRenderer);

    SDL_SetTextureAlphaMod(textures[0], 255 - (deltaTime >> 4));
    SDL_RenderCopy(mainRenderer, textures[0], nullptr, nullptr);
    SDL_RenderPresent(mainRenderer);

    std::cout << 312 - (deltaTime >> 4) << "\n";

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          state = gameState::terminating;
          break;

        default:
          break;
      }
    }
  }
}
