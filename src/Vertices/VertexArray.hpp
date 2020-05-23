#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "GL/glew.h"

class VertexBuffer;
class VertexBufferLayout;

class VertexArray
{
private:
	GLuint m_ID;

public:
	VertexArray();
	~VertexArray();

	VertexArray(const VertexArray& t_vertexArray) = delete;
	VertexArray& operator = (const VertexArray& t_vertexArray) = delete;

	void bind() const noexcept;
	void unbind() const noexcept;
	void addBuffer(const VertexBuffer& t_vb, const VertexBufferLayout& t_layout) const;
};

#endif // !_VERTEX_ARRAY_HPP
