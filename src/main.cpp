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
#include "Texture.hpp"
#include "stb_image.h"
#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

enum Shape
{
    TRIANGLE = 0,
    RECTANGLE = 1
};

int main()
{
    glfwLibrary::GlfwWrapper glfwWrapper;
    glfwLibrary::WindowHandler windowHandler(1200, 800, "Rotating Polygon");
    windowHandler.makeContextCurrent();
    windowHandler.setSwapInterval();

    DebugHelper::enableOpenGLDebugContext();
    
    std::string vertexPath = "../resources/shaders/trianglePos.vert";
    std::string fragPath = "../resources/shaders/triangleColor.frag";

    Shader shader(vertexPath, fragPath);

    /*===================  TRIANGLE ======================================*/
    float triangle[] = {
        -0.5f, 0.0f,    0.0f, 0.0f,
         0.0f, 0.6f,    0.5f, 1.0f,
         0.5f, 0.0f,    1.0f, 0.0f
    };
    
    VertexArray triangle_va;
    triangle_va.bind();
    VertexBuffer vb_triangle(GL_ARRAY_BUFFER, triangle, sizeof(triangle), GL_STATIC_DRAW);
    VertexBufferLayout vertBufTriangularLayout;
    vertBufTriangularLayout.push(2, GL_FLOAT, GL_FALSE);
    vertBufTriangularLayout.push(2, GL_FLOAT, GL_FALSE);
    
    triangle_va.addBuffer(vb_triangle, vertBufTriangularLayout);
    Texture iluminatiLogo("../resources/textures/iluminatiLogo.png", Texture::FILE_TYPE::PNG);

    //======================= RECTANGLE ====================
    float vertices[] = {
        // positions        // texture coords
         0.25f,  0.0f,     1.0f, 1.0f, // top right
         0.25f,  -0.3f,     1.0f, 0.0f, // bottom right
        -0.25f,  -0.3f,     0.0f, 0.0f, // bottom left
        -0.25f,  0.0f,     0.0f, 1.0f  // top left 
    };

    unsigned int rectangleIndices[] = {
        0, 1, 3,
        1, 2, 3
    };

    VertexArray va_rectangle;
    va_rectangle.bind();
    VertexBuffer vb_rectangle(GL_ARRAY_BUFFER, vertices, sizeof(vertices), GL_STATIC_DRAW);
    VertexBufferLayout vertBufLayout;
    vertBufLayout.push(2, GL_FLOAT, GL_FALSE);
    vertBufLayout.push(2, GL_FLOAT, GL_FALSE);
    
    va_rectangle.addBuffer(vb_rectangle, vertBufLayout);
    IndexBuffer indexBuf(rectangleIndices, sizeof(rectangleIndices) / sizeof(unsigned int), GL_STATIC_DRAW);
    Texture containerTexture("../resources/textures/oneDollar.jpg", Texture::FILE_TYPE::JPG);
    /*==========================================================================*/

    while (!windowHandler.shouldClose())
    {
        windowHandler.processInput();

        /* Render here */
        Renderer::clearScreen();
   
        containerTexture.bind(0);

        glm::mat4 transRectangle = glm::mat4(1.0f);
        transRectangle = glm::translate(transRectangle, glm::vec3(0.7f, -0.5f, 0.0f));

        shader.setMat4f("transform", transRectangle);
        Renderer::drawElements(va_rectangle, shader, indexBuf);

        iluminatiLogo.bind(0);
        glm::mat4 transTriangle = glm::mat4(1.0f);
        transTriangle = glm::translate(transTriangle, glm::vec3(0.0f, 0.15f, 0.0f));
        transTriangle = glm::rotate(transTriangle, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        transTriangle = glm::translate(transTriangle, glm::vec3(0.0f, -0.15f, 0.0f));
        transTriangle = glm::scale(transTriangle, glm::vec3(0.5f, 0.5f, 0.5f));
        shader.setMat4f("transform", transTriangle);
        Renderer::drawArray(triangle_va, shader, 3);

        windowHandler.swapBuffers();
        /* Poll for and process events */
        windowHandler.pollEvents();
    }


    return 0;
}