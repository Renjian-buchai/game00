#include "game.hh"
#include "pch.hh"

int main(int argc, char** argv) {
  (void)argc, (void)argv;

  int err;

  if ((err = SDL_Init(SDL_INIT_EVERYTHING))) {
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

  if ((err = TTF_Init())) {
    std::cerr << TTF_GetError() << "\n";
    exit(err);
  }
  std::atexit(TTF_Quit);

  game game;

  while (game.state != game::gameState::terminating) {
    switch (game.state) {
      case game::gameState::intro:
#define skipIntro
#ifdef skipIntro
        game.state = game::gameState::gameplay;
#else
        game.intro();
#endif
        break;

      case game::gameState::gameplay:
        game.gameplay();
        break;

      case game::gameState::terminating:
        // It should never reach this point anyways
        break;

      default:
        break;
    }
  }

  return 0;
}
