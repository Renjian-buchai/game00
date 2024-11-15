#if !defined(game_GAME_HH)
#define game_GAME_HH

#include <cstdlib>
#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_ttf.h"

struct game {
  enum class gameState : uint8_t {
    terminating,
    intro,
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
  SDL_Window* mainWindow = nullptr;
  SDL_Renderer* mainRenderer = nullptr;
  std::vector<SDL_Texture*> textures{};

  TTF_Font* font;

 private:
  std::vector<slide> slideQueue;

 public:
  game();

  ~game();

  void intro();

 private:
  void slideShow(size_t time, bool& click, size_t skipGrace = 1000);
  void addSlide(SDL_Surface* surface, size_t fadeIn, size_t duration,
                size_t fadeOut, SDL_Rect dest = SDL_Rect{}, bool centred = true,
                bool skippable = true);

  void centreRect(SDL_Rect& rect, game::centre centre = centre::BOTH);
};

#endif
