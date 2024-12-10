#if !defined(SHITCORD_HH)
#define SHITCORD_HH

#include "scene.hh"

class shitcord_t : public scene {
 public:
  /**
   * @brief Construct a new shitcord t object
   *
   * Called only once when WM is initialised
   *
   * @param context game context
   */
  shitcord_t(game* context);

  /**
   * @brief Destroy the shitcord t object
   *
   * Called only when the wm is destroyed
   */
  ~shitcord_t();

  /**
   * @brief Update logic for shitcord
   *
   * Probably does the message appearing
   *
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  std::pair<scenes, sceneData> update() override;

  /**
   * @brief Renders menu, and messages
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
