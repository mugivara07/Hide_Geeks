#include <SFML/Graphics.hpp>
#include <iostream>


class Player {
private:
    float x, y;
    float CurrentFrame = 0;
public:
    float w, h, dx, dy ,speed = 0;
    int dir = 0;
    std::string file;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite sprite_2;
    Player(std::string F, int X, int Y, float W, float H) {
        file = F;
        x = X; y = Y; w =W; h = H;
        image.loadFromFile(file);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect (1480, 895, w, h));
        sprite.setOrigin(w/2, h/2);
        sprite_2.setTexture(texture);
        sprite_2.setTextureRect(sf::IntRect(1481, 904, w/2, h/4));
        sprite_2.setOrigin(w/4, w/8);
    }
    void Update(float time);
    float Get_Player_X();
    float Get_Player_Y();
    void Key_Input(float time);
    void Rotation(sf::Vector2f); // ������� �������� ������� � ������� ����������� �������.
};
