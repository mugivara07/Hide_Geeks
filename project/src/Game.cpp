#include "Game.h"
#include "map.h"
#include "view.h"

#include <string>
#include <utility>
#include <iostream>

Game::Game() : _window(sf::VideoMode(640, 480), "Hide and Geeks", sf::Style::Close) {}

void Game::run() {

    sf::CircleShape shape(150.f);
    shape.setFillColor(sf::Color::Green);

    view.reset(sf::FloatRect(0, 0, 640, 480));

    Player player_1("hero.png", 250, 250, 96.0, 96.0);

    sf::Clock clock;

    sf::Image map_image;
    map_image.loadFromFile("map.png");
    sf::Texture map_texture;
    map_texture.loadFromImage(map_image);
    sf::Sprite map_sprite;
    map_sprite.setTexture(map_texture);

    while (_window.isOpen()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/350;
//        sf::Event event;
//        while (_window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                _window.close();
//        }
        get_input(&player_1, time);
        // update();

        GetViewCoordinate(player_1.Get_Player_X(), player_1.Get_Player_Y());
        _window.setView(view);
        _window.clear();

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

                _window.draw(map_sprite);
            }
        }

        _window.draw(player_1.sprite);
        _window.display();

//        while (total_time > _time_per_frame) {
//            total_time -= _time_per_frame;
//
//            get_input();
//            update(_time_per_frame);
//
//            if (_state_stack.is_empty()) {
//                _window.close();
//            }
//        }
//
//        render();
    }
}

//bool Game::update(sf::Time dt) {
//    _state_stack.update(dt);
//    return true;
//}
//
//void Game::render() {
//    _window.clear();
//    _state_stack.draw();
//    _window.display();
//}
//
void Game::get_input(Player* player, float time) {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
    }
    player->Key_Input();
    player->Update(time);
}
