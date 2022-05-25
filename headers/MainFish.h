#ifndef MAINFISH_H_INCLUDED
#define MAINFISH_H_INCLUDED

#include "include.h"
#include "GameEngine.h"
#include "TexturesManager.h"
#include "AiFishLeft.h"
#include "AiFishRight.h"
#include "AudioManager.h"
#include "Timer.h"
class MainFish
{
    public:

        int MAINFISHWIDTH = 80, MAINFISHHEIGHT = 43;

		MainFish();

		~MainFish();

		bool isLeft, isRight;

		void handleEventMainFish(SDL_Event &e);

		void updateGame();

		void updateNextlevel();

        void checkCollision_L1();

        void checkCollision_L2();

        void checkCollision_L3();

        void checkCollision_L2toL1();

        void checkCollision_L3toL1L2();

        void renderMainFish( );

		//Current position
		int mPosX, mPosY;

		//Velocity of MainFish
		int mVelX, mVelY;

		int mousex, mousey;

		int frame;

		int premousex, premousey;

		ManageTexture gMainFish[5];

        Timer time;

        Timer timer;

        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

        SDL_RendererFlip flipf=SDL_FLIP_NONE;

		//Init AI fishes of Program
        AiFishLeft_Level1 fishl1[maxAIfishes_level1];
        AiFishRight_Level1 fishr1[maxAIfishes_level1];

        AiFishLeft_Level2 fishl2[maxAIfishes_level2];
        AiFishRight_Level2 fishr2[maxAIfishes_level2];

        AiFishLeft_Level3 fishl3[maxAIfishes_level3];
        AiFishRight_Level3 fishr3[maxAIfishes_level3];
};

#endif // MAINFISH_H_INCLUDED
