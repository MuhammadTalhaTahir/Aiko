#include "Aiko.h"

Aiko::Aiko():windowX(1024),windowY(576) {
	background = new RectangleShape[3];
	window = new RenderWindow(VideoMode(windowX, windowY), "Aiko Test Window");
	events = new Event;
	loadIntro();
}

void Aiko::catchEvents() {
	while (window->pollEvent(*events)) {
		if (events->type == Event::Closed) {
			window->close();
		}
		if (events->type == Event::MouseButtonPressed) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				mouseInputLeft.enqueue("Left");
			}
			else if (Mouse::isButtonPressed(Mouse::Right)) {
				mouseInputRight.enqueue("Right");
			}
		}
		if (events->type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				keyBoardInputW.enqueue("W");
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				keyBoardInputA.enqueue("A");
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				keyBoardInputS.enqueue("S");
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				keyBoardInputD.enqueue("D");
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				keyBoardInputSpace.enqueue("Space");
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				keyBoardInputEnter.enqueue("Enter");
			}
		}
	}
}
void Aiko::loadIntro() {
	Texture arry[3];
	string file = "intro\\intro1.png";
	char num = 48;
	for (int i = 0; i < 3; i++) {
		num += 1;
		file[11] = num;
		arry[i].loadFromFile(file);
		background[i].setTexture(&arry[i]);
		background[i].setPosition(0, 0);
		//background[i].setScale(100, 100);
		background[i].setSize(Vector2f(20, 20));
	}
	/*background[2].setSize(Vector2f(windowX-10, windowY-10));
	background[2].setPosition(0, 0);
	background[2].setFillColor(Color::Blue);*/
}
void Aiko::runIntro() {

}
void Aiko::Run() {
	while (window->isOpen()) {
		catchEvents();
		window->clear(Color::Green);
		window->draw(background[0]);
		aikoObjects.updateObjects(window);
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
	if (temp == "Left") {
		if (mouseInputLeft.isEmpty())return false;
		else {
			mouseInputLeft.dequeue();
			return true;
		}
	}
	else if (temp == "Right") {
		if (mouseInputRight.isEmpty())return false;
		else {
			mouseInputRight.dequeue();
			return true;
		}
	}
	else return false;
}
bool Aiko::keyBoardButtonPressed(string temp) {
	if (temp == "W") {
		if (keyBoardInputW.isEmpty())return false;
		else {
			keyBoardInputW.dequeue();
			return true;
		}
	}
	else if (temp == "A") {
		if (keyBoardInputA.isEmpty())return false;
		else {
			keyBoardInputA.dequeue();
			return true;
		}
	}
	else if (temp == "S") {
		if (keyBoardInputS.isEmpty())return false;
		else {
			keyBoardInputS.dequeue();
			return true;
		}
	}
	else if (temp == "D") {
		if (keyBoardInputD.isEmpty())return false;
		else {
			keyBoardInputD.dequeue();
			return true;
		}
	}
	else if (temp == "Space") {
		if (keyBoardInputSpace.isEmpty())return false;
		else {
			keyBoardInputSpace.dequeue();
			return true;
		}
	}
	else if (temp == "Enter") {
		if (keyBoardInputEnter.isEmpty())return false;
		else {
			keyBoardInputEnter.dequeue();
			return true;
		}
	}
	else return false;
}

Vector2i Aiko::getMousePosition() {
	return Mouse::getPosition(*window);
}
bool Aiko::isCursorOverObject(RectangleShape* obj) {
	int x = obj->getPosition().x;
	int y = obj->getPosition().y;
	int mx = getMousePosition().x;
	int my = getMousePosition().y;
	if (mx >= x && my >= y) {
		if (mx <= x + obj->getSize().x && my <= y + obj->getSize().y)return true;
		else return false;
	}
	else return false;
}