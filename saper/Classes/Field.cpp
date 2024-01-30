#include "Field.h"

Field::Field(float WW, float WH, float CS) {

	CELL_SIZE = CS;
	WINDOW_WIDTH = WW;
	WINDOW_HEIGHT = WH;

	totalBombsCount = 0;

	for (int i = 0; i < int(WINDOW_WIDTH / CELL_SIZE); i++) {

		f.push_back({});

		for (int j = 0; j < int(WINDOW_HEIGHT / CELL_SIZE);  j++) {

			Cell c ( CELL_SIZE, Vector2f( i * CELL_SIZE , j * CELL_SIZE ));

			if (rand() % 5 == 0) {
				c.setBomb();
				totalBombsCount++;
			}

			f[i].push_back(c);

		}
	}

	int count = 0;

	for (int i = 0; i < int(WINDOW_WIDTH / CELL_SIZE); i++) {
		for (int j = 0; j < int(WINDOW_HEIGHT / CELL_SIZE); j++) {
			
			if (f[i][j].isBomb())
				continue;

			if (i - 1 > -1) {
				count = f[i - 1][j].isBomb() ? count + 1 : count;

				if(j - 1 > -1)
					count = f[i - 1][j - 1].isBomb() ? count + 1 : count;
				if (j + 1 < int(WINDOW_HEIGHT / CELL_SIZE))
					count = f[i - 1][j + 1].isBomb() ? count + 1 : count;

			}

			if (i + 1 < int(WINDOW_WIDTH / CELL_SIZE)) {

				count = f[i + 1][j].isBomb() ? count + 1 : count;

				if (j - 1 > -1)
					count = f[i + 1][j - 1].isBomb() ? count + 1 : count;
				if (j + 1 < int(WINDOW_HEIGHT / CELL_SIZE))
					count = f[i + 1][j + 1].isBomb() ? count + 1 : count;

			}

			if (j - 1 > -1)
				count = f[i][j - 1].isBomb() ? count + 1 : count;
			
			if (j + 1 < int(WINDOW_HEIGHT / CELL_SIZE))
				count = f[i][j + 1].isBomb() ? count + 1 : count;

			f[i][j].setBombsAround(count);
			count = 0;

		}
	}

}


vector < vector <Cell> > Field::getField() {
	return f;
}


void Field::loadFont(const Font& font) {
	for (auto& i : f) {
		for (auto& j : i) {

			j.getTextObj().setFont(font);

		}
	}
}


void Field::openCell(Vector2i mousePos, char mouseButton) {

	int x = mousePos.x / CELL_SIZE;
	int y = mousePos.y / CELL_SIZE;

	Cell& c = f[ x ][ int( mousePos.y / CELL_SIZE ) ];

	cout << x << ' ' << y << endl;

	if (firstClick) {
		firstClick = false;

		for (int i = x + rand() % 8 + 3; i > x - rand() % 8; i--) {
			for (int j = y + rand() % 8 + 3; j > y - rand() % 8; j--) {
				
				if (i > -1 && j > -1 && i < (WINDOW_WIDTH / CELL_SIZE) && j < (WINDOW_HEIGHT / CELL_SIZE)) {
					cout << i << ' ' << j << endl;
					f[i][j].setOpen();
				}

			}
		}

		return;

	}

	if (c.isOpen())
		return;

	c.setOpen();

	if (c.isBomb()) {

		if (mouseButton == 'r') {
			score++;
			return;
		}

		lose = true;

	}

}


int Field::getScore() {
	return score;
}


bool Field::hasLose() {
	return lose;
}

bool Field::hasWin() {
	return win;
}