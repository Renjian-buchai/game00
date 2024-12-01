#include "../../include/scenes/init.hh"

#include "../../include/game.hh"

init_t::slide::slide(size_t _fadeIn, size_t _fadeOut, size_t _duration,
                     SDL_Texture* _texture, SDL_Rect _dest, bool _skippable)
    : fadeIn(_fadeIn),
      duration(_duration),
      fadeOut(_fadeOut),
      texture(_texture),
      dest(_dest),
      skippable(_skippable) {}

void init_t::slideShow(size_t time, bool& click, size_t skipGrace) {
  static size_t lastTime = time;
  static size_t currentSlide;

  if (slides.empty()) {
    return;
  }

  slide& head = slides[currentSlide];

  if (click && head.skippable && time - lastTime > skipGrace) {
    lastTime = time;
    ++currentSlide;
    click = false;
    return;
  }

  if (time - lastTime > head.fadeIn + head.duration + head.fadeOut) {
    lastTime = time;
    ++currentSlide;
    return;
  }

  if (time - lastTime < head.fadeIn) {
    SDL_SetTextureAlphaMod(head.texture, 255 * (time - lastTime) / head.fadeIn);
  } else if (time - lastTime < head.fadeIn + head.duration) {
    (void)0;  // Head should be 255 already, so save on some clock cycles
  } else {
    SDL_SetTextureAlphaMod(
        head.texture,
        255 - (255 * (time - lastTime - head.fadeIn - head.duration) /
               head.fadeOut));
  }

  SDL_RenderCopy(context->mainRenderer, head.texture, nullptr,
                 SDL_RectEmpty(&head.dest) ? nullptr : &head.dest);
}

void init_t::addSlide(SDL_Surface* surface, size_t fadeIn, size_t duration,
                      size_t fadeOut, SDL_Rect dest, bool centred,
                      bool skippable) {
  slides.emplace_back(
      fadeIn, fadeOut, duration,
      SDL_CreateTextureFromSurface(context->mainRenderer, surface), dest,
      skippable);
  SDL_FreeSurface(surface);

  if (centred) init_t::centreRect(slides.rbegin()->dest);
}

void init_t::centreRect(SDL_Rect& rect, centre _centre) const {
  if (_centre == centre::BOTH) {
    rect.x = (context->dispBounds.w - rect.w) / 2;
    rect.y = (context->dispBounds.h - rect.h) / 2;
  } else if (_centre == centre::HORIZONTAL) {
    rect.x = (context->dispBounds.w - rect.w) / 2;
  } else {
    rect.y = (context->dispBounds.h - rect.h) / 2;
  }

  return;
}

init_t::init_t(game* _context) : scene(_context), startTime(SDL_GetTicks64()) {
  addSlide(IMG_Load("res/images/0001.png"), 0, 1500, 500);

  SDL_Colour white{0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE};

  // 1.5s
  SDL_Surface* surface = TTF_RenderText_Solid(
      context->font, "Ah, but I'll be causing trouble for my family, won't I?",
      white);

  addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

  // 1.5s
  surface = TTF_RenderText_Solid_Wrapped(
      context->font, "If only someone else could just...", white, 0);

  addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

  // 1.5s
  surface = TTF_RenderText_Solid_Wrapped(context->font, "Live on my behalf...",
                                         white, 0);

  addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

  // 1.5s
  surface = TTF_RenderText_Solid_Wrapped(context->font,
                                         "So that I don't have to.", white, 0);

  addSlide(surface, 250, 1000, 250, {0, 0, surface->w, surface->h});

  // 2.0s
  surface = TTF_RenderText_Solid_Wrapped(context->font, "", {}, 0);
  addSlide(surface, 0, 2000, 0, SDL_Rect{}, true, false);

  // 1.0s
  surface = TTF_RenderText_Solid_Wrapped(context->font,
                                         "This game does not represent\n"
                                         "the experiences of the creator.\n"
                                         "See: The Beginner's Guide",
                                         white, 0);

  addSlide(surface, 250, 500, 250, {0, 0, surface->w, surface->h});

  // 1.0s
  surface = TTF_RenderText_Solid_Wrapped(context->font,

                                         "Please don't spam my e-mail\n"
                                         "asking about my mental health"
                                         "\nlike last time.",
                                         white, 0);

  addSlide(surface, 250, 500, 250, {0, 0, surface->w, surface->h});

  // 2.0s
  surface = TTF_RenderText_Solid_Wrapped(context->font, "", {}, 0);
  addSlide(surface, 0, 2000, 0, SDL_Rect{}, true, false);

  // 5s
  surface = TTF_RenderText_Solid_Wrapped(
      context->font, "Loading...", {0xbb, 0xbb, 0xbb, SDL_ALPHA_OPAQUE}, 0);

  addSlide(surface, 250, 5000, 250,
           {context->dispBounds.w - surface->w - context->dispBounds.h / 40,
            context->dispBounds.h - surface->h - context->dispBounds.h / 40,
            surface->w, surface->h},
           false, false);
}

init_t::~init_t() {
  for (slide& _slide : slides) {
    SDL_DestroyTexture(_slide.texture);
  }
}

scene::scenes init_t::update() {
  size_t deltaTime = SDL_GetTicks64() - startTime;
  if (deltaTime > 19000) {
    return scenes::explorer;
  }
  return scenes::intro;
}

void init_t::render() {
  SDL_RenderClear(context->mainRenderer);
  slideShow(SDL_GetTicks64(), skip);
}

scene::scenes init_t::handle(SDL_Event& event) {
  skip = event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE;
  return scenes::intro;
}
