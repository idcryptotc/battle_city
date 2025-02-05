#include "AnimatedSprite.h"
#include "Texture2D.h"

#include <iostream>

namespace Renderer
{
    AnimatedSprite::AnimatedSprite(
        std::shared_ptr<Texture2D> pTexture
        , std::string initialSubTexture
        , std::shared_ptr<ShaderProgram> pShaderProgram
        , const glm::vec2& position
        , const glm::vec2& size
        , const float rotation)
        : Sprite(std::move(pTexture), std::move(initialSubTexture), std::move(pShaderProgram), position, size, rotation)
    {
        m_pCurrentAnimaionDurations = m_states.end();
    }

    void AnimatedSprite::insertState(std::string state, std::vector<std::pair<std::string, uint64_t>> subTexturesDuration)
    {
        m_states.emplace(std::move(state), std::move(subTexturesDuration));
    }

    void AnimatedSprite::render() const
    {
        if (m_dirty)
        {
            auto& subTexture = m_pTexture->getSubtexture(m_pCurrentAnimaionDurations->second[m_currentFrame].first);

            const GLfloat textureCoords[] =
            {
                subTexture.leftBottomUV.x, subTexture.leftBottomUV.y,
                subTexture.leftBottomUV.x, subTexture.rightTopUV.y,
                subTexture.rightTopUV.x, subTexture.rightTopUV.y,

                subTexture.rightTopUV.x, subTexture.rightTopUV.y,
                subTexture.rightTopUV.x, subTexture.leftBottomUV.y,
                subTexture.leftBottomUV.x, subTexture.leftBottomUV.y,
            };

            glBindBuffer(GL_ARRAY_BUFFER, m_textureCoordsVbo);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(textureCoords), &textureCoords);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            m_dirty = false;
        }

        Sprite::render();
    }

    void AnimatedSprite::setState(const std::string& newState)
    {
        auto it = m_states.find(newState);

        if (it == m_states.end())
        {
            std::cerr << "Can't find animation state: " << newState << std::endl;
            return;
        }

        if (it != m_pCurrentAnimaionDurations)
        {
            m_currentAnimationTime = 0;
            m_currentFrame = 0;
            m_pCurrentAnimaionDurations = it;
            m_dirty = true;
        }
    }

    void AnimatedSprite::update(uint64_t delta)
    {
        if (m_pCurrentAnimaionDurations != m_states.end())
        {
            m_currentAnimationTime += delta;

            while (m_currentAnimationTime >= m_pCurrentAnimaionDurations->second[m_currentFrame].second)
            {
                m_currentAnimationTime -= m_pCurrentAnimaionDurations->second[m_currentFrame].second;
                ++m_currentFrame;
                m_dirty = true;

                if (m_currentFrame == m_pCurrentAnimaionDurations->second.size())
                {
                    m_currentFrame = 0;
                }
            }
        }
    }
}