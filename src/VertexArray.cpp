#include "VertexArray.hpp"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_ID);
}

void VertexArray::bind() const noexcept
{
	glBindVertexArray(m_ID);
}

void VertexArray::unbind() const noexcept
{
	glBindVertexArray(0);
}
