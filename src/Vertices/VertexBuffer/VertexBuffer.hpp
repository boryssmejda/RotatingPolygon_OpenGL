#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include "GL/glew.h"
#include <memory>

class VertexBuffer
{
private:
	GLuint m_ID;
	GLenum m_targetToBeBound;

public:
	VertexBuffer(GLenum t_target, const GLvoid* t_data, GLsizeiptr t_size, GLenum t_usage);
	VertexBuffer(const VertexBuffer& t_vertexBuffer) = delete;
	VertexBuffer& operator = (const VertexBuffer& t_vertexBuffer) = delete;
	~VertexBuffer();



	GLuint getID() const noexcept { return m_ID; }
	void bind()    const noexcept;
	void unBind()  const noexcept;
};

#endif // !VERTEX_BUFFER_HPP
