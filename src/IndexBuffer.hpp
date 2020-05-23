#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "GL/glew.h"

class IndexBuffer
{
private:
	GLuint m_ID;
	unsigned int m_count;

public:
	IndexBuffer(const GLuint* t_data, unsigned int t_count, GLenum t_usage);
	~IndexBuffer();

	void bind()   const noexcept;
	void unBind() const noexcept;
	inline unsigned int getCount() const noexcept { return m_count; }
};


#endif // !INDEX_BUFFER_HPP