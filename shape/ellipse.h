#ifndef CELLIPSE_H
#define CELLIPSE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class CEllipse : public sf::Shape
{
private:
    sf::Vector2f m_radius;

public:
    explicit CEllipse(const sf::Vector2f& radius = sf::Vector2f(0, 0));
    ~CEllipse();

    void SetPosition(float x, float y);

    virtual std::size_t getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;
};

#endif // CELLIPSE_H
