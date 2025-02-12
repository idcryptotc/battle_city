#pragma once

#include <vector>
#include <glad/glad.h>

namespace RenderEngine
{
	struct VertexBufferLayoutElement
	{
		GLint count;
		GLenum type;
		GLboolean normalized;
		unsigned int size;
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout();

		~VertexBufferLayout() = default;

		void reserveElements(size_t count);

		unsigned int getStride() const
		{
			return m_stride;
		}

		const std::vector<VertexBufferLayoutElement>& getLayoutElements() const
		{
			return m_layoutElements;
		}

		void addElementLayoutFloat(int count, bool normalized);

	private:
		std::vector<VertexBufferLayoutElement> m_layoutElements;
		unsigned int m_stride;
	};
}