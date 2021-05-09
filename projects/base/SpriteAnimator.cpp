#include "SpriteAnimator.h"
#include "kage2dutil/texture_manager.h"

SpriteAnimator::SpriteAnimator() :
	spriteSheetTexture(nullptr)


{

};

SpriteAnimator::~SpriteAnimator() {

};

void SpriteAnimator::Load(std::string filename) 
{
	spriteSheetTexture = kage::TextureManager::getTexture(filename);
	spriteSheet.setTexture (*spriteSheetTexture);
	spriteSheet.setTextureRect(sf::IntRect(85, 85, 85, 85));
}

void SpriteAnimator::init() {

};

void SpriteAnimator::Render(sf::RenderWindow& window)
{
	window.draw(spriteSheet);
}

