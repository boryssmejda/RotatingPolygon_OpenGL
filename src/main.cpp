#include "glfwHandlers/WindowHandler.hpp"
#include "glfwHandlers/glfwWrapper.hpp"
#include "DebugHelper.hpp"

#include "glm/common.hpp"
#include "Shader.hpp"
#include "Vertices/VertexArray.hpp"
#include "Vertices/VertexBuffer/VertexBuffer.hpp"
#include "Vertices/VertexBuffer/VertexBufferLayout.hpp"

#include "IndexBuffer.hpp"
#include "Renderer.hpp"

enum Shape
{
    TRIANGLE = 0,
    RECTANGLE = 1
};

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

    /*=================== RENDER TRIANGLE ======================================*/
    float triangle[] = {
        -0.5f, 0.0f,
         0.0f, 0.5f,
         0.5f, 0.0f
    };
  
    VertexArray va[2];
    va[TRIANGLE].bind();
    VertexBuffer vb_triangle(GL_ARRAY_BUFFER, triangle, sizeof(triangle), GL_STATIC_DRAW);
    VertexBufferLayout vertBufTriangularLayout;
    vertBufTriangularLayout.push(2, GL_FLOAT, GL_FALSE);
    va[TRIANGLE].addBuffer(vb_triangle, vertBufTriangularLayout);

    //======= RECTANGLE ====================


    float rectangle[] = {
        -0.5f, -0.25f, 
        -0.5f, -0.75f, 
         0.5f, -0.25f, 
         0.5f, -0.75f
    };

    unsigned int rectangleIndices[] = {
        0, 1, 2,
        1, 2, 3
    };

    va[RECTANGLE].bind();
    VertexBuffer vb_rectangle(GL_ARRAY_BUFFER, rectangle, sizeof(rectangle), GL_STATIC_DRAW);
    VertexBufferLayout vertBufLayout;
    vertBufLayout.push(2, GL_FLOAT, GL_FALSE);

    va[RECTANGLE].addBuffer(vb_rectangle, vertBufLayout);
    IndexBuffer indexBuf(rectangleIndices, sizeof(rectangleIndices) / sizeof(unsigned int), GL_STATIC_DRAW);
    /*==========================================================================*/


    while (!windowHandler.shouldClose())
    {
        windowHandler.processInput();

        /* Render here */
        Renderer::clearScreen();
        va[TRIANGLE].bind();
        shader.use();
        shader.setColor("u_color", { 1.0f, 0.0f, 1.0f, 1.0f });
        Renderer::drawArray(va[0], shader, 3);

        va[RECTANGLE].bind();
        shader.setColor("u_color", { 0.0f, 0.0f, 1.0f, 1.0f });
        Renderer::drawElements(va[1], shader, indexBuf);

        windowHandler.swapBuffers();
        /* Poll for and process events */
        windowHandler.pollEvents();
    }


    return 0;
}