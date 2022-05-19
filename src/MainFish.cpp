#include "MainFish.h"

MainFish::MainFish()
{
    gMainFish.loadImage("textures/characters/anglerfish.png");
    mPosX = SCREEN_WIDTH/2 - 10;
    mPosY = 20;
    time.start();
    mVelX = 0;
    mVelY = 0;
    premousex=0;
    premousey=0;
}

MainFish::~MainFish()
{
    gMainFish.free();
}

void MainFish::handleEventMainFish( SDL_Event& e)
{
    if(e.type == SDL_MOUSEMOTION )
    {
    SDL_GetMouseState(&mousex,&mousey);
    if(premousex > mousex + 5 )
    {
       mPosX = mousex + 50;
       mPosY = mousey + 15;
       flip = SDL_FLIP_HORIZONTAL;
    }
    else if( premousex < mousex){
    mPosX = mousex - 50;
    mPosY = mousey - 15;
    flip = SDL_FLIP_NONE;
    }
    time.start();
    if(mPosX < 0) mPosX=0;
    if(mPosY < 0) mPosY = 0;
    }
}

void MainFish::moveMainFish()
{
}

/**
        OK ROI!
**/
void MainFish::checkCollision_L1()
{
    for(int i=0;i<maxAIfishes_level1;i++)
    {
        //Fish from right to left
        if(mPosX + gMainFish.getWidth() >= fishr1[i].getPosXR1(i)
           && fishr1[i].getPosXR1(i) >= mPosX
           && fishr1[i].getPosYR1(i) >= mPosY
           && fishr1[i].getPosYR1(i) <= mPosY + gMainFish.getHeight())
           {
               Mix_PlayChannel(-1,Audio::gEatlevel1,0);
               fishr1[i].AiPosX[i] = SCREEN_WIDTH + fishr1[i].AI_WIDTHR1 + 300;
               Engine::countl1+=0.5;
           }
        if( fishr1[i].getPosXR1(i) + fishr1[i].getWidthR1(i) >= mPosX
           && fishr1[i].getPosXR1(i) + fishr1[i].getWidthR1(i) <= mPosX + gMainFish.getWidth()
           && fishr1[i].getPosYR1(i) >= mPosY
           && fishr1[i].getPosYR1(i) <= mPosY + gMainFish.getHeight() )
             {
                Mix_PlayChannel(-1,Audio::gEatlevel1,0);
                fishr1[i].AiPosX[i] = SCREEN_WIDTH + fishr1[i].AI_WIDTHR1 + 330;
                Engine::countl1+=0.5;
           }
        if(mPosX + gMainFish.getWidth() >= fishl1[i].getPosXL1(i)
           && fishl1[i].getPosXL1(i) >= mPosX
           && fishl1[i].getPosYL1(i) >= mPosY
           && fishl1[i].getPosYL1(i) <= mPosY + gMainFish.getHeight())
           {
               Mix_PlayChannel(-1,Audio::gEatlevel1,0);
               fishl1[i].AiPosX[i] = -fishl1[i].AI_WIDTHL1 - 350;
                Engine::countl1+=0.5;
           }
        if(fishl1[i].getPosXL1(i) + fishl1[i].getWidthL1(i) >= mPosX
           && fishl1[i].getPosXL1(i) + fishl1[i].getWidthL1(i) <= mPosX + gMainFish.getWidth()
           && fishl1[i].getPosYL1(i) >= mPosY
           && fishl1[i].getPosYL1(i) <= mPosY + gMainFish.getHeight())
        {
            Mix_PlayChannel(-1,Audio::gEatlevel1,0);
           fishl1[i].AiPosX[i] =-fishl1[i].AI_WIDTHL1 - 350;
            Engine::countl1+=0.5;
        }
    }
}

void MainFish::checkCollision_L2()
{
    for(int i=0;i<maxAIfishes_level2;i++)
    {
        //Fish from right to left
        if(gMainFish.getWidth() > fishr2[i].getWidthR2(i) && gMainFish.getHeight() > fishr2[i].getHeightR2(i)
           && mPosX + gMainFish.getWidth() >= fishr2[i].getPosXR2(i)
           && fishr2[i].getPosXR2(i) >= mPosX && fishr2[i].getPosYR2(i) >= mPosY
           && fishr2[i].getPosYR2(i) <= mPosY + gMainFish.getHeight())
           {
               cout<<"EAT l2"<<endl;
               Mix_PlayChannel(-1,Audio::gEatlevel2,0);
               fishr2[i].AiPosX[i] = SCREEN_WIDTH + fishr2[i].getWidthR2(i) + 500;
               Engine::countl2+=1;
           }
        else if (gMainFish.getWidth() < fishr2[i].getWidthR2(i) && gMainFish.getHeight() < fishr2[i].getHeightR2(i)
                 && mPosX + gMainFish.getWidth() >= fishr2[i].getPosXR2(i)
                 && fishr2[i].getPosXR2(i) >= mPosX && fishr2[i].getPosYR2(i) >= mPosY
                 && fishr2[i].getPosYR2(i) <= mPosY + gMainFish.getHeight())
                    {
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               cout<<"EATEN l2"<<endl;
               gMainFish.free();
           }
        if(gMainFish.getWidth() > fishr2[i].getWidthR2(i) && gMainFish.getHeight() > fishr2[i].getHeightR2(i)
           && fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i) >= mPosX
           && fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i) <= mPosX + gMainFish.getWidth()
           && fishr2[i].getPosYR2(i) >= mPosY && fishr2[i].getPosYR2(i) <= mPosY + gMainFish.getHeight() )
             {
                 cout<<"EAT l2"<<endl;
                Mix_PlayChannel(-1,Audio::gEatlevel2,0);
               fishr2[i].AiPosX[i] = SCREEN_WIDTH + fishr2[i].getWidthR2(i) + 500;
               Engine::countl2+=1;
           }
        else if(gMainFish.getWidth() < fishr2[i].getWidthR2(i) && gMainFish.getHeight() < fishr2[i].getHeightR2(i)
                && fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i) >= mPosX
                && fishr2[i].getPosXR2(i) + fishr2[i].getWidthR2(i) <= mPosX + gMainFish.getWidth()
                && fishr2[i].getPosYR2(i) >= mPosY && fishr2[i].getPosYR2(i) <= mPosY + gMainFish.getHeight() )
                {
                    cout<<"EATEN l2"<<endl;
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               gMainFish.free();
                }
        //Fish from left to right
        if(gMainFish.getWidth() > fishl2[i].AI_WIDTHL2 && gMainFish.getHeight() > fishl2[i].AI_HEIGHTL2
           && mPosX + gMainFish.getWidth() >= fishl2[i].getPosXL2(i)
           && fishl2[i].getPosXL2(i) >= mPosX && fishl2[i].getPosYL2(i) >= mPosY
           && fishl2[i].getPosYL2(i) <= mPosY + gMainFish.getHeight())
           {
               cout<<"EAT l2"<<endl;
               Mix_PlayChannel(-1,Audio::gEatlevel2,0);
               fishl2[i].AiPosX[i] = -fishl2[i].AI_WIDTHL2 - 500;
                Engine::countl2+=1;
           }
        else if(gMainFish.getWidth() < fishl2[i].AI_WIDTHL2 && gMainFish.getHeight() < fishl2[i].AI_HEIGHTL2
           && mPosX + gMainFish.getWidth() >= fishl2[i].getPosXL2(i)
           && fishl2[i].getPosXL2(i) >= mPosX && fishl2[i].getPosYL2(i) >= mPosY
           && fishl2[i].getPosYL2(i) <= mPosY + gMainFish.getHeight())
           {
               cout<<"EATEN l2"<<endl;
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               gMainFish.free();
           }
        if(gMainFish.getWidth() > fishl2[i].AI_WIDTHL2 && gMainFish.getHeight() > fishl2[i].AI_HEIGHTL2
           &&fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) >= mPosX
           && fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) <= mPosX + gMainFish.getWidth()
           && fishl2[i].getPosYL2(i) >= mPosY && fishl2[i].getPosYL2(i) <= mPosY + gMainFish.getHeight())
        {
            cout<<"EAT l2"<<endl;
            Mix_PlayChannel(-1,Audio::gEatlevel2,0);
           fishl2[i].AiPosX[i] =-fishl2[i].AI_WIDTHL2 - 500;
           Engine::countl2+=1;
        }
        else if(gMainFish.getWidth() < fishl2[i].AI_WIDTHL2 && gMainFish.getHeight() < fishl2[i].AI_HEIGHTL2
           &&fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) >= mPosX
           && fishl2[i].getPosXL2(i) + fishl2[i].getWidthL2(i) <= mPosX + gMainFish.getWidth()
           && fishl2[i].getPosYL2(i) >= mPosY && fishl2[i].getPosYL2(i) <= mPosY + gMainFish.getHeight())
           {
               cout<<"EATEN l2"<<endl;
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               gMainFish.free();
           }
    }
}

void MainFish::checkCollision_L3()
{
    for(int i=0;i<maxAIfishes_level3;i++)
    {
        //Fish from right to left
        if(gMainFish.getWidth() > fishr3[i].AI_WIDTHR3 && gMainFish.getHeight() > fishr3[i].AI_HEIGHTR3
           && mPosX + gMainFish.getWidth() >= fishr3[i].getPosXR3(i)
           && fishr3[i].getPosXR3(i) >= mPosX && fishr3[i].getPosYR3(i) >= mPosY
           && fishr3[i].getPosYR3(i) <= mPosY + gMainFish.getHeight())
           {
               Mix_PlayChannel(-1,Audio::gEatlevel3,0);
               fishr3[i].AiPosX[i] = SCREEN_WIDTH + fishr3[i].AI_WIDTHR3 + 70;
               Engine::countl3+=2;
           }
        else if (gMainFish.getWidth() < fishr3[i].AI_WIDTHR3 && gMainFish.getHeight() < fishr3[i].AI_HEIGHTR3
                 && mPosX + gMainFish.getWidth() >= fishr3[i].getPosXR3(i)
           && fishr3[i].getPosXR3(i) >= mPosX && fishr3[i].getPosYR3(i) >= mPosY
           && fishr3[i].getPosYR3(i) <= mPosY + gMainFish.getHeight())
                    {
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               gMainFish.free();
           }
        if(gMainFish.getWidth() > fishr3[i].AI_WIDTHR3 && gMainFish.getHeight() > fishr3[i].AI_HEIGHTR3
           && fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i) >= mPosX
           && fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i) <= mPosX + gMainFish.getWidth()
           && fishr3[i].getPosYR3(i) >= mPosY && fishr3[i].getPosYR3(i) <= mPosY + gMainFish.getHeight() )
             {
               Mix_PlayChannel(-1,Audio::gEatlevel3,0);
               fishr3[i].AiPosX[i] = SCREEN_WIDTH + fishr3[i].AI_WIDTHR3 + 70;
               Engine::countl3+=2;
           }
        else if(gMainFish.getWidth() < fishr3[i].AI_WIDTHR3 && gMainFish.getHeight() < fishr3[i].AI_HEIGHTR3
           && fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i) >= mPosX
           && fishr3[i].getPosXR3(i) + fishr3[i].getWidthR3(i) <= mPosX + gMainFish.getWidth()
           && fishr3[i].getPosYR3(i) >= mPosY && fishr3[i].getPosYR3(i) <= mPosY + gMainFish.getHeight())
                {
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               gMainFish.free();
           }

        //Fish from left to right
        if(gMainFish.getWidth() > fishl3[i].AI_WIDTHL3 && gMainFish.getHeight() > fishl3[i].AI_HEIGHTL3
           && mPosX + gMainFish.getWidth() >= fishl3[i].getPosXL3(i)
           && fishl3[i].getPosXL3(i) >= mPosX && fishl3[i].getPosYL3(i) >= mPosY
           && fishl3[i].getPosYL3(i) <= mPosY + gMainFish.getHeight())
           {
               Mix_PlayChannel(-1,Audio::gEatlevel3,0);
               fishl3[i].AiPosX[i] = -fishl3[i].AI_WIDTHL3 - 70;
                Engine::countl3+=2;
           }
        else if(gMainFish.getWidth() < fishl3[i].AI_WIDTHL3 && gMainFish.getHeight() < fishl3[i].AI_HEIGHTL3
           && mPosX + gMainFish.getWidth() >= fishl3[i].getPosXL3(i)
           && fishl3[i].getPosXL3(i) >= mPosX && fishl3[i].getPosYL3(i) >= mPosY
           && fishl3[i].getPosYL3(i) <= mPosY + gMainFish.getHeight())
           {
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               gMainFish.free();
           }
        if(gMainFish.getWidth() > fishl3[i].AI_WIDTHL3 && gMainFish.getHeight() > fishl3[i].AI_HEIGHTL3
           &&fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) >= mPosX
           && fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) <= mPosX + gMainFish.getWidth()
           && fishl3[i].getPosYL3(i) >= mPosY && fishl3[i].getPosYL3(i) <= mPosY + gMainFish.getHeight())
        {
           Mix_PlayChannel(-1,Audio::gEatlevel3,0);
           fishl3[i].AiPosX[i] =-fishl3[i].AI_WIDTHL3 - 70;
           Engine::countl3+=2;
        }
        else if(gMainFish.getWidth() < fishl3[i].AI_WIDTHL3 && gMainFish.getHeight() < fishl3[i].AI_HEIGHTL3
           &&fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) >= mPosX
           && fishl3[i].getPosXL3(i) + fishl3[i].getWidthL3(i) <= mPosX + gMainFish.getWidth()
           && fishl3[i].getPosYL3(i) >= mPosY && fishl3[i].getPosYL3(i) <= mPosY + gMainFish.getHeight())
           {
               Mix_PlayChannel(-1,Audio::gHavingBeenEaten,0);
               gMainFish.free();
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
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 200;
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
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 200;
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
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 200;
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
               fishr1[j].AiPosX[j] = -fishr1[j].AI_WIDTHR1 - 200;
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
               fishr2[j].AiPosX[j] = -fishr2[j].AI_WIDTHR2 - 200;
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
               fishr2[j].AiPosX[j] = -fishr2[j].AI_WIDTHR2 - 200;
        }
    }
}

void MainFish::renderMainFish( )
{
    cout<<Engine::countl1<<" "<<Engine::countl2<<" "<<Engine::countl3<<endl;
    if(Engine::countl1 >= 4 && Engine::countl2 == 0 && Engine::countl3 == 0 && Engine::level2 == false)
    {
        Mix_PlayChannel(-1,Audio::gNextLevel,0);
        gMainFish.loadImage("textures/characters/anglerfishlv2.png");
        Engine::level2 = true;
    }
    else if(Engine::countl1 + Engine::countl2 >= 10 && Engine::countl3 == 0 && Engine::level3 == false)
    {
        Mix_PlayChannel(-1,Audio::gNextLevel,0);
        gMainFish.loadImage("textures/characters/anglerfishlv3.png");
        Engine::countl3=1;
        Engine::level3 = true;
    }
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
    gMainFish.render( mPosX, mPosY,nullptr,0,nullptr,flip );
    premousex=mousex;
    premousey = mousey;
    //for(int i=0;i <maxBubble;i++) bubble[i].generateBB(i);
}

void win1Game();

int MainFish::getCurrentPosXMainFish()
{
    return mPosX;
}

int MainFish::getCurrentPosYMainFish()
{
    return mPosY;
}
