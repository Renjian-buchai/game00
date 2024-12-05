#if !defined(WM_HH)
#define WM_HH

#include "enum.hh"
#include "pch.hh"
#include "scenes/explorer.hh"
#include "scenes/init.hh"
#include "scenes/notepad.hh"
#include "scenes/pause.hh"

class game;

class scene;

class wm {
 public:
  /**
   * @brief Icons for the task bar
   *
   */
  std::vector<std::pair<SDL_Texture*, SDL_Rect>> icons;

  /**
   * @brief Task bar overlay.
   *
   */
  SDL_Texture* OSOverlay;

  /**
   * @brief game context
   *
   */
  game* context;

  /**
   * @brief Position of the pause button
   *
   */
  SDL_Rect pauseBounds;

  /**
   * @brief Stores whether the last music track was silent
   *
   */
  bool wasSilence = 0;

  /**
   * @brief Scenes
   *
   * Unique pointers so that they'll kill themselves once wm terminates
   *
   */
  std::unique_ptr<explorer_t> explorer;
  std::unique_ptr<notepad_t> notepad;
  std::unique_ptr<pause_t> pause;
  std::unique_ptr<intro_t> intro;

  /**
   * @brief Current scene
   *
   */
  scene* current;
  /**
   * @brief Scene to resume on. Only used for unpausing purposes
   *
   */
  scene* resume;
  /**
   * @brief Construct a new wm object
   *
   * Just to placate the warnings
   *
   */
  wm() = default;
  /**
   * @brief Construct a new wm object.
   *
   * Constructs all the scenes, too
   *
   * @param context game context
   */
  wm(game* context);
  /**
   * @brief Renders the current scene, icons, and the overlay.
   *
   * Does not render if the current scene is the intro.
   *
   */
  void render();
  /**
   * @brief Handles events and scene switches via task bar
   *
   * @param event Event to be handled.
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  std::pair<scenes, sceneData> handle(SDL_Event& event);
  /**
   * @brief Updates scene data.
   *
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  std::pair<scenes, sceneData> update();
};

#endif