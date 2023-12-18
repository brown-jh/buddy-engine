

#include "InitHelper.h"


void InitHelper::initWindow()
{
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(800, 600, "Vulkan", NULL, NULL);

}

void InitHelper::initVulkan()
{
    createInstance();
}

GLFWwindow* InitHelper::getWindow()
{
    return window;
}

void InitHelper::cleanup()
{
    vkDestroyInstance(instance, NULL);
    glfwDestroyWindow(window);

    glfwTerminate();

}

void InitHelper::createInstance()
{
    std::cout << "Instantiating Vulkan instance\n";
    // Application information structure
    // BOZO: mostly temporary info atm
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Application Name";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Instance info
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    // BOZO NULL callback
    if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create instance!");
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

    std::vector<VkExtensionProperties> extensions(extensionCount);

    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, extensions.data());

    std::cout << "available extensions:\n";

    for (const auto& extension : extensions)
    {
        std::cout << '\t' << extension.extensionName << '\n';
    }

    // BOZO Add function to check that extensions required (glfwGetRequiredInstanceExtensions)
    // are present in the support extensions list

    std::cout << "Instance created\n";
}