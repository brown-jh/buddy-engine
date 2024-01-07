
#include "HelloTriangle.h"


void HelloTriangle::mainLoop(GLFWwindow* window, InitHelper* initHelper)
{

  void* data;

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    initHelper->drawFrame();
    initHelper-> vertices[0] = {{0.0f, -0.5f}, {1.0f, test, 0.0f}};


    vkMapMemory(initHelper->device, initHelper->vertexBufferMemory, 0, sizeof(initHelper->vertices[0]) * initHelper->vertices.size(), 0, &data);
    memcpy(data, initHelper->vertices.data(), (size_t) sizeof(initHelper->vertices[0]) * initHelper->vertices.size());
    vkUnmapMemory(initHelper->device, initHelper->vertexBufferMemory);
    //drawFrame();
  }
  initHelper->waitDeviceIdle();
}



void HelloTriangle::run(GLFWwindow* window, InitHelper* initHelper)
{
    mainLoop(window, initHelper);
}

