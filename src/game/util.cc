#include "../../include/game.hh"

game::slide::slide(size_t _fadeIn, size_t _fadeOut, size_t _duration,
                   SDL_Texture* _texture, SDL_Rect _dest, bool _skippable)
    : fadeIn(_fadeIn),
      duration(_duration),
      fadeOut(_fadeOut),
      texture(_texture),
      dest(_dest),
      skippable(_skippable) {}

void game::slideShow(size_t time, bool& click, size_t skipGrace) {
  static size_t lastTime = time;

  if (!slideQueue.empty()) {
    slide& head = slideQueue[0];

    if (click and slideQueue.begin()->skippable and
        time - lastTime > skipGrace) {
      lastTime = time;
      slideQueue.erase(slideQueue.begin());
      head = slideQueue[0];
      click = false;
      return;
    }

    if (time - lastTime > head.fadeIn + head.duration + head.fadeOut) {
      lastTime = time;
      slideQueue.erase(slideQueue.begin());
      head = slideQueue[0];

      return;
    }

    if (time - lastTime < head.fadeIn) {
      SDL_SetTextureAlphaMod(head.texture,
                             255 * (time - lastTime) / head.fadeIn);
    } else if (time - lastTime < head.fadeIn + head.duration) {
      (void)0;  // Alpha should already be 255 from the fade in
    } else if (time - lastTime < head.fadeIn + head.duration + head.fadeOut) {
      SDL_SetTextureAlphaMod(
          head.texture,
          255 - (255 * (time - lastTime - head.fadeIn - head.duration) /
                 head.fadeOut));
    }
    SDL_RenderCopy(mainRenderer, head.texture, nullptr,
                   SDL_RectEmpty(&head.dest) ? nullptr : &head.dest);
  }
}

void game::addSlide(SDL_Surface* surface, size_t fadeIn, size_t duration,
                    size_t fadeOut, SDL_Rect dest, bool centred,
                    bool skippable) {
  textures.emplace_back(SDL_CreateTextureFromSurface(mainRenderer, surface));
  SDL_SetTextureBlendMode(textures.back(), SDL_BLENDMODE_BLEND);
  slideQueue.emplace_back(fadeIn, fadeOut, duration, textures.back(), dest,
                          skippable);
  SDL_FreeSurface(surface);

  if (centred) game::centreRect(slideQueue.rbegin()->dest);
}

void game::centreRect(SDL_Rect& rect, game::centre centre) const {
  if (centre == centre::BOTH) {
    rect.x = (dispBounds.w - rect.w) / 2;
    rect.y = (dispBounds.h - rect.h) / 2;
  } else if (centre == centre::HORIZONTAL) {
    rect.x = (dispBounds.w - rect.w) / 2;
  } else {
    rect.y = (dispBounds.h - rect.h) / 2;
  }

  return;
}
