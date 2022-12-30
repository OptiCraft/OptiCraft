#include "Application.hpp"

int main(int argc, char *argv[]) {
  try {
    OptiCraft::App::init();
    OptiCraft::App::run();
  } catch (const std::exception &e) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Exception caught", e.what(),
                             nullptr);
  }
  OptiCraft::App::quit();

  return EXIT_SUCCESS;
}