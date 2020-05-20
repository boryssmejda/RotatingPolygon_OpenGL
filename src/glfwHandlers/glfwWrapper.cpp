#include "glfwWrapper.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

void glfwLibrary::GlfwWrapper::errorCallback(int error, const char* description)
{
	std::cerr << "Error: " << description;
}

glfwLibrary::GlfwWrapper::GlfwWrapper()
{
	/* Initialize the library */
	if (!glfwInit())
		throw std::runtime_error("Could not init GLFW!");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		std::cout << "We are on MacOS\n";
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	glfwSetErrorCallback(errorCallback);

	std::cout << "GLFW was initialized!\n";
}

glfwLibrary::GlfwWrapper::~GlfwWrapper()
{
	std::cout << "Terminating GLFW library!\n";
	glfwTerminate();
}
