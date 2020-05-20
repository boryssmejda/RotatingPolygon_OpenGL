#ifndef WINDOW_HANDLER_HPP
#define WINDOW_HANDLER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

template<typename T, typename Parameter>
class NamedType
{
public:
	explicit NamedType(const T& t_value) : m_value{ t_value } {}
	T& get() { return m_value; }

private:
	T m_value;
};

using Width  = NamedType<int, struct WidthParameter>;
using Height = NamedType<int, struct HeightParameter>;
using Title = NamedType<std::string, struct TitleParameter>;

namespace glfwLibrary {
	class WindowHandler
	{
	private:
		const std::string m_WINDOW_TITLE;
		GLFWwindow* m_windowHandle;
		static void frameBufferSizeCallback(GLFWwindow* t_window, int t_width, int t_height);

	public:
		WindowHandler(Width t_width, Height t_height, Title t_windowTitle);
		WindowHandler(const WindowHandler& t_winHandler) = delete;
		WindowHandler& operator = (const WindowHandler& t_windHandler) = delete;
		~WindowHandler();

		int getWidth()  const;
		int getHeight() const;
		GLFWwindow* getWindowHandler() const { return m_windowHandle; }
		void makeContextCurrent() const { glfwMakeContextCurrent(m_windowHandle); }
		void setSwapInterval(int t_interval = 1) const { glfwSwapInterval(t_interval); }
		void clearWindow() const;
		void swapBuffers() const { glfwSwapBuffers(m_windowHandle); }
		void pollEvents()  const { glfwPollEvents(); }
		bool shouldClose() const;
		void processInput();

	};

}


#endif // !WINDOW_HANDLER_HPP
