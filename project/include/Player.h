#include <SFML/Graphics.hpp>
#include <iostream>


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
        image.loadFromFile(file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect (1188, 936, w, h));
        sprite.setOrigin(w/2, h/2);
    }
    void Update(float time);
    float Get_Player_X();
    float Get_Player_Y();
    void  Key_Input();
};
