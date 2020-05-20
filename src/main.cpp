#include "glfwHandlers/WindowHandler.hpp"
#include "glfwHandlers/glfwWrapper.hpp"
#include <iostream>


int main()
{
    glfwLibrary::GlfwWrapper glfwWrapper;
    glfwLibrary::WindowHandler windowHandler(Width{ 800 }, Height{ 600 }, Title{ "Rotating Polygon" });
    windowHandler.makeContextCurrent();
    windowHandler.setSwapInterval();

    
    if (glewInit() != GLEW_OK)
        std::cout << "Error creating GLEW\n";

    while (!windowHandler.shouldClose())
    {
        windowHandler.processInput();

        /* Render here */
        windowHandler.clearWindow();


        windowHandler.swapBuffers();
        /* Poll for and process events */
        windowHandler.pollEvents();
    }


    return 0;
}