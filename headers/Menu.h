#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "include.h"
#include "TexturesManager.h"
#include "GameEngine.h"
#include "AiFishLeft.h"
#include "AiFishRight.h"
#include "AudioManager.h"

class MenuFishLevel1
{
      public:
        // W and H of AIs
        const int AI_WIDTHL1 = gMenuFishL[0].getWidth();
		const int AI_HEIGHTL1 = gMenuFishL[0].getHeight();

		MenuFishLevel1();

		~MenuFishLevel1();

		void moveAIL(int incaseAI);

		void renderAIL( int i);

		void generateAIL(int i);

        double getPosXL(int i);

        double getPosYL(int i);

        double getWidthL(int i);

        double getHeightL(int i);

        void moveAIR(int incaseAI);

		void renderAIR( int i);

		void generateAIR(int i);

        double getPosXR(int i);

        double getPosYR(int i);

        double getWidthR(int i);

        double getHeightR(int i);

        double AiPosXL[maxAIfishes_level1 - 2], AiPosYL[maxAIfishes_level1 - 2];

        double AiPosXR[maxAIfishes_level1 - 2], AiPosYR[maxAIfishes_level1 - 2];

        double AiVelXL[maxAIfishes_level1 - 2], AiVelYL[maxAIfishes_level1 - 2];

        double AiVelXR[maxAIfishes_level1 - 2], AiVelYR[maxAIfishes_level1 - 2];

        void moveFishMenu();

    private:
        SDL_RendererFlip flipL=SDL_FLIP_NONE;

        SDL_RendererFlip flipR = SDL_FLIP_HORIZONTAL;

        ManageTexture gMenuFishL[maxAIfishes_level1 - 2],gMenuFishR[maxAIfishes_level1 - 2];
};


class Menu
{
    public:

    Menu();

    ~Menu();

    void loadSource();

    void renderButtons();

    void renderLogo();

    void renderFish();

    void firstmenu();

    void loadSourceOpts();

    void renderOpts();

    void mainOpts();

    void loadSourceInstruc();

    void renderInstruc();

    void mainIns();

    bool runningOpts;

    bool runningMenu;

    bool runningInstruc;

    private:

    Mix_Music* gMenu = nullptr;

    SDL_Event e;

    int mousex, mousey;

    double velLogo=0.2;

    double mPosYMenu=15;

    MenuFishLevel1 fishmn;

    ManageTexture gBackground;

    ManageTexture gPlayGame[2],gInstruction[2],gOptions[2],gQuit[2],gHighScores[2], gLogo,gCredits[2];

    ManageTexture gOpts;

    ManageTexture gBack[2];

    ManageTexture gBubbleM[2], gBubbleS[2];

    ManageTexture gTickM, gTickS;

    ManageTexture gInstruc;

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_RendererFlip cbflip = SDL_FLIP_HORIZONTAL;

    const string ins_load = "textures/instruction/maininstruc.png";
    const string playgame = "textures/menu/StartGame/SG.png";
    const string playgame_button = "textures/menu/StartGame/SG_Button.png";
    const string instruc = "textures/menu/Instructions/Ins.png";
    const string instruc_button = "textures/menu/Instructions/Ins_Button.png";
    const string option = "textures/menu/Options_110x65/OPT.png";
    const string option_button = "textures/menu/Options_110x65/OPT_Button.png";
    const string quit = "textures/menu/Quit_110x65/QUIT.png";
    const string quit_button = "textures/menu/Quit_110x65/QUIT_Button.png";
    const string highsc = "textures/menu/HighScores/HS.png";
    const string highsc_button = "textures/menu/HighScores/HS_Button.png";
    const string logo = "textures/menu/Logo/LOGO.png";
    const string cred = "textures/menu/Credits_142x70/Cre.png";
    const string cred_button = "textures/menu/Credits_142x70/Cre_Button.png";
    const string opt_load = "textures/menu/Options_110x65/opts.png";
    const string cback = "textures/instruction/Back.png";
    const string cback_button = "textures/instruction/Back_Button.png";
    const string bub = "textures/menu/Options_110x65/bubble.png";
    const string bub_button = "textures/menu/Options_110x65/bubble_button.png";
    const string tick = "textures/menu/Options_110x65/tick.png";
};

#endif // MENU_H_INCLUDED
