#if !defined(SCENE_HH)
#define SCENE_HH

#include "SDL.h"
#include "game.hh"

// Just to make sure everything has the same interface
struct scene {
  game* context;

  scene(game*);

  virtual ~scene();

  virtual void update() = 0;

  virtual void render() = 0;

  // Return 1 if pause is hit
  virtual bool handle(SDL_Event&) = 0;
};

#endif