cmake_minimum_required(VERSION 3.17)
project(RotatingPolygon)

    set(SOURCES
    
        src/glfwHandlers/WindowHandler.cpp
        src/glfwHandlers/glfwWrapper.cpp
        
        src/DebugHelper.cpp
        
        src/main.cpp
    )
    
    set(HEADERS
    
        src/glfwHandlers/WindowHandler.hpp
        src/glfwHandlers/glfwWrapper.hpp
        
        src/DebugHelper.hpp
    )
    
    add_executable(RotatingPolygon ${SOURCES} ${HEADERS})
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