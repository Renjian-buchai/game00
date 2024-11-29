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
  void update() override;
  void render() override;
  scene* handle(SDL_Event& event) override;
};
#endif
