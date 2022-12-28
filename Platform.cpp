#include "Platform.h"

float Platform::clamp(float value, float minn, float maxx) {
    if (value < minn) return minn;
    else if (value > maxx) return maxx;
    else return value;
}

int Platform::checkCollision(RectangleShape& R1, CircleShape& C1) {
    float closestX = clamp(C1.getPosition().x, R1.getPosition().x, R1.getPosition().x + R1.getSize().x);
    float closestY = clamp(C1.getPosition().y, R1.getPosition().y, R1.getPosition().y + R1.getSize().y);

    float distanceX = C1.getPosition().x - closestX;
    float distanceY = C1.getPosition().y - closestY;

    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    if (distanceSquared < C1.getRadius() * C1.getRadius() &&
        closestX != C1.getPosition().x &&
        closestY != C1.getPosition().y) {
        return 3;
    }
    else if (distanceSquared < C1.getRadius() * C1.getRadius() &&
        closestX == C1.getPosition().x) {
        return 2;
    }
    else if (distanceSquared < C1.getRadius() * C1.getRadius() &&
        closestY == C1.getPosition().y) {
        return 1;
    }
    else return 0;
}

Platform::Platform(RenderWindow & window, Ball & ball, float x, float y, float width, float height) : m_window(window), m_ball(ball) {
    setSize(Vector2f(width, height));
    setPosition(x, y);
    setFillColor(Color::Red);
}

void Platform::update() {
    if (checkCollision(*this, m_ball) == 1) {
        m_ball.setXStep(-m_ball.xStep());
    }
    else if (checkCollision(*this, m_ball) == 2) {
        m_ball.setYStep(-m_ball.yStep());
    }
    else if (checkCollision(*this, m_ball) == 3) {
        m_ball.setXStep(-m_ball.xStep());
        m_ball.setYStep(-m_ball.yStep());
    }

    if (Keyboard::isKeyPressed(Keyboard::A)) {
        move(-15, 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        move(15, 0);
    }

    m_window.draw(*this);
}