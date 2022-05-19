#include "AiFishRight.h"

AiFishRight_Level1::AiFishRight_Level1()
{
    for(int i=0;i< maxAIfishes_level1; i++)
    {
        gAiFishRight_level1[i].loadImage(fishlv1);

        AiPosX[i]= SCREEN_WIDTH + AI_WIDTHR1 + 50;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTR1 - 20);

        AiVelX[i]=rand()%maxVel + 1.5;

        AiVelY[i]=rand()%maxVel + 1.5;
    }
}

AiFishRight_Level1::~AiFishRight_Level1()
{
    for(int i=0;i<maxAIfishes_level1;i++)
        gAiFishRight_level1[i].free();
}

void AiFishRight_Level1::moveAIL1(int i)
{
    srand(time(nullptr));

    AiPosX[i]-= AiVelX[i];

    if( (AiPosX[i] <  -AI_WIDTHR1))
    {
        AiPosX[i] = SCREEN_WIDTH + AI_WIDTHR1 + 150;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTR1 - 10);
    }

    AiPosY[i] += AiVelY[i];

    if( AiPosY[i] <= 5.5)
    {
        AiVelY[i] = -AiVelY[i];

        AiPosY[i] += AiVelY[i];
    }

    if( ( AiPosY[i] + AI_HEIGHTR1 > SCREEN_HEIGHT - 20) )
    {
        AiVelY[i] = -AiVelY[i];

        AiPosY[i] += AiVelY[i];
    }


}

void AiFishRight_Level1::renderAIL1(int i){

        gAiFishRight_level1[i].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
}

void AiFishRight_Level1::generateAIRL1(int i)
{
   moveAIL1(i);
   renderAIL1(i);
}

double AiFishRight_Level1::getPosXR1(int i)
{
    return AiPosX[i];
}

double AiFishRight_Level1::getPosYR1(int i)
{
    return AiPosY[i];
}

double AiFishRight_Level1::getWidthR1(int i)
{
    return gAiFishRight_level1[i].getWidth();
}

double AiFishRight_Level1::getHeightR1(int i)
{
    return gAiFishRight_level1[i].getHeight();
}

AiFishRight_Level2::AiFishRight_Level2()
{
    for(int i=0;i< maxAIfishes_level2; i++)
    {
        gAiFishRight_level2[i].loadImage(fishlv2);

        AiPosX[i]= SCREEN_WIDTH + AI_WIDTHR2 + 150;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTR2 - 20);

        AiVelX[i]=rand()%maxVel + 0.75;

        AiVelY[i]=rand()%maxVel + 0.75;
    }
}

AiFishRight_Level2::~AiFishRight_Level2()
{
    for(int i=0;i<maxAIfishes_level2;i++)
        gAiFishRight_level2[i].free();
}

void AiFishRight_Level2::moveAIL2(int i)
{
    srand(time(nullptr));

    AiPosX[i]-= AiVelX[i];

    if( (AiPosX[i] <  -AI_WIDTHR2))
    {
        AiPosX[i] = SCREEN_WIDTH + 200 + AI_WIDTHR2;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTR2 - 10);
    }

    AiPosY[i] += 0.075*AiVelY[i];

    if(AiPosY[i] + AI_HEIGHTR2 > SCREEN_HEIGHT + 4)
    {
        AiPosX[i]= SCREEN_WIDTH + 200 + AI_WIDTHR2;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - AI_HEIGHTR2 - 20);

        AiVelY[i]=rand()%maxVel + 0.75;
    }
}


void AiFishRight_Level2::renderAIL2(int i){

        gAiFishRight_level2[i].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
}

void AiFishRight_Level2::generateAIRL2(int i)
{
   moveAIL2(i);
   renderAIL2(i);
}

double AiFishRight_Level2::getPosXR2(int i)
{
    return AiPosX[i];
}

double AiFishRight_Level2::getPosYR2(int i)
{
    return AiPosY[i];
}

double AiFishRight_Level2::getWidthR2(int i)
{
    return gAiFishRight_level2[i].getWidth();
}

double AiFishRight_Level2::getHeightR2(int i)
{
    return gAiFishRight_level2[i].getHeight();
}

AiFishRight_Level3::AiFishRight_Level3()
{
    for(int i=0;i< maxAIfishes_level3; i++)
    {
        gAiFishRight_level3[i].loadImage(fishlv3);
        AiPosX[i]= SCREEN_WIDTH + AI_WIDTHR3 + 350;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTR3 - 20);

        AiVelX[i]=rand()%maxVel + 0.2;

        AiVelY[i]=rand()%maxVel + 0.2;
    }
}

AiFishRight_Level3::~AiFishRight_Level3()
{
    for(int i=0;i<maxAIfishes_level3;i++)
        gAiFishRight_level3[i].free();
}
void AiFishRight_Level3::moveAIL3(int i)
{
    srand(time(nullptr));

    AiPosX[i]-= AiVelX[i];

    if( (AiPosX[i] <  -AI_WIDTHR3))
    {
        AiPosX[i] = SCREEN_WIDTH + AI_WIDTHR3 + 300;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTR3 - 10);
    }

    AiPosY[i] += 0.075*AiVelY[i];

    if(AiPosY[i] + AI_HEIGHTR3 > SCREEN_HEIGHT + 4)
    {
        AiPosX[i]= SCREEN_WIDTH + 300 + AI_WIDTHR3;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - AI_HEIGHTR3 - 20);

        AiVelY[i]=rand()%maxVel + 0.2;
    }

}

void AiFishRight_Level3::renderAIL3(int i){

        gAiFishRight_level3[i].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
}

void AiFishRight_Level3::generateAIRL3(int i)
{
   moveAIL3(i);
   renderAIL3(i);
}

double AiFishRight_Level3::getPosXR3(int i)
{
    return AiPosX[i];
}

double AiFishRight_Level3::getPosYR3(int i)
{
    return AiPosY[i];
}

double AiFishRight_Level3::getWidthR3(int i)
{
    return gAiFishRight_level3[i].getWidth();
}

double AiFishRight_Level3::getHeightR3(int i)
{
    return gAiFishRight_level3[i].getHeight();
}
