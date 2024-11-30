#include "../../include/game.hh"
#include "../../include/wm.hh"

void game::gameplay() {
  SDL_WaitThread(loadThread, nullptr);
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
