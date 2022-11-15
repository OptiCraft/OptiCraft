#include "Application.hpp"

#include <stdexcept>

namespace OptiCraft {
namespace App {

static Window *s_Window;

void init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    throw std::runtime_error("Failed to initialize SDL");
  }
  s_Window = new Window(WindowProps());
}

void run() {
  SDL_Event event;
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }
  }
}

void quit() {
  delete s_Window;
  s_Window = nullptr;
  SDL_Quit();
}

} // namespace App
} // namespace OptiCraft