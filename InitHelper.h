#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

#include <vector>



class InitHelper
{
  public:
    //functions
    void initWindow();
    void initVulkan();
    void cleanup();
    
    // vars
    GLFWwindow* getWindow();

  private:
    // functions
    void createInstance();

    // vars
    GLFWwindow* window;
    VkInstance instance;
};