#include "Engine.h"
#include "dude.h"

void Engine::input()
{
    // Обрабатываем нажатие Escape
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }

    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Bob.getSprite().setTextureRect(IntRect(95, 95, 80, 80));
        m_Bob.moveLeft();
    }
    else
    {
        m_Bob.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Bob.moveRight();
    }
    else
    {
        m_Bob.stopRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        m_Bob.moveUp();
    }
    else
    {
        m_Bob.stopUp();
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        m_Bob.moveDown();
    }
    else
    {
        m_Bob.stopDown();
    }
}