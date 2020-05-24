#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include "GL/glew.h"
#include "glm/glm.hpp"

struct Color
{
	float r, g, b, alpha = 1.0f;
};

class Shader
{
private:
	GLuint m_ID;

public:
	Shader(const std::string& t_vertexPath, const std::string& t_fragmentPath);
	~Shader();
	Shader(const Shader& t_shader) = delete;
	Shader& operator = (const Shader& t_shader) = delete;
	void use() const noexcept;

	int getUniformLocation(const std::string& t_uniformName) const noexcept;
	void setColor(const std::string& t_uniformName, const Color& t_color) const noexcept;
	void setMat4f(const std::string& t_uniformName, const glm::mat4 t_transformation) const noexcept;
	
};

#endif // !SHADER_HPP
