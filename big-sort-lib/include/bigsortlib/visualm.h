#pragma once
#include <algorithm>
#include <iostream>
#include <thread>
#include <string>
#include "GLFW/glfw3.h"

#define PI 3.14159
#define PALETTE 1785
#define COLORS (PALETTE - PALETTE / 6)
#define RT (COLORS / 6)

struct Color {
  float r, g, b;
};

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

  // Color function
  Color toColor(int& value);
  // Draw color circle
  void drawCircle();

 public:
  VisualModule(std::string title, updateTick update, int* arr, int size);
  ~VisualModule();
};