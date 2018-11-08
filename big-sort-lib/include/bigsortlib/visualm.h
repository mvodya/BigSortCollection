#pragma once
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include "GLFW/glfw3.h"

#define PI 3.14159
#define PALETTE 1785
#define COLORS (PALETTE - PALETTE / 6)
#define RT (COLORS / 6)

struct Color {
  float r, g, b;
};

typedef void (*Function)();

class VisualModule {
 private:
  // Main window
  GLFWwindow* window;
  // Function (with sorting)
  Function function;
  // Function thread
  std::thread* thrFunction;
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

  // Color function
  Color toColor(int& value);
  // Draw color circle
  void drawCircle();

 public:
  VisualModule(std::string title, Function f, int* arr, int size);
  ~VisualModule();
};