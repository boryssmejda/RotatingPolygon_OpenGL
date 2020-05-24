cmake_minimum_required(VERSION 3.17)
project(RotatingPolygon)

    set(SOURCES
    
        src/glfwHandlers/WindowHandler.cpp
        src/glfwHandlers/glfwWrapper.cpp
        
        src/DebugHelper.cpp
        src/Shader.cpp
        
        src/Vertices/VertexArray.cpp
        src/Vertices/VertexBuffer/VertexBuffer.cpp
        
        src/Vertices/VertexBuffer/VertexBufferLayout.cpp
        src/IndexBuffer.cpp
        
        src/Renderer.cpp
        src/Texture.cpp
        
        src/main.cpp
    )
    
    set(HEADERS
    
        src/glfwHandlers/WindowHandler.hpp
        src/glfwHandlers/glfwWrapper.hpp
        
        src/DebugHelper.hpp
        src/Shader.hpp
        
        src/Vertices/VertexArray.hpp
        src/Vertices/VertexBuffer/VertexBuffer.hpp
        
        src/Vertices/VertexBuffer/VertexBufferLayout.hpp
        src/IndexBuffer.hpp
        
        src/Renderer.hpp
        src/Texture.hpp
    )
    
    set(EXTERNAL_LIBRARIES
        libs/stb_image.h
        libs/stb_image.c
    )
    
    add_executable(RotatingPolygon ${SOURCES} ${HEADERS} ${EXTERNAL_LIBRARIES})
    
    target_include_directories(RotatingPolygon PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/>
    )
    
    set_target_properties(RotatingPolygon PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
    )
    
    if (MSVC)
        set(GLEW_USE_STATIC_LIBS 1)
    endif (MSVC)
    
    find_package(GLEW REQUIRED)
    find_package(glfw3 CONFIG REQUIRED)
    find_package(OpenGL REQUIRED)
    
    target_compile_definitions(RotatingPolygon PRIVATE GLEW_STATIC)
    
    target_link_libraries(RotatingPolygon
        PRIVATE
        glfw
        OpenGL::GL
        GLEW::GLEW
    )