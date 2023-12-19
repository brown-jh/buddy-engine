cmake_minimum_required(VERSION 3.10)

project(buddy_engine)

add_library(buddy_lib
             src/InitHelper.cpp
             src/HelloTriangle.cpp
            )

add_executable(buddy_engine src/main.cpp)


target_link_libraries(buddy_engine PUBLIC buddy_lib
                       glfw
                       vulkan)

#message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")

target_include_directories(buddy_engine PUBLIC
                           "${PROJECT_SOURCE_DIR}/src"
                           )
#alt VK_USE_PLATFORM_XCB_KHR VK_USE_PLATFORM_WAYLAND_KHR
target_compile_options(buddy_engine PRIVATE -DDEBUG_EN )                           