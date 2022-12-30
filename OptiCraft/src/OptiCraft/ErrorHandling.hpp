#pragma once

namespace OptiCraft {
class Exception : public std::exception {
public:
  Exception(const char *file, uint32_t line, const char *origin,
            const char *message = "No message provided");

  char const *what() const override;

  inline const char *getFile() const { return m_File.c_str(); }
  inline uint32_t getLine() const { return m_Line; }
  inline const char *getOrigin() const { return m_Origin.c_str(); }
  inline const char *getMessage() const { return m_Message.c_str(); }

private:
  std::string m_File;
  uint32_t m_Line;
  std::string m_Origin;
  std::string m_Message;

protected:
  mutable std::string m_WhatBuffer;
};

bool oc_assert(bool condition, const char *message = "No message provided",
               const char *file = OC_FILE, uint32_t line = OC_LINE);

} // namespace OptiCraft

#define SDL_Call(x)                                                            \
  SDL_ClearError();                                                            \
  if ((x) != 0) throw std::exception(SDL_GetError())

#define OC_THROW(...)                                                          \
  throw ::OptiCraft::Exception(OC_FILE, OC_LINE, __VA_ARGS__)

#define OC_ASSERT(...)                                                         \
  if (!::OptiCraft::oc_assert(__VA_ARGS__)) __debugbreak()