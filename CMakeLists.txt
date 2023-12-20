cmake_minimum_required(VERSION 3.10)

project(buddy_engine VERSION 0.0)

add_library(buddy_lib
             src/InitHelper.cpp
             src/HelloTriangle.cpp
            )

add_executable(buddy_engine src/main.cpp)

set(PROJECT_INCLUDE_DIR include/)

configure_file(${PROJECT_INCLUDE_DIR}/buddy_engine_config.hpp.in buddy_engine_config.hpp)

target_link_libraries(buddy_engine PUBLIC buddy_lib
                       glfw
                       vulkan)


target_include_directories(buddy_engine PUBLIC
                           "${PROJECT_SOURCE_DIR}/src"
                           )
#alt VK_USE_PLATFORM_XCB_KHR VK_USE_PLATFORM_WAYLAND_KHR
target_compile_options(buddy_engine PRIVATE -DDEBUG_EN )