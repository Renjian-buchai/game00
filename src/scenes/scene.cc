#include "scenes/scene.hh"

#include "game.hh"

scene::scene(game* _context) : context(_context) {}

scene::~scene() {}

SDL_Texture* scene::loadTexture(const char* path) {
  SDL_Surface* surface = IMG_Load(path);
  if (surface == nullptr) {
    std::cerr << IMG_GetError();
    // Safe because SDL guarantees that all functions can take nullptr as
    // textures.
    return nullptr;
  }

  SDL_Texture* texture =
      SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  if (texture == nullptr) {
    std::cerr << SDL_GetError();
    return nullptr;
  }

  SDL_FreeSurface(surface);
  return texture;
}
