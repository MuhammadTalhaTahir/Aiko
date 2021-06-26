#include "Aiko.h"

Aiko::Aiko() {
	window = new RenderWindow(VideoMode(1024, 576), "Aiko Test Window");
	events = new Event;
}

void Aiko::catchEvents() {
	while (window->pollEvent(*events)) {
		if (events->type == Event::Closed) {
			window->close();
		}
	}
}

void Aiko::Run() {
	while (window->isOpen()) {
		catchEvents();
		window->clear(Color::Blue);
		aikoObjects.updateObjects();
		window->display();
	}
}

void Aiko::insertObject(object* temp) {
	aikoObjects.insert(temp);
	temp->start();
}
void Aiko::deleteObject(object* temp) {
	aikoObjects.remove(temp);
}

RenderWindow* Aiko::win() {
	return window;
}