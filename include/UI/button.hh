#if !defined(BUTTON_HH)
#define BUTTON_HH

#include "SDL.h"

class game;

/**
 * @brief Class for button UI elements
 */
class button {
 public:
  /**
   * @brief Game context
   */
  game* context;

  /**
   * @brief Button when not mouse is not hovering over it
   */
  SDL_Texture* inactive;

  /**
   * @brief Button when mouse is hovering over it.
   */
  SDL_Texture* hovered;

  /**
   * @brief Current state of the button.
   */
  SDL_Texture* state;

  /**
   * @brief Bounds of the button.
   */
  SDL_Rect bounds;

  /**
   * @brief Construct a new button object
   */
  button(game* context, const char* inactive, const char* hovered,
         SDL_Rect bounds);

  ~button();

  /**
   * @brief Changes the state when the button hovers over the button.
   *
   * @param event Point associated with mouse movement
   */
  void handle(SDL_Point point);

  /**
   * @brief Renders button
   */
  void render();
};

#endif
