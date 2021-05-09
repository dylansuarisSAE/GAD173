#pragma once
#include <string>
#include<SFML/Graphics.hpp>

class SpriteAnimator
{
private:
	sf::Sprite spriteSheet;
	sf::Texture* spriteSheetTexture;
	



public:
	SpriteAnimator();
	~SpriteAnimator();

	void  init();
	void Load(std::string filename);
	void update();
	void Render(sf::RenderWindow& window);
};


