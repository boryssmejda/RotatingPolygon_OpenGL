#include "VertexBuffer.hpp"


VertexBuffer::VertexBuffer(GLenum t_target, const GLvoid* t_data, GLsizeiptr t_size, GLenum t_usage)
	: m_targetToBeBound {t_target}
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(t_target, m_ID);
	glBufferData(t_target, t_size, t_data, t_usage);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}

void VertexBuffer::bind() const noexcept
{
	glBindBuffer(m_targetToBeBound, m_ID);
}

void VertexBuffer::unBind() const noexcept
{
	glBindBuffer(m_targetToBeBound, 0);
}

