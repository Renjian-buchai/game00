#if !defined(game_GAME_HH)
#define game_GAME_HH

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "SDL.h"
#include "SDL_ttf.h"
#include "scenes/scene.hh"

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
  std::vector<SDL_Texture*> textures{};

  std::vector<std::unique_ptr<scene>> scenes{};

  TTF_Font* font;

  double pixelSize;

 private:
  std::vector<slide> slideQueue;

 public:
  game();

  ~game();

  void intro();
  void gameplay();
  void paused();

 private:
  SDL_Texture* loadTexture(std::string path);

  void slideShow(size_t time, bool& click, size_t skipGrace = 1000);
  void addSlide(SDL_Surface* surface, size_t fadeIn, size_t duration,
                size_t fadeOut, SDL_Rect dest = SDL_Rect{}, bool centred = true,
                bool skippable = true);

  void centreRect(SDL_Rect& rect, game::centre centre = centre::BOTH) const;
};

#endif
