#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
public:
    Game();
    ~Game() = default;
    void run();
private:
    bool update();
    void render();
    bool handle_event(const sf::Event& event);
    void get_input(Player* player, float time);
    sf::RenderWindow _window;
    // Player _player;
};