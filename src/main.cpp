

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

  #ifdef DEBUG_EN
  std::cout << "DEBUG ENABLED\n";
  #endif
  // Initialize window
  initHelper.initWindow();

  initHelper.initVulkan();

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