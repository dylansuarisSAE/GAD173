#include "Grid.h"

void Grid::Update()

{

}

void Grid::Draw()
{
}

Grid::Grid() 
{

for (size_t i = 0; i < horLine; i++)

	{
	x_line[i].setSize(sf::Vector2f(horLine_Length, lineWidth));
	x_line[i].setPosition(sf::Vector2f(Grid_Offset_x, Grid_Offset_y + i* cellLength));
	}
for (size_t i = 0; i < verLine; i++)
{
	y_line[i].setSize(sf::Vector2f(lineWidth, verLine_length));
	y_line[i].setPosition(sf::Vector2f(Grid_Offset_x + i * cellHeight, Grid_Offset_y ));
}
}



Grid::~Grid()
{


}

void Grid::Render(sf::RenderWindow & window)
{

	for (size_t i = 0; i < horLine; i++)
	{
		window.draw(x_line[i]);

	}
	for (size_t i = 0; i < verLine; i++)
	{
		window.draw(y_line[i]);
	}
}

