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

    glfwSwapBuffers(window);
    glfwPollEvents();
    tick();
  }
  delete this;
}

VisualModule::VisualModule(std::string title, updateTick update) {
  // Write pointer to update tick function
  tick = update;
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