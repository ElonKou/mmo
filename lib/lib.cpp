//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File   :lib.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 09 Mar 2019 09:34:28 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "lib.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "std_image.h"

void getImage(char const *filename, GLFWimage &images) {
    // load image for icon.
    int nrChannels;
    unsigned char *pixels =
        stbi_load(filename, &images.width, &images.height, &nrChannels, 0);
    // images.pixels = pixels;
    images.pixels = (unsigned char *)malloc(sizeof(unsigned int) *
                                            images.width * images.height * 4);
    for (int i = 0; i < images.height; i++) {
        for (int j = 0; j < images.width; j++) {
            if (nrChannels == 3) {
                for (int k = 0; k < 3; k++) {
                    images.pixels[(i * images.width + j) * 4 + k] =
                        pixels[(i * images.width + j) * 3 + k];
                }
                images.pixels[(i * images.width + j) * 4 + 3] = 255;
            } else if (nrChannels == 4) {
                for (int k = 0; k < 4; k++) {
                    images.pixels[(i * images.width + j) * 4 + k] =
                        pixels[(i * images.width + j) * 4 + k];
                }
            }
        }
    }
    // for (int i = 0; i < images.height; i++) {
    //     for (int j = 0; j < images.width; j++) {
    //         for (int k = 0; k < 4; k++) {
    //             std::cout
    //                 << int(images.pixels[(i * images.width + j) * 4 +
    //                 k])
    //                 << "-";
    //         }
    //         std::cout << "\t";
    //     }
    //     std::cout << std::endl;
    // }
    // for (int i = 0; i < images.width; i++) {
    //     for (int j = 0; j < images.height; j++) {
    //     }
    // }
    // std::cout << "chanel:" << nrChannels << "-" << images.height << " "
    //           << images.width << std::endl;
}