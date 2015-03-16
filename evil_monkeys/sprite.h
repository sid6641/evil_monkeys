#ifndef SPRITE_H
#define SPRITE_H

#include "draw_engine.h"

struct vector
{
	float x, y;
};
enum
{
	SPRITE_CLASSID,
	CHARACTER_CLASSID,
};

class sprite
{
public:
	sprite(draw_engine* de, int s_index, float x=1, float y=1, int i_lives=1);
	~sprite();

	// position accessor functions
	vector get_position(void);
	float get_x(void);
	float get_y(void);

	// life related functions
	virtual void add_lives(int num=1);
	int get_lives(void);
	bool is_alive(void);

	virtual bool move(float x, float y); // is it moves then return true

protected:
	draw_engine* draw_area; // not an instance (draw_engine is always going to live in game class)
	vector pos;
	int sprite_index;
	int num_lives;
	int classID;
	vector facing_direction;

	void idle_update(void);
	void draw(float x, float y);
	void erase(float x, float y);

};

#endif