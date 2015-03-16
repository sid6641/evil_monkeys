#ifndef GAME_H
#define GAME_H

#include "draw_engine.h"
#include "character.h"

class game
{
public:
	bool run(void);

protected:
	bool get_input(char*c);
	void timer_update(void);

private:
	double frame_count;
	double start_time, run_time, end_time;
	
	draw_engine draw_area;
	character* player;
};

#endif