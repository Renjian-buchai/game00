#include "../../include/game.hh"
#include "SDL_image.h"

void game::intro() {
  {
    // 1.5s
    addSlide(IMG_Load("res/images/0001.png"), 0, 1500, 500);

    SDL_Colour white{0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE};

    // 1.5s
    SDL_Surface* surface = TTF_RenderText_Solid_Wrapped(
        font, "Ah, but I'll be causing trouble for my family, won't I?", white,
        0);
    addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

    // 1.5s
    surface = TTF_RenderText_Solid_Wrapped(
        font, "If only someone else could just...", white, 0);
    addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

    // 1.5s
    surface =
        TTF_RenderText_Solid_Wrapped(font, "Live on my behalf...", white, 0);
    addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

    // 1.5s
    surface = TTF_RenderText_Solid_Wrapped(font, "So that I don't have to.",
                                           white, 0);
    addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

    // 2.0s
    surface = TTF_RenderText_Solid_Wrapped(font, "", {}, 0);
    addSlide(surface, 0, 2000, 0, SDL_Rect{}, true, false);

    // 1.0s
    surface = TTF_RenderText_Solid_Wrapped(font,
                                           "This game does not represent\n"
                                           "the experiences of the creator.\n"
                                           "See: The Beginner's Guide",
                                           white, 0);
    addSlide(surface, 250, 500, 250, {0, 0, surface->w, surface->h});

    // 1.0s
    surface = TTF_RenderText_Solid_Wrapped(font,
                                           "Please don't spam my e-mail\n"
                                           "asking about my mental health"
                                           "\nlike last time.",
                                           white, 0);
    addSlide(surface, 250, 500, 250, {0, 0, surface->w, surface->h});

    // 2.0s
    surface = TTF_RenderText_Solid_Wrapped(font, "", {}, 0);
    addSlide(surface, 0, 2000, 0, SDL_Rect{}, true, false);

    // 5s
    surface = TTF_RenderText_Solid_Wrapped(
        font, "Loading...", {0xbb, 0xbb, 0xbb, SDL_ALPHA_OPAQUE}, 0);
    addSlide(
        surface, 250, 5000, 250,
        {dispBounds.w - surface->w - dispBounds.h / 40,
         dispBounds.h - surface->h - dispBounds.h / 40, surface->w, surface->h},
        false, false);
  }

  size_t startTime = SDL_GetTicks64();

  bool skip = false;

  for (size_t deltaTime = SDL_GetTicks64() - startTime;
       // 15000, because I know that I'm going to be changing this value to
       // something else
       state == gameState::intro and deltaTime < 19000;
       deltaTime = SDL_GetTicks64() - startTime) {
    SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(mainRenderer);

    slideShow(SDL_GetTicks64(), skip);
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
              skip = true;
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

  for (SDL_Texture* texture : textures) {
    SDL_DestroyTexture(texture);
  }
  textures.clear();

  state = gameState::gameplay;
}
