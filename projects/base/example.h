#pragma once

#include "app.h"
#include "Grid.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;
	sf::Texture* normaltileTexture;
	sf::Texture* greentileTexture;
	sf::Texture* browntileTexture;

	int chosenTileId;
	
	sf::Sprite tiles[36];

	int map[36] ={
		1,1,1,1,2,2,
		1,1,1,2,1,1,
		1,3,1,2,3,1,
		1,1,2,1,2,3,
		1,2,1,3,1,3,
		1,1,2,2,3,3,
	};


	Grid horGrid;
	Grid verGrid;
};
