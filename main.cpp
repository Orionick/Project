#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Platform.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Project Game");
    window.setFramerateLimit(60);

    Ball ball(window, window.getSize().x / 10, window.getSize().y / 2, 30.0, Color::Yellow, 10, 9);
    Platform platform(window, ball, 200, 400, 150, 40);

    while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape)) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();

        ball.update();
        platform.update();

        window.display();
    }

    return 0;
}