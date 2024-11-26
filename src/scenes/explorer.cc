#include "../../include/scenes/explorer.hh"

#include <fstream>

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
  {
    SDL_Surface* explorer = IMG_Load("res/images/OSExplorer.png");
    if (explorer == nullptr) {
      std::cout << IMG_GetError();
      std::exit(-1);
    }

    SDL_Surface* os = IMG_Load("res/images/OS.png");
    if (os == nullptr) {
      std::cout << IMG_GetError();
      std::exit(-1);
    }
    SDL_BlitScaled(os, nullptr, explorer, nullptr);
    SDL_FreeSurface(os);

    OS = SDL_CreateTextureFromSurface(context->mainRenderer, explorer);
    if (OS == nullptr) {
      std::cout << SDL_GetError();
      std::exit(-1);
    }
    SDL_FreeSurface(explorer);
  }

  if (saveData == explorerSave::init) {
    SDL_Surface* text = TTF_RenderUTF8_Blended_Wrapped(
        context->font,
        "↑ His files have been deleted. Let's download them from the cloud.",
        {0x80, 0x87, 0x7d, SDL_ALPHA_OPAQUE}, pix(300));
    if (text == nullptr) {
      std::cout << TTF_GetError();
      exit(-1);
    }

    items.emplace_back(
        SDL_CreateTextureFromSurface(context->mainRenderer, text),
        SDL_Rect{pix(8), pix(56), text->w, text->h});

    SDL_FreeSurface(text);
  }

  return;
}

explorer::~explorer() {
  for (size_t i = 0; i < items.size(); ++i) {
    SDL_DestroyTexture(items[0].first);
    items.erase(items.begin());
  }
}

void explorer::update() {
  // Technically, assigned too much space, but better than finding off-by-1 bugs
  static std::vector<bool> first(static_cast<size_t>(explorerSave::size), 1);

  if (saveData == explorerSave::entry1) {
    if (first[static_cast<size_t>(explorerSave::entry1)]) {
      first[static_cast<size_t>(explorerSave::entry1)] = 0;
      auto [texture, position] = items.back();
      SDL_DestroyTexture(texture);
      items.pop_back();
    }
  }
}

void explorer::render() {
  SDL_RenderCopy(context->mainRenderer, OS, nullptr, nullptr);

  for (auto [texture, position] : items) {
    SDL_RenderCopy(context->mainRenderer, texture, nullptr, &position);
  }
  return;
}

scene* explorer::handle(SDL_Event& event) {
  SDL_Point point;
  switch (event.type) {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {}
      break;

    case SDL_MOUSEBUTTONDOWN:
      point.x = event.button.x;
      point.y = event.button.y;

      if (SDL_PointInRect(&point, &downloadBounds)) {
        if (saveData != explorerSave::init) {
          // return std::move(context->scenes[1]);
        }
        ++saveData;
      }

      if (SDL_PointInRect(&point, &pauseBounds)) {
        context->state = game::gameState::paused;
        return this;
      }

      break;

    default:
      break;
  }

  return this;
}
