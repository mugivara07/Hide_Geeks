#include <SFML/Graphics.hpp>

sf::View view;

sf::View GetViewCoordinate(float x, float y) {
    float temp_x = x;
    float temp_y = y;

    if (temp_x < 320) {
        temp_x = 320;
    }
    if (temp_y < 240) {
        temp_y = 240;
    }
    if (temp_y > 554) {
        temp_y = 554;
    }

    view.setCenter(temp_x, temp_y);
    return view;
}