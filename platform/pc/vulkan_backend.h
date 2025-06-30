#pragma once
#include "../graphics_backend.h"
#include <vulkan/vulkan.h>

class VulkanBackend : public GraphicsBackend {
public:
    void initialize() override;
    void render_frame() override;
    
private:
    VkInstance instance;
    VkDevice device;
    VkSwapchainKHR swapchain;
    
    void init_swapchain();
    void create_render_passes();
};