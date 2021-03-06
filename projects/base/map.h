#pragma once

#include <SFML/Graphics.hpp>
#include <kage2dutil/texture_manager.h>
#include "Grid.h"

#define cell_count_x 6
#define cell_count_y 6


class tileMap
{
public:

	tileMap::tileMap() {

	}
	tileMap:: ~tileMap() {

	}

	void LoadTexture();
	void SetTilesFromMap();

	void LoadTile();

	sf::Texture* normaltileTexture;
	sf::Texture* greentileTexture;
	sf::Texture* browntileTexture;
	sf::Sprite textureTiles[36];

	int map[36] = {
		1, 1, 1, 1, 2, 2,
		1, 1, 1, 2, 1, 1,
		1, 3, 1, 2, 3, 1,
		1, 1, 2, 1, 2, 3,
		1, 2, 1, 3, 1, 3,
		1, 1, 2, 2, 3, 3

	};
};