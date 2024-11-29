#if !defined(WM_HH)
#define WM_HH

#include <memory>
#include <utility>
#include <vector>

#include "SDL.h"

struct game;

#include "scenes/explorer.hh"
#include "scenes/notepad.hh"
#include "scenes/pause.hh"

struct wm {
  std::vector<scene*> scenes;
  std::vector<std::pair<SDL_Texture*, SDL_Rect>> icons;

  SDL_Texture* OSOverlay;

  wm(game* context);

  void render();
  void handle(SDL_Event& event);
  void update();

  game* context;

  SDL_Rect pauseBounds;

  // So that it will delete itself when wm terminates
  std::unique_ptr<explorer_t> expl;
  std::unique_ptr<notepad_t> note;
  std::unique_ptr<pause_t> pause;

  scene* current;
  scene* resume;
};

#endif