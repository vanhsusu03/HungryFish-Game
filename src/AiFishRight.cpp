#include "AiFishRight.h"

AiFishRight_Level1::AiFishRight_Level1()
{

}

AiFishRight_Level1::~AiFishRight_Level1()
{
    for(int i=0;i<maxAIfishes_level1*3;i++)
        gAiFishRight_level1[i].free();
}

void AiFishRight_Level1::update()
{
    for(int i=0; i< maxAIfishes_level1*2; i+=3)
    {
        gAiFishRight_level1[i].loadImage(fishlv1);

        gAiFishRight_level1[i+1].loadImage(fishlv1_1);

        gAiFishRight_level1[i+2].loadImage(fishlv1_2);
    }
    for(int i=0;i< maxAIfishes_level1; i++)
    {
        frame[i] = 0;

        timer[i].start();

        AiPosX[i]= SCREEN_WIDTH + AI_WIDTHR1 + 50;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTR1 - 90 + 1) + 90;

        AiVelX[i]=rand()%maxVel + 1.5;

        AiVelY[i]=rand()%maxVel + 1.5;
    }
}

void AiFishRight_Level1::moveAIL1(int i)
{
    srand(time(nullptr));

    AiPosX[i]-= AiVelX[i];

    if( (AiPosX[i] <  -AI_WIDTHR1))
    {
        AiPosX[i] = SCREEN_WIDTH + AI_WIDTHR1 ;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTR1 - 10);
    }

    AiPosY[i] += AiVelY[i]*0.35;

    if( AiPosY[i] <= 86)
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

        if(frame[i] == 3) frame[i] =0;
        int index=3*i + frame[i];
        gAiFishRight_level1[index].render(AiPosX[i],AiPosY[i],nullptr,0,nullptr,flip);

        if((timer[i].get_ticks())%15 == 0) frame[i]++;
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

}

AiFishRight_Level2::~AiFishRight_Level2()
{
    for(int i=0;i<maxAIfishes_level2 * 4;i++)
        gAiFishRight_level2[i].free();
}

void AiFishRight_Level2::update()
{

    for(int i=0; i < 3*maxAIfishes_level2 ; i+=4)
    {
        gAiFishRight_level2[i].loadImage(fishlv2);

        gAiFishRight_level2[i+1].loadImage(fishlv2_1);

        gAiFishRight_level2[i+2].loadImage(fishlv2_2);

        gAiFishRight_level2[i+3].loadImage(fishlv2_3);
    }

    for(int i=0;i< maxAIfishes_level2; i++)
    {
        timer[i].start();

        frame[i] = 0;

        AiPosX[i]= SCREEN_WIDTH + AI_WIDTHR2;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTR2 - 90 + 1) + 90;

        AiVelX[i]=rand()%maxVel + 0.75;

        AiVelY[i]=rand()%maxVel + 0.75;
    }
}

void AiFishRight_Level2::moveAIL2(int i)
{

    AiPosX[i]-= AiVelX[i];

    if( (AiPosX[i] <  -AI_WIDTHR2))
    {
        AiPosX[i] = SCREEN_WIDTH + AI_WIDTHR2;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTR2 - 10);
    }

    AiPosY[i] += 0.075*AiVelY[i];

    if(AiPosY[i] + AI_HEIGHTR2 > SCREEN_HEIGHT + 4)
    {
        AiPosX[i]= SCREEN_WIDTH + AI_WIDTHR2;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - AI_HEIGHTR2 - 90+1) + 1;

        AiVelY[i]=rand()%maxVel + 0.75;
    }
}


void AiFishRight_Level2::renderAIL2(int i){
    if(frame[i] == 4) frame[i] = 0;
    int index = 4*i + frame[i];
    gAiFishRight_level2[index].render(AiPosX[i], AiPosY[i],nullptr,0,nullptr,flip);
    if((timer[i].get_ticks()%10) == 0) frame[i] ++;

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

}

AiFishRight_Level3::~AiFishRight_Level3()
{
    for(int i=0;i<maxAIfishes_level3*3;i++)
        gAiFishRight_level3[i].free();
}

void AiFishRight_Level3::update()
{
     for(int i=0;i < maxAIfishes_level2*2; i+=3)
    {
        gAiFishRight_level3[i].loadImage(fishlv3);

        gAiFishRight_level3[i+1].loadImage(fishlv3_1);

        gAiFishRight_level3[i+2].loadImage(fishlv3_2);
    }
    for(int i=0;i< maxAIfishes_level3; i++)
    {
        frame[i] = 0;

        timer[i].start();

        AiPosX[i]= SCREEN_WIDTH + AI_WIDTHR3 ;

        AiPosY[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTR3 - 90 + 1) + 90;

        AiVelX[i]=rand()%maxVel + 0.2;

        AiVelY[i]=rand()%maxVel + 0.2;
    }
}


void AiFishRight_Level3::moveAIL3(int i)
{

    AiPosX[i]-= AiVelX[i];

    if( (AiPosX[i] <  -AI_WIDTHR3))
    {
        AiPosX[i] = SCREEN_WIDTH + AI_WIDTHR3 + 50;

        AiPosY[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTR3 - 10);
    }

    AiPosY[i] += 0.075*AiVelY[i];

    if(AiPosY[i] + AI_HEIGHTR3 > SCREEN_HEIGHT + 4)
    {
        AiPosX[i]= SCREEN_WIDTH + 50 + AI_WIDTHR3;

        AiPosY[i]= rand()%(SCREEN_HEIGHT - AI_HEIGHTR3 - 90 + 1) + 90;

        AiVelY[i]=rand()%maxVel + 0.2;
    }

}

void AiFishRight_Level3::renderAIL3(int i){

        if(frame[i] == 3) frame[i] = 0;

        gAiFishRight_level3[3*i + frame[i]].render(AiPosX[i],AiPosY[i],nullptr,0,nullptr,flip);

        if((timer[i].get_ticks() % 15) == 0) frame[i] ++;
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
