#pragma once

#define SDL_Call(x)                                                            \
  SDL_ClearError();                                                            \
  if ((x) != 0) throw std::exception(SDL_GetError())