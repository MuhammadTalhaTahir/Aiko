#include "Aiko.h"


class dummyObject2 :public object {
    Aiko* engine;
    RectangleShape* body;
    int x, y;
public:
    dummyObject2(Aiko* e,int x,int y) {
        engine = e;
        body = new RectangleShape;
        this->x = x;
        this->y = y;
    }
    void update() {
        body->move(2, 0);
        engine->win()->draw(*body);
    };
    void start() {
        body->setFillColor(Color::Red);
        body->setPosition(x, y);
        body->setSize(Vector2f(15, 15));
    };
};

class dummyObject :public object {
    Aiko* engine;
    RectangleShape* body;
    dummyObject2* bullet;
public:
    dummyObject(Aiko* e) {
        engine = e;
        body = new RectangleShape;
        bullet = NULL;
    };
    void update() { 
        if (engine->mouseButtonPressed("Left")) {
            bullet = new dummyObject2(engine,body->getPosition().x,body->getPosition().y);
            engine->insertObject(bullet);
        }
        if (engine->keyBoardButtonPressed("W")) {
            body->move(0, -4);
        }
        if (engine->keyBoardButtonPressed("S")) {
            body->move(0, 4);
        }
        if (engine->keyBoardButtonPressed("A")) {
            body->move(-4, 0);
        }
		if (engine->keyBoardButtonPressed("D")) {
            body->move(4, 0);
        }
        engine->win()->draw(*body);
    };
    void start() {
        body->setFillColor(Color::Green);
        body->setPosition(100, 100);
        body->setSize(Vector2f(34, 34));
    };
};

int main(){
    Aiko a;
    dummyObject b(&a);
    a.insertObject(&b);
    a.Run();
    return 0;
}