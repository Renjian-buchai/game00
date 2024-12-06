#include "scenes/notepad.hh"

#include <fstream>
#include <iostream>

#include "SDL_image.h"
#include "game.hh"

notepad_t::notepad_t(game* _context)
    : scene(_context),
      lineWrapLength(static_cast<int>(
          scale * static_cast<double>(context->dispBounds.w - pix(16)))),
      currentData(notepadData::empty),
      prevData(notepadData::empty),
      entryRect(SDL_Rect{pix(8), pix(32),
                         static_cast<int>(lineWrapLength / scale), 0}) {
  SDL_Surface* surface = IMG_Load("res/images/notepad.png");
  if (surface == nullptr) {
    std::cout << IMG_GetError();
    exit(-1);
  }
  background = SDL_CreateTextureFromSurface(context->mainRenderer, surface);
  SDL_FreeSurface(surface);
  if (background == nullptr) {
    std::cout << SDL_GetError();
    exit(-1);
  }

  entry = SDL_CreateTexture(context->mainRenderer,
                            SDL_GetWindowPixelFormat(context->mainWindow),
                            SDL_TextureAccess::SDL_TEXTUREACCESS_STATIC, 0, 0);
}

notepad_t::~notepad_t() {
  SDL_DestroyTexture(entry);
  SDL_DestroyTexture(background);
}

std::pair<scenes, sceneData> notepad_t::update() {
  if (currentData != prevData) {
    SDL_Surface* text;
    {
      std::ifstream read("res/story/" +
                         std::to_string(static_cast<int>(currentData)) +
                         ".txt");
      std::string buffer;
      std::string txt;
      while (std::getline(read, buffer)) {
        txt += buffer + "\n";
      }
      text = TTF_RenderUTF8_Solid_Wrapped(context->font, txt.c_str(),
                                          {0xe0, 0xe1, 0xcc, SDL_ALPHA_OPAQUE},
                                          lineWrapLength);
    }

    SDL_DestroyTexture(entry);

    entry = SDL_CreateTextureFromSurface(context->mainRenderer, text);
    entryRect.h = static_cast<int>(text->h / scale);
    SDL_FreeSurface(text);
    prevData = currentData;
  }
  return std::make_pair(scenes::notepad, currentData);
}

void notepad_t::render() {
  SDL_RenderCopy(context->mainRenderer, background, nullptr, nullptr);
  SDL_RenderCopy(context->mainRenderer, entry, nullptr, &entryRect);
}

std::pair<scenes, sceneData> notepad_t::handle(SDL_Event& event) {
  return std::make_pair(scenes::notepad, currentData);
}
