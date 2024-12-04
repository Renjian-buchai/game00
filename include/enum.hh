#if !defined(ENUM_HH)
#define ENUM_HH

#include <cstdint>

enum class notepadData : uint8_t {
  empty,
  entry1 = 1,
  entry2 = 2,
};

enum class scenes : uint8_t {
  intro,
  explorer,
  notepad,
  pause,
};

enum class explorerData : uint8_t {
  init,
  entry1,
  entry2,
  size,
};

using sceneData = std::variant<std::monostate, notepadData>;

#endif
