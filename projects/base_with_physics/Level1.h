#pragma once
#include "ScenE.h"
#include "mapTile.h"
#include "Grid.h"
#include "Load.h"

class Level1 : public ScenE
{
public:
	Level1();
	~Level1();


	void init() override;
	void Load() override;
	void update() override;
	void Render(sf::RenderWindow& window) override;


	int chosenTileId;

	mapTile MapTile;
	

	Grid horGrid;
	Grid verGrid;

};

