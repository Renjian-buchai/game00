#include "../../include/scenes/explorer.hh"

explorer::explorer(game* context) : scene(context) {
  // TODO load images and shit
}

explorer::~explorer() {
  // TODO Idk, probably don't free stuff? Not sure
}

void explorer::update() {
  // TODO gameplay loop
}

void explorer::render() {}

bool explorer::handle(SDL_Event& event) { return false; }
