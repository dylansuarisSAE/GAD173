#include "mapTile.h"
#include <iostream>



void mapTile::LoadTexture()
{
	normaltileTexture = kage::TextureManager::getTexture("data/red brick.png");
	greentileTexture = kage::TextureManager::getTexture("data/grass.png");
	browntileTexture = kage::TextureManager::getTexture("data/water.png");

}
void mapTile::SetTilesFromMap() {

	for (size_t y = 0; y < cell_count_y; y++)
	{
		for (size_t x = 0; x < cell_count_x; x++)
		{
			int i = x + y * cell_count_x;

			if (map[i] == 1)
			{
				textureTiles[i].setTexture(*normaltileTexture);
			}

			if (map[i] == 2)
			{
				textureTiles[i].setTexture(*greentileTexture);
			}

			if (map[i] == 3)
			{
				textureTiles[i].setTexture(*browntileTexture);
			}

			textureTiles[i].setPosition(sf::Vector2f(Grid_Offset_x + x * cellLength, Grid_Offset_y + y * cellHeight));
		}
		std::cout << "\n";
	}
}

void mapTile::LoadTile()
{


}

/*void Render(sf::RenderWindow& window) 
{
	for (size_t i = 0; i < 36; i++)
	{
		window.draw(Tile.textureTiles[i]);
	}
}*/