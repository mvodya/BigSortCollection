#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include "GLFW/glfw3.h"

#define PI 3.14159

typedef void (*updateTick)();

class VisualModule {
 private:
  // Main window
  GLFWwindow* window;
  // Function for update tick
  updateTick tick;
  // Array
  int* arr_;
  // Array size
  int size_;

  // Error callback for GLFW
  static void error_callback(int error, const char* description);
  // Key events callback from GLFW
  static void key_callback(GLFWwindow* window, int key, int scancode,
                           int action, int mods);
  // Main loop
  void loop();

 public:
  VisualModule(std::string title, updateTick update, int* arr, int size);
  ~VisualModule();
};