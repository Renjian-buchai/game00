#include "enum.hh"
#include "game.hh"
#include "wm.hh"

void changeScene(const std::pair<scenes, sceneData>& sceneChangeData,
                 wm& winMan) {
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
      break;

    case scenes::shitcord:
      winMan.current = winMan.shitcord.get();
      break;
  }

  return;
}

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
      changeScene(sceneChangeData, winMan);
    }

    sceneChangeData = winMan.update();
    changeScene(sceneChangeData, winMan);
  }

  // Adding a destructor causes the initialisation of wm to fail
  SDL_DestroyTexture(winMan.OSOverlay);

  return;
}
