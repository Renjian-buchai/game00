#include <string>

#include "../../include/game.hh"
#include "SDL_image.h"

void game::paused() {
  // Whyyyyyyyy
  SDL_Texture* overlay = loadTexture("../res/UI/PauseOverlay.png");

  SDL_Texture* resume = loadTexture("../res/UI/PauseBTResume.png");
  SDL_Texture* resumeHover = loadTexture("../res/UI/PauseBTResumeHover.png");
  SDL_Texture* resumeState = resume;

  SDL_Texture* exit = loadTexture("../res/UI/PauseBTExit.png");
  SDL_Texture* exitHover = loadTexture("../res/UI/PauseBTExitHover.png");
  SDL_Texture* exitState = exit;

  SDL_Rect resumePos = {
      static_cast<int>(219 * pixelSize), static_cast<int>(169 * pixelSize),
      static_cast<int>(201 * pixelSize), static_cast<int>(63 * pixelSize)};
  SDL_Rect exitPos = {
      static_cast<int>(219 * pixelSize), static_cast<int>(235 * pixelSize),
      static_cast<int>(201 * pixelSize), static_cast<int>(63 * pixelSize)};

  SDL_SetRenderDrawBlendMode(mainRenderer, SDL_BLENDMODE_MUL);
  SDL_Point mousePosition;
  while (state == gameState::paused) {
    SDL_RenderCopy(mainRenderer, overlay, nullptr, nullptr);
    SDL_RenderCopy(mainRenderer, resumeState, nullptr, nullptr);
    SDL_RenderCopy(mainRenderer, exitState, nullptr, nullptr);

    SDL_RenderPresent(mainRenderer);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          state = gameState::terminating;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              state = gameState::gameplay;
              break;

            default:
              break;
          }
          break;

        case SDL_MOUSEBUTTONDOWN:
          mousePosition = {event.button.x, event.button.y};

          if (event.button.button == SDL_BUTTON_LEFT) {
            if (SDL_PointInRect(&mousePosition, &resumePos)) {
              state = gameState::gameplay;
            }

            // TODO: make it go to main menu instead
            if (SDL_PointInRect(&mousePosition, &exitPos)) {
              state = gameState::terminating;
            }
            break;
          }
          break;

        case SDL_MOUSEMOTION:
          mousePosition = {event.motion.x, event.motion.y};

          resumeState = SDL_PointInRect(&mousePosition, &resumePos)
                            ? resumeHover
                            : resume;

          exitState =
              SDL_PointInRect(&mousePosition, &exitPos) ? exitHover : exit;

          break;

        default:
          break;
      }
    }
  }

  return;
}