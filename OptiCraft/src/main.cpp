#include "Application.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {
  OptiCraft::App::init();
  try {
    OptiCraft::App::run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  OptiCraft::App::quit();

  return EXIT_SUCCESS;
}