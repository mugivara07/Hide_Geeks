#include "Game.h"
#include "map.h"
#include "view.h"

#include <string>
#include <utility>
#include <iostream>

Game::Game() : _window(sf::VideoMode(1024, 768), "Hide and Geeks", sf::Style::Close) {}

void Game::run() {

	view.reset(sf::FloatRect(0, 0, 320, 240)); // Todo(Nikita) Create new class for camera and put it in

	Player player_1("hotline_sprites.png", 100, 100, 32, 32);

	sf::Clock clock; // Todo(Nikita) Create new class for time and put it in

	//!!!!!!!!!!!!!!!!!!!!!!!!!ћожно удалить (добавил функцию Rotation дл€ класса Player)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//float dX = 0;
	//float dY = 0;

	//float dX = pos.x - p.x;//
	//float dY = pos.y - p.y;//
	//float rotation = (atan2(dY, dX)) * 180 / 3.14159265;//
	//std::cout << rotation << "\n";//
	//p.sprite.setRotation(rotation);//


	// ***********Temporary map, dont touch it*****************

	sf::Image map_image;
	map_image.loadFromFile("map.png");
	sf::Texture map_texture;
	map_texture.loadFromImage(map_image);
	sf::Sprite map_sprite;
	map_sprite.setTexture(map_texture);

	// **********************************************************

	while (_window.isOpen()) {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);//определение координат курсора
		sf::Vector2f pos = _window.mapPixelToCoords(pixelPos);//перевод координат курсора в игровые

		float time = clock.getElapsedTime().asMicroseconds(); // Todo(Nikita) put in time class
		clock.restart(); // Todo(Nikita) put in time class
		time = time / 500; // Todo(Nikita) put in time class

		get_input(&player_1, time, pos);
		// update();

		GetViewCoordinate(player_1.Get_Player_X(), player_1.Get_Player_Y()); // Todo(Nikita) put in camera class
		_window.setView(view); // Todo(Nikita) put in camera class

		_window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++) {
			for (int j = 0; j < WIDTH_MAP; j++) {
				if (map[i][j] == '0') {
					map_sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
				}
				if (map[i][j] == ' ') {
					map_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
				}
				if (map[i][j] == 's') {
					map_sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
				}

				map_sprite.setPosition(j * 32, i * 32);

				_window.draw(map_sprite);
			}
		}

		_window.draw(player_1.sprite);
		_window.draw(player_1.sprite_2);
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
//void Game::render() { // Todo(Artem) Inmplement this function. Maybe you should create new class for drawing (player + map)
//    _window.clear();
//    _state_stack.draw();
//    _window.display();
//}
//
void Game::get_input(Player* player, float time, sf::Vector2f pos) {
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			_window.close();
		}
	}
	player->Rotation(pos);
	player->Key_Input(time);
	player->Update(time);
}
