#include "Aiko.h"
#include "queue.h"
#include "queue.cpp"
class dummyObject2 :public object {
    Aiko* engine;
    RectangleShape* body;
public:
    dummyObject2(Aiko* e) {
        engine = e;
        body = new RectangleShape;
    }
    void update() {
        body->move(2, 0);
        engine->win()->draw(*body);
    };
    void start() {
        body->setFillColor(Color::Red);
        body->setPosition(100, 100);
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
        if (engine->input[0] == 'W') {
            //move forward
        }
        if (engine->isMouseButtonPressed()) {
            bullet = new dummyObject2(engine);
            engine->insertObject(bullet);
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