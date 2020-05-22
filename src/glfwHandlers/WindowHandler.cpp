#include "WindowHandler.hpp"
#include <iostream>
#include <stdexcept>

void glfwLibrary::WindowHandler::frameBufferSizeCallback(GLFWwindow* t_window, int t_width, int t_height)
{
	std::cout << "Resizing window!\n"
		"New Width: " << t_width << '\n' <<
		"New Height: " << t_height << '\n' <<
		"--------------------------------\n";
	glViewport(0, 0, t_width, t_height);
}

glfwLibrary::WindowHandler::WindowHandler(int t_width, int t_height, std::string t_windowTitle)
{
	m_windowHandle = glfwCreateWindow(t_width, t_height, t_windowTitle.c_str(), nullptr, nullptr);
	if (!m_windowHandle)
		throw std::runtime_error("Could not create window");
	
	glfwSetFramebufferSizeCallback(m_windowHandle, glfwLibrary::WindowHandler::frameBufferSizeCallback);

	std::cout << "Window created successfully!\n" <<
		"Width: " << t_width << '\n' <<
		"Height: " << t_height << "\n\n";
}

glfwLibrary::WindowHandler::~WindowHandler()
{
	std::cout << "Closing the window!\n";
	glfwDestroyWindow(m_windowHandle);
}

int glfwLibrary::WindowHandler::getWidth() const
{
	int width;
	glfwGetWindowSize(m_windowHandle, &width, nullptr);
	return width;
}

int glfwLibrary::WindowHandler::getHeight() const
{
	int height;
	glfwGetWindowSize(m_windowHandle, nullptr, &height);
	return height;
}

void glfwLibrary::WindowHandler::makeContextCurrent() const
{
	glfwMakeContextCurrent(m_windowHandle);
	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("Could not initialize GLEW!\n");
	}
	std::cout << glGetString(GL_VERSION) << '\n';
}

void glfwLibrary::WindowHandler::clearWindow() const
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool glfwLibrary::WindowHandler::shouldClose() const
{
	return glfwWindowShouldClose(m_windowHandle);
}

void glfwLibrary::WindowHandler::processInput()
{
	if (glfwGetKey(m_windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		std::cout << "Escape key was pressed!\n";
		glfwSetWindowShouldClose(m_windowHandle, true);
	}
}
