#include "Engine.h"

void Engine::draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(Color::Black);

    // Отрисовываем фон
    m_Window.draw(m_BackgroundSprite);
    // И Боба
    m_Window.draw(m_Bob.getSprite());

    // Отображаем все, что нарисовали
    m_Window.display();
}