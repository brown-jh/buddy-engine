#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <set>
#include <iostream>

#include <vector>
#include <cstring>
#include <map>
#include <optional>


class InitHelper
{
  public:
    // structs
    struct QueueFamilyIndices
    {
      std::optional<uint32_t> graphicsFamily;
      std::optional<uint32_t> presentFamily;
      bool isComplete()
      {
        return graphicsFamily.has_value() && presentFamily.has_value();
      }
    };

    //functions
    void initWindow();
    void initVulkan();
    void pickPhysicalDevice();
    void cleanup();
    void getCfg();
    bool checkValidationLayerSupport();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    int isDeviceSuitable(VkPhysicalDevice device);
    std::vector<const char*> getRequiredExtensions();
    void setupDebugMessenger();
    void createLogicalDevice();
    void createSurface();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
      VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
      VkDebugUtilsMessageTypeFlagsEXT messageType,
      const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
      void* pUserData
    );
  
    
    // vars
    GLFWwindow* getWindow();

    const std::vector<const char*> validationLayers =
    {
      "VK_LAYER_KHRONOS_validation"
    };
    
    #ifdef DEBUG_EN
      const bool enableValidationLayers = true;
    #else
      const bool enableValidationLayers = false;
    #endif
    

  private:
    // functions
    void createInstance();

    // vars
    GLFWwindow* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkSurfaceKHR surface;
    VkQueue presentQueue;

};