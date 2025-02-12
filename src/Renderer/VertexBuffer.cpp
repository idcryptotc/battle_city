#include "VertexBuffer.h"

namespace RenderEngine
{
    VertexFuffer::VertexFuffer()
        : m_id(0)
    {
    }

    VertexFuffer::VertexFuffer(VertexFuffer&& vertexFuffer) noexcept
    {
        m_id = vertexFuffer.m_id;
        vertexFuffer.m_id = 0;
    }

    VertexFuffer::~VertexFuffer()
    {
        glDeleteBuffers(1, &m_id);
    }

    VertexFuffer& VertexFuffer::operator=(VertexFuffer&& vertexFuffer) noexcept
    {
        m_id = vertexFuffer.m_id;
        vertexFuffer.m_id = 0;
        return *this;
    }

    void VertexFuffer::init(const void* data, unsigned int size)
    {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void VertexFuffer::update(const void* data, unsigned int size) const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

    void VertexFuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexFuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}