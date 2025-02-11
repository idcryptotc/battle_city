#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include <glad/glad.h>

namespace Renderer
{
	class VertexArray
	{
	public:
		VertexArray();
		VertexArray(const VertexArray&) = delete;
		VertexArray(VertexArray&& vertexArray) noexcept;

		~VertexArray();

		VertexArray& operator=(const VertexArray&) = delete;
		VertexArray& operator=(VertexArray&& vertexArray) noexcept;

		void addBuffer(const VertexFuffer& vertexFuffer, const VertexBufferLayout& layout);
		void bind() const;
		void unbind() const;

	private:
		GLuint m_id = 0;
		size_t m_elementsCount = 0;
	};
}