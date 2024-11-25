#include "../../include/scenes/explorer.hh"

#include "../../include/game.hh"
#include "SDL_image.h"

#define pix(val) static_cast<int>(val * context->pixelSize)

explorer::explorer(game* context)
    : scene(context),
      nameWrapLength(260 * context->pixelSize),
      pauseBounds(SDL_Rect{pix(600), 0, pix(39), pix(24)}),
      downloadBounds(SDL_Rect{0, 0, pix(40), pix(24)}),
      explorerBounds(SDL_Rect{pix(24), pix(376), pix(24), pix(24)}) {
  saveData = explorerSave::init;

  {
    SDL_Surface* explorer = IMG_Load("../res/images/OSExplorer.png");
    if (explorer == nullptr) {
      std::cout << IMG_GetError();
      std::exit(-1);
    }

    SDL_Surface* os = IMG_Load("../res/images/OS.png");
    if (os == nullptr) {
      std::cout << IMG_GetError();
      std::exit(-1);
    }
    SDL_FreeSurface(os);

    SDL_BlitScaled(os, nullptr, explorer, nullptr);
    this->OS = SDL_CreateTextureFromSurface(context->mainRenderer, explorer);
    if (this->OS == nullptr) {
      std::cout << SDL_GetError();
      std::exit(-1);
    }
    SDL_FreeSurface(explorer);
  }

  return;
}

explorer::~explorer() {
  // TODO Idk, probably don't free stuff? Not sure
}

std::unique_ptr<scene> explorer::update() {
  // TODO gameplay loop

  return std::unique_ptr<scene>(nullptr);
}

void explorer::render() {
  for (auto [texture, position] : this->items) {
    SDL_RenderCopy(context->mainRenderer, texture, nullptr, &position);
  }

  // Render everything else here

  SDL_RenderCopy(context->mainRenderer, this->OS, nullptr, nullptr);
  return;
}

bool explorer::handle(SDL_Event& event) {
  switch (event.type) {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {}
  }

  return false;
}
