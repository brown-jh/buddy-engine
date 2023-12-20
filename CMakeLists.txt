cmake_minimum_required(VERSION 3.10)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

project(buddy_engine VERSION 0.0)

set(PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/")
configure_file("${PROJECT_INCLUDE_DIR}/buddy_engine_config.hpp.in" "buddy_engine_config.hpp")

add_library(buddy_lib
             src/InitHelper.cpp
             src/HelloTriangle.cpp
            )
target_include_directories(buddy_lib PUBLIC "${PROJECT_INCLUDE_DIR}")

add_executable(buddy_engine src/main.cpp)
target_include_directories(buddy_engine PUBLIC
                           "${PROJECT_SOURCE_DIR}/src"
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_INCLUDE_DIR}"
                           )

target_link_libraries(buddy_engine PUBLIC buddy_lib
                       glfw
                       vulkan)

message(PROJECT_INCLUDE_DIR="${PROJECT_INCLUDE_DIR}")



#alt VK_USE_PLATFORM_XCB_KHR VK_USE_PLATFORM_WAYLAND_KHR
target_compile_options(buddy_engine PRIVATE -DDEBUG_EN )