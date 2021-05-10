#include "Level1.h"


Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::init()
{
}

void Level1::Load()
{
	ScenE::Load();

	Load::Loadlevel("map.txt", MapTile.map, 36);
	MapTile.LoadTexture();//loads textures
	//MapTile.LoadTile();//loads the tiles
	MapTile.SetTilesFromMap();//places tiles on grid
	std::cout << " " << std::endl;
	std::cout << "lvl 1 loaded" << std::endl;
	//return;
}

void Level1::update()
{
	ScenE::update();
	//std::cout << "lvl 1 updating" << std::endl;
}

void Level1::Render(sf::RenderWindow& window)
{

	ScenE::Render(window);
	//std::cout << "this is level 1 render " << std::endl;
	for (size_t i = 0; i < 36; i++)
	{
		window.draw(MapTile.textureTiles[i]);
	}
	//std::cout << "level 1 done rendering" << std::endl;
}