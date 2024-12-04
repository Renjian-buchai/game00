#if !defined(EXPLORER_HH)
#define EXPLORER_HH

#include "scene.hh"

struct explorer_t : public scene {
 public:
  explorerData saveData;
  std::vector<std::pair<SDL_Texture*, SDL_Rect>> items;
  SDL_Texture* background;
  const int nameWrapLength;
  const SDL_Rect downloadBounds;

  explorer_t(game* context);
  ~explorer_t();
  std::pair<scenes, sceneData> update() override;
  void render() override;
  std::pair<scenes, sceneData> handle(SDL_Event& event) override;
  SDL_Texture* createFilesystemEntry(const char* text, const char* size);
};

#endif