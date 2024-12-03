#if !defined(WM_HH)
#define WM_HH

#include "enum.hh"
#include "pch.hh"
#include "scenes/explorer.hh"
#include "scenes/init.hh"
#include "scenes/notepad.hh"
#include "scenes/pause.hh"

struct game;

struct scene;

struct wm {
  std::vector<std::pair<SDL_Texture*, SDL_Rect>> icons;

  SDL_Texture* OSOverlay;

  wm() = default;
  wm(game* context);

  void render();
  std::pair<scenes, sceneData> handle(SDL_Event& event);
  std::pair<scenes, sceneData> update();

  game* context;

  SDL_Rect pauseBounds;

  // So that it will delete itself when wm terminates
  std::unique_ptr<explorer_t> explorer;
  std::unique_ptr<notepad_t> notepad;
  std::unique_ptr<pause_t> pause;
  std::unique_ptr<intro_t> intro;

  scene* current;
  scene* resume;
};

#endif