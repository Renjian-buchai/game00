#include "scenes/shitcord.hh"

#include "SDL_image.h"
#include "game.hh"

shitcord_t::shitcord_t(const game* _context) : scene(_context) {
  SDL_Surface* surface = IMG_Load("res/UI/backgrounds/shitcord.png");
  background = SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);

  return;
}

shitcord_t::~shitcord_t() {}

std::pair<scenes, sceneData> shitcord_t::update() {
  return std::make_pair(scenes::shitcord, std::monostate());
}

void shitcord_t::render() {
  SDL_RenderCopy(context->mainRenderer, background, nullptr, nullptr);
}

std::pair<scenes, sceneData> shitcord_t::handle(const SDL_Event& event) {
  return std::make_pair(scenes::shitcord, std::monostate());
}

SDL_Texture* shitcord_t::generateOptions(
    const std::array<std::string, 3> options) {
  SDL_Surface* surface = IMG_Load("res/UI/shitcordOptions.png");
  SDL_Renderer* surfaceRenderer = SDL_CreateSoftwareRenderer(surface);

  std::string render;
  for (size_t i = 0; i < 2; ++i) {
    if (options[i] == "") {
      render += "\n";
    } else {
      render += std::to_string(i + 1) + ". " + options[i] + "\n";
    }
  }

  if (options[2] != "") {
    render += "3. " + options[2];
  }

  SDL_Surface* optionText =
      TTF_RenderUTF8_Solid_Wrapped(context->font, render.c_str(),
                                   {0xe0, 0xe1, 0xcc, SDL_ALPHA_OPAQUE}, 1248);
  SDL_Texture* optionTexture =
      SDL_CreateTextureFromSurface(surfaceRenderer, optionText);
  SDL_Rect bounds{16, 16, optionText->w, optionText->h};
  SDL_FreeSurface(optionText);

  SDL_RenderCopy(surfaceRenderer, optionTexture, nullptr, &bounds);
  SDL_DestroyTexture(optionTexture);

  SDL_Texture* returnTexture =
      SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);

  return returnTexture;
}
