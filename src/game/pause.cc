#include "scenes/pause.hh"

#include <iostream>

#include "game.hh"
pause_t::pause_t(game* _context)
    : scene(_context),
      resume{context,
             "res/UI/PauseBTResume.png",
             "res/UI/PauseBTResumeHover.png",
             {pix(219), pix(169), pix(201), pix(63)}},
      exit{context,
           "res/UI/PauseBTExit.png",
           "res/UI/PauseBTExitHover.png",
           {pix(219), pix(235), pix(201), pix(63)}} {
  overlay = loadTexture("res/UI/PauseOverlay.png");
}

pause_t::~pause_t() { SDL_DestroyTexture(overlay); }

std::pair<scenes, sceneData> pause_t::update() {
  return std::make_pair(scenes::pause, std::monostate());
}

void pause_t::render() {
  SDL_RenderCopy(context->mainRenderer, overlay, nullptr, nullptr);
  resume.render();
  exit.render();
}

std::pair<scenes, sceneData> pause_t::handle(SDL_Event& event) {
  if (event.type == SDL_MOUSEMOTION) {
    SDL_Point mousePosition = {event.motion.x, event.motion.y};

    resume.handle(mousePosition);
    exit.handle(mousePosition);
  }

  return std::make_pair(scenes::pause, std::monostate());
}
