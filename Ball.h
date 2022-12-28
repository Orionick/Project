#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public CircleShape {
private:
    float m_xStep;
    float m_yStep;
    RenderWindow& m_window;
public:
    Ball(RenderWindow& window, float x, float y, float radius, Color color, float xStep, float yStep) : m_window(window), m_xStep(xStep), m_yStep(yStep) {
        setRadius(radius);
        setFillColor(color);
        setOrigin(radius, radius);
        setPosition(x, y);
    }

    void setXStep(float step) {
        m_xStep = step;
    }

    void setYStep(float step) {
        m_yStep = step;
    }

    float xStep() {
        return m_xStep;
    }

    float yStep() {
        return m_yStep;
    }

    void update() {
        move(m_xStep, m_yStep);

        const Vector2f& position = getPosition();

        if (position.x > m_window.getSize().x - getRadius() || position.x < getRadius()) {
            m_xStep = -m_xStep;
        }
        else if (position.y > m_window.getSize().y - getRadius() || position.y < getRadius()) {
            m_yStep = -m_yStep;
        }

        m_window.draw(*this);
    }
};