#include "Engine.h"

Engine::Engine()
{
	// �������� ���������� ������, ������� ���� SFML � View
	/*Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode(.width);
	resolution.y = VideoMode::getDesktopMode(.height);*/

	m_Window.create(VideoMode(1000, 1000), "Simple Game Engine");

	// ��������� ��� � ��������
	// ����������� ����������� ��� ��� ������ ������ � ���������
	m_BackgroundTexture.loadFromFile("back.jpg");

	// ��������� ������ � ��������
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

void Engine::start()
{
	// ������ �������
	Clock clock;

	while (m_Window.isOpen())
	{
		// ������������� ������ � ���������� ���������� ����� � dt
		Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}