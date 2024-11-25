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
  SDL_Surface* surface = IMG_Load("../res/images/OSExplorer.png");
  SDL_BlitScaled(IMG_Load("../res/images/OS.png"), nullptr, surface, nullptr);
  this->OS = SDL_CreateTextureFromSurface(context->mainRenderer, surface);
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
      (void)0;
  }

  return false;
}
