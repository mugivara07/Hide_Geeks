#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bob
{
    // ��� private ���������� ����� ���� �������� ������ ������ �������
private:

    // ������� ����
    Vector2f m_Position;

    // ��������� ������ Sprite
    Sprite m_Sprite;

    // ��������� ��������
    Texture m_Texture;

    // ���������� ���������� ��� ������������ ����������� ��������
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;

    // �������� ���� � �������� � �������
    float m_Speed;

    // �������� ������
public:

    // ����������� ���� � ������������
    Bob();

    // ��� �������� ������� � ������� �������
    Sprite getSprite();

    // ��� �������� ����
    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();
    // ����������� ��������
    void stopLeft();

    void stopRight();

    void stopUp();

    void stopDown();
    // ��� ������� ����� ���������� �� ������ ����
    void update(float elapsedTime);

};