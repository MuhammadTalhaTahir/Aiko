#include "pong.cpp"

int main(){
    Aiko e;
    game Game(&e);
    e.insertObject(&Game);
    e.Run();
    return 0;
}