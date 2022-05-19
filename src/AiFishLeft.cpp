#include "AiFishLeft.h"

AiFishLeft_Level1::AiFishLeft_Level1()
{
    for(int i=0;i< maxAIfishes_level1; i++)
    {
        gAiFishLeft_Level1[i].loadImage(fishlv1);

        AiPosX[i]= -AI_WIDTHL1 - 50;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTL1 - 10);

        AiVelX[i]=rand()%maxVel + 1.5 ;

        AiVelY[i]=rand()%maxVel + 1.5;
    }
}

AiFishLeft_Level1::~AiFishLeft_Level1()
{
    for(int i=0;i<maxAIfishes_level1;i++)
        gAiFishLeft_Level1[i].free();
}

void AiFishLeft_Level1::moveAIL1(int i)
{
    srand(time(nullptr));

    AiPosX[i]+= AiVelX[i];

    if((AiPosX[i] + AI_WIDTHL1 > SCREEN_WIDTH))
    {
        AiPosX[i] = -AI_WIDTHL1 - 100;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTL1 - 20);

        AiVelX[i]=rand()%maxVel + 1.5 ;
    }

    AiPosY[i] +=AiVelY[i];

    if( AiPosY[i] <= 6)
    {
        AiVelY[i] = -AiVelY[i];

        AiPosY[i] += AiVelY[i];
    }
    if( ( AiPosY[i] + AI_HEIGHTL1 > SCREEN_HEIGHT - 10) )
    {
        AiVelY[i] = -AiVelY[i];

        AiPosY[i] += AiVelY[i];
    }

}

void AiFishLeft_Level1::renderAIL1(int i)
{
    gAiFishLeft_Level1[i].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
}

void AiFishLeft_Level1::generateAILL1(int i)
{
    moveAIL1(i);
    renderAIL1(i);
}

double AiFishLeft_Level1::getPosXL1(int i)
{
    return AiPosX[i];
}

double AiFishLeft_Level1::getPosYL1(int i)
{
    return AiPosY[i];
}

double AiFishLeft_Level1::getWidthL1(int i)
{
    return gAiFishLeft_Level1[i].getWidth();
}

double AiFishLeft_Level1::getHeightL1(int i)
{
    return gAiFishLeft_Level1[i].getHeight();
}

AiFishLeft_Level2::AiFishLeft_Level2()
{
    for(int i=0;i< maxAIfishes_level2; i++)
    {
        gAiFishLeft_Level2[i].loadImage(fishlv2);

        AiPosX[i]= -AI_WIDTHL2 - 150;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - AI_HEIGHTL2 - 20);

        AiVelX[i]=rand()%maxVel + 0.75;

        AiVelY[i]=rand()%maxVel + 0.75;
    }
}

AiFishLeft_Level2::~AiFishLeft_Level2()
{
    for(int i=0;i<maxAIfishes_level2;i++)
        gAiFishLeft_Level2[i].free();
}

void AiFishLeft_Level2::moveAIL2(int i)
{
    srand(time(0));

    AiPosX[i]+= AiVelX[i];

    if( AiPosX[i] > SCREEN_WIDTH + AI_WIDTHL2 + 5)
    {
        AiPosX[i] = -AI_WIDTHL2 - 200;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTL2 - 20);

        AiVelX[i]=rand()%maxVel + 0.75;
    }

     AiPosY[i] += 0.075*AiVelY[i];

    if(AiPosY[i] + AI_HEIGHTL2 > SCREEN_HEIGHT + 4)
    {
        AiPosX[i]= -AI_WIDTHL2 - 200;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - AI_HEIGHTL2 - 20);

        AiVelY[i]=rand()%maxVel + 0.75;
    }

}

void AiFishLeft_Level2::renderAIL2(int i)
{
    gAiFishLeft_Level2[i].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
}

void AiFishLeft_Level2::generateAILL2(int i)
{
    moveAIL2(i);
    renderAIL2(i);
}

double AiFishLeft_Level2::getPosXL2(int i)
{
    return AiPosX[i];
}

double AiFishLeft_Level2::getPosYL2(int i)
{
    return AiPosY[i];
}

double AiFishLeft_Level2::getWidthL2(int i)
{
    return gAiFishLeft_Level2[i].getWidth();
}

double AiFishLeft_Level2::getHeightL2(int i)
{
    return gAiFishLeft_Level2[i].getHeight();
}

AiFishLeft_Level3::AiFishLeft_Level3()
{
    for(int i=0;i< maxAIfishes_level3; i++)
    {
        gAiFishLeft_Level3[i].loadImage(fishlv3);

        AiPosX[i]= -AI_WIDTHL3 - 200;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTL3 - 20);

        AiVelX[i]=rand()%maxVel + 0.2;

        AiVelY[i]=rand()%maxVel + 0.2;
    }
}

AiFishLeft_Level3::~AiFishLeft_Level3()
{
    for(int i=0;i<maxAIfishes_level3;i++)
        gAiFishLeft_Level3[i].free();
}

void AiFishLeft_Level3::moveAIL3(int i)
{
    srand(time(0));

    AiPosX[i]+= AiVelX[i];

    if((AiPosX[i] + AI_WIDTHL3 > SCREEN_WIDTH))
    {
      AiPosX[i] = -AI_WIDTHL3 - 400;

      AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTL3 - 20);

      AiVelX[i]=rand()%maxVel + 0.2;
    }

    AiPosY[i] += 0.0175*AiVelY[i];

    if( AiPosY[i] + AI_HEIGHTL3 > SCREEN_HEIGHT )
    {
        AiPosX[i]= -AI_WIDTHL3 - 400;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTL3 - 20);

        AiVelY[i]=rand()%maxVel + 0.2;
    }
}

void AiFishLeft_Level3::renderAIL3(int i){
         gAiFishLeft_Level3[i].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
}

void AiFishLeft_Level3::generateAILL3(int i)
{
    moveAIL3(i);
    renderAIL3(i);
}

double AiFishLeft_Level3::getPosXL3(int i)
{
    return AiPosX[i];
}

double AiFishLeft_Level3::getPosYL3(int i)
{
    return AiPosY[i];
}

double AiFishLeft_Level3::getWidthL3(int i)
{
    return gAiFishLeft_Level3[i].getWidth();
}

double AiFishLeft_Level3::getHeightL3(int i)
{
    return gAiFishLeft_Level3[i].getHeight();
}
