#include "MainFish.h"

MainFish::MainFish()
{

}

MainFish::~MainFish()
{

}

void MainFish::handleEventMainFish( SDL_Event& e)
{
    SDL_GetMouseState(&mousex,&mousey);
    if(premousex > mousex + 5 )
    {
       isLeft = true;
       isRight = false;
       mPosX = mousex;
       mPosY = mousey;
       flip = SDL_FLIP_HORIZONTAL;
    }
    else if( premousex < mousex){
        isLeft = false;
        isRight = true;
    mPosX = mousex - MAINFISHWIDTH;
    mPosY = mousey;
    flip = SDL_FLIP_NONE;

    time.start();
    if(mPosX < 0) mPosX=0;
    if(mPosY < 0) mPosY = 0;
    }
}

void MainFish::updateGame()
{
    MAINFISHWIDTH = 80;
    MAINFISHHEIGHT = 43;
    Engine::countl1 = 0;
    Engine::countl2 = 0;
    Engine::countl3 = 0;
    gMainFish[0].loadImage(fishmain_lv1);
    gMainFish[1].loadImage(fishmain_lv1_1);
    gMainFish[2].loadImage(fishmain_lv1_2);
    gMainFish[3].loadImage(fishmain_lv1_3);
    gMainFish[4].loadImage(fishmain_lv1_4);

    mPosX = SCREEN_WIDTH/2 - 10;
    mPosY = 20;
    time.start();
    timer.start();
    frame = 0;
    mVelX = 0;
    mVelY = 0;
    premousex=0;
    premousey=0;

    for(int i=0;i<maxAIfishes_level1;i++)
    {
        fishl1[i].update();
        fishr1[i].update();
    }
    for(int i=0;i<maxAIfishes_level2;i++)
    {
        fishl2[i].update();
        fishr2[i].update();
    }
    for(int i=0;i<maxAIfishes_level3;i++)
    {
        fishl3[i].update();
        fishr3[i].update();
    }
}
void MainFish::updateNextlevel()
{
    if(Engine::countl1 >= 50 && Engine::level2 == false)
    {
        Mix_PlayChannel(-1,Audio::gNextLevel,0);
        gMainFish[0].loadImage(fishmain_lv2);
        gMainFish[1].loadImage(fishmain_lv2_1);
        gMainFish[2].loadImage(fishmain_lv2_2);
        gMainFish[3].loadImage(fishmain_lv2_3);
        gMainFish[4].loadImage(fishmain_lv2_4);
        MAINFISHWIDTH = 130;
        MAINFISHHEIGHT = 70;
        Engine::level2 = true;
    }
    if(Engine::countl1 + Engine::countl2 >= 150 && Engine::countl2 >= 35 && Engine::level3 == false)
    {
        Mix_PlayChannel(-1,Audio::gNextLevel,0);
        gMainFish[0].loadImage(fishmain_lv3);
        gMainFish[1].loadImage(fishmain_lv3_1);
        gMainFish[2].loadImage(fishmain_lv3_2);
        gMainFish[3].loadImage(fishmain_lv3_3);
        gMainFish[4].loadImage(fishmain_lv3_4);
        MAINFISHWIDTH = 260;
        MAINFISHHEIGHT = 140;
        Engine::level3 = true;
    }
}

/**
        OK ROI!
**/
void MainFish::checkCollision_L1()
{
    for(int i=0;i<maxAIfishes_level1;i++)
    {
        //Fish from right to left
        if( mPosX + MAINFISHWIDTH >= fishr1[i].getPosXR1(i)
           && fishr1[i].getPosXR1(i) >= mPosX + MAINFISHWIDTH
           && fishr1[i].getPosYR1(i) >= mPosY
           && fishr1[i].getPosYR1(i) <= mPosY + MAINFISHHEIGHT - 7)
           {
               Mix_PlayChannel(-1,Audio::gEatlevel1,0);
               fishr1[i].AiPosX[i] = SCREEN_WIDTH + fishr1[i].AI_WIDTHR1 + 100;
               Engine::countl1+=1;
           }
        if(fishr1[i].getPosXR1(i) + fishr1[i].getWidthR1(i) >= mPosX
           && fishr1[i].getPosXR1(i) + fishr1[i].getWidthR1(i) <= mPosX + MAINFISHWIDTH
           && fishr1[i].getPosYR1(i) >= mPosY
           && fishr1[i].getPosYR1(i) <= mPosY + MAINFISHHEIGHT - 7 )
             {
                Mix_PlayChannel(-1,Audio::gEatlevel1,0);
                fishr1[i].AiPosX[i] = SCREEN_WIDTH + fishr1[i].AI_WIDTHR1 + 100;
                Engine::countl1+=1;
           }

        //FIsh from left to right
        if(mPosX + MAINFISHWIDTH >= fishl1[i].getPosXL1(i)
           && fishl1[i].getPosXL1(i) >= mPosX + MAINFISHWIDTH
           && fishl1[i].getPosYL1(i) >= mPosY
           && fishl1[i].getPosYL1(i) <= mPosY + MAINFISHHEIGHT - 7)
           {
               Mix_PlayChannel(-1,Audio::gEatlevel1,0);
               fishl1[i].AiPosX[i] = -fishl1[i].AI_WIDTHL1 - 100;
                Engine::countl1+=1;
           }
        if(fishl1[i].getPosXL1(i) + fishl1[i].getWidthL1(i) >= mPosX
           && fishl1[i].getPosXL1(i) + fishl1[i].getWidthL1(i) <= mPosX + MAINFISHWIDTH
           && fishl1[i].getPosYL1(i) >= mPosY
           && fishl1[i].getPosYL1(i) <= mPosY + MAINFISHHEIGHT - 7)
        {
            Mix_PlayChannel(-1,Audio::gEatlevel1,0);
           fishl1[i].AiPosX[i] =-fishl1[i].AI_WIDTHL1 - 100;
            Engine::countl1+=1;
        }
    }
}

void MainFish::checkCollision_L2()
{
    for(int i=0;i<maxAIfishes_level2;i++)
    {
        //Fish from right to left
        if(isRight && MAINFISHWIDTH > fishr2[i].getWidthR2(i) && MAINFISHHEIGHT > fishr2[i].getHeightR2(i)
           && mPosX + MAINFISHWIDTH >= fishr2[i].getPosXR2(i)
           && fishr2[i].getPosXR2(i) >= mPosX && fishr2[i].getPosYR2(i) >= mPosY
           && fishr2[i].getPosYR2(i) <= mPosY + MAINFISHHEIGHT)
           {
               Mix_PlayChannel(-1,Audio::gEatlevel2,0);
               fishr2[i].AiPosX[i] = SCREEN_WIDTH + fishr2[i].getWidthR2(i) + 200;
               Engine::countl2+=1;
           }
        //MainFish on the LEFT of the AIs
        if (MAINFISHWIDTH < fishr2[i].getWidthR2(i) && MAINFISHHEIGHT < fishr2[i].getHeightR2(i)
                 && mPosX + MAINFISHWIDTH > fishr2[i].getPosXR2(i)
                 && fishr2[i].getPosXR2(i) + fishr2[i].getHeightR2(i) > mPosX + MAINFISHWIDTH && fishr2[i].getPosYR2(i) < mPosY
                 && mPosY < fishr2[i].getPosYR2(i) + fishr2[i].getHeightR2(i))
                    {
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               Engine::stillAlive = false;
           }

        if(isLeft && MAINFISHWIDTH > fishr2[i].getWidthR2(i) && MAINFISHHEIGHT > fishr2[i].getHeightR2(i)
           && fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i) > mPosX
           && fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i) < mPosX + MAINFISHWIDTH
           && fishr2[i].getPosYR2(i) > mPosY && fishr2[i].getPosYR2(i) < mPosY + MAINFISHHEIGHT )
             {
                Mix_PlayChannel(-1,Audio::gEatlevel2,0);
               fishr2[i].AiPosX[i] = SCREEN_WIDTH + fishr2[i].getWidthR2(i) + 200;
               Engine::countl2+=1;
           }
        //MainFish on the RIGHT of the AIs
        if(MAINFISHWIDTH < fishr2[i].getWidthR2(i) && MAINFISHHEIGHT < fishr2[i].getHeightR2(i)
                && fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i) > mPosX
                && fishr2[i].getPosXR2(i) < mPosX
                && fishr2[i].getPosYR2(i) < mPosY && fishr2[i].getPosYR2(i) + fishr2[i].getHeightR2(i) > mPosY )
                {
                Engine::stillAlive = false;
                Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
                }

        //Fish from left to right
        if(isRight && MAINFISHWIDTH > fishl2[i].AI_WIDTHL2 && MAINFISHHEIGHT > fishl2[i].AI_HEIGHTL2
           && mPosX + MAINFISHWIDTH > fishl2[i].getPosXL2(i)
           && mPosX + MAINFISHWIDTH < fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) && fishl2[i].getPosYL2(i) > mPosY
           && fishl2[i].getPosYL2(i) < mPosY + MAINFISHHEIGHT)
           {
               Mix_PlayChannel(-1,Audio::gEatlevel2,0);
               fishl2[i].AiPosX[i] = -fishl2[i].AI_WIDTHL2 - 200;
                Engine::countl2+=1;
           }
        //MAINFISH is on the LEFT of the AIs
        if(MAINFISHWIDTH < fishl2[i].AI_WIDTHL2 && MAINFISHHEIGHT < fishl2[i].AI_HEIGHTL2
           && mPosX + MAINFISHWIDTH > fishl2[i].getPosXL2(i)
           && mPosX + MAINFISHWIDTH < fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) && fishl2[i].getPosYL2(i) < mPosY
           && fishl2[i].getPosYL2(i) + fishl2[i].getHeightL2(i) > mPosY )
           {
                Engine::stillAlive = false;
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
           }

        if(isLeft && MAINFISHWIDTH > fishl2[i].AI_WIDTHL2 && MAINFISHHEIGHT > fishl2[i].AI_HEIGHTL2
           &&fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) > mPosX
           && fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) < mPosX + MAINFISHWIDTH
           && fishl2[i].getPosYL2(i) > mPosY && fishl2[i].getPosYL2(i) < mPosY + MAINFISHHEIGHT)
        {
            Mix_PlayChannel(-1,Audio::gEatlevel2,0);
           fishl2[i].AiPosX[i] =-fishl2[i].AI_WIDTHL2 - 150;
           Engine::countl2+=1;
        }
        //MAINFISH is on the RIGHT of the AIs
        if(MAINFISHWIDTH < fishl2[i].AI_WIDTHL2 && MAINFISHHEIGHT < fishl2[i].AI_HEIGHTL2
           &&fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) > mPosX
           && fishl2[i].getPosXL2(i) < mPosX
           && fishl2[i].getPosYL2(i) < mPosY && fishl2[i].getPosYL2(i) + fishl2[i].getHeightL2(i) > mPosY)
           {
                Engine::stillAlive = false;
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
           }
    }
}

void MainFish::checkCollision_L3()
{
    for(int i=0;i<maxAIfishes_level3;i++)
    {
        //Fish from right to left
        if(isRight && MAINFISHWIDTH > fishr3[i].getWidthR3(i) && MAINFISHHEIGHT > fishr3[i].getHeightR3(i)
           && mPosX + MAINFISHWIDTH >= fishr3[i].getPosXR3(i)
           && fishr3[i].getPosXR3(i) >= mPosX && fishr3[i].getPosYR3(i) >= mPosY
           && fishr3[i].getPosYR3(i) <= mPosY + MAINFISHHEIGHT)
           {
               Mix_PlayChannel(-1,Audio::gEatlevel3,0);
               fishr3[i].AiPosX[i] = SCREEN_WIDTH + fishr3[i].getWidthR3(i) + 200;
               Engine::countl3+=1;
           }
        //MainFish on the LEFT of the AIs
        if (MAINFISHWIDTH < fishr3[i].getWidthR3(i) && MAINFISHHEIGHT < fishr3[i].getHeightR3(i)
                 && mPosX + MAINFISHWIDTH > fishr3[i].getPosXR3(i)
                 && fishr3[i].getPosXR3(i) + fishr3[i].getHeightR3(i) > mPosX + MAINFISHWIDTH && fishr3[i].getPosYR3(i) < mPosY
                 && mPosY < fishr3[i].getPosYR3(i) + fishr3[i].getHeightR3(i))
                    {
                Engine::stillAlive = false;
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
           }

        if(isLeft && MAINFISHWIDTH > fishr3[i].getWidthR3(i) && MAINFISHHEIGHT > fishr3[i].getHeightR3(i)
           && fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i) > mPosX
           && fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i) < mPosX + MAINFISHWIDTH
           && fishr3[i].getPosYR3(i) > mPosY && fishr3[i].getPosYR3(i) < mPosY + MAINFISHHEIGHT )
             {
                Mix_PlayChannel(-1,Audio::gEatlevel3,0);
               fishr3[i].AiPosX[i] = SCREEN_WIDTH + fishr3[i].getWidthR3(i) + 200;
               Engine::countl3+=1;
           }
        //MainFish on the RIGHT of the AIs
        if(MAINFISHWIDTH < fishr3[i].getWidthR3(i) && MAINFISHHEIGHT < fishr3[i].getHeightR3(i)
                && fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i) > mPosX
                && fishr3[i].getPosXR3(i) < mPosX
                && fishr3[i].getPosYR3(i) < mPosY && fishr3[i].getPosYR3(i) + fishr3[i].getHeightR3(i) > mPosY )
                {
                Engine::stillAlive = false;
                Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
                }

        //Fish from left to right
        if(isRight && MAINFISHWIDTH > fishl3[i].AI_WIDTHL3 && MAINFISHHEIGHT > fishl3[i].AI_HEIGHTL3
           && mPosX + MAINFISHWIDTH > fishl3[i].getPosXL3(i)
           && mPosX + MAINFISHWIDTH < fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) && fishl3[i].getPosYL3(i) > mPosY
           && fishl3[i].getPosYL3(i) < mPosY + MAINFISHHEIGHT)
           {
               Mix_PlayChannel(-1,Audio::gEatlevel3,0);
               fishl3[i].AiPosX[i] = -fishl3[i].AI_WIDTHL3 - 200;
                Engine::countl3+=1;
           }
        //MAINFISH is on the LEFT of the AIs
        if(MAINFISHWIDTH < fishl3[i].AI_WIDTHL3 && MAINFISHHEIGHT < fishl3[i].AI_HEIGHTL3
           && mPosX + MAINFISHWIDTH > fishl3[i].getPosXL3(i)
           && mPosX + MAINFISHWIDTH < fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) && fishl3[i].getPosYL3(i) < mPosY
           && fishl3[i].getPosYL3(i) + fishl3[i].getHeightL3(i) > mPosY )
           {
            Engine::stillAlive = false;
            Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
           }

        if(isLeft && MAINFISHWIDTH > fishl3[i].AI_WIDTHL3 && MAINFISHHEIGHT > fishl3[i].AI_HEIGHTL3
           &&fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) > mPosX
           && fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) < mPosX + MAINFISHWIDTH
           && fishl3[i].getPosYL3(i) > mPosY && fishl3[i].getPosYL3(i) < mPosY + MAINFISHHEIGHT)
        {
            Mix_PlayChannel(-1,Audio::gEatlevel3,0);
           fishl3[i].AiPosX[i] =-fishl3[i].AI_WIDTHL3 - 150;
           Engine::countl3+=1;
        }
        //MAINFISH is on the RIGHT of the AIs
        if(MAINFISHWIDTH < fishl3[i].AI_WIDTHL3 && MAINFISHHEIGHT < fishl3[i].AI_HEIGHTL3
           &&fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) > mPosX
           && fishl3[i].getPosXL3(i) < mPosX
           && fishl3[i].getPosYL3(i) < mPosY && fishl3[i].getPosYL3(i) + fishl3[i].getHeightL3(i) > mPosY)
           {
            Engine::stillAlive = false;
            Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
           }
    }
}

void MainFish::checkCollision_L2toL1()
{
    for(int i=0;i<maxAIfishes_level2;i++)
    {
        for(int j=0;j<maxAIfishes_level1;j++)
        {
            // L2 to L1
            if(fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) > fishl1[j].getPosXL1(j)
               && fishl2[i].getPosXL2(i) < fishl1[j].getPosXL1(j)
               && fishl2[i].getPosYL2(i) < fishl1[j].getPosYL1(j)
               && fishl2[i].getPosYL2(i) + fishl2[i].getHeightL2(i) > fishl1[j].getPosYL1(j))
            fishl1[j].AiPosX[j] = -fishl1[j].AI_WIDTHL1 - 100;
            // L2 to R1
            if(fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) > fishr1[j].getPosXR1(j)
               && fishl2[i].getPosXL2(i) < fishr1[j].getPosXR1(j)
               && fishl2[i].getPosYL2(i) < fishr1[j].getPosYR1(j)
               && fishl2[i].getPosYL2(i) + fishl2[i].getHeightL2(i) > fishr1[j].getPosYR1(j))
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 150;
            //R2 to L1
            if( fishr2[i].getPosXR2(i) < fishl1[j].getWidthL1(j) + fishl1[j].getPosXL1(j)
               && fishl1[j].getWidthL1(j) + fishl1[j].getPosXL1(j) < fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i)
               && fishl1[j].getPosYL1(j) > fishr2[i].getPosYR2(i)
               && fishl1[j].getPosYL1(j) < fishr2[i].getPosYR2(i) + fishr2[i].getHeightR2(i))
                fishl1[j].AiPosX[j] = -fishl1[j].AI_WIDTHL1 - 100;
            //L2 to R1
            if( fishr2[i].getPosXR2(i) < fishl1[j].getWidthL1(j) + fishr1[j].getPosXR1(j)
               && fishl1[j].getWidthL1(j) + fishr1[j].getPosXR1(j) < fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i)
               && fishr1[j].getPosYR1(j) > fishr2[i].getPosYR2(i)
               && fishr1[j].getPosYR1(j) < fishr2[i].getPosYR2(i) + fishr2[i].getHeightR2(i))
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 150;
        }
    }
}

void MainFish::checkCollision_L3toL1L2()
{
    //Fish3 to Fish1
    for(int i=0;i<maxAIfishes_level3;i++)
    {
        for(int j=0;j<maxAIfishes_level1;j++)
        {
            // L3 to L1
            if(fishl3[i].getPosXL3(i) + fishr3[i].getWidthR3(i) > fishl1[j].getPosXL1(j)
               && fishl3[i].getPosXL3(i) < fishl1[j].getPosXL1(j)
               && fishl3[i].getPosYL3(i) < fishl1[j].getPosYL1(j)
               && fishl3[i].getPosYL3(i) + fishr3[i].getHeightR3(i) > fishl1[j].getPosYL1(j))
            fishl1[j].AiPosX[j] = -fishl1[j].AI_WIDTHL1 - 100;

            // L3 to R1
            if(fishl3[i].getPosXL3(i) + fishr3[i].getWidthR3(i) > fishr1[j].getPosXR1(j)
               && fishl3[i].getPosXL3(i) < fishr1[j].getPosXR1(j)
               && fishl3[i].getPosYL3(i) < fishr1[j].getPosYR1(j)
               && fishl3[i].getPosYL3(i) + fishr3[i].getHeightR3(i) > fishr1[j].getPosYR1(j))
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 150;
            //R3 to L1
            if( fishr3[i].getPosXR3(i) < fishl1[j].getWidthL1(j) + fishl1[j].getPosXL1(j)
               && fishl1[j].getWidthL1(j) + fishl1[j].getPosXL1(j) < fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i)
               && fishl1[j].getPosYL1(j) > fishr3[i].getPosYR3(i)
               && fishl1[j].getPosYL1(j) < fishr3[i].getPosYR3(i) + fishr3[i].getHeightR3(i))
                fishl1[j].AiPosX[j] = -fishl1[j].AI_WIDTHL1 - 100;
            //L3 to R1
            if( fishr3[i].getPosXR3(i) < fishl1[j].getWidthL1(j) + fishr1[j].getPosXR1(j)
               && fishl1[j].getWidthL1(j) + fishr1[j].getPosXR1(j) < fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i)
               && fishr1[j].getPosYR1(j) > fishr3[i].getPosYR3(i)
               && fishr1[j].getPosYR1(j) < fishr3[i].getPosYR3(i) + fishr3[i].getHeightR3(i))
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 150;
        }
    }

    //Fish 3 to Fish2
    for(int i=0;i<maxAIfishes_level3;i++)
    {
        for(int j=0;j<maxAIfishes_level2;j++)
        {
            // L3 to L2
            if(fishl3[i].getPosXL3(i) + fishr3[i].getWidthR3(i) > fishl2[j].getPosXL2(j)
               && fishl3[i].getPosXL3(i) < fishl2[j].getPosXL2(j)
               && fishl3[i].getPosYL3(i) < fishl2[j].getPosYL2(j)
               && fishl3[i].getPosYL3(i) + fishr3[i].getHeightR3(i) > fishl2[j].getPosYL2(j))
            fishl2[j].AiPosX[j] = -fishl2[j].AI_WIDTHL2 - 100;
            // L3 to R2
            if(fishl3[i].getPosXL3(i) + fishr3[i].getWidthR3(i) > fishr2[j].getPosXR2(j)
               && fishl3[i].getPosXL3(i) < fishr2[j].getPosXR2(j)
               && fishl3[i].getPosYL3(i) < fishr2[j].getPosYR2(j)
               && fishl3[i].getPosYL3(i) + fishr3[i].getHeightR3(i) > fishr2[j].getPosYR2(j))
               fishr2[j].AiPosX[j] = -fishr2[j].AI_WIDTHR2 - 100;
            //R3 to L2
            if( fishr3[i].getPosXR3(i) < fishl2[j].getWidthL2(j) + fishl2[j].getPosXL2(j)
               && fishl2[j].getWidthL2(j) + fishl2[j].getPosXL2(j) < fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i)
               && fishl2[j].getPosYL2(j) > fishr3[i].getPosYR3(i)
               && fishl2[j].getPosYL2(j) < fishr3[i].getPosYR3(i) + fishr3[i].getHeightR3(i))
                fishl2[j].AiPosX[j] = -fishl2[j].AI_WIDTHL2 - 100;
            //L3 to R2
            if( fishr3[i].getPosXR3(i) < fishl2[j].getWidthL2(j) + fishr2[j].getPosXR2(j)
               && fishl2[j].getWidthL2(j) + fishr2[j].getPosXR2(j) < fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i)
               && fishr2[j].getPosYR2(j) > fishr3[i].getPosYR3(i)
               && fishr2[j].getPosYR2(j) < fishr3[i].getPosYR3(i) + fishr3[i].getHeightR3(i))
               fishr2[j].AiPosX[j] = -fishr2[j].AI_WIDTHR2 - 100;
        }
    }
}

void MainFish::renderMainFish( )
{
    for(int i=0;i<maxAIfishes_level1;i++)
    {
        fishl1[i].generateAILL1(i);
        fishr1[i].generateAIRL1(i);
    }
    for(int i=0;i<maxAIfishes_level2;i++)
    {
        fishl2[i].generateAILL2(i);
        fishr2[i].generateAIRL2(i);
    }
    for(int i=0;i<maxAIfishes_level3;i++)
    {
        fishl3[i].generateAILL3(i);
        fishr3[i].generateAIRL3(i);
    }
    if(frame == 5) frame = 0;
    gMainFish[frame].render( mPosX, mPosY,nullptr,0,nullptr,flip );
    if((timer.get_ticks() % 10) == 0) frame++;
    premousex=mousex;
    premousey = mousey;
    updateNextlevel();
}

