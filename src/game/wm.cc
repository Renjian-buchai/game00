#include "../../include/wm.hh"

#include "../../include/game.hh"
#include "../../include/scenes/explorer.hh"
#include "../../include/scenes/notepad.hh"
#include "../../include/scenes/scene.hh"
#include "SDL_image.h"

wm::wm(game* _context)
    : context(_context),
      expl(std::make_unique<explorer>(context)),
      note(std::make_unique<notepad>(context)),
      current(expl.get()) {
  SDL_Surface* os = IMG_Load("res/images/OS.png");
  if (os == nullptr) {
    std::cout << IMG_GetError();
    std::exit(-1);
  }

  OSOverlay = SDL_CreateTextureFromSurface(context->mainRenderer, os);
  SDL_FreeSurface(os);
}

void wm::render() {
  current->render();
  SDL_RenderCopy(context->mainRenderer, OSOverlay, nullptr, nullptr);
}

void wm::update() { current->update(); }

void wm::handle(SDL_Event& event) {
  if (event.key.keysym.sym == SDLK_ESCAPE) {
    // TODO pause thing
  }

  current->handle(event);
}
