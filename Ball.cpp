#include "Ball.h"

Ball::Ball(RenderWindow& window, float x, float y, float radius, Color color, float xStep, float yStep) : m_window(window), m_xStep(xStep), m_yStep(yStep) {
    setRadius(radius);
    setFillColor(color);
    setOrigin(radius, radius);
    setPosition(x, y);
}

void Ball::setXStep(float step) {
    m_xStep = step;
}

void Ball::setYStep(float step) {
    m_yStep = step;
}

float Ball::xStep() {
    return m_xStep;
}

float Ball::yStep() {
    return m_yStep;
}

void Ball::update() {
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