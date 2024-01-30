#pragma once
#include "Dependencies.h"

class Cell
{
protected:
	RectangleShape r;
	float SIZE;

	int bombsAround;
	

	bool open = false;
	bool bomb = false;

	Text bombsText;

public:

	Cell( float SIZE);
	Cell( float SIZE, Vector2f pos);

	RectangleShape& getCell();
	Text& getTextObj();

	void setBombsAround(int COUNT);
	String getBombsAround();

	bool isBomb();
	bool isOpen();

	void setOpen();
	void setBomb();

	void setPosition(Vector2f pos);
	Vector2f getPosition();
};

