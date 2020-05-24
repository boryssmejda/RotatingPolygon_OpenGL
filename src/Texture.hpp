#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "GL/glew.h"
#include <string>

class Texture
{
private:
	GLuint m_ID;
	std::string m_filePath;
	unsigned char* m_imageData;
	int m_width, m_height, m_bitsPerPixel;

public:
	enum class FILE_TYPE
	{
		JPG, PNG
	};

	Texture(const std::string& t_filePath, FILE_TYPE t_fileType);
	Texture(const Texture& t_texture) = delete;
	Texture& operator = (const Texture& t_texture) = delete;
	~Texture();

	void bind(unsigned int t_slot = 0)   const noexcept;
	void unbind() const noexcept;
};

#endif // !TEXTURE_HPP
