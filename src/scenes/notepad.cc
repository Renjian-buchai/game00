#include "../../include/scenes/notepad.hh"

#include "../../include/game.hh"

notepad_t::notepad_t(game* _context)
    : scene(_context),
      pauseBounds(SDL_Rect{pix(600), 0, pix(39), pix(24)}),
      lineWrapLength(scale *
                     static_cast<double>(context->dispBounds.w - pix(16))) {}

notepad_t::~notepad_t() {}

std::pair<scene::scenes, sceneData> notepad_t::update() {
  return {scenes::notepad, nullptr};
}

void notepad_t::render() {}

std::pair<scene::scenes, sceneData> notepad_t::handle(SDL_Event& event) {
  return {scenes::notepad, nullptr};
}
