#include "scenes/shitcord.hh"

#include "SDL_image.h"
#include "game.hh"

shitcord_t::shitcord_t(game* _context) : scene(_context) {
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

std::pair<scenes, sceneData> shitcord_t::handle(SDL_Event& event) {
  return std::make_pair(scenes::shitcord, std::monostate());
}
