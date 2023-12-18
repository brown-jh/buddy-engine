cmake_minimum_required(VERSION 3.10)

project(buddy_engine)

add_executable(buddy_engine main.cpp
                InitHelper.cpp
                HelloTriangle.cpp)



target_link_libraries(buddy_engine glfw)
target_link_libraries(buddy_engine vulkan)