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
        body->setSize(Vector2f(5, 5));
    };
};

class dummyObject :public object {
    Aiko* engine;
    Texture* text;
    Sprite* body;
    dummyObject2* bullet;
    Music* music;
    int m = 0;
public:
    dummyObject(Aiko* e) {
        engine = e;
        text = new Texture;
        text->loadFromFile("char.png");
        body = new Sprite;
        body->setTexture(*text);
        bullet = NULL;
        music = new Music;
        music->openFromFile("music.wav");
    }
    void update() { 
        m++;
        if (engine->mouseButtonPressed("Left")) {
            bullet = new dummyObject2(engine,body->getPosition().x+40,body->getPosition().y+25);
            engine->insertObject(bullet);
        }
		float x = engine->getMousePosition().x;
		float y = engine->getMousePosition().y;
	//	body->setPosition(x,y);
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
        //body->setFillColor(Color::Green);
        body->setPosition(100, 100);
        body->setScale(Vector2f(2, 2));
    };
};
void fire() {
	cout << "";
}
int main(){
    Aiko a;
    dummyObject b(&a);
    a.insertObject(&b);
    a.Run();
    return 0;
}
void add() {

}