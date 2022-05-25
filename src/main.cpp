#include "Menu.h"
#include "MainGame.h"
#include "GameEngine.h"

int main(int argc, char** args)
{
    srand(time(nullptr));
    Engine g;
    g.initProg();
    MainGame mainplay;
    Menu m;
    while(!Engine::quitloop)
    {
        switch(Engine::status)
        {
            case 0: cout<<Engine::status<<endl; m.firstmenu(); break;
            case 1: cout<<Engine::status<<endl; mainplay.playGame(); break;
            default: SDL_Quit();
        }
    }
    g.closeProg();
    return 0;
}
