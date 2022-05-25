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

    void endGame();

    void loseGame();

    void playGame();

    private:

    int mousex, mousey;

    int score;

    bool quitgame=false;

    bool pausedgame = false;

    bool renderText = false;

    bool menuWin = true;

    bool menuLose = true;

    SDL_RendererFlip flipp=SDL_FLIP_NONE;

    SDL_Event e;

    SDL_Color colorText;

    ManageTexture gBackground,gPaused;

    ManageTexture gEndBackgr;

    ManageTexture gResume[2], gHome[2];

    ManageTexture clock, border,board;

    ManageTexture gLogo1, gLogo2, gLogo3, gScore1, gScore2, gScore3, gTextScore,gSumScore, gBestScore;

    ManageTexture gWinGame[7], gLoseGame[8];

    ManageTexture bestScore;

    MainFish fishmain;

    Timer gameT;

    Uint32 startTime = 120;

    stringstream timeText, gFish1, gFish2, gFish3, gYourScore;

    string textInput = " " ;

    const string pau = "textures/menu/Paused/resumebackgr.png";
    const string res = "textures/menu/Paused/resume.png";
    const string res_but = "textures/menu/Paused/resume_but.png";
    const string home = "textures/menu/Paused/home.png";
    const string home_but = "textures/menu/Paused/home_but.png";
    const string bord = "textures/backgrounds/border.png";
};


#endif // MAINGAME_H_INCLUDED
