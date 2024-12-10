#if !defined(NOTEPAD_HH)
#define NOTEPAD_HH

#include "../scenes/scene.hh"

class notepad_t : public scene {
 public:
  /**
   * @brief The multiplier by which the text is scaled **down**
   */
  constexpr static double scale = 1.7;

 public:
  /**
   * @brief Background of the notepad as a texture
   */
  SDL_Texture* background;
  /**
   * @brief Text of the notepad, as a texture
   */
  SDL_Texture* entry;
  /**
   * @brief Length before the note wraps the length
   */
  const int lineWrapLength;
  /**
   * @brief The current entry
   */
  notepadData currentData;
  /**
   * @brief The last entry that was there when notepad was exited
   */
  notepadData prevData;
  /**
   * @brief Position of the entry.
   */
  SDL_Rect entryRect;

 public:
  /**
   * @brief Construct a new notepad t object
   *
   * Called only once when WM is initialised
   *
   * @param _context game context
   */
  notepad_t(game* context);
  /**
   * @brief Destroy the notepad t object
   *
   * Called only when the wm is destroyed
   */
  ~notepad_t();
  /**
   * @brief Checks if the current data is the same as the data stored
   * previously.
   *
   * Does nothing if it's the same.
   *
   * @return std::pair<scenes, sceneData>
   */
  std::pair<scenes, sceneData> update() override;
  /**
   * @brief Renders notepad, and entry
   */
  void render() override;
  /**
   * @brief Handles event.
   *
   * Realistically, does nothing unless I add scrolling.
   *
   * @param event Event to be handled
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  std::pair<scenes, sceneData> handle(SDL_Event& event) override;
};

#endif
