#include <SFML/Graphics.hpp>

sf::View view; // Todo(Nikita) put this all in class + create .cpp file for function's description

sf::View GetViewCoordinate(float x, float y) {
    float temp_x = x;
    float temp_y = y;

    if (temp_x < 176) {
        temp_x = 176;
    }
    if (temp_x > 1104) {
        temp_x = 1104;
    }
    if (temp_y < 136) {
        temp_y = 136;
    }
    if (temp_y > 664) {
        temp_y = 664;
    }

    view.setCenter(temp_x, temp_y);
    return view;
}