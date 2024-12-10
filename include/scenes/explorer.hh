#if !defined(EXPLORER_HH)
#define EXPLORER_HH

#include <vector>

#include "scene.hh"

class explorer_t : public scene {
 public:
  /**
   * @brief Information of game state
   *
   * Stores what entries are available to the player
   */
  explorerData saveData;

  /**
   * @brief Explorer items to be rendered
   */
  std::vector<std::pair<SDL_Texture*, SDL_Rect>> items;

  /**
   * @brief Background of explorer
   */
  SDL_Texture* background;

  /**
   * @brief Maximum length of the name in texture
   */
  const int nameWrapLength;

  /**
   * @brief Position of the download button
   */
  const SDL_Rect downloadBounds;

  /**
   * @brief Construct a new explorer t object
   *
   * Called only once when WM is initialised
   *
   * @param context game context
   */
  explorer_t(const game* context);

  /**
   * @brief Destroy the explorer t object
   *
   * Called only when the wm is destroyed
   */
  ~explorer_t();

  /**
   * @brief Update logic for the explorer t object
   *
   * Realistically, does absolutely nothing.
   *
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  const std::pair<scenes, sceneData> update() override;

  /**
   * @brief Renders explorer, and files
   */
  void render() override;

  /**
   * @brief Handles mouse movement and file selection
   *
   * @param event Event to be handled
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  const std::pair<scenes, sceneData> handle(const SDL_Event& event) override;

  /**
   * @brief Creates texture to display in filesystem
   *
   * @param text Text to be inserted as name
   * @param size Text to be inserted in size
   * @return SDL_Texture* Texture at size width x 40 to make the text itself
   * more readable
   */
  SDL_Texture* createFilesystemEntry(const char* text, const char* size);
};

#endif