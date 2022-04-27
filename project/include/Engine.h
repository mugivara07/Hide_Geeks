#pragma once
#include <SFML/Graphics.hpp>

#include "dude.h";

using namespace sf;

class Engine
{
private:

    RenderWindow m_Window;

    // ��������� ������ � �������� ��� ����
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;

    // ��������� ����
    Bob m_Bob;

    void input();
    void update(float dtAsSeconds);
    void draw();

public:
    // ����������� ������
    Engine();

    // ������� ����� ������� ��� ��������� �������
    void start();

};