#ifndef VERTEX_BUFFER_LAYOUT_HPP
#define VERTEX_BUFFER_LAYOUT_HPP

#include "GL/glew.h"
#include <vector>

struct VertexBufferElement
{
	GLenum m_type;
	GLuint m_size;
	GLboolean m_normalized;

	static unsigned int getSizeOfType(GLenum t_type)
	{
		switch (t_type)
		{
		case GL_UNSIGNED_INT:  return sizeof(GLuint);
		case GL_UNSIGNED_BYTE: return sizeof(GLchar);
		case GL_FLOAT:		   return sizeof(GL_FLOAT);
		default:
			return 0;
		}
	}
};


class VertexBufferLayout
{
private:
	GLuint m_stride;
	std::vector<VertexBufferElement> m_elements;

public:
	VertexBufferLayout() : m_stride{ 0 } {}

	GLuint getStride() const { return m_stride; }
	const std::vector<VertexBufferElement>& getElements() const { return m_elements; }
	void push(unsigned int t_size, GLenum t_type, GLboolean t_normalized);
};

#endif // !VERTEX_BUFFER_LAYOUT_HPP
