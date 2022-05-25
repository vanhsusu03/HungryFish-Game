#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include "include.h"
#include "AudioManager.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;
const int maxAIfishes_level1 = 10;
const int maxAIfishes_level2 = 3;
const int maxAIfishes_level3 = 2;
const int maxMenuFishL1 = 3;
const int maxMenuFishL2 = 3;
const int maxBubble = 10;

static int maxVel = 2;

const string fishmain_lv1 = "textures/characters/fishmain/mainlv1/main.png";
const string fishmain_lv1_1 = "textures/characters/fishmain/mainlv1/main1.png";
const string fishmain_lv1_2 = "textures/characters/fishmain/mainlv1/main2.png";
const string fishmain_lv1_3 = "textures/characters/fishmain/mainlv1/main3.png";
const string fishmain_lv1_4 = "textures/characters/fishmain/mainlv1/main4.png";
//Main lv2
const string fishmain_lv2 = "textures/characters/fishmain/mainlv2/main.png";
const string fishmain_lv2_1 = "textures/characters/fishmain/mainlv2/main1.png";
const string fishmain_lv2_2 = "textures/characters/fishmain/mainlv2/main2.png";
const string fishmain_lv2_3 = "textures/characters/fishmain/mainlv2/main3.png";
const string fishmain_lv2_4 = "textures/characters/fishmain/mainlv2/main4.png";
//Main lv3
const string fishmain_lv3 = "textures/characters/fishmain/mainlv3/main.png";
const string fishmain_lv3_1 = "textures/characters/fishmain/mainlv3/main1.png";
const string fishmain_lv3_2 = "textures/characters/fishmain/mainlv3/main2.png";
const string fishmain_lv3_3 = "textures/characters/fishmain/mainlv3/main3.png";
const string fishmain_lv3_4 = "textures/characters/fishmain/mainlv3/main4.png";
const string fishlv1 = "textures/characters/fishlv1/fishlv1.png";
const string fishlv2 = "textures/characters/fishlv2/fishlv2.png";
const string fishlv3 = "textures/characters/fishlv3/fishlv3.png";
const string fishlv1_1 = "textures/characters/fishlv1/fishlv1_1.png";
const string fishlv1_2 = "textures/characters/fishlv1/fishlv1_2.png";
const string fishlv2_1 = "textures/characters/fishlv2/Fish2-1.png";
const string fishlv2_2 = "textures/characters/fishlv2/Fish2-2.png";
const string fishlv2_3 = "textures/characters/fishlv2/Fish2-3.png";
const string fishlv3_1 = "textures/characters/fishlv3/fishlv3_1.png";
const string fishlv3_2 = "textures/characters/fishlv3/fishlv3_2.png";
const string board_game = "textures/backgrounds/board.png";
const string fishlv1_logo = "textures/characters/fishlv1/fishlv1_logo.png";
const string fishlv2_logo = "textures/characters/fishlv2/fishlv2_logo.png";
const string fishlv3_logo = "textures/characters/fishlv3/fishlv3_logo.png";
const string background = "textures/backgrounds/2_game_background.png";
const string menu = "textures/menu/background.png";

class Engine
{
    public:
        SDL_Window* gWindow;
        static SDL_Renderer* gRenderer;

        static bool quitloop;

        static bool tickM, tickS;

        static int status;

        static int countl1,countl2,countl3;

        static bool level2,level3;

        static bool stillAlive;

        static TTF_Font* gFont;

        static Audio audio;

        static int readBest();

        bool initProg();

        void closeProg();

};


#endif // GAMEENGINE_H_INCLUDED
