#include "Aiko.h"

class ball :public object {
private:
	Aiko* engine;
	float velocity;
public:
	ball(Aiko* e) {
		this->engine = e;
		velocity = 0.0;
		body = new RectangleShape;
	};
	void start() {
		body->setSize(Vector2f(20, 20));
		body->setFillColor(Color::White);
		body->setPosition(Vector2f(engine->windowX / 2, engine->windowY / 2));
	};
	void update() {
		if (body->getPosition().x > engine->windowX || body->getPosition().x < 0)
			velocity *= -1;
		body->move(-velocity * 0.01, 0);
		velocity += 0.1;
	};
};

class paddle :public object {
private:
	Aiko* engine;
	ball* b;
public:
	paddle(Aiko* e) {
		engine = e;
		body = new RectangleShape;
		b = new ball(e);
	};
	void start() {
		body->setSize(Vector2f(10, 60));
		body->setPosition(Vector2f(20, 20));
		body->setFillColor(Color::White);
		engine->insertObject(b);
	};
	void update() {
		if (engine->keyBoardButtonPressed("W")) {
			if (body->getPosition().y > 0)body->move(0, -10);
		}
		else if (engine->keyBoardButtonPressed("S")) {
			if (body->getPosition().y < 550)body->move(0, 10);
		}
		if (engine->collision(this->body, b->body)) {
			cout << "Hit..@!" << endl;
		}
	};
};