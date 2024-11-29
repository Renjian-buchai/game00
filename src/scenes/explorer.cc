#include "../../include/scenes/explorer.hh"

#include <fstream>

#include "../../include/game.hh"
#include "SDL_image.h"

explorer_t::saveState operator++(explorer_t::saveState& save) {
  using IntType = typename std::underlying_type<explorer_t::saveState>::type;
  save = static_cast<explorer_t::saveState>(static_cast<IntType>(save) + 1);

  return save;
}

explorer_t::explorer_t(game* _context)
    : scene(_context),
      nameWrapLength(260 * _context->pixelSize),
      downloadBounds(SDL_Rect{0, 0, pix(40), pix(24)}) {
  {
    saveData = saveState::init;
    SDL_Surface* surface = IMG_Load("res/images/OSExplorer.png");
    if (surface == nullptr) {
      std::cout << IMG_GetError();
      std::exit(-1);
    }

    OS = SDL_CreateTextureFromSurface(_context->mainRenderer, surface);
    if (OS == nullptr) {
      std::cout << SDL_GetError();
      std::exit(-1);
    }
    SDL_FreeSurface(surface);
  }

  if (saveData == saveState::init) {
    SDL_Surface* text = TTF_RenderUTF8_Blended_Wrapped(
        _context->font,
        "↑ His files have been deleted. Let's download them from the cloud.",
        {0x80, 0x87, 0x7d, SDL_ALPHA_OPAQUE}, pix(300));
    if (text == nullptr) {
      std::cout << TTF_GetError();
      exit(-1);
    }

    items.emplace_back(
        SDL_CreateTextureFromSurface(_context->mainRenderer, text),
        SDL_Rect{pix(8), pix(56), text->w, text->h});

    SDL_FreeSurface(text);
  }

  return;
}

explorer_t::~explorer_t() {
  for (size_t i = 0; i < items.size(); ++i) {
    SDL_DestroyTexture(items[0].first);
    items.erase(items.begin());
  }
}

void explorer_t::update() {
  // Technically, assigned too much space, but better than finding off-by-1 bugs
  static std::vector<bool> first(static_cast<size_t>(saveState::size), 1);

  if (saveData == saveState::entry1) {
    if (first[static_cast<size_t>(saveState::entry1)]) {
      first[static_cast<size_t>(saveState::entry1)] = 0;
      auto [texture, position] = items.back();
      SDL_DestroyTexture(texture);
      items.pop_back();
    }
  }
}

void explorer_t::render() {
  SDL_RenderCopy(context->mainRenderer, OS, nullptr, nullptr);

  for (auto [texture, position] : items) {
    SDL_RenderCopy(context->mainRenderer, texture, nullptr, &position);
  }
  return;
}

scene* explorer_t::handle(SDL_Event& event) {
  SDL_Point point;
  switch (event.type) {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {}
      break;

    case SDL_MOUSEBUTTONDOWN:
      point.x = event.button.x;
      point.y = event.button.y;

      if (SDL_PointInRect(&point, &downloadBounds)) {
        ++saveData;
      }

      break;

    default:
      break;
  }

  return this;
}
