#include "../../include/game.hh"
#include "../../include/wm.hh"

void game::gameplay() {
  SDL_WaitThread(loadThread, nullptr);
  Mix_PlayMusic(bgm[0], 0);

  SDL_Event event;
  std::pair<scenes, sceneData> sceneChangeData =
      std::make_pair(scenes::intro, std::monostate());

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
        case scenes::explorer:
          winMan.current = winMan.explorer.get();
          break;

        case scenes::notepad:
          winMan.current = winMan.notepad.get();
          winMan.notepad->currentData =
              std::get<notepadData>(sceneChangeData.second);
          break;

        case scenes::intro:
          winMan.current = winMan.intro.get();
          break;

        case scenes::pause:
          winMan.current = winMan.pause.get();
      }
    }

    sceneChangeData = winMan.update();
    switch (sceneChangeData.first) {
      case scenes::explorer:
        winMan.current = winMan.explorer.get();
        break;

      case scenes::notepad:
        winMan.current = winMan.notepad.get();
        winMan.notepad->currentData =
            std::get<notepadData>(sceneChangeData.second);
        break;

      case scenes::intro:
        winMan.current = winMan.intro.get();
        break;

      case scenes::pause:
        winMan.current = winMan.pause.get();
    }
  }

  return;
}
