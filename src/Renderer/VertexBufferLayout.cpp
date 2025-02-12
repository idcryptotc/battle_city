#include "VertexBufferLayout.h"

namespace RenderEngine
{
    VertexBufferLayout::VertexBufferLayout()
        : m_stride(0)
    {
    }

    void VertexBufferLayout::reserveElements(size_t count)
    {
        m_layoutElements.reserve(count);
    }

    void VertexBufferLayout::addElementLayoutFloat(int count, bool normalized)
    {
        m_layoutElements.push_back({ count, GL_FLOAT, normalized, count * sizeof(GLfloat) });
        m_stride += m_layoutElements.back().size;
    }
}