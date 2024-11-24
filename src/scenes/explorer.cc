#include "../../include/scenes/explorer.hh"

#include "../../include/game.hh"
#include "SDL_image.h"

explorer::explorer(game* context)
    : scene(context), nameWrapLength(260 * context->pixelSize) {
  saveData = explorerSave::init;
  SDL_Surface* surface = IMG_Load("../res/UI/OS.png");
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
