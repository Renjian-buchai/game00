#if !defined(PAUSE_HH)
#define PAUSE_HH

#include "UI/button.hh"
#include "scene.hh"

class pause_t : public scene {
 public:
  /**
   * @brief Pause overlay
   */
  SDL_Texture* overlay;

  /**
   * @brief Resume button
   */
  button resume;

  /**
   * @brief Exit button
   */
  button exit;

  /**
   * @brief Construct a new pause t object
   *
   * Called only once when WM is initialised
   *
   * @param context game context
   */
  pause_t(game* context);
  /**
   * @brief Destroy the pause t object
   *
   * Called only when the wm is destroyed
   */
  ~pause_t();
  /**
   * @brief Update logic for the pause menu
   *
   * Realistically, does absolutely nothing.
   *
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  std::pair<scenes, sceneData> update() override;
  /**
   * @brief Renders menu, and buttons
   */
  void render() override;
  /**
   * @brief Handles hovers
   *
   * @param event Event to be handled
   * @return std::pair<scenes, sceneData>Returns the scene to be changed to,
   * and the data that scene should contain
   */
  std::pair<scenes, sceneData> handle(SDL_Event& event) override;
};
#endif
