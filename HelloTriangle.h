#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class HelloTriangle
{
    public:
        void run(GLFWwindow* window);

    private:
        void mainLoop(GLFWwindow* window);

};