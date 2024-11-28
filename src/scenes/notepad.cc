#include "../../include/scenes/notepad.hh"

#define pix(val) static_cast<int>(val * context->pixelSize)

#include "../../include/game.hh"

notepad::notepad(game* _context)
    : scene(_context),
      pauseBounds(SDL_Rect{pix(600), 0, pix(39), pix(24)}),
      lineWrapLength(scale *
                     static_cast<double>(context->dispBounds.w - pix(16))) {}

notepad::~notepad() {}

void notepad::update() {}

void notepad::render() {}

scene* notepad::handle(SDL_Event& event) { return this; }
