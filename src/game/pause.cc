#include "../../include/game.hh"
#include "SDL_image.h"

void game::paused() {
  SDL_Surface* surface;
  surface = IMG_Load("../res/UI/PauseOverlay.png");
  SDL_Texture* overlay = SDL_CreateTextureFromSurface(mainRenderer, surface);
  textures.emplace_back(overlay);
  SDL_FreeSurface(surface);

  SDL_RenderDrawRect(mainRenderer, &dispBounds);

  while (state == gameState::paused) {
    SDL_RenderCopy(mainRenderer, overlay, nullptr, nullptr);

    SDL_RenderPresent(mainRenderer);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          state = gameState::terminating;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              state = gameState::gameplay;
              break;

            default:
              break;
          }
          break;

        default:
          break;
      }
    }
  }

  return;
}