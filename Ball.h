#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public CircleShape {
private:
    float m_xStep = 10;
    float m_yStep;
    RenderWindow& m_window;
    
public:
    Ball(RenderWindow& window, float x, float y, float radius, Color color, float xStep, float yStep);

    void setXStep(float step);

    void setYStep(float step);

    float xStep();

    float yStep();

    void update();

};