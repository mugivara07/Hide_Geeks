#include "Player.h"
#include <iostream>

//Player::Player() {
//    _key_binding[sf::Keyboard::W] = Action::MOVE_FORWARD;
//    _key_binding[sf::Keyboard::A] = Action::MOVE_LEFT;
//    _key_binding[sf::Keyboard::S] = Action::MOVE_BACKWARD;
//    _key_binding[sf::Keyboard::D] = Action::MOVE_RIGHT;
//    _key_binding[sf::Keyboard::Space] = FIRE;
//}

void Player::Update(float time) {
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

float Player::Get_Player_X() {
    return x;
}

float Player::Get_Player_Y() {
    return y;
}

void Player::Key_Input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        dir = 1; speed = 0.1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        dir = 0; speed = 0.1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        dir = 3; speed = 0.1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        dir = 2; speed = 0.1;
    }
}