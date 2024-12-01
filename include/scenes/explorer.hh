#if !defined(EXPLORER_HH)
#define EXPLORER_HH

#include "scene.hh"

struct explorer_t : public scene {
 public:
  enum class saveState {
    init,
    entry1,
    size,
  };

  saveState saveData;
  std::vector<std::pair<SDL_Texture*, SDL_Rect>> items;
  SDL_Texture* OS;
  const int nameWrapLength;
  const SDL_Rect downloadBounds;

  explorer_t(game* context);
  ~explorer_t();
  scenes update() override;
  void render() override;
  scenes handle(SDL_Event& event) override;
};

#endif