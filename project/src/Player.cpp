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
	sprite_2.setPosition(x - w / 4, y - w / 8);
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
		CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������".������� 0.005 ����� �������� �������� ��������
		if (CurrentFrame > 8) CurrentFrame -= 8; //���������� �� ������ � �������. ���� ������ � ��������� ����� - ������������ �����.
		sprite.setTextureRect(sf::IntRect(32 * int(CurrentFrame) + 1480, 895, 32, 32)); //���������� �� ����������� �.
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
	}
}

void Player::Rotation(sf::Vector2f pos) {
	//pos_x, pos_y - ���������� �������
	float dX = pos.x - Get_Player_X(); //������ , ����������� ������, ������� ���������� ������ � ������
	float dY = pos.y - Get_Player_Y(); //�� ��, ���������� y
	float rotation = (atan2(dY, dX)) * 180 / 3.14159265;//�������� ���� � �������� � ��������� ��� � �������
	std::cout << rotation << "\n";//������� �� ������� � ���������


	//11111algorithm for rotation player's parts toward current direction with or without moving of player111111111111111111111111111111
	//if (dir == 4) {
	//	if (rotation <= -30 && rotation >= -150 && rotation == -150) {
	//		sprite_2.setRotation(-150);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= -30 && rotation >= -150 && rotation == -30) {
	//		sprite_2.setRotation(-30);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= -30 && rotation >= -150) {
	//		sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
	//	}
	//}
	//if (dir == 5) {
	//	if (rotation <= 60 && rotation >= -60 && rotation == 60) {
	//		sprite_2.setRotation(60);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= 60 && rotation >= -60 && rotation == -60) {
	//		sprite_2.setRotation(-60);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= 60 && rotation >= -60) {
	//		sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
	//	}
	//}


	//11111algorithm for rotation player's parts and player toward current direction with or without moving of player111111111111111111111111111111
	//if (dir == 4) {
	//	if (rotation <= -30 && rotation >= -150 && rotation == -150) {
	//		sprite_2.setRotation(-150);//������������ ������ �� ��� �������
	//		sprite.setRotation(-150);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= -30 && rotation >= -150 && rotation == -30) {
	//		sprite_2.setRotation(-30);//������������ ������ �� ��� �������
	//		sprite.setRotation(-30);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= -30 && rotation >= -150) {
	//		sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
	//		sprite.setRotation(rotation);//������������ ������ �� ��� �������
	//	}
	//}
	//if (dir == 5) {
	//	if (rotation <= 60 && rotation >= -60 && rotation == 60) {
	//		sprite_2.setRotation(60);//������������ ������ �� ��� �������
	//		sprite.setRotation(60);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= 60 && rotation >= -60 && rotation == -60) {
	//		sprite_2.setRotation(-60);//������������ ������ �� ��� �������
	//		sprite.setRotation(-60);//������������ ������ �� ��� �������
	//	}
	//	else if (rotation <= 60 && rotation >= -60) {
	//		sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
	//		sprite.setRotation(rotation);//������������ ������ �� ��� �������
	//	}
	//}


	//11111algorithm for rotation player's parts and player toward current direction with moving of player
	// and for rotation player's parts toward current direction withoout moving of player111111111111111111111111111111
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (rotation <= -30 && rotation >= -150 && rotation == -150) {
			sprite_2.setRotation(-150);//������������ ������ �� ��� �������
			sprite.setRotation(-150);//������������ ������ �� ��� �������
		}
		else if (rotation <= -30 && rotation >= -150 && rotation == -30) {
			sprite_2.setRotation(-30);//������������ ������ �� ��� �������
			sprite.setRotation(-30);//������������ ������ �� ��� �������
		}
		else if (rotation <= -30 && rotation >= -150) {
			sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
			sprite.setRotation(rotation);//������������ ������ �� ��� �������
		}
	}
	else if (dir == 4) {
		if (rotation <= -30 && rotation >= -150 && rotation == -150) {
			sprite_2.setRotation(-150);//������������ ������ �� ��� �������
			sprite.setRotation(-90);//������������ ������ �� ��� �������
		}
		else if (rotation <= -30 && rotation >= -150 && rotation == -30) {
			sprite_2.setRotation(-30);//������������ ������ �� ��� �������
			sprite.setRotation(-90);//������������ ������ �� ��� �������
		}
		else if (rotation <= -30 && rotation >= -150) {
			sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
			sprite.setRotation(-90);//������������ ������ �� ��� �������
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (rotation <= 60 && rotation >= -60 && rotation == 60) {
			sprite_2.setRotation(60);//������������ ������ �� ��� �������
			sprite.setRotation(rotation);//������������ ������ �� ��� �������
		}
		else if (rotation <= 60 && rotation >= -60 && rotation == -60) {
			sprite_2.setRotation(-60);//������������ ������ �� ��� �������
			sprite.setRotation(rotation);//������������ ������ �� ��� �������
		}
		else if (rotation <= 60 && rotation >= -60) {
			sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
			sprite.setRotation(rotation);//������������ ������ �� ��� �������
		}
	}
	else if (dir == 5) {
		if (rotation <= 60 && rotation >= -60 && rotation == 60) {
			sprite_2.setRotation(60);//������������ ������ �� ��� �������
			sprite.setRotation(0);//������������ ������ �� ��� �������
		}
		else if (rotation <= 60 && rotation >= -60 && rotation == -60) {
			sprite_2.setRotation(-60);//������������ ������ �� ��� �������
			sprite.setRotation(0);//������������ ������ �� ��� �������
		}
		else if (rotation <= 60 && rotation >= -60) {
			sprite_2.setRotation(rotation);//������������ ������ �� ��� �������
			sprite.setRotation(0);//������������ ������ �� ��� �������
		}
	}



	//algorithm for rotation player's parts and player around simultaneously
	//sprite_2.setRotation(rotation);
	//sprite.setRotation(rotation);
}