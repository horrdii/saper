#pragma once
#include "Cell.h"

class Field
{
protected:
	vector < vector <Cell> > f;

	float WINDOW_WIDTH, WINDOW_HEIGHT;
	float CELL_SIZE;

	bool win = false, lose = false;
	bool firstClick = true;

	int totalBombsCount;

	int score;

public:

	Field(float WINDOW_WIDTH, float WINDOW_HEIGHT, float CELL_SIZE);

	vector < vector <Cell> > getField();

	void loadFont(const Font& font);
	void openCell(Vector2i mousePos, char MouseButton);

	int getScore();

	bool hasLose();
	bool hasWin();

};

