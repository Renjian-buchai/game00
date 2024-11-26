#include <memory>
#include <variant>

#include "../../include/game.hh"
#include "../../include/scenes/explorer.hh"
#include "../../include/scenes/scene.hh"
#include "SDL_image.h"

void game::gameplay() {
  // Generate scene
  std::unique_ptr<scene> currentScene = std::make_unique<explorer>(this);

  SDL_Event event;
  while (state == gameState::gameplay) {
    currentScene->render();
    SDL_RenderPresent(mainRenderer);

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        state = gameState::terminating;
        return;
      }

      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        state = gameState::paused;
        return;
      }

      scene* next = currentScene->handle(event);
      if (currentScene.get() != next) {
        currentScene.reset(next);
      }

      // All clean-up should be done by the scene's destructor if
      // scene control changes
      if (state == gameState::paused) return;
    }

    currentScene->update();
  }

  return;
}
