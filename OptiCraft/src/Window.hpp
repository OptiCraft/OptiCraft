#pragma once

#include <SDL.h>

#include <string>

namespace OptiCraft {
struct WindowProps {
  std::string title;
  uint16_t width;
  uint16_t height;

  WindowProps(const std::string title = "OptiCraft", uint16_t width = 800,
              uint16_t height = 600)
      : title(std::move(title)), width(width), height(height) {}
};

class Window {
public:
  Window(const WindowProps &props);
  ~Window();

  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;

  inline uint16_t getWidth() const { return m_Props.width; }
  inline uint16_t getHeight() const { return m_Props.height; }

private:
  WindowProps m_Props;
  SDL_Window *m_Window;
};
} // namespace OptiCraft