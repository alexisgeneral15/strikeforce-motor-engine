#include "vulkan_backend.h"

#define VK_CHECK(call) \
    if (auto result = call; result != VK_SUCCESS) { \
        throw VulkanException(result, __FILE__, __LINE__); \
    }

void VulkanBackend::init_swapchain() {
    VkSwapchainCreateInfoKHR createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    createInfo.surface = surface;
    createInfo.minImageCount = image_count;
    
    VK_CHECK(vkCreateSwapchainKHR(device, &createInfo, nullptr, &swapchain));
}