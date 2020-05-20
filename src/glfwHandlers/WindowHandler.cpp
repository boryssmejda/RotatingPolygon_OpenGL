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

glfwLibrary::WindowHandler::WindowHandler(Width t_width, Height t_height, Title t_windowTitle) :
	m_WINDOW_TITLE{ t_windowTitle.get() }
{
	m_windowHandle = glfwCreateWindow(t_width.get(), t_height.get(), m_WINDOW_TITLE.c_str(), nullptr, nullptr);
	if (!m_windowHandle)
		throw std::runtime_error("Could not create window");
	
	glfwSetFramebufferSizeCallback(m_windowHandle, glfwLibrary::WindowHandler::frameBufferSizeCallback);

	std::cout << "Window created successfully!\n" <<
		"Width: " << t_width.get() << '\n' <<
		"Height: " << t_height.get() << "\n\n";
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
