#include "glfwHandlers/WindowHandler.hpp"
#include "glfwHandlers/glfwWrapper.hpp"
#include "DebugHelper.hpp"

#include "glm/common.hpp"
#include "Shader.hpp"

int main()
{
    glfwLibrary::GlfwWrapper glfwWrapper;
    glfwLibrary::WindowHandler windowHandler(800, 600, "Rotating Polygon");
    windowHandler.makeContextCurrent();
    windowHandler.setSwapInterval();

    DebugHelper::enableOpenGLDebugContext();
    
    std::string vertexPath = "../resources/shaders/trianglePos.vert";
    std::string fragPath = "../resources/shaders/triangleColor.frag";

    Shader shader(vertexPath, fragPath);

    while (!windowHandler.shouldClose())
    {
        windowHandler.processInput();

        /* Render here */
        windowHandler.clearWindow();
        shader.use();


        windowHandler.swapBuffers();
        /* Poll for and process events */
        windowHandler.pollEvents();
    }


    return 0;
}