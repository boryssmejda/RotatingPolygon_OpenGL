#ifndef GLFW_WRAPPER_HPP
#define GLFW_WRAPPER_HPP

namespace glfwLibrary {
	
	class GlfwWrapper
	{
	private:
		static void errorCallback(int error, const char* description);
	public:
		GlfwWrapper();
		~GlfwWrapper();
	};

}
#endif // !GLFW_WRAPPER_HPP
