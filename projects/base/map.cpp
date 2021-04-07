#include "map.h"
#include <iostream>


void tileMap::LoadTexture()
{
	normaltileTexture = kage::TextureManager::getTexture("data/red brick.png");
	greentileTexture = kage::TextureManager::getTexture("data/grass.png");
	browntileTexture = kage::TextureManager::getTexture("data/water.png");

}

void tileMap::LoadTile()
{
	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 6; x++)
		{
			int i = x + y * 6;

			if (map[i]==1)
			{
				textureTiles[i].setTexture(*normaltileTexture);
				;
			}

			if (map[i]==2)
			{
				textureTiles[i].setTexture(*greentileTexture);

			}

			if (map[i]==3)
			{
				textureTiles[i].setTexture(*browntileTexture);

			}
			textureTiles[i].setPosition(sf::Vector2f(600 + x * cellLength, 180 + y * cellHeight));
		}
		std::cout << "/n";
	}

}