#include <memory>
#include <variant>

#include "../../include/game.hh"
#include "../../include/scenes/explorer.hh"
#include "../../include/scenes/scene.hh"
#include "SDL_image.h"

void game::gameplay() {
  // Generate scene
  std::variant<explorer> currentScene = explorer(this);

  SDL_Event event;
  while (state == gameState::gameplay) {
    std::visit([](auto& scene) { scene.render(); }, currentScene);
    SDL_RenderPresent(mainRenderer);

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        state = gameState::terminating;
        return;
      }

      if (std::visit([&](auto& scene) -> bool { return scene.handle(event); },
                     currentScene) == 1) {
        state = gameState::paused;
        return;  // All clean-up should be done by the scene's destructor if
                 // scene control changes
      }
    }

    std::visit([](auto& scene) { scene.update(); }, currentScene);
  }

  return;
}
