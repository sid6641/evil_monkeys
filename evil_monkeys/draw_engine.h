#ifndef DRAW_ENGINE_H
#define DRAW_ENGINE_H

class draw_engine
{
public:
	draw_engine(int xSize=30,int ySize=20);
	~draw_engine();

	int create_sprite(int index,char c); // return the index of the sprite, (-1) if not possible
	void delete_sprite(int index);

	void draw_sprite(int index,int posx,int posy); // 
	void erase_sprite(int posx, int posy); // draw ' ' char

private:
	void gotoxy(int x, int y);
	void cursor_visibility(bool visibility);

protected:
	char sprite_image[16];
	int screen_width;
	int screen_height;
};

#endif