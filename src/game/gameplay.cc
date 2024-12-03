#include "../../include/game.hh"
#include "../../include/wm.hh"

void game::gameplay() {
  SDL_WaitThread(loadThread, nullptr);

  SDL_Event event;
  std::pair<scene::scenes, sceneData> sceneChangeData = {scene::scenes::intro,
                                                         std::monostate()};

  while (state != gameState::terminating) {
    winMan.render();
    SDL_RenderPresent(mainRenderer);

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        state = gameState::terminating;
        return;
      }

      sceneChangeData = winMan.handle(event);
      switch (sceneChangeData.first) {
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

    sceneChangeData = winMan.update();
    switch (sceneChangeData.first) {
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
