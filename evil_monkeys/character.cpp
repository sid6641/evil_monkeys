#include "character.h"

character::character(draw_engine* de, int s_index, float x, float y,
	int i_lives, char u, char d, char l, char r)
	: sprite(de, s_index, x, y, i_lives)
{
	up_key = u;
	down_key = d;
	left_key = l;
	right_key = r;

	classID = CHARACTER_CLASSID;
}

bool character::key_press(char c)
{
	if (c == up_key)
		return move(0, -1);
	else if (c == down_key)
		return move(0, 1);
	else if (c == left_key)
		return move(-1, 0);
	else if (c == right_key)
		return move(1, 0);
	
	return false;
}