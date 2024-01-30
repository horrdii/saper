#include "startMenu.h"



startMenu::startMenu(int WINDOW_WIDTH, int WINDOW_HEIGHT) {

	WINDOW_WIDTH = WINDOW_WIDTH;
	WINDOW_HEIGHT = WINDOW_HEIGHT;

	
	menuField.setSize( Vector2f( WINDOW_WIDTH, WINDOW_HEIGHT ) );
	menuField.setFillColor({255, 193, 203});
	menuField.setPosition(0, 0);

	mainMenuText.setString( "Enter your nickname" );
	mainMenuText.setCharacterSize(int(WINDOW_WIDTH / 15));
	mainMenuText.setFillColor(Color::Magenta);

	inputTextMenu.setString("");
	inputTextMenu.setCharacterSize(int(WINDOW_WIDTH / 15));
	inputTextMenu.setFillColor(Color::Magenta);

	nickname = "";
}


bool startMenu::isMenu() {
	return menu;
}


RectangleShape& startMenu::getMenuField() {
	return menuField;
}

Text& startMenu::getTitleText() {
	return mainMenuText;
}

Text& startMenu::getInputText() {
	return inputTextMenu;
}


void startMenu::setTextFont(const Font& f) {
	mainMenuText.setFont(f);
	inputTextMenu.setFont(f);

	mainMenuText.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT + 100));
	inputTextMenu.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT + 160));
}


void startMenu::getSymbol(char symbol) {

	if ((int)symbol > 64 && (int)symbol < 123) {
		nickname += symbol;
		inputTextMenu.setString(nickname);
		return;
	}

	if ((int)symbol == 8 && !nickname.length() == 0) {
		nickname = nickname.substr(0, nickname.length() - 1);
		inputTextMenu.setString(nickname);
		return;
	}

	if ((int)symbol == 13) {
		menu = false;
		return;
	}

}

string startMenu::getNick() {
	return nickname;
}