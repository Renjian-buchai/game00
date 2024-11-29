#include "../../include/scenes/notepad.hh"

#include "../../include/game.hh"

notepad_t::notepad_t(game* _context)
    : scene(_context),
      pauseBounds(SDL_Rect{pix(600), 0, pix(39), pix(24)}),
      lineWrapLength(scale *
                     static_cast<double>(context->dispBounds.w - pix(16))) {}

notepad_t::~notepad_t() {}

void notepad_t::update() {}

void notepad_t::render() {}

scene* notepad_t::handle(SDL_Event& event) { return this; }
