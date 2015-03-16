#include "draw_engine.h"

#include <Windows.h>
#include <iostream>

using namespace std;

draw_engine::draw_engine(int xSize, int ySize)
{
	screen_width = xSize;
	screen_height = ySize;

	// set cursor visibility to false
	cursor_visibility(false);
}

draw_engine::~draw_engine()
{
	// set cursor visibility to true
	cursor_visibility(true);
}

int draw_engine::create_sprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		sprite_image[index] = c;
		return index;
	}
	return -1;
}

void draw_engine::delete_sprite(int index)
{
	// no need to implement this function
}

void draw_engine::draw_sprite(int index, int posx, int posy)
{
	// go to the correct location
	gotoxy(posx, posy);
	// print the correct sprite_image[index]
	cout << sprite_image[index];
}

void draw_engine::erase_sprite(int posx,int posy)
{
	gotoxy(posx, posy);
	cout << " ";
}

void draw_engine::gotoxy(int posx,int posy)
{
	HANDLE output_handle;

	COORD pos;
	pos.X = posx;
	pos.Y = posy;
	
	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output_handle, pos);
}

void draw_engine::cursor_visibility(bool visibility)
{
	HANDLE output_handle;
	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci_info;
	cci_info.bVisible = visibility;
	cci_info.dwSize = 50; // must be between 1 and 100 to work properly
	
	SetConsoleCursorInfo(output_handle, &cci_info);
}

