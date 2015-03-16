#include "sprite.h"

sprite::sprite(draw_engine* de, int s_index, float x, float y, int i_lives)
{
	draw_area = de;
	sprite_index = s_index;

	pos.x = x;
	pos.y = y;
	num_lives = i_lives;

	facing_direction.x = 1;
	facing_direction.y = 0;

	classID = SPRITE_CLASSID;
}

sprite::~sprite()
{
	// erase the sprite
	erase(pos.x, pos.y);
}

// position accesors
vector sprite::get_position()
{
	return pos;
}
float sprite::get_x()
{
	return pos.x;
}
float sprite::get_y()
{
	return pos.y;
}

// life related functions
void sprite::add_lives(int num)
{
	num_lives += num;
}
int sprite::get_lives()
{
	return num_lives;
}
bool sprite::is_alive()
{
	if (num_lives > 0)
		return true;

	return false;
}

bool sprite::move(float x, float y)
{
	// erase the sprite
	erase(pos.x, pos.y);

	pos.x += x;
	pos.y += y;

	facing_direction.x = x;
	facing_direction.y = y;
	
	// draw the sprite
	draw(pos.x, pos.y);

	return true; 
}

void sprite::draw(float x, float y)
{
	draw_area->draw_sprite(sprite_index, (int)x, (int)y);
}
void sprite::erase(float x, float y)
{
	draw_area->erase_sprite((int)x, (int)y);
}

void sprite::idle_update(void)
{
	// no need to implement it right now
	// will be used during fireball and enemy class
}