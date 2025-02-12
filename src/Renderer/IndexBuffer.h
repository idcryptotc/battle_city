#pragma once

#include <glad/glad.h>

namespace RenderEngine
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

		void init(const void* data, unsigned int count);
		void bind() const;
		void unbind() const;

		unsigned int getCount() const
		{
			return m_count;
		}

	private:
		GLuint m_id;
		unsigned int m_count;
	};
}