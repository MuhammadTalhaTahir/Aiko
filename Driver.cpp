#include "Aiko.h"

class dummyObject :public object {
    Aiko* engine;
    RectangleShape* body;
public:
    dummyObject(Aiko* e) {
        engine = e;
        body = new RectangleShape;
    }
    void update() {
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