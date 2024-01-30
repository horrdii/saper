#include "Classes/Field.h"
#include "Classes/startMenu.h"
#include "Classes/playerAccount.h"


float WINDOW_WIDTH = 600, WINDOW_HEIGHT = 800;

RenderWindow w;
Event event;

float CELL_SIZE = 20;
RectangleShape r;
Text t;

Field f(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE );
startMenu sm ( WINDOW_WIDTH, WINDOW_HEIGHT ) ;
playerAccount p;



int main() {

	w.create(sf::VideoMode(600, 800), "Saper");
	
	Font font;
	font.loadFromFile("fonts/arial.ttf");
	f.loadFont(font);
	sm.setTextFont(font);

	while (w.isOpen()) {

		while (w.pollEvent(event)) {
			switch (event.type) {
			case Event::Closed:
				w.close();
				break;
			case Event::MouseButtonPressed: {
				if (!sm.isMenu()) {
					Vector2i mPos = Mouse::getPosition(w);
					f.openCell(mPos, event.mouseButton.button == sf::Mouse::Right ? 'r' : 'l');
				}
				break;
			}
			case Event::TextEntered:
				if (sm.isMenu())
					sm.getSymbol((char)event.text.unicode);
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Enter) {

					if ( sm.isMenu() || f.hasLose() || f.hasWin() )
						p.create(sm.getNick());

				}
				break;
			}
		}

		if (sm.isMenu()) {

			w.draw(sm.getMenuField());
			w.draw(sm.getTitleText());
			w.draw(sm.getInputText());

		}
		else {

			if (f.hasLose())
				cout << "LOOOOOOOSEEEEEEERRRRR" << endl;

			if (f.hasWin())
				cout << "WIIIIIINNNNNNNNEEEERRRRR" << endl;

			auto fv = f.getField();
			for (auto& i : fv) {
				for (auto& j : i) {

					r = j.getCell();

					w.draw(r);

					if (j.isOpen()) {
						w.draw(j.getTextObj());
					}

				}
			}

		}

		w.display();
	}

	p.setRecord( f.getScore() );

}