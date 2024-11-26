#include "../include/game.hh"

#include <iostream>

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

  font = TTF_OpenFont("res/UI/fonts/arial.ttf", 64);
  if (font == nullptr) {
    std::cerr << TTF_GetError();
    this->~game();
    exit(-1);
  }

  pixelSize = static_cast<double>(dispBounds.w) / 640.0f;

  return;
}

game::~game() {
  SDL_DestroyRenderer(mainRenderer);
  SDL_DestroyWindow(mainWindow);

  for (SDL_Texture* texture : textures) {
    SDL_DestroyTexture(texture);
  }

  TTF_CloseFont(font);

  return;
}
