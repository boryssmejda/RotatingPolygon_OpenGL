#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "GL/glew.h"

class VertexArray
{
private:
	GLuint m_ID;

public:
	VertexArray();
	~VertexArray();

	VertexArray(const VertexArray& t_vertexArray) = delete;
	VertexArray& operator = (const VertexArray& t_vertexArray) = delete;

	void bind() const;
	void unbind() const;
};

#endif // !_VERTEX_ARRAY_HPP
