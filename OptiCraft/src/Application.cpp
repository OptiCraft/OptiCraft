#include "Application.hpp"
#include "ErrorHandling.hpp"

#include <stdexcept>

namespace OptiCraft {
namespace App {

static Window *s_Window;

void init() {
  SDL_Call(SDL_Init(SDL_INIT_EVERYTHING));
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