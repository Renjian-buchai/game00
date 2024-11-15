#include "../../include/game.hh"
#include "SDL_image.h"

void game::gameplay() {
  {
    SDL_Surface* surface = IMG_Load("../res/images/noose.png");
    textures.emplace_back(SDL_CreateTextureFromSurface(mainRenderer, surface));
    SDL_SetTextureBlendMode(textures[0], SDL_BLENDMODE_BLEND);
    slideQueue.emplace_back(0, 2000, 500, textures[0]);

    SDL_FreeSurface(surface);

    surface = TTF_RenderText_Solid(
        font, "Ah, but I'll be causing trouble for\nmy family, won't I?",
        {0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE});
    textures.emplace_back(SDL_CreateTextureFromSurface(mainRenderer, surface));
    SDL_SetTextureBlendMode(textures[1], SDL_BLENDMODE_BLEND);
    slideQueue.emplace_back(
        slide{250, 500, 250, textures[1], {0, 0, surface->w, surface->h}});

    SDL_FreeSurface(surface);
  }

  size_t startTime = SDL_GetTicks64();

  bool slideshowing = false;

  for (size_t deltaTime = SDL_GetTicks64() - startTime;
       state != gameState::terminating and deltaTime < 10000;
       deltaTime = SDL_GetTicks64() - startTime) {
    SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(mainRenderer);

    slideShow(SDL_GetTicks64(), slideshowing);
    SDL_RenderPresent(mainRenderer);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          state = gameState::terminating;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_SPACE:
              slideshowing = true;
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
}
