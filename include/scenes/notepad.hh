#if !defined(NOTEPAD_HH)
#define NOTEPAD_HH

#include "../scenes/scene.hh"

struct notepad_t : public scene {
  constexpr static int scale = 2;

 public:
  SDL_Texture* background;
  const int lineWrapLength;
  notepadData currentData;

 public:
  notepad_t(game* context);
  ~notepad_t();
  std::pair<scenes, sceneData> update() override;
  void render() override;
  std::pair<scenes, sceneData> handle(SDL_Event& event) override;
};

#endif
