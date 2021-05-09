#pragma once
#include <SFML/Graphics.hpp>
#define horLine 7
#define verLine 7

#define horLine_Length 480
#define verLine_length 480

#define lineWidth 2
#define cellHeight 80

#define cellLength 80

#define Grid_Offset_x 600
#define Grid_Offset_y 180


class Grid
{
	void Update();
	void Draw();

public:
	Grid();
	~Grid();

	void Render(sf::RenderWindow& window);



	sf::RectangleShape x_line[horLine];
	sf::RectangleShape y_line[verLine];
};