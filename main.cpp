#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Project Game");
    window.setFramerateLimit(60);

    CircleShape shape;
    shape.setRadius(50.0);
    shape.setFillColor(Color::Yellow);
    shape.setOrigin(50.0, 50.0);
    shape.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    float xstep = 8, ystep = 4;

    while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape)) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        shape.move(xstep, ystep);

        if (shape.getPosition().x > window.getSize().x - 50)
            xstep = -xstep;
        else if (shape.getPosition().y > window.getSize().y - 50)
            ystep = -ystep;
        else if (shape.getPosition().x < 0 + 50)
            xstep = -xstep;
        else if (shape.getPosition().y < 0 + 50)
            ystep = -ystep;

        window.clear();
        window.draw(shape);
        window.display();
    }
    
    return 0;
}