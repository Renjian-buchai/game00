#include <iostream>
#include <vector>

#include "SDL.h"
#include "game.hh"

int main(int argc, char** argv) {
  (void)argc, (void)argv;

  if (int err = SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cerr << SDL_GetError() << "\n";
    exit(err);
  }
  std::atexit(SDL_Quit);

  game game;

  switch (game.state) {
    case game::gameState::gameplay:
      game.gameplay();
      break;

    default:
      break;
  }

  return 0;
}
