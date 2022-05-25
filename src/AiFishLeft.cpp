#include "AiFishLeft.h"

AiFishLeft_Level1::AiFishLeft_Level1()
{
    update();
}

AiFishLeft_Level1::~AiFishLeft_Level1()
{
    for(int i=0;i<3*maxAIfishes_level1;i++)
        gAiFishLeft_Level1[i].free();
}
void AiFishLeft_Level1::update()
{
    for(int i=0;i < maxAIfishes_level1*2;i+=3)
    {
        gAiFishLeft_Level1[i].loadImage(fishlv1);

        gAiFishLeft_Level1[i+1].loadImage(fishlv1_1);

        gAiFishLeft_Level1[i+2].loadImage(fishlv1_2);
    }

    for(int i=0;i< maxAIfishes_level1; i++)
    {
        timer[i].start();

        frame[i] = 0;

        AiPosX[i]= -gAiFishLeft_Level1[i].getWidth() - 50;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - gAiFishLeft_Level1[i].getHeight() - 90 + 1) + 90;

        AiVelX[i]=rand()%maxVel + 1.5 ;

        AiVelY[i]=rand()%maxVel + 1.5;
    }
}
void AiFishLeft_Level1::moveAIL1(int i)
{
    AiPosX[i]+= AiVelX[i];

    if((AiPosX[i] + gAiFishLeft_Level1[i].getWidth() > SCREEN_WIDTH))
    {
        AiPosX[i] = -gAiFishLeft_Level1[i].getWidth() ;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - gAiFishLeft_Level1[i].getHeight() - 20);

        AiVelX[i]=rand()%maxVel + 1.5 ;
    }

    AiPosY[i] +=AiVelY[i]* 0.35;

    if( AiPosY[i] <= 86)
    {
        AiVelY[i] = -AiVelY[i];

        AiPosY[i] += AiVelY[i];
    }
    if( ( AiPosY[i] + gAiFishLeft_Level1[i].getHeight() > SCREEN_HEIGHT - 10) )
    {
        AiVelY[i] = -AiVelY[i];

        AiPosY[i] += AiVelY[i];
    }

}

void AiFishLeft_Level1::renderAIL1(int i)
{
    if(frame[i] == 3) frame[i] =0;
    int index= 3*i + frame[i];
    gAiFishLeft_Level1[index].render(AiPosX[i],AiPosY[i],nullptr,0,nullptr,flip);
    if((timer[i].get_ticks())%15 == 0) frame[i]++;
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
    update();
}

AiFishLeft_Level2::~AiFishLeft_Level2()
{
    for(int i=0;i<maxAIfishes_level2 * 4;i++)
        gAiFishLeft_Level2[i].free();
}

void AiFishLeft_Level2::update()
{
    for(int i=0; i < 3*maxAIfishes_level2 ; i+=4)
    {
        gAiFishLeft_Level2[i].loadImage(fishlv2);

        gAiFishLeft_Level2[i+1].loadImage(fishlv2_1);

        gAiFishLeft_Level2[i+2].loadImage(fishlv2_2);

        gAiFishLeft_Level2[i+3].loadImage(fishlv2_3);
    }

    for(int i=0;i< maxAIfishes_level2; i++)
    {
        timer[i].start();
        frame[i] =0;

        AiPosX[i]= -gAiFishLeft_Level2[i].getWidth() ;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - gAiFishLeft_Level2[i].getHeight() - 90 + 1) + 87;

        AiVelX[i]=rand()%maxVel + 0.75;

        AiVelY[i]=rand()%maxVel + 0.75;
    }
}
void AiFishLeft_Level2::moveAIL2(int i)
{
    AiPosX[i]+= AiVelX[i];

    if( AiPosX[i] > SCREEN_WIDTH + gAiFishLeft_Level2[i].getWidth() + 5)
    {
        AiPosX[i] = -gAiFishLeft_Level2[i].getWidth() ;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - gAiFishLeft_Level2[i].getHeight() - 20);

        AiVelX[i]=rand()%maxVel + 0.75;
    }

     AiPosY[i] += 0.075*AiVelY[i];

    if(AiPosY[i] + gAiFishLeft_Level2[i].getHeight() > SCREEN_HEIGHT + 4)
    {
        AiPosX[i]= -gAiFishLeft_Level2[i].getWidth() ;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - gAiFishLeft_Level2[i].getHeight() - 90 + 1) + 90;

        AiVelY[i]=rand()%maxVel + 0.75;
    }

}

void AiFishLeft_Level2::renderAIL2(int i)
{
    if(frame[i] == 4) frame[i] = 0;
    int index = 4*i + frame[i];
    gAiFishLeft_Level2[index].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
    if((timer[i].get_ticks()%10) == 0) frame[i] ++;

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
    update();
}

AiFishLeft_Level3::~AiFishLeft_Level3()
{
    for(int i=0;i<maxAIfishes_level3*3;i++)
        gAiFishLeft_Level3[i].free();
}

void AiFishLeft_Level3::update()
{
    for(int i=0; i<maxAIfishes_level3*2; i+=3)
    {
        gAiFishLeft_Level3[i].loadImage(fishlv3);

        gAiFishLeft_Level3[i+1].loadImage(fishlv3_1);

        gAiFishLeft_Level3[i+2].loadImage(fishlv3_2);
    }
    for(int i=0;i< maxAIfishes_level3; i++)
    {
        frame[i] = 0;

        timer[i].start();

        AiPosX[i]= -AI_WIDTHL3 ;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTL3 - 90 + 1) + 90;

        AiVelX[i]=rand()%maxVel + 0.2;

        AiVelY[i]=rand()%maxVel + 0.2;
    }
}
void AiFishLeft_Level3::moveAIL3(int i)
{
    AiPosX[i]+= AiVelX[i];

    if((AiPosX[i] + AI_WIDTHL3 > SCREEN_WIDTH))
    {
      AiPosX[i] = -AI_WIDTHL3 - 100;

      AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTL3 - 20);

      AiVelX[i]=rand()%maxVel + 0.2;
    }

    AiPosY[i] += 0.0175*AiVelY[i];

    if( AiPosY[i] + AI_HEIGHTL3 > SCREEN_HEIGHT )
    {
        AiPosX[i]= -AI_WIDTHL3 - 100;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTL3 - 90 + 1) + 1;

        AiVelY[i]=rand()%maxVel + 0.2;
    }
}

void AiFishLeft_Level3::renderAIL3(int i){
        if(frame[i] == 3) frame[i] = 0;
        int index = 3*i + frame[i];

        gAiFishLeft_Level3[index].render(AiPosX[i],AiPosY[i],nullptr,0,nullptr,flip);

        if((timer[i].get_ticks()%15) == 0) frame[i]++;
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
