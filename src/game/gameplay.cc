#include <memory>
#include <variant>

#include "../../include/game.hh"
#include "../../include/wm.hh"
#include "SDL_image.h"

void game::gameplay() {
  wm winMan(this);

  SDL_Event event;
  while (state != gameState::terminating) {
    winMan.render();
    SDL_RenderPresent(mainRenderer);

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        state = gameState::terminating;
        return;
      }

      winMan.handle(event);
    }

    winMan.update();
  }

  return;
}
