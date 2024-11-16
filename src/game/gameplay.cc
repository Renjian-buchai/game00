#include "../../include/game.hh"
#include "SDL_image.h"

void game::gameplay() {
  {}
  SDL_Event event;
  while (state == gameState::gameplay) {
    SDL_SetRenderDrawColor(mainRenderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mainRenderer);

    SDL_RenderDrawRect(mainRenderer, &dispBounds);
    SDL_RenderPresent(mainRenderer);

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          state = gameState::terminating;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              state = gameState::paused;
              goto pause;
              break;

            default:
              break;
          }
          break;

        default:
          break;
      }
    }

    (void)0;
  }
pause:
  return;
}
