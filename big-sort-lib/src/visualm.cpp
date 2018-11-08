#include "bigsortlib/visualm.h"

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

    // Crawling all items in a circle
    for (int i = 0; i < size_; i++) {
      glLineWidth(2.5);
      float r = 0;
      float g = 0;
      float b = 0;

      if (arr_[i] >= 0) {
        r = 1.0f;
        b = (float)std::clamp(arr_[i], 0, 255) / 255;
        g = 0;
      }
      if (arr_[i] > 255) {
        r = 1.0f - (float)std::clamp(arr_[i] - 255, 0, 255) / 255;
        b = 1.0f;
        g = 0;
      }
      if (arr_[i] > 510) {
        r = 0;
        b = 1.0f;
        g = (float)std::clamp(arr_[i] - 510, 0, 255) / 255;
      }
      if (arr_[i] > 765) {
        r = 0;
        b = 1.0f - (float)std::clamp(arr_[i] - 765, 0, 255) / 255;
        g = 1.0f;
      }
      if (arr_[i] > 1020) {
        r = (float)std::clamp(arr_[i] - 1020, 0, 255) / 255;
        b = 0;
        g = 1.0f;
      }
      if (arr_[i] > 1530) {
        r = 1.0f;
        b = 0;
        g = 1.0f - (float)std::clamp(arr_[i] - 1530, 0, 255) / 255;
      }
      glColor3f(r, g, b);
      // Draw line from center
      glBegin(GL_LINES);
      glVertex3f(0.0f, 0.0f, 0.0f);
      glVertex3f(cos((float)i * PI / (size_ / 2)), sin((float)i * PI / (size_ / 2)), 0.0);
      glEnd();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();

    // Call tick
    tick();
  }
  // If loop end - remove this object
  delete this;
}

VisualModule::VisualModule(std::string title, updateTick update, int* arr, int size) {
  // Write pointer to update tick function
  tick = update;
  // Set array
  arr_= arr;
  // Set size
  size_ = size;
  // Set GLFW error callback
  glfwSetErrorCallback(error_callback);

  // Init GLFW
  if (!glfwInit()) exit(EXIT_FAILURE);

  // Create window
  window = glfwCreateWindow(640, 480, title.c_str(), NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Set GLFW key events callback
  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  // Start main loop
  loop();
}

VisualModule::~VisualModule() {
  // Remove windows
  glfwDestroyWindow(window);
  // Stop GLFW
  glfwTerminate();
}