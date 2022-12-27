#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

float clamp(float value, float minn, float maxx) {
    if (value < minn) return minn;
    else if (value > maxx) return maxx;
    else return value;
}

int checkCollision(RectangleShape& R1, CircleShape& C1) {
    float closestX = clamp(C1.getPosition().x, R1.getPosition().x, R1.getPosition().x + R1.getSize().x);
    float closestY = clamp(C1.getPosition().y, R1.getPosition().y, R1.getPosition().y + R1.getSize().y);

    float distanceX = C1.getPosition().x - closestX;
    float distanceY = C1.getPosition().y - closestY;

    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    if (distanceSquared < C1.getRadius()*C1.getRadius() &&
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

int main() {
    RenderWindow window(VideoMode(800, 600), "Project Game");
    window.setFramerateLimit(60);

    CircleShape shape;
    shape.setRadius(30.0);
    shape.setFillColor(Color::Yellow);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(window.getSize().x / 10, window.getSize().y / 2);

    float xstep = 10, ystep = 9;

    RectangleShape p1;
    p1.setSize(Vector2f(150, 40));
    p1.setPosition(200, 400);

    while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape)) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        shape.move(xstep, ystep);

        if (shape.getPosition().x > window.getSize().x - shape.getRadius())
            xstep = -xstep;
        else if (shape.getPosition().y > window.getSize().y - shape.getRadius())
            ystep = -ystep;
        else if (shape.getPosition().x < shape.getRadius())
            xstep = -xstep;
        else if (shape.getPosition().y < shape.getRadius())
            ystep = -ystep;

        if (checkCollision(p1, shape) == 1)
            xstep = -xstep;
        else if (checkCollision(p1, shape) == 2)
            ystep = -ystep;
        else if (checkCollision(p1, shape) == 3) {
            xstep = -xstep;
            ystep = -ystep;
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
            p1.move(-15, 0);
        if (Keyboard::isKeyPressed(Keyboard::D))
            p1.move(15, 0);

        window.clear();
        window.draw(shape);
        window.draw(p1);
        window.display();
    }
    
    return 0;
}