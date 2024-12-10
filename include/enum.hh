#if !defined(ENUM_HH)
#define ENUM_HH

#include <cstdint>
#include <variant>

/**
 * @brief Entry currently stored in notepad.
 *
 * Enumerated continuously and in order to make file name queries convenient
 */
enum class notepadData : uint8_t {
  empty,
  entry1 = 1,
  entry2 = 2,
};
/**
 * @brief Entries list
 */
enum class explorerData : uint8_t {
  init,
  entry1,
  entry2,
  size,
};

/**
 * @brief Scenes list
 */
enum class scenes : uint8_t {
  intro,
  explorer,
  notepad,
  pause,
  shitcord,
};

using sceneData = std::variant<std::monostate, notepadData>;

#endif
