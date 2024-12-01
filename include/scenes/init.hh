#if !defined(INIT_HH)
#define INIT_HH

#include "scene.hh"

struct init_t : public scene {
  enum class centre : uint8_t { HORIZONTAL, VERTICAL, BOTH };
  struct slide {
    slide(size_t _fadeIn, size_t _fadeOut, size_t _duration,
          SDL_Texture* _texture, SDL_Rect _dest = {}, bool skippable = true);

    size_t fadeIn;
    size_t duration;
    size_t fadeOut;
    SDL_Texture* texture;
    SDL_Rect dest;
    bool skippable;
  };

  std::vector<slide> slides;
  size_t startTime;
  bool skip;

  init_t(game* context);
  ~init_t();
  scenes update() override;
  void render() override;
  scenes handle(SDL_Event& event) override;

  void slideShow(size_t time, bool& click, size_t skipGrace = 1000);
  void addSlide(SDL_Surface* surface, size_t fadeIn, size_t duration,
                size_t fadeOut, SDL_Rect dest = SDL_Rect{}, bool centred = true,
                bool skippable = true);

  void centreRect(SDL_Rect& rect, centre centre = centre::BOTH) const;
};

#endif
