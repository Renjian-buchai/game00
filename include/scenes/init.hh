#if !defined(INIT_HH)
#define INIT_HH

#include "scene.hh"

class intro_t : public scene {
 public:
  enum class centre : uint8_t { HORIZONTAL, VERTICAL, BOTH };

  /**
   * @brief Contains all the information required for a functional slideshow.
   */
  class slide {
   public:
    /**
     * @brief Construct a new slide
     *
     * @param fadeIn Time taken for fade in (ms)
     * @param fadeOut Time taken for fade out (ms)
     * @param duration Duration that slide spends at full alpha (ms)
     * @param texture Texture containing slide contents
     * @param dest Location that the slide should be rendered. Default = empty;
     * empty => full screen
     * @param skippable Whether a slide can be skipped. Default = true
     */
    slide(const size_t fadeIn, const size_t fadeOut, const size_t duration,
          SDL_Texture* texture, const SDL_Rect dest = {},
          const bool skippable = true);

    /**
     * @brief Time taken for fade in
     */
    size_t fadeIn;

    /**
     * @brief Duration slide spends at full alpha
     */
    size_t duration;

    /**
     * @brief Time taken for fade out
     */
    size_t fadeOut;

    /**
     * @brief Texture containing slide contents
     */
    SDL_Texture* texture;

    /**
     * @brief Destination that the slide should be rendered
     */
    SDL_Rect dest;

    /**
     * @brief Whether a slide can be skipped
     */
    bool skippable;
  };

  /**
   * @brief Slides to be slideshowed
   */
  std::vector<slide> slides;

  /**
   * @brief The time at which each slide starts
   */
  size_t startTime;

  /**
   * @brief Whether a skip is requested by the event handler
   */
  bool skip;

  /**
   * @brief Construct a new intro t object
   *
   * Called only once when WM is initialised
   *
   * @param context Game context
   */
  intro_t(const game* context);

  /**
   * @brief Destroy the intro t object
   */
  ~intro_t();

  /**
   * @brief Updates scene info.
   *
   * Makes the call on when to move on to explorer.
   *
   * When it moves on, it calls its own destructor to minimise its size and
   * effect on memory usage.
   *
   * @return std::pair<scenes, sceneData> Returns the scene to be changed to,
   * and the data that scene should contain
   */
  const std::pair<scenes, sceneData> update() override;

  /**
   * @brief Renders slides
   */
  void render() override;

  /**
   * @brief
   *
   * @param event
   * @return std::pair<scenes, sceneData>
   */
  const std::pair<scenes, sceneData> handle(const SDL_Event& event) override;

  /**
   * @brief Performs the slideshow logic.
   *
   * @param time Current time
   * @param click Whether a click happened in the past n seconds
   * @param skipGrace Grace period for skipping. Default: 500
   */
  void slideShow(size_t time, bool& click, size_t skipGrace = 500);

  /**
   * @brief Adds slides to slideshow.
   *
   * @param surface Surface to be converted into a slideshow. Will be converted
   * into a texture, then freed.
   * @param fadeIn Fade in duration
   * @param duration Full brightness duration
   * @param fadeOut Fade out duration
   * @param dest Destination for where to render the slide
   * @param centred Whether the slide is centred.
   * @param skippable Whether it is permissible to skip the slide
   */
  void addSlide(SDL_Surface* surface, size_t fadeIn, size_t duration,
                size_t fadeOut, SDL_Rect dest = SDL_Rect{}, bool centred = true,
                bool skippable = true);

  /**
   * @brief Centres rect
   *
   * @param rect Rect to centre
   * @param centre Stores how the rect will be centred
   */
  void centreRect(SDL_Rect& rect, centre centre = centre::BOTH) const;
};

#endif
