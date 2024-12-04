#include "../../include/wm.hh"

#include "../../include/game.hh"
#include "../../include/scenes/explorer.hh"
#include "../../include/scenes/init.hh"
#include "../../include/scenes/notepad.hh"
#include "../../include/scenes/pause.hh"

wm::wm(game* _context)
    : context(_context),
      pauseBounds(SDL_Rect{pix(600), 0, pix(39), pix(24)}),
      explorer(std::make_unique<explorer_t>(context)),
      notepad(std::make_unique<notepad_t>(context)),
      pause(std::make_unique<pause_t>(context)),
      intro(std::make_unique<intro_t>(context)),
      // current(intro.get()) {
      current(explorer.get()) {
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

  surface = IMG_Load("res/UI/notepadIcon.png");
  if (surface == nullptr) {
    std::cout << IMG_GetError();
    std::exit(-1);
  }
  icons.emplace_back(
      SDL_CreateTextureFromSurface(context->mainRenderer, surface),
      SDL_Rect{pix(48), pix(376), pix(surface->w), pix(surface->h)});
  SDL_FreeSurface(surface);

  {
    time_t rtime;
    time(&rtime);
    std::srand(rtime);
  }
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

std::pair<scenes, sceneData> wm::update() {
  if (!Mix_PlayingMusic()) {
    if (wasSilence) {
      Mix_PlayMusic(context->bgm[std::rand() % 4], 0);
      wasSilence = 0;
    } else {
      Mix_PlayMusic(context->silence[std::rand() % 6], 0);
      wasSilence = 1;
    }
  }

  return current->update();
}

std::pair<scenes, sceneData> wm::handle(SDL_Event& event) {
  if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
    if (current == pause.get()) {
      if (resume == explorer.get()) {
        return std::make_pair(scenes::explorer, std::monostate());
      } else if (resume == notepad.get()) {
        return std::make_pair(scenes::notepad, notepad->currentData);
      } else if (resume == pause.get()) {
        return std::make_pair(scenes::pause, std::monostate());
      } else if (resume == intro.get()) {
        return std::make_pair(scenes::intro, std::monostate());
      }
    } else {
      resume = current;

      return std::make_pair(scenes::pause, std::monostate());
    }
  }

  if (event.type == SDL_MOUSEBUTTONDOWN &&
      event.button.button == SDL_BUTTON_LEFT) {
    SDL_Point point = {event.button.x, event.button.y};

    // Only for pausing
    if (current == pause.get()) {
      if (SDL_PointInRect(&point, &pause->resumePos)) {
        if (resume == explorer.get()) {
          return std::make_pair(scenes::explorer, std::monostate());
        } else if (resume == notepad.get()) {
          return std::make_pair(scenes::notepad, notepad->currentData);
        } else if (resume == pause.get()) {
          return std::make_pair(scenes::pause, std::monostate());
        } else if (resume == intro.get()) {
          return std::make_pair(scenes::intro, std::monostate());
        }
      }

      if (SDL_PointInRect(&point, &pause->exitPos)) {
        context->state = game::gameState::terminating;
        std::exit(0);
      }
    } else {
      if (SDL_PointInRect(&point, &pauseBounds)) {
        resume = current;

        return std::make_pair(scenes::pause, std::monostate());
      }
    }

    for (auto& [icon, bound] : icons) {
      if (SDL_PointInRect(&point, &bound)) {
        // Rounds down when converting from pixel to sceen, so need to round up
        // to compensate
        switch (static_cast<int>(bound.x / context->pixelSize) + 1) {
          case 24:
            return std::make_pair(scenes::explorer, std::monostate());

          case 48:
            return std::make_pair(scenes::notepad, notepad->currentData);

          default:
            break;
        }
      }
    }
  }

  return current->handle(event);
}
