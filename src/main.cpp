#include "InitHelper.h"
#include "HelloTriangle.h"
#include "buddy_engine_config.hpp"


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}



int main(int argc, char *argv[])
{
  std::cout << "Loading " << argv[0] << " VERSION " << 
    buddy_engine_VERSION_MAJOR << "." <<buddy_engine_VERSION_MINOR << std::endl;

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