cmake_minimum_required (VERSION 3.0)
project (glfw-demo)
find_package(OpenGL REQUIRED)

add_subdirectory(glfw)

add_executable(glfw_demo glfw_demo.c)
target_link_libraries(glfw_demo ${OPENGL_LIBRARY} glfw)
