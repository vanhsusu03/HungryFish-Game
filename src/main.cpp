#include "Menu.h"
#include "MainGame.h"
#include "GameEngine.h"
#include "Credits.h"
#include "HighScores.h"
Engine g;

int main(int argc, char** args)
{
    srand(time(nullptr));
    g.initProg();

    MainGame mainplay;
    Menu m;
    Credits cred;
    HighScores highsc;
    while(!Engine::quitloop)
    {
        switch(Engine::status)
        {
            case 0: cout<<Engine::status<<endl; m.firstmenu(); break;
            case 1: cout<<Engine::status<<endl; mainplay.playGame(); break;
            case 3: cout<<Engine::status<<endl; highsc.mainHS(); break;
            case 5: cout<<Engine::status<<endl; cred.mainCredits(); break;
            default: SDL_Quit();
        }
    }
    g.closeProg();
    return 0;
}
