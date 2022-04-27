#include "dude.h"

Bob::Bob()
{
    // ��������� � ���������� �������� ����
    m_Speed = 400;

    // ��������� �������� � ������
    m_Texture.loadFromFile("chel1.png");
    m_Sprite.setTexture(m_Texture);

    // ������������� ��������� ������� ���� � ��������
    m_Position.x = 300;
    m_Position.y = 300;

    m_Sprite.setTextureRect(IntRect(95, 0, 80, 80));
    // m_Sprite.setTextureRect(IntRect(0, 0, 500, 380));
}

// ������ ��������� ������ ��������� ��� ������� draw()
Sprite Bob::getSprite()
{
    return m_Sprite;
}

void Bob::moveLeft()
{
    m_LeftPressed = true;
}

void Bob::moveRight()
{
    m_RightPressed = true;
}

void Bob::moveUp()
{
    m_UpPressed = true;
}

void Bob::moveDown()
{
    m_DownPressed = true;
}

void Bob::stopLeft()
{
    m_LeftPressed = false;
}

void Bob::stopRight()
{
    m_RightPressed = false;
}

void Bob::stopDown()
{
    m_DownPressed = false;
}

void Bob::stopUp()
{
    m_UpPressed = false;
}
// ������� ���� �� ��������� ����������������� ����� � ���� �����,
// ���������� ������� � ��������
void Bob::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }

    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }
    
    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    // ������ �������� ������ �� ����� �������
    m_Sprite.setPosition(m_Position);

}