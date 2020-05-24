#include "Renderer.hpp"
#include "IndexBuffer.hpp"

void Renderer::clearScreen()
{
	glClearColor(0.2f, 0.3f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawArray(const VertexArray& t_va, const Shader& t_shader, int t_nrIndices)
{
	t_va.bind();
	t_shader.use();

	glDrawArrays(GL_TRIANGLES, 0, t_nrIndices);
}

void Renderer::drawElements(const VertexArray& t_va, const Shader& t_shader, const IndexBuffer& t_ib)
{
	t_va.bind();
	t_ib.bind();
	t_shader.use();

	glDrawElements(GL_TRIANGLES, t_ib.getCount(), GL_UNSIGNED_INT, nullptr);
}
