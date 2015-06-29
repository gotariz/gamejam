#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "general.h"
#include "system/GameData.h"
#include "scene/Camera.h"

class Level
{
	public:
		Level(){}
		~Level(){}

	public:
		void init();
		void draw();
		Vector2 CartToScreen(b2Vec2 point);

	public:
		Cell cells[10][10];
		int level_width = 20;
		int level_height = 20;


};

#endif // LEVEL_H_INCLUDED

