#if !defined(game_GAME_HH)
#define game_GAME_HH

#include "pch.hh"
#include "wm.hh"

struct game {
  enum class gameState : uint8_t {
    terminating,
    intro,
    gameplay,
    paused,
  };

 private:
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

 public:
  gameState state = gameState::intro;

  SDL_Rect dispBounds;
  SDL_Window* mainWindow;
  SDL_Renderer* mainRenderer;

  TTF_Font* font;

  double pixelSize;

  wm winMan;
  SDL_Thread* loadThread;

 private:
  std::vector<slide> slideQueue;

 public:
  game();

  ~game();

  void intro();
  void gameplay();

 private:
  void slideShow(size_t time, bool& click, size_t skipGrace = 1000);
  SDL_Texture* addSlide(SDL_Surface* surface, size_t fadeIn, size_t duration,
                        size_t fadeOut, SDL_Rect dest = SDL_Rect{},
                        bool centred = true, bool skippable = true);

  void centreRect(SDL_Rect& rect, game::centre centre = centre::BOTH) const;
};

#endif
