#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    sf::Texture texture;
    texture.loadFromFile("include/img.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(200, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            sprite.move(-0.1,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sprite.move(0.1,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            sprite.move(0,-0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sprite.move(0,0.1);
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}