#include <string>

#include "../../include/game.hh"
#include "SDL_image.h"

void game::paused() {
  SDL_Surface* surface;
  auto loadTexture = [&](std::string filePath) -> SDL_Texture* {
    SDL_Surface* surface = IMG_Load(filePath.c_str());
    if (surface == nullptr) {
      std::cerr << IMG_GetError();
      // Safe because SDL guarantees that all functions can take nullptr as
      // textures.
      return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
    if (texture == nullptr) {
      std::cerr << SDL_GetError();
      return nullptr;
    }

    textures.emplace_back(texture);
    SDL_FreeSurface(surface);
    return texture;
  };

  SDL_Texture* overlay = loadTexture("../res/UI/PauseOverlay.png");
  SDL_Texture* resume = loadTexture("../res/UI/PauseBTResume.png");
  SDL_Texture* exit = loadTexture("../res/UI/PauseBTExit.png");

  SDL_SetRenderDrawBlendMode(mainRenderer, SDL_BLENDMODE_MUL);
  while (state == gameState::paused) {
    SDL_RenderCopy(mainRenderer, overlay, nullptr, nullptr);
    SDL_RenderCopy(mainRenderer, resume, nullptr, nullptr);
    SDL_RenderCopy(mainRenderer, exit, nullptr, nullptr);

    SDL_RenderPresent(mainRenderer);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          state = gameState::terminating;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              state = gameState::gameplay;
              break;

            default:
              break;
          }
          break;

        default:
          break;
      }
    }
  }

  return;
}