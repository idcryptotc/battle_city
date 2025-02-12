#pragma once

#include <glad/glad.h>

namespace RenderEngine
{
	class VertexFuffer
	{
	public:
		VertexFuffer();
		VertexFuffer(const VertexFuffer&) = delete;
		VertexFuffer(VertexFuffer&& vertexFuffer) noexcept;

		~VertexFuffer();

		VertexFuffer& operator=(const VertexFuffer&) = delete;
		VertexFuffer& operator=(VertexFuffer&& vertexFuffer) noexcept;

		void init(const void* data, unsigned int size);
		void update(const void* data, unsigned int size) const;
		void bind() const;
		void unbind() const;

	private:
		GLuint m_id;
	};
}