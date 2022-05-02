#include "Player.h"
#include <iostream>

//Player::Player() {
//    _key_binding[sf::Keyboard::W] = Action::MOVE_FORWARD;
//    _key_binding[sf::Keyboard::A] = Action::MOVE_LEFT;
//    _key_binding[sf::Keyboard::S] = Action::MOVE_BACKWARD;
//    _key_binding[sf::Keyboard::D] = Action::MOVE_RIGHT;
//    _key_binding[sf::Keyboard::Space] = FIRE;
//}

void Player::Update(float time) { // // Todo(Artem) Implement diagonal movement
	switch (dir) {
	case 0:  //move right and up
		dx = speed;
		dy = -speed;
		break;
	case 1: //move right and down
		dx = speed;
		dy = speed;
		break;
	case 2: //move left and down
		dx = -speed;
		dy = speed;
		break;
	case 3: //move left and up
		dx = -speed;
		dy = -speed;
		break;
	case 4: //move up
		dx = 0;
		dy = -speed;
		break;
	case 5: //move right
		dx = speed;
		dy = 0;
		break;
	case 6: //move down
		dx = 0;
		dy = speed;
		break;
	case 7: //move left
		dx = -speed;
		dy = 0;
		break;
	}
	x += dx * time;
	y += dy * time;

	// *********** Temporary map interaction ***********

	if (x > 1241) {
		x = 1241;
	}
	if (x < 39) {
		x = 39;
	}
	if (y > 754) {
		y = 754;
	}
	if (y < 46) {
		y = 46;
	}

	// ****************************************************

	speed = 0;
	sprite.setPosition(x, y);
}

float Player::Get_Player_X() {
	return x;
}

float Player::Get_Player_Y() {
	return y;
}

void Player::Key_Input(float time) {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir = 0; speed = 0.1;
		CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам".изменив 0.005 можно изменить скорость анимации
		if (CurrentFrame > 8) CurrentFrame -= 8; //проходимся по кадрам с первого. если пришли к заданному кадру - откидываемся назад.
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32)); //проходимся по координатам Х.
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir = 1; speed = 0.1;
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 8) CurrentFrame -= 8;
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32));
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir = 2; speed = 0.1;
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 8) CurrentFrame -= 8;
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32));
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir = 3; speed = 0.1;
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 8) CurrentFrame -= 8;
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir = 4; speed = 0.1;
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 8) CurrentFrame -= 8;
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir = 5; speed = 0.1;
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 8) CurrentFrame -= 8;
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir = 6; speed = 0.1;
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 8) CurrentFrame -= 8;
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dir = 7; speed = 0.1;
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 8) CurrentFrame -= 8;
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32));
		sprite.move(-0.1 * time, 0);
	}
}

void Player::Rotation(sf::Vector2f pos) {
	//pos_x, pos_y - координаты курсора
	float dX = pos.x - Get_Player_X(); //вектор , колинеарный прямой, которая пересекает спрайт и курсор
	float dY = pos.y - Get_Player_Y(); //он же, координата y
	float rotation = (atan2(dY, dX)) * 180 / 3.14159265;//получаем угол в радианах и переводим его в градусы
	std::cout << rotation << "\n";//смотрим на градусы в консольке
	sprite.setRotation(rotation);//поворачиваем спрайт на эти градусы
}