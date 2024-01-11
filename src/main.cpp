
#include "HelloTriangle.h"
#include "buddy_engine_config.hpp"

InitHelper initHelper;
HelloTriangle helloTriangle;


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && (action == GLFW_PRESS ))
    {
      helloTriangle.w_flag = true;
    }
    else if (key == GLFW_KEY_W && (action == GLFW_RELEASE))
    {
      helloTriangle.w_flag = false;
    }

    if (key == GLFW_KEY_S && (action == GLFW_PRESS ))
    {
      helloTriangle.s_flag = true;
    }
    else if (key == GLFW_KEY_S && (action == GLFW_RELEASE))
    {
      helloTriangle.s_flag = false;
    }

    if (key == GLFW_KEY_A && (action == GLFW_PRESS ))
    {
      helloTriangle.a_flag = true;
    }
    else if (key == GLFW_KEY_A && (action == GLFW_RELEASE))
    {
      helloTriangle.a_flag = false;
    }


    if (key == GLFW_KEY_D && (action == GLFW_PRESS ))
    {
      helloTriangle.d_flag = true;
    }
    else if (key == GLFW_KEY_D && (action == GLFW_RELEASE))
    {
      helloTriangle.d_flag = false;
    }

}

int main(int argc, char *argv[])
{
  std::cout << "Loading " << argv[0] << " VERSION " << 
    buddy_engine_VERSION_MAJOR << "." <<buddy_engine_VERSION_MINOR << std::endl;



  #ifdef DEBUG_EN
  std::cout << "DEBUG ENABLED\n";
  #endif
  // Initialize window
  initHelper.initWindow();

  initHelper.initVulkan();

  glfwSetKeyCallback(initHelper.getWindow(), key_callback);


  try
  {
    helloTriangle.run(initHelper.getWindow(), &initHelper);
  } catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  initHelper.cleanup();


  return 0;

}