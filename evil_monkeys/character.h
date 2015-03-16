#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"

class character : public sprite
{
public:
	character(draw_engine* de, int s_index, float x = 1, float y = 1, int i_lives = 3,
				char u='w',char d='s',char l='a',char r='d');

	virtual bool key_press(char c);

protected:
	char up_key, down_key, left_key, right_key;
};

#endif