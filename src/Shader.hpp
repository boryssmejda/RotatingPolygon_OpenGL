#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include "GL/glew.h"

class Shader
{
private:
	GLuint m_ID;

public:
	Shader(const std::string& t_vertexPath, const std::string& t_fragmentPath);
	~Shader();
	Shader(const Shader& t_shader) = delete;
	Shader& operator = (const Shader& t_shader) = delete;
	void use();

};

#endif // !SHADER_HPP
