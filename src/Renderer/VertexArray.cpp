#include "VertexArray.h"

namespace RenderEngine
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_id);
    }

    VertexArray::VertexArray(VertexArray&& vertexArray) noexcept
    {
        m_id = vertexArray.m_id;
        vertexArray.m_id = 0;
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_id);
    }

    VertexArray& VertexArray::operator=(VertexArray&& vertexArray) noexcept
    {
        m_id = vertexArray.m_id;
        vertexArray.m_id = 0;
        return *this;
    }

    void VertexArray::addBuffer(const VertexFuffer& vertexFuffer, const VertexBufferLayout& layout)
    {
        bind();
        vertexFuffer.bind();
        const auto& layoutElements = layout.getLayoutElements();
        size_t size = layoutElements.size();
        GLbyte* offset = nullptr;

        for (size_t i = 0; i < size; ++i)
        {
            const auto& currentLayoutElement = layoutElements[i];
            GLuint currentAttribIndex = m_elementsCount + i;
            glEnableVertexAttribArray(currentAttribIndex);
            glVertexAttribPointer(
                currentAttribIndex
                , currentLayoutElement.count
                , currentLayoutElement.type
                , currentLayoutElement.normalized
                , layout.getStride()
                , offset);
            offset += currentLayoutElement.size;
        }

        m_elementsCount += size;
    }

    void VertexArray::bind() const
    {
        glBindVertexArray(m_id);
    }

    void VertexArray::unbind() const
    {
        glBindVertexArray(0);
    }
}