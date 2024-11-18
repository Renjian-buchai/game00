#if !defined(EXPLORER_HH)
#define EXPLORER_HH

#include "scene.hh"

struct explorer : public scene {
  explorer(game* context);
  ~explorer() override;
  void update() override;
  void render() override;
  bool handle(SDL_Event& event) override;
};

#endif