#if !defined(SCENE_HH)
#define SCENE_HH

#include "../../include/pch.hh"
#include "../enum.hh"

#define pix(val) static_cast<int>(val * context->pixelSize)

class game;

/**
 * @brief Interface class for scenes
 */
class scene {
 public:
  /**
   * @brief Loads texture based on path
   *
   * @param path File path
   * @return SDL_Texture* Loaded texture
   */
  SDL_Texture* loadTexture(const char* path);

  /**
   * @brief Game context
   */
  game* context;

  /**
   * @brief Construct a new scene object
   *
   * @param gameContext game context
   */
  scene(game* gameContext);

  /**
   * @brief Destroy the scene object
   *
   * Usually called only when wm is destroyed
   */
  virtual ~scene();

  /**
   * @brief Updates scene logic
   *
   * Called in wm::update()
   *
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  virtual std::pair<scenes, sceneData> update() = 0;

  /**
   * @brief Renders textures
   *
   * Called in wm::render()
   */
  virtual void render() = 0;

  /**
   * @brief Handles events
   *
   * Called in wm::handle()
   *
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  virtual std::pair<scenes, sceneData> handle(SDL_Event&) = 0;
};

#endif