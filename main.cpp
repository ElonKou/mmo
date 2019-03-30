//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File   :main.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 09 Mar 2019 09:28:22 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
// #include <GL/glew.h>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
#include "GLFW/glfw3.h"

using namespace std;

int main(void) {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit()) return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
