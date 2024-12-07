#include "UI/button.hh"

#include <iostream>

#include "SDL_image.h"
#include "game.hh"

button::button(game* _context, const char* _inactive, const char* _hovered,
               SDL_Rect _bounds)
    : context(_context), bounds(_bounds) {
  SDL_Surface* surface = IMG_Load(_inactive);
  inactive = SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);

  surface = IMG_Load(_hovered);
  hovered = SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);

  state = inactive;

  return;
}

button::~button() {
  SDL_DestroyTexture(inactive);
  SDL_DestroyTexture(hovered);
}

void button::handle(SDL_Point point) {
  state = SDL_PointInRect(&point, &bounds) ? hovered : inactive;
}

void button::render() {
  SDL_RenderCopy(context->mainRenderer, state, nullptr, &bounds);
}
