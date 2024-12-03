#if !defined(NOTEPAD_HH)
#define NOTEPAD_HH

#include "scene.hh"

enum class notepadSave {
  none,
};

// static notepadSave notepadSaveData  = notepadSave::none;

struct notepad_t : public scene {
  constexpr static int scale = 2;

 public:
  SDL_Texture* OS;
  const SDL_Rect pauseBounds;

  const int lineWrapLength;

 public:
  notepad_t(game* context);
  ~notepad_t();
  std::pair<scenes, sceneData> update() override;
  void render() override;
  std::pair<scenes, sceneData> handle(SDL_Event& event) override;
};

#endif
