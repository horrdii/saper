#include "Cell.h"

Cell::Cell( float SIZE ) {

	bombsText.setCharacterSize(SIZE);
	bombsText.setString(to_string(bombsAround));

	Color c(128, 128, 128);

	r.setFillColor(c);
	r.setOutlineColor(Color::Black);
	r.setOutlineThickness(3.f);
	r.setSize(Vector2f(SIZE, SIZE));

}

Cell::Cell( float SIZE, Vector2f pos) {

	bombsText.setPosition(pos.x + (SIZE-SIZE/2)/2, pos.y);
	bombsText.setCharacterSize(int(SIZE - 5));
	bombsText.setString( to_string( bombsAround ) );

	Color c(128, 128, 128);

	r.setFillColor(c);
	r.setOutlineColor(Color::Black);
	r.setOutlineThickness(3.f);
	r.setSize(Vector2f(SIZE, SIZE));

	r.setPosition(pos);

}


RectangleShape& Cell::getCell() {
	return r;
}

Text& Cell::getTextObj() {
	return bombsText;
}


void Cell::setBombsAround(int COUNT) {
	bombsAround = COUNT;

	bombsText.setString( to_string(COUNT) );
	bombsText.setFillColor(COUNT > 0 ? Color::Red : Color::Green);
}

String Cell::getBombsAround() {
	return to_string(bombsAround);
}


bool Cell::isBomb() {
	return bomb;
}

bool Cell::isOpen() {
	return open;
}

void Cell::setOpen() {
	open = true;
	r.setFillColor({ 196, 196, 196 });
}

void Cell::setBomb() {
	bomb = true;
	bombsText.setString('b');
}


void Cell::setPosition(Vector2f pos) {
	r.setPosition(pos);
	bombsText.setPosition(pos);
	return;
}

Vector2f Cell::getPosition() {
	return r.getPosition();
}