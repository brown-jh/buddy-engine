#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <set>
#include <iostream>
#include <chrono>
#include <array>
#include <vector>
#include <cstring>
#include <map>
#include <optional>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <fstream>
#include <iostream>


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

    struct SwapChainSupportDetails
    {
      VkSurfaceCapabilitiesKHR capabilities;
      std::vector<VkSurfaceFormatKHR> formats;
      std::vector<VkPresentModeKHR> presentModes;
    };

    struct Vertex
    {
      glm::vec2 pos;
      glm::vec3 color;

      static VkVertexInputBindingDescription getBindingDescription()
      {
        VkVertexInputBindingDescription bindingDescription{};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
      }  

      static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions()
      {
        std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};
        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescriptions[0].offset = offsetof(Vertex, pos);

        attributeDescriptions[1].binding = 0;
        attributeDescriptions[1].location = 1;
        attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[1].offset = offsetof(Vertex, color);

        return attributeDescriptions;
      }
  
    };

    struct UniformBufferObject
    {
      glm::mat4 model;
      glm::mat4 view;
      glm::mat4 proj;
    };

    //functions
    void initWindow();
    void initVulkan();
    void pickPhysicalDevice();
    void cleanup();
    void getCfg();
    void createSwapChain();
    bool checkValidationLayerSupport();
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    int isDeviceSuitable(VkPhysicalDevice device);
    VkShaderModule createShaderModule(const std::vector<char>& code);
    std::vector<const char*> getRequiredExtensions();
    void setupDebugMessenger();
    void createLogicalDevice();
    void createSurface();
    void createImageViews();
    void createGraphicsPipeline();
    void createRenderPass();
    void createCommandPool();
    void createVertexBuffer();
    void createCommandBuffers();
    void createFramebuffers();
    void createDescriptorPool();
    void createIndexBuffer();
    void createSyncObjects();
    void createDescriptorSetLayout();
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void drawFrame();
    void createDescriptorSets();
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void waitDeviceIdle();
    void recreateSwapChain();
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    void cleanupSwapChain();
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    static std::vector<char> readFile(const std::string& filename);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    void createUniformBuffers();
    void updateUniformBuffer(uint32_t currentImage);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
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
    // here for now, should prob be private
    VkDevice device;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer vertexBuffer;

    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;
    


    // THE TRIANGLE (from earlier, now no longer part of the shader file)
    /*
    std::vector<Vertex> vertices =
    {
      {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
      {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
      {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
      {{-1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}},
      {{1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},
      {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}}
    };
    */
   std::vector<Vertex> vertices =
   {
    {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
   };

   const std::vector<uint16_t> indices = 
   {
    0, 1, 2, 2, 3, 0
   };

    GLFWwindow* getWindow();

    const std::vector<const char*> validationLayers =
    {
      "VK_LAYER_KHRONOS_validation"
    };

    const std::vector<const char*> deviceExtensions =
    {
      VK_KHR_SWAPCHAIN_EXTENSION_NAME
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
    const int MAX_FRAMES_IN_FLIGHT = 2;
    const int WIDTH = 800;
    const int HEIGHT = 600;
    uint32_t currentFrame = 0;
    GLFWwindow* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkQueue graphicsQueue;
    VkSurfaceKHR surface;
    VkQueue presentQueue;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipeline graphicsPipeline;
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
  


    bool framebufferResized = false;
  


};