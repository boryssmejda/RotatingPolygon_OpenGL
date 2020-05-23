#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Vertices/VertexArray.hpp"
//#include "IndexBuffer.hpp"
#include "Shader.hpp"
class IndexBuffer;

class Renderer
{
public:
	static void clearScreen();
	static void drawArray(const VertexArray& t_va, const Shader& t_shader, int t_nrIndices);
	static void drawElements(const VertexArray& t_va, const Shader& t_shader, const IndexBuffer& t_ib);
};

#endif // !RENDERER_HPP
