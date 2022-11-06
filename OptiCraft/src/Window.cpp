#include "Window.hpp"

namespace OptiCraft {
Window::Window(const WindowProps &props) : m_Props(props) {
  m_Window = SDL_CreateWindow(m_Props.title.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, m_Props.width,
                              m_Props.height, SDL_WINDOW_VULKAN);
}

Window::~Window() {
  SDL_DestroyWindow(m_Window);
  m_Window = nullptr;
}
} // namespace OptiCraft