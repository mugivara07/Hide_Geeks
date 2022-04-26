#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.h"
#include "view.h"

class Player {
private:
    float x, y;
public:
    float w, h, dx, dy ,speed = 0;
    int dir = 0;
    std::string file;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    Player(std::string F, int X, int Y, float W, float H) {
        file = F;
        x = X; y = Y; w =W; h = H;
        image.loadFromFile("images/" + file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect (w, h, w, h));
    }
    void update(float time) {
        switch (dir) {
            case 0:
                dx = speed;
                dy = 0;
                break;
            case 1:
                dx = -speed;
                dy = 0;
                break;
            case 2:
                dx = 0;
                dy = speed;
                break;
            case 3:
                dx = 0;
                dy = -speed;
                break;
        }
        x += dx*time;
        y += dy*time;

        speed = 0;
        sprite.setPosition(x, y);
    }
    float Get_Player_X() {
        return x;
    }
    float Get_Player_Y() {
        return y;
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    view.reset(sf::FloatRect(0, 0, 640, 480));

    Player player_1("hero.png", 250, 250, 96.0, 96.0);

    sf::Image map_image;
    map_image.loadFromFile("map.png");
    sf::Texture map_texture;
    map_texture.loadFromImage(map_image);
    sf::Sprite map_sprite;
    map_sprite.setTexture(map_texture);

    float current_frame = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player_1.dir = 1; player_1.speed = 0.1;
            current_frame += 0.005*time;
            if (current_frame >= 3) {
                current_frame = 0;
            }
            player_1.sprite.setTextureRect(sf::IntRect (96*int(current_frame), 96, 96, 96));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player_1.dir = 0; player_1.speed = 0.1;
            current_frame += 0.005*time;
            if (current_frame >= 3) {
                current_frame = 0;
            }
            player_1.sprite.setTextureRect(sf::IntRect (96*int(current_frame), 192, 96, 96));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player_1.dir = 3; player_1.speed = 0.1;
            current_frame += 0.005*time;
            if (current_frame >= 3) {
                current_frame = 0;
            }
            player_1.sprite.setTextureRect(sf::IntRect (96*int(current_frame), 288, 96, 96));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player_1.dir = 2; player_1.speed = 0.1;
            current_frame += 0.005*time;
            if (current_frame >= 3) {
                current_frame = 0;
            }
            player_1.sprite.setTextureRect(sf::IntRect (96*int(current_frame), 0, 96, 96));
        }

        player_1.update(time);
        GetViewCoordinate(player_1.Get_Player_X(), player_1.Get_Player_Y());
        window.setView(view);
        window.clear();

        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++) {
                if (map[i][j] == '0') {
                    map_sprite.setTextureRect(sf::IntRect (64, 0, 32, 32));
                }
                if (map[i][j] == ' ') {
                    map_sprite.setTextureRect(sf::IntRect (0, 0, 32, 32));
                }
                if (map[i][j] == 's') {
                    map_sprite.setTextureRect(sf::IntRect (32, 0, 32, 32));
                }

                map_sprite.setPosition(j * 32, i * 32);

                window.draw(map_sprite);
            }
        }

        window.draw(player_1.sprite);
        window.display();
    }

    return 0;
}