#ifndef LEVEL_H
#define LEVEL_H

#include "draw_engine.h"
#include "character.h"

class level
{
public:
	level(draw_engine* de,);

	void create_level(int width = 30, int height = 20);
	void add_player();
	void draw();
	void key_press();
	void update(void);

protected:
	int width, height;
	draw_engine* draw_area;
	character* player;
	level* Level;

private:
};

#endif
