#pragma once

#include <glad/glad.h>

namespace Renderer
{
	class IndexBuffer
	{
	public:
		IndexBuffer();
		IndexBuffer(const IndexBuffer&) = delete;
		IndexBuffer(IndexBuffer&& IndexBuffer) noexcept;

		~IndexBuffer();

		IndexBuffer& operator=(const IndexBuffer&) = delete;
		IndexBuffer& operator=(IndexBuffer&& indexFuffer) noexcept;

		void init(const void* data, unsigned int size);
		void bind() const;
		void unbind() const;

	private:
		GLuint m_id;
	};
}