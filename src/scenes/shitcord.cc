#include "scenes/shitcord.hh"

shitcord_t::shitcord_t(game* _context) : scene(_context) { return; }

shitcord_t::~shitcord_t() {}

std::pair<scenes, sceneData> shitcord_t::update() {
  return std::make_pair(scenes::shitcord, std::monostate());
}

void shitcord_t::render() {}

std::pair<scenes, sceneData> shitcord_t::handle(SDL_Event& event) {
  return std::make_pair(scenes::shitcord, std::monostate());
}
