#include "Aiko.h"

class ball :public object {
private:
	Aiko* engine;
public:
	float velocityX;
	float velocityY;
	ball(Aiko* e) {
		this->engine = e;
		velocityX = -200.0;
		velocityY = 200.0;
		body = new RectangleShape;
	};
	void start() {
		body->setSize(Vector2f(20, 20));
		body->setFillColor(Color::White);
		body->setPosition(Vector2f(400, 200));
	};
	void update() {
		body->move(velocityX * engine->deltaTime.asSeconds(), velocityY * engine->deltaTime.asSeconds());
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
		body->setSize(Vector2f(10, 100));
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
class paddle2 :public object {
private:
	Aiko* engine;
public:
	paddle2(Aiko* e) {
		engine = e;
		body = new RectangleShape;
	};
	void start() {
		body->setSize(Vector2f(10, 100));
		body->setPosition(Vector2f(engine->windowX - 30, 100));
		body->setFillColor(Color::White);
	};
	void update() {
		if (engine->keyBoardButtonPressed("W")) {
			body->move(0, -20);
		}
		if (engine->keyBoardButtonPressed("S")) {
			body->move(0, 20);
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
	paddle2* Paddle2;
	ball* Ball;
	wall* wall1;
	wall* wall2;
	float ballSpeed;
public:
	game(Aiko* e) {
		engine = e;
		Paddle = new paddle(engine);
		Paddle2 = new paddle2(engine);
		Ball = new ball(engine);
		wall1 = new wall(engine,engine->windowX, 20, 0, 0);
		wall2 = new wall(engine, engine->windowX, 20, 0, engine->windowY - 20);
		ballSpeed = 300;
	}
	void start() {
		engine->insertObject(Ball);
		engine->insertObject(Paddle);
		engine->insertObject(Paddle2);
		engine->insertObject(wall1);
		engine->insertObject(wall2);
	}
	void update() {
		if (engine->collision(Paddle->body, Ball->body)) {
			int paddleY = Paddle->body->getSize().y;
			paddleY /= 3;
			int oneBy = paddleY + Paddle->body->getPosition().y; 
			int threeBy = oneBy + paddleY;
			if (Ball->body->getPosition().y <= oneBy) {
				Ball->velocityX = ballSpeed;
				Ball->velocityY = -ballSpeed;
			}
			else if (Ball->body->getPosition().y > oneBy && Ball->body->getPosition().y < threeBy) {
				Ball->velocityX = ballSpeed;
				Ball->velocityY = 0;
			}
			else if (Ball->body->getPosition().y >= threeBy) {
				Ball->velocityX = ballSpeed;
				Ball->velocityY = +ballSpeed;
			}
		}
		else if (engine->collision(wall1->body, Ball->body)) {
			Ball->velocityY = +200;
		}
		else if (engine->collision(wall2->body, Ball->body)) {
			Ball->velocityY = -200;
		}
		else if (engine->collision(Paddle2->body, Ball->body)) {
			int paddleY = Paddle2->body->getSize().y;
			paddleY /= 3;
			int oneBy = paddleY + Paddle2->body->getPosition().y;
			int threeBy = oneBy + paddleY;
			if (Ball->body->getPosition().y <= oneBy) {
				Ball->velocityX = -ballSpeed;
				Ball->velocityY = -ballSpeed;
			}
			else if (Ball->body->getPosition().y > oneBy && Ball->body->getPosition().y < threeBy) {
				Ball->velocityX = -ballSpeed;
				Ball->velocityY = 0;
			}
			else if (Ball->body->getPosition().y >= threeBy) {
				Ball->velocityX = -ballSpeed;
				Ball->velocityY = +ballSpeed;
			}
		}
	}
};