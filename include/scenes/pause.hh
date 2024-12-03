#if !defined(PAUSE_HH)
#define PAUSE_HH

#include "scene.hh"

struct pause_t : public scene {
  SDL_Texture* overlay;

  SDL_Texture* resume;
  SDL_Texture* resumeHover;
  SDL_Texture* resumeState;
  SDL_Rect resumePos;

  SDL_Texture* exit;
  SDL_Texture* exitHover;
  SDL_Texture* exitState;
  SDL_Rect exitPos;

  pause_t(game* context);
  ~pause_t();
  std::pair<scene::scenes, sceneData> update() override;
  void render() override;
  std::pair<scene::scenes, sceneData> handle(SDL_Event& event) override;
};
#endif
