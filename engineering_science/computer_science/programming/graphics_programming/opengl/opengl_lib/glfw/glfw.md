# GLFW

GLFW is an open source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop. It provides a simple API for creating windows, contexts and surfaces, receiving input and events.

GLFW is written in C and supports Windows, macOS, X11 and Wayland.

Demo code [glfw_demo.c](__src__/glfw_demo.c) showing a window:

```c++
#include <GLFW/glfw3.h>

int main(){
    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContentCurrent(window);

    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
```

