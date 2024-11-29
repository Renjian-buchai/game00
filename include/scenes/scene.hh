#if !defined(SCENE_HH)
#define SCENE_HH

#include <memory>

#include "SDL.h"

#define pix(val) static_cast<int>(val * context->pixelSize)

struct game;

// Just to make sure everything has the same interface
struct scene {
  SDL_Texture* loadTexture(const char* path);

  game* context;

  scene(game* gameContext);

  virtual ~scene();

  virtual void update() = 0;

  virtual void render() = 0;

  // Return 1 if pause is hit
  virtual scene* handle(SDL_Event&) = 0;
};

#endif