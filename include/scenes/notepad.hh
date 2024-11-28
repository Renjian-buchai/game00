#if !defined(NOTEPAD_HH)
#define NOTEPAD_HH

#include "scene.hh"

enum class notepadSave {
  none,
};

static notepadSave notepadSaveData [[maybe_unused]] = notepadSave::none;

struct notepad : public scene {
  constexpr static int scale = 2;

 public:
  SDL_Texture* OS;
  const SDL_Rect pauseBounds;

  const int lineWrapLength;

 public:
  notepad(game* context);
  ~notepad();
  void update() override;
  void render() override;
  scene* handle(SDL_Event& event) override;
};

#endif
