#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

using namespace sf;

class Platform : public RectangleShape {
private:
    RenderWindow& m_window;
    Ball& m_ball;

    float clamp(float value, float minn, float maxx);

    int checkCollision(RectangleShape& R1, CircleShape& C1);
public:
    Platform(RenderWindow& window, Ball& ball, float x, float y, float width, float height);

    void update();
};