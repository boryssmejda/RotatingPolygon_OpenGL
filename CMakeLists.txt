cmake_minimum_required(VERSION 3.17)
project(RotatingPolygon)

    set(SOURCES
    
        src/WindowHandler.cpp
        src/main.cpp
    )
    
    set(HEADERS
    
        src/WindowHandler.hpp
    )
    
    add_executable(RotatingPolygon ${SOURCES} ${HEADERS})
    set_target_properties(RotatingPolygon PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
    )
    
    
    find_package(GLEW REQUIRED)
    find_package(glfw3 CONFIG REQUIRED)
    find_package(OpenGL REQUIRED)
    
    target_link_libraries(RotatingPolygon
        PRIVATE
        glfw    #rozwaz zmiane na glfw3
        OpenGL::GL
		GLEW::GLEW
    )
    
    #if(MSVC)
    #    set(GLEW_USE_STATIC_LIBS 1)
    #endif()
    
    #target_compile_definitions(RotatingPolygon PRIVATE GLEW_STATIC)