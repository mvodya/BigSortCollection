#include "bigsortlib/visualm.h"

using namespace sortlib;

// Error callback for GLFW
void VisualModule::error_callback(int error, const char* description) {
  printf("Error: %s\n", description);
}

// Key events callback from GLFW
void VisualModule::key_callback(GLFWwindow* window, int key, int scancode,
                                int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

// Main loop
void VisualModule::loop() {
  while (!glfwWindowShouldClose(window)) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw circle
    drawCircle();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  // If loop end - remove this object
  delete this;
}

// Color function
Color VisualModule::toColor(int& value) {
  float r, g, b;
  Color c;

  // Calculate 3 color chanels by simple integer value
  if (value > RT * 6) {
    c.r = 1.0f;
    c.b = 0;
    c.g = 1.0f - (float)std::clamp(value - RT * 6, 0, RT) / RT;
  } else if (value > RT * 4) {
    c.r = (float)std::clamp(value - RT * 4, 0, RT) / RT;
    c.b = 0;
    c.g = 1.0f;
  } else if (value > RT * 3) {
    c.r = 0;
    c.b = 1.0f - (float)std::clamp(value - RT * 3, 0, RT) / RT;
    c.g = 1.0f;
  } else if (value > RT * 2) {
    c.r = 0;
    c.b = 1.0f;
    c.g = (float)std::clamp(value - RT * 2, 0, RT) / RT;
  } else if (value > RT) {
    c.r = 1.0f - (float)std::clamp(value - RT, 0, RT) / RT;
    c.b = 1.0f;
    c.g = 0;
  } else if (value >= 0) {
    c.r = 1.0f;
    c.b = (float)std::clamp(value, 0, RT) / RT;
    c.g = 0;
  }
  return c;
}

// Draw color circle
void VisualModule::drawCircle() {
  // Crawling all items in a circle
  for (int i = 0; i < size_; i++) {
    glLineWidth(2.5);
    // Set color
    Color color = toColor(arr_[i]);
    glColor3f(color.r, color.g, color.b);
    // Draw line from center
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(cos((float)i * PI / (size_ / 2)),
               sin((float)i * PI / (size_ / 2)), 0.0);
    glEnd();
  }
}

VisualModule::VisualModule(std::string title, Function f, int* arr, int size) {
  // Write pointer to function
  function = f;
  // Set array
  arr_ = arr;
  // Set size
  size_ = size;
  // Set GLFW error callback
  glfwSetErrorCallback(error_callback);

  // Init GLFW
  if (!glfwInit()) exit(EXIT_FAILURE);

  // Create window
  window = glfwCreateWindow(640, 640, title.c_str(), NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Set GLFW key events callback
  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  // Start function thread
  thrFunction = new std::thread(function);
  thrFunction->detach();
  // Start main loop
  loop();
}

VisualModule::~VisualModule() {
  // Remove windows
  glfwDestroyWindow(window);
  // Stop GLFW
  glfwTerminate();
}