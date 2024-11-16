#include "../../include/game.hh"
#include "SDL_image.h"

void game::gameplay() {
  {}
  SDL_Event event;
  while (state == gameState::gameplay) {
    (void)0;

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
