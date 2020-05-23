#include "VertexBufferLayout.hpp"
#include <stdexcept>


void VertexBufferLayout::push(unsigned int t_size, GLenum t_type, GLboolean t_normalized)
{
	VertexBufferElement verBufEl;
	verBufEl.m_normalized = t_normalized;
	verBufEl.m_type = t_type;
	verBufEl.m_size = t_size;

	m_elements.push_back(verBufEl);

	m_stride += t_size * VertexBufferElement::getSizeOfType(t_type);
}
