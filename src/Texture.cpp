#include "Texture.hpp"
#include "stb_image.h"

#include <iostream>
#include <stdexcept>

Texture::Texture(const std::string& t_filePath, FILE_TYPE t_fileType)
	: m_ID{ 0 }, m_imageData{ nullptr }, m_width{ 0 }, m_height{0}, m_bitsPerPixel{0}
{
	m_filePath = t_filePath;
	
	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	m_imageData = stbi_load(t_filePath.c_str(), &m_width, &m_height, &m_bitsPerPixel, 0);

	if (!m_imageData)
	{
		std::cout << "Couldn't find the image\n!";
		throw std::runtime_error("No such image exists!\n");
	}

	switch (t_fileType)
	{
	case FILE_TYPE::JPG:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_imageData);
		break;
	case FILE_TYPE::PNG:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_imageData);
		break;
	}

	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(m_imageData);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_ID);
}

void Texture::bind(unsigned int t_slot) const noexcept
{
	glActiveTexture(GL_TEXTURE0 + t_slot);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::unbind() const noexcept
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
