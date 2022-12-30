#include "ErrorHandling.hpp"

OptiCraft::Exception::Exception(const char *file, uint32_t line,
                                const char *origin, const char *message)
    : m_File(file), m_Line(line), m_Origin(origin), m_Message(message) {}

char const *OptiCraft::Exception::what() const {
  std::ostringstream oss;
  oss << "[File] " << m_File << std::endl
      << "[Line] " << m_Line << std::endl
      << "[Origin] " << m_Origin << std::endl
      << "[Message] " << m_Message;
  m_WhatBuffer = oss.str();
  return m_WhatBuffer.c_str();
}

bool OptiCraft::oc_assert(bool condition,
                          const char *message /*= "No message provided"*/,
                          const char *file /*= OC_FILE*/,
                          uint32_t line /*= OC_LINE*/) {
  if (condition) return true;

#ifdef OC_DEBUG

  std::ostringstream oss;
  oss << "Assertion failed!"
      << "\n"
      << "[Line] " << line << "\n"
      << "[File] " << file << "\n"
      << "[Message] " << message;
  std::string formattedMessage = oss.str();

  SDL_MessageBoxData data = {0};
  data.flags = SDL_MESSAGEBOX_ERROR;
  data.window = nullptr;
  data.title = "Assertion Failed";
  data.message = formattedMessage.c_str();
  data.numbuttons = 2;
  SDL_MessageBoxButtonData buttons[2] = {
      {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "Ignore"},
      {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Break"}};
  data.buttons = buttons;
  data.colorScheme = nullptr;
  int32_t buttonPressed = -1;
  SDL_ShowMessageBox(&data, &buttonPressed);

  if (buttonPressed == 1) return false;

#endif

  OC_THROW("Assert failure", message);
}
