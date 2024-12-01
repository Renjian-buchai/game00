#if !defined(SCENE_HH)
#define SCENE_HH

#include "../../include/pch.hh"

#define pix(val) static_cast<int>(val * context->pixelSize)

struct game;

// Just to make sure everything has the same interface
struct scene {
  enum class scenes : uint8_t { intro, explorer, notepad, pause };

  SDL_Texture* loadTexture(const char* path);

  game* context;

  scene(game* gameContext);

  virtual ~scene();

  virtual scenes update() = 0;

  virtual void render() = 0;

  // Return 1 if pause is hit
  virtual scenes handle(SDL_Event&) = 0;
};

#endif