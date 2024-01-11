
#include "HelloTriangle.h"



void HelloTriangle::mainLoop(GLFWwindow* window, InitHelper* initHelper)
{

  //void* data;
  //int i = 0;
  //VkDeviceSize bufferSize = sizeof(initHelper->vertices[0]) * initHelper->vertices.size();

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    static auto startTime = std::chrono::high_resolution_clock::now();

    auto currentTime = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

    initHelper->x += ((w_flag == true ? time * 0.001f : 0.0f) - (s_flag == true ? time * 0.001f : 0.0f));
    initHelper->y += ((a_flag == true ? time * 0.001f : 0.0f) - (d_flag == true ? time * 0.001f : 0.0f)); 
    initHelper->drawFrame();

    //initHelper-> vertices[0] = {{0.0f, -0.5f}, {1.0f, test, 0.0f}};
    
    // messing around with vert array, copying to local buffer, copying to buffer on gpu
    /*
    for (i = 0; i < 3; i++)
    {
      initHelper -> vertices[i] = {{i == 0 ? x : x + (-1 * (i/2)) + 0.5f , i == 0 ? y - 0.5f : y + 0.5f}, {1.0f, test, 0.0f}};
    }
    */

    /*

    vkMapMemory(initHelper->device, initHelper->stagingBufferMemory, 0, sizeof(initHelper->vertices[0]) * initHelper->vertices.size(), 0, &data);
    memcpy(data, initHelper->vertices.data(), (size_t) sizeof(initHelper->vertices[0]) * initHelper->vertices.size());
    vkUnmapMemory(initHelper->device, initHelper->stagingBufferMemory);
    //drawFrame();
    initHelper->copyBuffer(initHelper->stagingBuffer, initHelper->vertexBuffer, bufferSize);

    */

  }
  initHelper->waitDeviceIdle();
}



void HelloTriangle::run(GLFWwindow* window, InitHelper* initHelper)
{
    mainLoop(window, initHelper);
}

