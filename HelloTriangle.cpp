#include "HelloTriangle.h"


void HelloTriangle::mainLoop(GLFWwindow* window)
{
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
  }
}

void HelloTriangle::run(GLFWwindow* window)
{
    mainLoop(window);
}

