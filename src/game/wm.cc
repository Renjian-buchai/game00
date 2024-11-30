#include "../../include/wm.hh"

#include "../../include/game.hh"
#include "../../include/scenes/explorer.hh"
#include "../../include/scenes/notepad.hh"
#include "../../include/scenes/pause.hh"
#include "../../include/scenes/scene.hh"

wm::wm(game* _context)
    : context(_context),
      pauseBounds(SDL_Rect{pix(600), 0, pix(39), pix(24)}),
      expl(std::make_unique<explorer_t>(context)),
      note(std::make_unique<notepad_t>(context)),
      pause(std::make_unique<pause_t>(context)),
      current(expl.get()) {
  SDL_Surface* surface = IMG_Load("res/UI/OS.png");
  if (surface == nullptr) {
    std::cout << IMG_GetError();
    std::exit(-1);
  }

  OSOverlay = SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);

  surface = IMG_Load("res/UI/explorerIcon.png");
  if (surface == nullptr) {
    std::cout << IMG_GetError();
    std::exit(-1);
  }

  icons.emplace_back(
      SDL_CreateTextureFromSurface(context->mainRenderer, surface),
      SDL_Rect{pix(24), pix(376), pix(surface->w), pix(surface->h)});
  SDL_FreeSurface(surface);
}

void wm::render() {
  current->render();
  SDL_RenderCopy(context->mainRenderer, OSOverlay, nullptr, nullptr);
  for (auto& [texture, position] : icons) {
    SDL_RenderCopy(context->mainRenderer, texture, nullptr, &position);
  }
}

void wm::update() { current->update(); }

void wm::handle(SDL_Event& event) {
  static auto pauseSeq = [&]() {
    context->state = game::gameState::paused;
    resume = current;
    current = pause.get();
  };
  static auto resumeSeq = [&]() {
    context->state = game::gameState::gameplay;
    current = resume;
    resume = nullptr;
  };

  if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
    if (context->state == game::gameState::paused) {
      resumeSeq();
    } else {
      pauseSeq();
    }
  }

  if (event.type == SDL_MOUSEBUTTONDOWN &&
      event.button.button == SDL_BUTTON_LEFT) {
    SDL_Point point = {event.button.x, event.button.y};
    if (context->state == game::gameState::paused) {
      if (SDL_PointInRect(&point, &pause->resumePos)) {
        resumeSeq();
      }

      if (SDL_PointInRect(&point, &pause->exitPos)) {
        context->state = game::gameState::terminating;
        std::exit(0);
      }
    } else {
      if (SDL_PointInRect(&point, &pauseBounds)) {
        pauseSeq();
      }
    }
  }

  current->handle(event);
}
