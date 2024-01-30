#pragma once

#include "Dependencies.h"
#include "playerAccount.h"

class startMenu
{
protected:
	
	RectangleShape menuField;
	Text mainMenuText;
	Text inputTextMenu;

	int WINDOW_WIDTH, WINDOW_HEIGHT;

	string nickname;

	bool menu = true;

public:

	startMenu(int WINDOW_WIDTH, int WINDOW_HEIGHT);

	bool isMenu();

	RectangleShape& getMenuField();
	Text& getTitleText();
	Text& getInputText();

	void setTextFont(const Font& f);

	void getSymbol(char symbol);
	string getNick();

};

