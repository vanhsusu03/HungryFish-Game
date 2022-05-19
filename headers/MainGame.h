#ifndef MAINGAME_H_INCLUDED
#define MAINGAME_H_INCLUDED

#include "include.h"
#include "MainFish.h"
#include "AudioManager.h"
#include "Timer.h"
class MainGame
{
    public:

    MainGame();

    ~MainGame();

    void renderButtonPaused();

    void pausedGame();

    void playGame();

    private:

    int mousex, mousey;

    bool quitgame=false;

    bool pausedgame = false;

    SDL_RendererFlip flipp=SDL_FLIP_NONE;

    SDL_Event e;

    SDL_Color colorText;

    ManageTexture gBackground,gPaused;

    ManageTexture gResume[2], gHome[2];

    ManageTexture clock, border;

    MainFish fishmain;

    Timer gameT;

    Uint32 startTime = 120;

    stringstream timeText;

    const string pau = "textures/menu/Resume/resumebackgr.png";
    const string res = "textures/menu/Resume/resume.png";
    const string res_but = "textures/menu/Resume/resume_but.png";
    const string home = "textures/menu/Resume/home.png";
    const string home_but = "textures/menu/Resume/home_but.png";
    const string bord = "textures/backgrounds/border.png";
};


#endif // MAINGAME_H_INCLUDED
