#ifndef WINDOW_HANDLER_HPP
#define WINDOW_HANDLER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>


namespace glfwLibrary {
	class WindowHandler
	{
	private:
		GLFWwindow* m_windowHandle;
		static void frameBufferSizeCallback(GLFWwindow* t_window, int t_width, int t_height);

	public:
		WindowHandler(int t_width, int t_height, std::string t_windowTitle);
		WindowHandler(const WindowHandler& t_winHandler) = delete;
		WindowHandler& operator = (const WindowHandler& t_windHandler) = delete;
		~WindowHandler();

		int getWidth()  const;
		int getHeight() const;
		GLFWwindow* getWindowHandler() const { return m_windowHandle; }
		void makeContextCurrent() const;
		void setSwapInterval(int t_interval = 1) const { glfwSwapInterval(t_interval); }
		void clearWindow() const;
		void swapBuffers() const { glfwSwapBuffers(m_windowHandle); }
		void pollEvents()  const { glfwPollEvents(); }
		bool shouldClose() const;
		void processInput();

	};

}


#endif // !WINDOW_HANDLER_HPP
