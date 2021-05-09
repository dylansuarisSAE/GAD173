#include "example.h"
#include "SaveLoad.h"
#include "map.h "
#include "SpriteAnimator.h"
#include "MainMenu.h"
#include "LevelOne.h"

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
	
	mapTile.LoadTexture();
	mapTile.LoadTile();
	mapTile.SetTilesFromMap();
	spriteAnimator.init();
	//spriteAnimator.Load(File name );
	sceneManager.Addscene(new MainMenu());
	sceneManager.Addscene(new LevelOne());
	sceneManager.Load();


	
	
return true;
}


void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && m_window.hasFocus())
	{
		sceneManager.Loadscene(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && m_window.hasFocus())
	{
		sceneManager.Loadscene(1);
	}

	ImGui::Begin("Kage2D");
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}
	if (ImGui::Button("Save"))
	{
		 SaveLoad::Save("bin/data/map.txt", mapTile.map, 6, 6);
	}
	if (ImGui::Button("Load"))
	{
		SaveLoad::Load("map.txt", mapTile.map, 36);
		
		mapTile.SetTilesFromMap();
	}

	if (ImGui::ImageButton(*mapTile.normaltileTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 1;
	}
	if (ImGui::ImageButton(*mapTile.greentileTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 2;
	}
	if (ImGui::ImageButton(*mapTile.browntileTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 3;
	}
	sceneManager.Update();
	

	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& mousePosition.x >= Grid_Offset_x && mousePosition.x <= Grid_Offset_x + cellLength * cell_count_x
		&& mousePosition.y >= Grid_Offset_y && mousePosition.y <= Grid_Offset_y + cellHeight * cell_count_y)
	{
		
		int mouseonCellX = (mousePosition.x - Grid_Offset_x) / cellLength;  //width
		int mouseonCellY = (mousePosition.y - Grid_Offset_y) / cellHeight;

		int i = mouseonCellX + mouseonCellY * cell_count_x;

		std::cout << i << std::endl;
		 
			

		if (chosenTileId == 1)
		{
			mapTile.textureTiles[i].setTexture(*mapTile.normaltileTexture);
			mapTile.map[i] = 1;
		}

		if (chosenTileId == 2)
		{
			mapTile.textureTiles[i].setTexture(*mapTile.greentileTexture);
			mapTile.map[i] = 2;
		}

		if (chosenTileId == 3)
		{
			mapTile.textureTiles[i].setTexture(*mapTile.browntileTexture);
			mapTile.map[i] = 3;
		}
	}
	ImGui::End();
}

	




void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < 36; i++)
	{
		m_window.draw(mapTile.textureTiles[i]);
	}

	horGrid.Render(m_window);
	verGrid.Render(m_window);
	sceneManager.Render(m_window);
	
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

