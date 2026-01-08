#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Size of the window:

int g_windowSizeX = 720;
int g_windowSizeY = 450;

// Change of window size:

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height) {
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

// Key assignment:

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main() {

    // GLFW initialization:

    if (!glfwInit()) {
        std::cout << "GLFW initialisation failed!" << std::endl;
        return -1;
    }

    // GLFW required version:

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window creation:

    GLFWwindow* pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Graphic engine", nullptr, nullptr);

    if (!pWindow) {
        std::cout << "Window creation failed" << std::endl;
        glfwTerminate(); // Freeing all glfw resources.
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback); // Change window size registration.
    glfwSetKeyCallback(pWindow, glfwKeyCallback); // Key assignment registration.
    glfwMakeContextCurrent(pWindow); 

    // GLAD initialization:

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "GLAD initialisation failed!" << std::endl;
        return -1;
    }

    // OpenGL version:

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    // Main Loop:

    while (!glfwWindowShouldClose(pWindow)) {
        // Render:

        glClear(GL_COLOR_BUFFER_BIT);
        
        // Double buffering:

        glfwSwapBuffers(pWindow);
        
        // Poll and process events:

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}