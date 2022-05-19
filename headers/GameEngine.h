#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include "include.h"
#include "AudioManager.h"
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;
const int maxAIfishes_level1 = 5;
const int maxAIfishes_level2 = 3;
const int maxAIfishes_level3 = 2;
const int maxMenuFishL1 = 3;
const int maxMenuFishL2 = 3;
const int maxBubble = 10;
const int maxVel = 2;

const string fishlv1 = "textures/characters/fishlv1.png";
const string fishlv2 = "textures/characters/fishlv2.png";
const string fishlv3 = "textures/characters/fishlv3.png";
const string background = "textures/backgrounds/2_game_background.png";
const string menu = "textures/menu/HS_Button.png";


class Engine
{
    public:
        SDL_Window* gWindow;
        static SDL_Renderer* gRenderer;

        static bool quitloop;

        static bool tickM, tickS;

        static int status;

        static double countl1,countl2,countl3;

        static bool level2,level3;
        static TTF_Font* gFont;
        bool initProg();
        void closeProg();

        Audio audio;
};


#endif // GAMEENGINE_H_INCLUDED
