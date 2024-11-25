#include "../../include/scenes/explorer.hh"

#include <functional>

#include "../../include/game.hh"
#include "SDL_image.h"

#define pix(val) static_cast<int>(val * context->pixelSize)

explorerSave operator++(explorerSave& save) {
  using IntType = typename std::underlying_type<explorerSave>::type;
  save = static_cast<explorerSave>(static_cast<IntType>(save) + 1);

  return save;
}

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
    SDL_BlitScaled(os, nullptr, explorer, nullptr);
    SDL_FreeSurface(os);

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

void explorer::update() {
  // TODO gameplay loop

  // return std::unique_ptr<scene>(nullptr);
}

void explorer::render() {
  SDL_RenderCopy(context->mainRenderer, this->OS, nullptr, nullptr);

  // Render everything else here

  for (auto [texture, position] : this->items) {
    SDL_RenderCopy(context->mainRenderer, texture, nullptr, &position);
  }
  return;
}

std::unique_ptr<scene> explorer::handle(SDL_Event& event) {
  SDL_Point point;
  switch (event.type) {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {}
      break;

    case SDL_MOUSEBUTTONDOWN:
      point.x = event.button.x;
      point.y = event.button.y;

      if (SDL_PointInRect(&point, &downloadBounds)) {
        std::cout << static_cast<int>(++saveData);
      }

      if (SDL_PointInRect(&point, &pauseBounds)) {
        std::cout << "Pausing";
        context->state = game::gameState::paused;
        return std::unique_ptr<scene>(nullptr);
      }

      break;

    default:
      break;
  }

  return std::unique_ptr<scene>(nullptr);
}
