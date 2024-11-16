#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "game.hh"

int main(int argc, char** argv) {
  (void)argc, (void)argv;

  int err;

  if (err = SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cerr << SDL_GetError() << "\n";
    exit(err);
  }
  std::atexit(SDL_Quit);

  err = IMG_Init(IMG_INIT_PNG);
  if (err != IMG_INIT_PNG) {
    std::cerr << IMG_GetError() << "\n";
    exit(err);
  }
  std::atexit(IMG_Quit);

  if (err = TTF_Init()) {
    std::cerr << TTF_GetError() << "\n";
    exit(err);
  }
  std::atexit(TTF_Quit);

  game game;

  while (game.state != game::gameState::terminating) {
    switch (game.state) {
      case game::gameState::intro:
        game.intro();
        break;

      case game::gameState::gameplay:
        game.gameplay();
        break;

      case game::gameState::paused:
        game.paused();
        break;

      default:
        break;
    }
  }

  return 0;
}
