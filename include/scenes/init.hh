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
    slide(size_t _fadeIn, size_t _fadeOut, size_t _duration,
          SDL_Texture* _texture, SDL_Rect _dest = {}, bool skippable = true);

    size_t fadeIn;
    size_t duration;
    size_t fadeOut;
    SDL_Texture* texture;
    SDL_Rect dest;
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
  intro_t(game* context);
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
  std::pair<scenes, sceneData> update() override;
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
  std::pair<scenes, sceneData> handle(const SDL_Event& event) override;

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
