//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File   :main.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 09 Mar 2019 09:28:22 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "imgui.h"
#include "lib.h"

using namespace std;

int main(void) {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    };

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "mmo", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwSetWindowPos(window, 480, 270);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    const char *filename = "./assert/icon/mmo.jpg";
    GLFWimage images;
    getImage(filename, images);
    glfwSetWindowIcon(window, 1, &images);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
