#include "../include/game.hh"

#include "SDL_image.h"

game::game() {
  if (int err = SDL_GetDisplayBounds(0, &dispBounds)) {
    std::cerr << SDL_GetError() << "\n";
    exit(err);
  }

  mainWindow = SDL_CreateWindow(
      "Game Jam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dispBounds.w,
      dispBounds.h, SDL_WINDOW_BORDERLESS | SDL_WINDOW_MAXIMIZED);
  if (mainWindow == nullptr) {
    std::cerr << SDL_GetError() << "\n";
    exit(-1);
  }

  mainRenderer = SDL_CreateRenderer(
      mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (mainRenderer == nullptr) {
    std::cerr << SDL_GetError() << "\n";
    this->~game();
    exit(-1);
  }

  // Testing if it can render
  {
    if (int err = SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00,
                                         SDL_ALPHA_OPAQUE)) {
      std::cerr << SDL_GetError() << "\n";
      this->~game();
      exit(err);
    }

    if (int err = SDL_RenderClear(mainRenderer)) {
      std::cerr << SDL_GetError() << "\n";
      this->~game();
      exit(err);
    }
  }

  return;
}

game::~game() {
  SDL_DestroyRenderer(mainRenderer);
  SDL_DestroyWindow(mainWindow);

  return;
}

void game::gameplay() {
  {
    SDL_Surface* surface = IMG_Load("../res/noose.png");
    textures.emplace_back(SDL_CreateTextureFromSurface(mainRenderer, surface));
    SDL_SetTextureBlendMode(textures[0], SDL_BLENDMODE_BLEND);
    slideQueue.emplace_back(0, 2000, 500, textures[0]);
    slideQueue.emplace_back(0, 2000, 500, textures[0]);
    slideQueue.emplace_back(0, 2000, 500, textures[0]);
    slideQueue.emplace_back(0, 2000, 500, textures[0]);

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

    // uint8_t alpha;
    // SDL_GetTextureAlphaMod(textures[0], &alpha);
    // std::cout << static_cast<int>(alpha) << "\n";

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

void game::slideShow(size_t time, bool& click) {
  static size_t lastTime = time;

  if (!slideQueue.empty()) {
    slide& head = slideQueue[0];

    if (click) {
      lastTime = time;
      slideQueue.erase(slideQueue.begin());
      head = slideQueue[0];
      click = false;
      return;
    }

    if (time - lastTime < head.fadeIn) {
      SDL_SetTextureAlphaMod(head.texture,
                             255 * (time - lastTime) / head.fadeIn);
      SDL_RenderCopy(mainRenderer, head.texture, nullptr, nullptr);
    } else if (time - lastTime < head.fadeIn + head.duration) {
      SDL_SetTextureAlphaMod(head.texture, 255);
      SDL_RenderCopy(mainRenderer, head.texture, nullptr, nullptr);
    } else if (time - lastTime < head.fadeIn + head.duration + head.fadeOut) {
      SDL_SetTextureAlphaMod(
          head.texture,
          255 - (255 * (time - lastTime - head.fadeIn - head.duration) /
                 head.fadeOut));
      SDL_RenderCopy(mainRenderer, head.texture, nullptr, nullptr);
    } else {
      lastTime = time;
      slideQueue.erase(slideQueue.begin());
      head = slideQueue[0];
    }
  }
}
