#include "../../include/game.hh"
#include "../../include/wm.hh"

void game::gameplay() {
  SDL_WaitThread(loadThread, nullptr);

  SDL_Event event;
  std::pair<scene::scenes, sceneData> sceneData = {scene::scenes::intro,
                                                   nullptr};

  while (state != gameState::terminating) {
    winMan.render();
    SDL_RenderPresent(mainRenderer);

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        state = gameState::terminating;
        return;
      }

      sceneData = winMan.handle(event);
      switch (sceneData.first) {
        case scene::scenes::explorer:
          winMan.current = winMan.expl.get();
          break;

        case scene::scenes::notepad:
          winMan.current = winMan.note.get();
          break;

        case scene::scenes::intro:
          winMan.current = winMan.intro.get();
          break;

        case scene::scenes::pause:
          winMan.current = winMan.pause.get();
      }
    }

    sceneData = winMan.update();
    switch (sceneData.first) {
      case scene::scenes::explorer:
        winMan.current = winMan.expl.get();
        break;

      case scene::scenes::notepad:
        winMan.current = winMan.note.get();
        break;

      case scene::scenes::intro:
        winMan.current = winMan.intro.get();
        break;

      case scene::scenes::pause:
        winMan.current = winMan.pause.get();
    }
  }

  return;
}
