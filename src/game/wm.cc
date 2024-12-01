#include "../../include/wm.hh"

#include "../../include/game.hh"

wm::wm(game* _context)
    : context(_context),
      pauseBounds(SDL_Rect{pix(600), 0, pix(39), pix(24)}),
      expl(std::make_unique<explorer_t>(context)),
      note(std::make_unique<notepad_t>(context)),
      pause(std::make_unique<pause_t>(context)),
      intro(std::make_unique<init_t>(context)),
      current(intro.get()) {
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
  if (current != intro.get()) {
    SDL_RenderCopy(context->mainRenderer, OSOverlay, nullptr, nullptr);
    for (auto& [texture, position] : icons) {
      SDL_RenderCopy(context->mainRenderer, texture, nullptr, &position);
    }
  }
}

scene::scenes wm::update() { return current->update(); }

scene::scenes wm::handle(SDL_Event& event) {
  if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
    if (current == pause.get()) {
      if (resume == expl.get()) {
        return scene::scenes::explorer;
      } else if (resume == note.get()) {
        return scene::scenes::notepad;
      } else if (resume == pause.get()) {
        return scene::scenes::pause;
      } else if (resume == intro.get()) {
        return scene::scenes::intro;
      }
    } else {
      resume = current;

      return scene::scenes::pause;
    }
  }

  if (event.type == SDL_MOUSEBUTTONDOWN &&
      event.button.button == SDL_BUTTON_LEFT) {
    SDL_Point point = {event.button.x, event.button.y};
    if (current == pause.get()) {
      if (SDL_PointInRect(&point, &pause->resumePos)) {
        if (resume == expl.get()) {
          return scene::scenes::explorer;
        } else if (resume == note.get()) {
          return scene::scenes::notepad;
        } else if (resume == pause.get()) {
          return scene::scenes::pause;
        } else if (resume == intro.get()) {
          return scene::scenes::intro;
        }
      }

      if (SDL_PointInRect(&point, &pause->exitPos)) {
        context->state = game::gameState::terminating;
        std::exit(0);
      }
    } else {
      if (SDL_PointInRect(&point, &pauseBounds)) {
        resume = current;

        return scene::scenes::pause;
      }
    }
  }

  return current->handle(event);
}
