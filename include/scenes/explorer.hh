#if !defined(EXPLORER_HH)
#define EXPLORER_HH

#include <vector>

#include "SDL.h"
#include "scene.hh"

enum class explorerSave {
  init,
  entry1,
  size,
};
static explorerSave saveData = explorerSave::init;
static std::vector<std::pair<SDL_Texture*, SDL_Rect>> items;

struct explorer : public scene {
  explorer(game* context);
  ~explorer();
  void update() override;
  void render() override;
  scene* handle(SDL_Event& event) override;

  SDL_Texture* OS;
  const SDL_Rect pauseBounds;
  const SDL_Rect downloadBounds;
  const SDL_Rect explorerBounds;

  const int nameWrapLength;
};

#endif