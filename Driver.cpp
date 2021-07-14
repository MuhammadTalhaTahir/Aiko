#include "Aiko.h"

class ball :public object {
    Aiko* engine;
    int i;
    bool flag;
public:
    ball(Aiko* e) {
        engine = e;
        body = new RectangleShape;
        i = 0;
        flag = false;
    }
    void update() {
        body->move(0, i);
        if (!flag) i -= 5;
        else if (flag) i += 5;
        if (i <= -40) {
            flag = true;
            i = 0;
        }
        if (i >= 40) {
            flag = false;
            i = 0;
        }
    };
    void start() {
        body->setFillColor(Color::Green);
        body->setSize(Vector2f(20, 20));
        body->setPosition(512, 550);
    };
};

class dummyObject2 :public object {
    Aiko* engine;
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
    };
    void start() {
        body->setFillColor(Color::Red);
        body->setPosition(x, y);
        body->setSize(Vector2f(5, 5));
    };
};

class dummyObject :public object {
    Aiko* engine;
    dummyObject2* bullet;
    Sound* music;
    SoundBuffer* buffer;
public:
    dummyObject(Aiko* e) {
        engine = e;
        texture = new Texture;
        texture->loadFromFile("char.png");
        bullet = NULL;
        buffer = new SoundBuffer;
        buffer->loadFromFile("music.wav");
        music = new Sound;
        music->setBuffer(*buffer);
        body = new RectangleShape;
        body->setTexture(texture);
    }
    void update() { 
        if (engine->mouseButtonPressed("Left")) {
            bullet = new dummyObject2(engine,body->getPosition().x+40,body->getPosition().y+25);
            engine->insertObject(bullet);
            music->play();
        }
        float x = engine->getMousePosition().x;
        float y = engine->getMousePosition().y;
        //body->setPosition(x, y);
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
    };
    void start() {
        //body->setFillColor(Color::Green);
        body->setPosition(100, 100);
        body->setSize(Vector2f(70, 70));
    };
};

int main(){
    Aiko a;
    ball c(&a);
    a.insertObject(&c);
    dummyObject b(&a);
    a.insertObject(&b);
    a.Run();
    return 0;
}