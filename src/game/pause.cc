#include "../../include/scenes/pause.hh"

#include "../../include/game.hh"

pause_t::pause_t(game* _context)
    : scene(_context),
      resumePos({pix(219), pix(169), pix(201), pix(63)}),
      exitPos({pix(219), pix(235), pix(201), pix(63)}) {
  overlay = loadTexture("res/UI/PauseOverlay.png");
  resume = loadTexture("res/UI/PauseBTResume.png");
  resumeHover = loadTexture("res/UI/PauseBTResumeHover.png");
  resumeState = resume;

  exit = loadTexture("res/UI/PauseBTExit.png");
  exitHover = loadTexture("res/UI/PauseBTExitHover.png");
  exitState = exit;
}

pause_t::~pause_t() {
  SDL_DestroyTexture(overlay);
  SDL_DestroyTexture(resume);
  SDL_DestroyTexture(resumeHover);
  SDL_DestroyTexture(exit);
  SDL_DestroyTexture(exitHover);
}

void pause_t::update() {}

void pause_t::render() {
  SDL_RenderCopy(context->mainRenderer, overlay, nullptr, nullptr);
  SDL_RenderCopy(context->mainRenderer, resumeState, nullptr, nullptr);
  SDL_RenderCopy(context->mainRenderer, exitState, nullptr, nullptr);
}

scene* pause_t::handle(SDL_Event& event) {
  SDL_Point mousePosition = {event.motion.x, event.motion.y};

  resumeState =
      SDL_PointInRect(&mousePosition, &resumePos) ? resumeHover : resume;

  exitState = SDL_PointInRect(&mousePosition, &exitPos) ? exitHover : exit;

  return nullptr;
}
