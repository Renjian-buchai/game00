#if !defined(EXPLORER_HH)
#define EXPLORER_HH

#include <vector>

#include "SDL.h"
#include "scene.hh"

enum class explorerSave {
  init,
  first,
};
static explorerSave saveData;

struct explorer : public scene {
  explorer(game* context);
  ~explorer();
  std::unique_ptr<scene> update() override;
  void render() override;
  bool handle(SDL_Event& event) override;

  SDL_Texture* OS;
  const SDL_Rect pauseBounds;
  const SDL_Rect downloadBounds;
  const SDL_Rect explorerBounds;

  std::vector<std::pair<SDL_Texture*, SDL_Rect>> items;

  const int nameWrapLength;
};

#endif