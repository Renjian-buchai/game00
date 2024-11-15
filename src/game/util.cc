#include "../../include/game.hh"

game::slide::slide(size_t _fadeIn, size_t _fadeOut, size_t _duration,
                   SDL_Texture* _texture, SDL_Rect _dest)
    : fadeIn(_fadeIn),
      duration(_duration),
      fadeOut(_fadeOut),
      texture(_texture),
      dest(_dest) {}

void game::slideShow(size_t time, bool& click) {
  static size_t lastTime = time;

  if (!slideQueue.empty()) {
    slide& head = slideQueue[0];

    if (click) {
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
