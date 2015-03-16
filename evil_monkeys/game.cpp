#include "game.h"

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

#define GAME_SPEED 33.3333 // 1000/30

bool game::run(void)
{
	draw_area.create_sprite(0, '$');

	player = new character(&draw_area, 0);

	char key = ' ';

	frame_count = 0;
	end_time = 0;
	start_time = timeGetTime();

	while (key != 'q') // play the game
	{
		while (get_input(&key) == false) // no input from the user
		{
			// call timer_update()
			timer_update();
		}
		player->key_press(key);
	   //cout << "here is what u pressed : " << key << endl;
	}
	cout << "END OF GAME" << endl << endl;

	// print some stats
	run_time = timeGetTime() - start_time;
	//cout << "milliseconds elapsed  :  " << run_time << endl;
	//cout << "frame_count  =  " << frame_count << endl;
	cout << "frames_per_second  :  " << frame_count / (run_time / 1000) << endl;
	
	return true;
}

bool game::get_input(char* c) // returns true when key is hit, else false
{
	if (_kbhit()) // if key is hit, store it in *c
	{
		*c = _getch();
		return true;
	}
	return false;
}

void game::timer_update(void) // controls the game speed (30 fps)
{
	double current_time = timeGetTime() - end_time;
	if (current_time < GAME_SPEED)
		return;

	frame_count++;
	end_time = timeGetTime();
}