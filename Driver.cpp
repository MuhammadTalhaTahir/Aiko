#include "Aiko.h"

class dummyObject :public object {
    Aiko* engine;
public:
    void update() {

    };
};

int main(){
    list a;
    dummyObject d,b,c;
    a.insert(&d);
    a.insert(&b);
    a.insert(&c);
    cout << a.getObjectCount() << endl;
    a.remove(&b);
    cout << a.getObjectCount() << endl;
    return 0;
}