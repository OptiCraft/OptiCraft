#include "Application.hpp"

int main(int argc, char *argv[]) {
  try {
    OptiCraft::App::init();
    OptiCraft::App::run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  OptiCraft::App::quit();

  return EXIT_SUCCESS;
}