

#include "InitHelper.h"
#include "HelloTriangle.h"



void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}



int main()
{
  InitHelper initHelper;
  HelloTriangle helloTriangle;


  // Initialize window
  initHelper.initWindow();

  initHelper.initVulkan();

  glm::mat4 matrix;
  glm::vec4 vec;
  auto test = matrix * vec;


  try
  {
    helloTriangle.run(initHelper.getWindow());
  } catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  initHelper.cleanup();


  return 0;

}