#include "Aiko.h"

class ball :public object {
private:
	Aiko* engine;
public:
	float velocityX;
	float velocityY;
	ball(Aiko* e) {
		this->engine = e;
		velocityX = 1.0;
		velocityY = 0.0;
		body = new RectangleShape;
	};
	void start() {
		body->setSize(Vector2f(20, 20));
		body->setFillColor(Color::White);
		body->setPosition(Vector2f(600, 400));
	};
	void update() {
		body->move(-velocityX, velocityY);
	};
};

class paddle :public object {
private:
	Aiko* engine;
	int y;
public:
	paddle(Aiko* e) {
		engine = e;
		body = new RectangleShape;
		y = 100;
	};
	void start() {
		body->setSize(Vector2f(10, 60));
		body->setPosition(Vector2f(20, 100));
		body->setFillColor(Color::White);
	};
	void update() {
		y = engine->getMousePosition().y;
		if (y > 0 && y < 550) {
			body->setPosition(Vector2f(20, y));
		}
	};
};

class wall :public object {
	Aiko* engine;
	int x, y;
	int px, py;
public:
	wall(Aiko* e, int x, int y, int px, int py) {
		engine = e;
		this->x = x;
		this->y = y;
		this->px = px;
		this->py = py;
		body = new RectangleShape;
	}
	void start() {
		body->setSize(Vector2f(x, y));
		body->setPosition(px, py);
		body->setFillColor(Color::Red);
	}
	void update() {

	}
};

class game :public object {
private:
	Aiko* engine;
	paddle* Paddle;
	ball* Ball;
	wall* wall1;
	wall* wall2;
	wall* wall3;
public:
	game(Aiko* e) {
		engine = e;
		Paddle = new paddle(engine);
		Ball = new ball(engine);
		wall1 = new wall(engine,engine->windowX, 20, 0, 0);
		wall2 = new wall(engine, engine->windowX, 20, 0, engine->windowY - 20);
		wall3 = new wall(engine, 20, engine->windowY, engine->windowX - 20, 0);
	}
	void start() {
		engine->insertObject(Ball);
		engine->insertObject(Paddle);
		engine->insertObject(wall1);
		engine->insertObject(wall2);
		engine->insertObject(wall3);
	}
	void update() {
		if (engine->collision(Paddle->body, Ball->body)) {
			int paddleY = Paddle->body->getSize().y;
			paddleY /= 4;
			paddleY += Paddle->body->getPosition().y;
			if (Ball->body->getPosition().y <= paddleY) {
				Ball->velocityX *= -1;
				Ball->velocityY = -1;
			}
			else {
				Ball->velocityX *= -1;
				Ball->velocityY = 0;
			}
		}
		if (engine->collision(wall1->body, Ball->body)) Ball->velocityX *= -1;
		if (engine->collision(wall2->body, Ball->body)) Ball->velocityX *= -1;
		if (engine->collision(wall3->body, Ball->body)) Ball->velocityX *= -1;
	}
};