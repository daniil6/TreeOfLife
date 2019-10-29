#include "ellipse.h"

CEllipse::CEllipse(const sf::Vector2f& radius)
    : m_radius(radius)
{
    update();
}

CEllipse::~CEllipse()
{
}

void CEllipse::SetPosition(float x, float y)
{
    setPosition(x - m_radius.x, y - m_radius.y);
}

std::size_t CEllipse::getPointCount() const
{
    return 30; // fixed, but could be an attribute of the class if needed
}

sf::Vector2f CEllipse::getPoint(std::size_t index) const
{
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * m_radius.x;
    float y = std::sin(angle) * m_radius.y;

    return sf::Vector2f(m_radius.x + x, m_radius.y + y);
}