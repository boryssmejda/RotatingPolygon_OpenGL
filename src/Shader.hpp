#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include "GL/glew.h"

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

	void setColor(const std::string& t_uniformName, const Color& t_color) const noexcept;
};

#endif // !SHADER_HPP
