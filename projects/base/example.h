#pragma once

#include "app.h"
#include "Grid.h"
#include "map.h"
#include "SceneManager.h"

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

	sf::Sprite* m_backgroundSprite;

	int chosenTileId;

	SpriteAnimator spriteAnimator;
	SceneManager sceneManager;
	tileMap mapTile;
	Grid horGrid;
	Grid verGrid;
};
