#include "Shader.hpp"
#include "GL/glew.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace 
{
	std::string readShaderSourceFromFile(const std::string& t_filepath)
	{
		std::ifstream shaderFile(t_filepath);
		if (!shaderFile.is_open())
			throw std::runtime_error("No such file exists!\n");

		std::stringstream ss;
		ss << shaderFile.rdbuf();
		shaderFile.close();

		return ss.str();
	}

	GLuint compileShader(GLenum t_shaderType, const std::string& t_source)
	{
		GLuint shaderID = glCreateShader(t_shaderType);
		const char* src = t_source.c_str();
		glShaderSource(shaderID, 1, &src, nullptr);
		glCompileShader(shaderID);

		return shaderID;
	}

	void checkCompileErrors(GLuint t_shader, const std::string& t_type)
	{
		GLint vertexCompiled;
		glGetShaderiv(t_shader, GL_COMPILE_STATUS, &vertexCompiled);

		if (vertexCompiled != GL_TRUE)
		{
			GLchar message[1024];
			glGetShaderInfoLog(t_shader, sizeof(message), nullptr, message);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << t_type << "\n"
				<< message << '\n';
		}
		else
		{
			std::cout << t_type << " shader compiled successfully\n";
		}
	}

	GLuint linkShadersIntoProgram(GLuint t_vertexID, GLuint t_fragmentID)
	{
		GLuint program = glCreateProgram();
		glAttachShader(program, t_vertexID);
		glAttachShader(program, t_fragmentID);
		glLinkProgram(program);

		return program;
	}

	void checkLinkingErrors(GLuint t_shader)
	{
		GLint programLinked;
		glGetProgramiv(t_shader, GL_LINK_STATUS, &programLinked);
		if (programLinked != GL_TRUE)
		{
			GLchar message[1024];
			glGetProgramInfoLog(t_shader, sizeof(message), nullptr, message);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: PROGRAM\n"
				<< message << '\n';
		}
	}
}


Shader::Shader(const std::string& t_vertexPath, const std::string& t_fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;

	vertexCode   = readShaderSourceFromFile(t_vertexPath);
	fragmentCode = readShaderSourceFromFile(t_fragmentPath);
	
	GLuint vertexID   = compileShader(GL_VERTEX_SHADER, vertexCode);
	GLuint fragmentID = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

	checkCompileErrors(vertexID, "VERTEX");
	checkCompileErrors(fragmentID, "FRAGMENT");

	m_ID = linkShadersIntoProgram(vertexID, fragmentID);

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

Shader::~Shader()
{
	glDeleteProgram(m_ID);
}

void Shader::use() const noexcept
{
	glUseProgram(m_ID);
}

int Shader::getUniformLocation(const std::string& t_uniformName) const noexcept
{
	return glGetUniformLocation(m_ID, t_uniformName.c_str());
}

void Shader::setColor(const std::string& t_uniformName, const Color& t_color) const noexcept
{
	this->use();
	glUniform4f(getUniformLocation(t_uniformName), t_color.r, t_color.g, t_color.b, t_color.alpha);
}

void Shader::setMat4f(const std::string& t_uniformName, const glm::mat4 t_transformation) const noexcept
{
	this->use();
	glUniformMatrix4fv(getUniformLocation(t_uniformName), 1, GL_FALSE, &t_transformation[0][0]);
}
