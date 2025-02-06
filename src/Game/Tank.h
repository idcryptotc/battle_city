#pragma once

#include <vec2.hpp>
#include <memory>

namespace Renderer
{
    class AnimatedSprite;
}

class Tank
{
public:
    enum class EOrientation
    {
        Top,
        Bottom,
        Left,
        Right
    };

    Tank(std::shared_ptr<Renderer::AnimatedSprite> pSprite, const float velocity, const glm::vec2& position);

    ~Tank() = default;

    void render() const;
    void setOrientation(EOrientation eOrientation);
    void move(bool move);
    void update(uint64_t delta);

private:
    EOrientation m_eOrientation;
    std::shared_ptr<Renderer::AnimatedSprite> m_pSprite;
    bool m_move;
    float m_velocity;
    glm::vec2 m_position;
    glm::vec2 m_moveOffset;
};