#include "VertexArray.hpp"
#include "VertexBuffer/VertexBuffer.hpp"
#include "VertexBuffer/VertexBufferLayout.hpp"
#include <cstdint>

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

void VertexArray::addBuffer(const VertexBuffer& t_vb, const VertexBufferLayout& t_layout) const
{
	this->bind();
	t_vb.bind();
	const auto& elements = t_layout.getElements();
	uint64_t offset{ 0 };

	for (unsigned int i = 0; i < elements.size(); ++i)
	{
		const auto& curEl = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, curEl.m_size, curEl.m_type, curEl.m_normalized, t_layout.getStride(), (const void*)offset);

		offset += curEl.m_size * static_cast<uint64_t>(VertexBufferElement::getSizeOfType(curEl.m_type));
	}

	
}
