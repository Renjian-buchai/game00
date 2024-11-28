#if !defined(WM_HH)
#define WM_HH

#include <memory>
#include <utility>
#include <vector>

#include "SDL.h"

struct game;

#include "scenes/explorer.hh"
#include "scenes/notepad.hh"

struct wm {
  std::vector<scene*> scenes;
  std::vector<std::pair<SDL_Texture*, SDL_Rect>> icons;

  SDL_Texture* OSOverlay;

  wm(game* context);

  void render();
  void handle(SDL_Event& event);
  void update();

  game* context;

  // So that it will delete itself when wm terminates
  std::unique_ptr<explorer> expl;
  std::unique_ptr<notepad> note;

  scene* current;
};

#endif