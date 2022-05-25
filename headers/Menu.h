#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "include.h"
#include "TexturesManager.h"
#include "GameEngine.h"
#include "AudioManager.h"

class Menu
{
    public:

    Menu();

    ~Menu();

    void loadSource();

    void renderButtons();

    void renderLogo();

    void firstmenu();

    void loadSourceOpts();

    void renderOpts();

    void mainOpts();

    void loadSourceInstruc();

    void renderInstruc();

    void mainIns();

    void loadSourceHighSc();

    void renderHighSc();

    void mainHighSc();

    void loadSourceCredits();

    void renderCredits();

    void mainCredits();

    bool runningOpts;

    bool runningMenu;

    bool runningInstruc;

    bool runningHighsc;

    bool runningCredits;

    private:

    SDL_Event e;

    int mousex, mousey;

    double velLogo=0.2;

    double mPosYMenu=15;

    ManageTexture gBackground;

    ManageTexture gPlayGame[2],gInstruction[2],gOptions[2],gQuit[2],gHighScores[2], gLogo,gCredits[2];

    ManageTexture gOpts;

    ManageTexture gBack[2];

    ManageTexture gBubbleM[2], gBubbleS[2];

    ManageTexture gTickM, gTickS;

    ManageTexture gInstruc;

    ManageTexture gHighSc;

    ManageTexture gBestScore;

    ManageTexture gCred;

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_RendererFlip cbflip = SDL_FLIP_HORIZONTAL;

    const string ins_load = "textures/menu/Instructions/maininstruc.png";
    const string playgame = "textures/menu/StartGame/SG.png";
    const string playgame_button = "textures/menu/StartGame/SG_Button.png";
    const string instruc = "textures/menu/Instructions/Ins.png";
    const string instruc_button = "textures/menu/Instructions/Ins_Button.png";
    const string option = "textures/menu/Options/OPT.png";
    const string option_button = "textures/menu/Options/OPT_Button.png";
    const string quit = "textures/menu/Quit/QUIT.png";
    const string quit_button = "textures/menu/Quit/QUIT_Button.png";
    const string highsc = "textures/menu/HighScores/HS.png";
    const string highsc_button = "textures/menu/HighScores/HS_Button.png";
    const string logo = "textures/menu/Logo/LOGO.png";
    const string cred = "textures/menu/Credits/Cre.png";
    const string cred_button = "textures/menu/Credits/Cre_Button.png";
    const string opt_load = "textures/menu/Options/opts.png";
    const string highsc_load = "textures/menu/HighScores/highsc.png";
    const string credits_load = "textures/menu/Credits/creditsmain.png";
    const string cback = "textures/menu/Instructions/Back.png";
    const string cback_button = "textures/menu/Instructions/Back_Button.png";
    const string bub = "textures/menu/Options/bubble.png";
    const string bub_button = "textures/menu/Options/bubble_button.png";
    const string tick = "textures/menu/Options/tick.png";
};

#endif // MENU_H_INCLUDED
