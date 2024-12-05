#if !defined(game_GAME_HH)
#define game_GAME_HH

#include "pch.hh"
#include "wm.hh"

class game {
 public:
  enum class gameState : uint8_t {
    terminating,
    intro,
    gameplay,
    paused,
  };

  /**
   * @brief State that the game is in
   *
   */
  gameState state = gameState::intro;

  /**
   * @brief Rect containing the screen height and width
   *
   */
  SDL_Rect dispBounds;
  /**
   * @brief Main window to render to
   *
   */
  SDL_Window* mainWindow;
  /**
   * @brief Main renderer that renders to mainWindow
   *
   */
  SDL_Renderer* mainRenderer;

  /**
   * @brief Background music. Randomly selected.
   *
   */
  std::array<Mix_Music*, 4> bgm;
  /**
   * @brief Different lengths of silence. Randomly selected.
   *
   */
  std::array<Mix_Music*, 6> silence;

  /**
   * @brief Font used for text.
   *
   */
  TTF_Font* font;

  /** Size of virtual pixels per real pixel.  */
  double pixelSize;

  /**
   * @brief Windows manager
   *
   */
  wm winMan;

  SDL_mutex* mutex;

  /**
   * @brief Thread that loads winMan
   *
   */
  SDL_Thread* loadThread;

  /**
   * @brief Construct a new game object
   *
   * WM will be loaded in a thread.
   */
  game();

  /**
   * @brief Destroy the game object
   *
   */
  ~game();

  /**
   * @brief Runs the WM. Waits for the WM to be initialised, first.
   *
   */
  void gameplay();
};

#endif
