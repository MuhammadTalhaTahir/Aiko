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
		if (events->type == Event::MouseButtonPressed) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				mouseInput.enqueue("Left");
			}
			else if (Mouse::isButtonPressed(Mouse::Right)) {
				mouseInput.enqueue("Right");
			}
		}
		if (events->type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				keyBoardInput.enqueue("W");
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				keyBoardInput.enqueue("A");
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				keyBoardInput.enqueue("S");
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				keyBoardInput.enqueue("D");
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				keyBoardInput.enqueue("Space");
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				keyBoardInput.enqueue("Enter");
			}
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

bool Aiko::mouseButtonPressed(string temp) {
	if (!mouseInput.isEmpty()) {
		if (mouseInput.getTop() == temp) {
			mouseInput.dequeue();
			return true;
		}
		else return false;
	}
	else return false;
}
bool Aiko::keyBoardButtonPressed(string temp) {
	if (!keyBoardInput.isEmpty()) {
		if (keyBoardInput.getTop() == temp) {
			keyBoardInput.dequeue();
			return true;
		}
		else return false;
	}
	else return false;
}