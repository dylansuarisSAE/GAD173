#include "example.h"
#include "Grid.h"

using namespace sf;
using namespace std;

Example::Example() : App(), horGrid(), verGrid()
{

}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	 normaltileTexture = kage::TextureManager::getTexture("data/brick.png");
	 greentileTexture = kage::TextureManager::getTexture("data/grass_1024.jpg");
	 browntileTexture = kage::TextureManager::getTexture("data/brick.png");


	
	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 6; x++)
		{
			int i = x + y * 6;

			if (map[i] == 1) 
			{
				tiles[i].setTexture(*normaltileTexture);
				;
			}

			if (map[i] == 2) 
			{
				tiles[i].setTexture(*greentileTexture);
				
			}

			if (map[i] == 3) 
			{
				tiles[i].setTexture(*browntileTexture);
				
			}
		}
	}
return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}

	if (ImGui::ImageButton(*normaltileTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 1;
	}
	if (ImGui::ImageButton(*greentileTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 2;
	}
	if (ImGui::ImageButton(*browntileTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 3;
	}

	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		int mouseonCellX = mousePosition.x / cellLength;  //width
		int mouseonCellY = mousePosition.y / cellHeight;

			int i = mouseonCellX + mouseonCellY * 5;

		if (chosenTileId == 1)
		{
			tiles[i].setTexture(*normaltileTexture);
			map[i] = 1;
		}

		if (chosenTileId == 2)
		{
			tiles[i].setTexture(*greentileTexture);
			map[i] = 2;
		}

		if (chosenTileId == 3)
		{
			tiles[i].setTexture(*browntileTexture);
			map[i] = 3;
		}
	}
	ImGui::End();
}

	




void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < 36; i++)
	{
		m_window.draw(tiles[i]);
	}

	horGrid.Render(m_window);
	verGrid.Render(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

