#pragma once
#include <iostream>
#include <string>
#include "GLFW/glfw3.h"

typedef void (*updateTick)();

class VisualModule {
 private:
  // Main window
  GLFWwindow* window;
  // Function for update tick
  updateTick tick;

  // Error callback for GLFW
  static void error_callback(int error, const char* description);
  // Key events callback from GLFW
  static void key_callback(GLFWwindow* window, int key, int scancode,
                           int action, int mods);
  // Main loop
  void loop();

 public:
  VisualModule(std::string title, updateTick update);
  ~VisualModule();
};