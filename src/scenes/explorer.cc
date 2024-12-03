#include "../../include/scenes/explorer.hh"

#include "../../include/game.hh"

explorer_t::saveState operator++(explorer_t::saveState& save) {
  using IntType = typename std::underlying_type<explorer_t::saveState>::type;
  save = static_cast<explorer_t::saveState>(static_cast<IntType>(save) + 1);

  return save;
}

SDL_Texture* explorer_t::createFilesystemEntry(const char* text,
                                               const char* size) {
  SDL_Surface* surface = IMG_Load("res/UI/file.png");
  SDL_Renderer* renderer = SDL_CreateSoftwareRenderer(surface);
  SDL_Texture* newTexture = nullptr;

  SDL_Surface* thingSurface = TTF_RenderUTF8_Solid_Wrapped(
      context->font, text, {0xe0, 0xe1, 0xcc, SDL_ALPHA_OPAQUE}, pix(0));
  newTexture = SDL_CreateTextureFromSurface(renderer, thingSurface);
  SDL_FreeSurface(thingSurface);

  SDL_Rect rect = {11, 6, thingSurface->w * 40 / thingSurface->h, 40};
  SDL_RenderCopy(renderer, newTexture, nullptr, &rect);
  SDL_DestroyTexture(newTexture);

  thingSurface = TTF_RenderUTF8_Solid_Wrapped(
      context->font, size, {0xe0, 0xe1, 0xcc, SDL_ALPHA_OPAQUE}, pix(0));
  newTexture = SDL_CreateTextureFromSurface(renderer, thingSurface);
  SDL_FreeSurface(thingSurface);

  rect = {550, 6, thingSurface->w * 40 / thingSurface->h, 40};
  SDL_RenderCopy(renderer, newTexture, nullptr, &rect);
  SDL_DestroyTexture(newTexture);

  SDL_Texture* texture =
      SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);

  return texture;
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

    background = SDL_CreateTextureFromSurface(_context->mainRenderer, surface);
    if (background == nullptr) {
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
  SDL_DestroyTexture(background);
}

std::pair<scene::scenes, void*> explorer_t::update() {
  return {scenes::explorer, nullptr};
}

void explorer_t::render() {
  SDL_RenderCopy(context->mainRenderer, background, nullptr, nullptr);

  for (auto [texture, position] : items) {
    SDL_RenderCopy(context->mainRenderer, texture, nullptr, &position);
  }
}

std::pair<scene::scenes, void*> explorer_t::handle(SDL_Event& event) {
  SDL_Point point;
  switch (event.type) {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {}
      break;

    case SDL_MOUSEBUTTONDOWN:
      point.x = event.button.x;
      point.y = event.button.y;

      if (SDL_PointInRect(&point, &downloadBounds)) {
        switch (saveData) {
          case saveState::entry2:
            items.emplace_back(createFilesystemEntry("2024/6/15", "921B"),
                               SDL_Rect{pix(1), pix(72), pix(320), pix(24)});
            break;

          case saveState::init:
            ++saveData;
            [[fallthrough]];

          case saveState::entry1:
            SDL_DestroyTexture(items.front().first);
            items.erase(items.begin());

            items.emplace_back(createFilesystemEntry("2024/7/20", "1.3K"),
                               SDL_Rect{pix(1), pix(48), pix(320), pix(24)});
            break;

          default:
            break;
        }

        for (size_t i = 0; i < items.size(); ++i) {
          if (SDL_PointInRect(&point, &items[i].second)) {
            return {scene::scenes::notepad, nullptr};
          }
        }
      }

      break;

    default:
      break;
  }

  return {scenes::explorer, nullptr};
}
