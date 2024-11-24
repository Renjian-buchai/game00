#if !defined(SCENE_HH)
#define SCENE_HH

#include <memory>

#include "SDL.h"

struct game;

// Just to make sure everything has the same interface
struct scene {
  game* context;

  scene(game* gameContext);

  virtual ~scene();

  virtual std::unique_ptr<scene> update() = 0;

  virtual void render() = 0;

  // Return 1 if pause is hit
  virtual bool handle(SDL_Event&) = 0;
};

#endif