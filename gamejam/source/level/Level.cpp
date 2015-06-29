#include "Level.h"

Vector2 Level::CartToScreen(b2Vec2 point)
{
	Vector2 pos = gdata.toPixels(point.x, point.y);
	pos.x -= gdata.camera->getScreenX();
	pos.y -= gdata.camera->getScreenY();
	return pos;
}

void Level::init()
{
	int row = 0; 
	for (int i = 0; i < 10; ++i)
	{
		int col = 0;
		for (int j = 0; j < 10; ++j)
		{
			cells[i][j] = Cell(row,col,false);
			++col;
		}
		++row;
	}

	cells[0][7].occupied = true;
	cells[3][3].occupied = true;
	cells[4][5].occupied = true;
	cells[5][1].occupied = true;
	cells[7][4].occupied = true;
	cells[9][8].occupied = true;

}

void Level::draw()
{
	int r = 255;
	int g = 255;
	int b = 255;
	int a = 255;

	for (int i = 0; i < 10; ++i)
	{
		int col = 0;
		for (int j = 0; j < 10; ++j)
		{
			Cell& cell = cells[i][j];

			Vector2 p1 = CartToScreen(b2Vec2(cell.row, cell.col));
			Vector2 p2 = CartToScreen(b2Vec2(cell.row + 1, cell.col + 1));
			if (cell.occupied)
			{
				//SDL_RenderFillRect(gdata.renderer, &r);
				Sint16 x[] = { p1.x, p2.x, p2.x, p1.x };
				Sint16 y[] = { p1.y, p1.y, p2.y, p2.y };
				filledPolygonRGBA(gdata.renderer, x, y, 4, 255, 0, 0, 64);
				rectangleRGBA(gdata.renderer, p1.x, p1.y, p2.x, p2.y, 255, 0, 0, 255);
			}
			else
			{
				rectangleRGBA(gdata.renderer, p1.x, p1.y, p2.x, p2.y, r, g, b, a);
			}
		}
	}

	SDL_SetRenderDrawColor(gdata.renderer, 0, 0, 0, 255);
}
