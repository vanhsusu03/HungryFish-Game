#include "Menu.h"

//MenuFish

MenuFishLevel1::MenuFishLevel1()
{
    for(int i=0;i< maxAIfishes_level1 - 2; i++)
    {
        gMenuFishL[i].loadImage(fishlv1);
        gMenuFishR[i].loadImage(fishlv1);

        AiPosXL[i]= -AI_WIDTHL1 ;

        AiPosYL[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTL1 - 10);

        AiVelXL[i]=rand()%maxVel + 1.5 ;

        AiVelYL[i]=rand()%maxVel + 1.5;

        AiPosXR[i]= SCREEN_WIDTH + AI_WIDTHL1;

        AiPosYR[i]= rand()% (SCREEN_HEIGHT - AI_HEIGHTL1 - 20);

        AiVelXR[i]=rand()%maxVel + 1.5;

        AiVelYR[i]=rand()%maxVel + 1.5;
    }
}

MenuFishLevel1::~MenuFishLevel1()
{
    for(int i=0;i<maxAIfishes_level1 - 2 ; i++)
    {
        gMenuFishL[i].free();
        gMenuFishR[i].free();
    }
}

void MenuFishLevel1::moveAIL(int i)
{
    AiPosXL[i]+= AiVelXL[i];

    if((AiPosXL[i] + AI_WIDTHL1 > SCREEN_WIDTH))
    {
        AiPosXL[i] = -AI_WIDTHL1 - 50;

        AiPosYL[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTL1 - 20);

        AiVelXL[i]=rand()%maxVel + 1.5 ;
    }

    AiPosYL[i] +=AiVelYL[i];

    if( AiPosYL[i] <= 6)
    {
        AiVelYL[i] = -AiVelYL[i];

        AiPosYL[i] += AiVelYL[i];
    }
    if( ( AiPosYL[i] + AI_HEIGHTL1 > SCREEN_HEIGHT - 10) )
    {
        AiVelYL[i] = -AiVelYL[i];

        AiPosYL[i] += AiVelYL[i];
    }
}

void MenuFishLevel1::moveAIR(int i)
{
    AiPosXR[i]-= AiVelXR[i];

    if( (AiPosXR[i] <  -AI_WIDTHL1))
    {
        AiPosXR[i] = SCREEN_WIDTH + AI_WIDTHL1 + 50;

        AiPosYR[i] = rand()% (SCREEN_HEIGHT - AI_HEIGHTL1 - 10);
    }

    AiPosYR[i] += AiVelYR[i];

    if( AiPosYR[i] <= 5.5)
    {
        AiVelYR[i] = -AiVelYR[i];

        AiPosYR[i] += AiVelYR[i];
    }

    if( ( AiPosYR[i] + AI_HEIGHTL1 > SCREEN_HEIGHT - 20) )
    {
        AiVelYR[i] = -AiVelYR[i];

        AiPosYR[i] += AiVelYR[i];
    }
}

void MenuFishLevel1::renderAIL(int i)
{
    gMenuFishL[i].render(AiPosXL[i],AiPosYL[i],nullptr,0,nullptr,flipL);
}

void MenuFishLevel1::renderAIR(int i)
{
    gMenuFishR[i].render(AiPosXR[i], AiPosYR[i], nullptr, 0, nullptr, flipR);
}

void MenuFishLevel1::generateAIL(int i)
{
    moveAIL(i);
    renderAIL(i);
}

void MenuFishLevel1::generateAIR(int i)
{
    moveAIR(i);
    renderAIR(i);
}

void MenuFishLevel1::moveFishMenu()
{
    for(int i=0;i<maxAIfishes_level1-2;i++)
    {
        generateAIL(i);
        generateAIR(i);
    }
}

//Menu
Menu::Menu()
{
    gMenu = Mix_LoadMUS("audios/Ins_Help_HighS_Setting.mp3");
    loadSource();
}

Menu::~Menu()
{

}

void Menu::loadSource()
{
   gLogo.loadImage(logo);
   gPlayGame[0].loadImage(playgame);
   gInstruction[0].loadImage(instruc);
   gOptions[0].loadImage(option);
   gQuit[0].loadImage(quit);
   gHighScores[0].loadImage(highsc);
   gCredits[0].loadImage(cred);
   gPlayGame[1].loadImage(playgame_button);
   gInstruction[1].loadImage(instruc_button);
   gOptions[1].loadImage(option_button);
   gQuit[1].loadImage(quit_button);
   gHighScores[1].loadImage(highsc_button);
   gCredits[1].loadImage(cred_button);
   gBackground.loadImage("textures/menu/background.png");

}

void Menu::renderLogo()
{
    gLogo.render(400,mPosYMenu,nullptr,0,nullptr,flip);

    mPosYMenu+=velLogo;

    if(mPosYMenu >= 19) velLogo=-velLogo;
    if(mPosYMenu <= 11) velLogo = -velLogo;
}

void Menu::renderFish()
{
    fishmn.moveFishMenu();
}

void Menu::renderButtons()
{
    gBackground.render(0,0,nullptr,0,nullptr,flip);
    //gLogo.render(400,17,nullptr,0,nullptr,flip);
    renderLogo();
    gPlayGame[0].render(325,280, nullptr,-8,nullptr,flip);
    gInstruction[0].render(615,337,nullptr,8,nullptr,flip);
    gHighScores[0].render(345,425,nullptr,-8,nullptr,flip);
    gOptions[0].render(635,505,nullptr,8,nullptr,flip);
    gQuit[0].render(500,580,nullptr,0,nullptr,flip);
    gCredits[0].render(60,580,nullptr,0,nullptr,flip);
    //ON BUTTON
    if(mousex >= gPlayGame[0].getPosX() && mousex <= gPlayGame[0].getPosX() + gPlayGame[0].getWidth()
        && mousey >= gPlayGame[0].getPosY() && mousey <= gPlayGame[0].getPosY() + gPlayGame[0].getHeight())
        {
            gPlayGame[1].render(325,280,nullptr,-8,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gInstruction[0].getPosX() && mousex <= gInstruction[0].getPosX() + gInstruction[0].getWidth()
        && mousey >= gInstruction[0].getPosY() && mousey <= gInstruction[0].getPosY() + gInstruction[0].getHeight())
        {
            gInstruction[1].render(615,337,nullptr,8,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gHighScores[0].getPosX() && mousex <= gHighScores[0].getPosX() + gHighScores[0].getWidth()
        && mousey >= gHighScores[0].getPosY() && mousey <= gHighScores[0].getPosY() + gHighScores[0].getHeight())
        {
            gHighScores[1].render(345,425,nullptr,-8,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gOptions[0].getPosX() && mousex <= gOptions[0].getPosX() + gOptions[0].getWidth()
        && mousey >= gOptions[0].getPosY() && mousey <= gOptions[0].getPosY() + gOptions[0].getHeight())
        {
            gOptions[1].render(635,505,nullptr,8,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gQuit[0].getPosX() && mousex <= gQuit[0].getPosX() + gQuit[0].getWidth()
        && mousey >= gQuit[0].getPosY() && mousey <= gQuit[0].getPosY() + gQuit[0].getHeight())
        {
            gQuit[1].render(500,580,nullptr,0,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gCredits[0].getPosX() && mousex <= gCredits[0].getPosX() + gCredits[0].getWidth()
        && mousey >= gCredits[0].getPosY() && mousey <= gCredits[0].getPosY() + gCredits[0].getHeight())
        {
            gCredits[1].render(60,580,nullptr,0,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
}

void Menu::loadSourceOpts()
{
   gOpts.loadImage(opt_load);
   gBack[0].loadImage(cback);
   gBack[1].loadImage(cback_button);
   gBubbleM[0].loadImage(bub);
   gBubbleS[0].loadImage(bub);
   gBubbleM[1].loadImage(bub_button);
   gBubbleS[1].loadImage(bub_button);
   gTickM.loadImage(tick);
   gTickS.loadImage(tick);
}
void Menu::renderOpts()
{
    gOpts.render(0,0,nullptr,0,nullptr,flip);
    gBack[0].render(560,472,nullptr,0,nullptr,cbflip);
    gBubbleM[0].render (505,325,nullptr,0,nullptr,flip);
    gBubbleS[0].render (505,440,nullptr,0,nullptr,flip);
    if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
        && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
        {
            gBack[1].render(560,472,nullptr,0,nullptr,cbflip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gBubbleM[0].getPosX() && mousex <= gBubbleM[0].getPosX() + gBubbleM[0].getWidth()
        && mousey >= gBubbleM[0].getPosY() && mousey <= gBubbleM[0].getPosY() + gBubbleM[0].getHeight())
        {
            gBubbleM[1].render(505,325,nullptr,0,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gBubbleS[0].getPosX() && mousex <= gBubbleS[0].getPosX() + gBubbleS[0].getWidth()
        && mousey >= gBubbleS[0].getPosY() && mousey <= gBubbleS[0].getPosY() + gBubbleS[0].getHeight())
        {
            gBubbleS[1].render(505,440,nullptr,0,nullptr,flip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(Engine::tickM == true)
    {
        gTickM.render(512,310,nullptr,0,nullptr,flip);
    }
    if(Engine::tickS == true)
    {
        gTickS.render(512,427,nullptr,0,nullptr,flip);
    }
}

void Menu::mainOpts()
{
    runningOpts = true;
    while(runningOpts)
    {
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime =0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }

        SDL_GetMouseState(&mousex,&mousey);
        renderOpts();

        SDL_RenderPresent(Engine::gRenderer);

        while (SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningOpts = false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
                && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
                    {
                        //Engine::status = 0;
                        runningOpts = false;
                        return ;
                    }
                if(mousex >= gBubbleM[0].getPosX() && mousex <= gBubbleM[0].getPosX() + gBubbleM[0].getWidth()
                && mousey >= gBubbleM[0].getPosY() && mousey <= gBubbleM[0].getPosY() + gBubbleM[0].getHeight())
                    {
                        if(Engine::tickM == true) Engine::tickM = false;
                        else Engine::tickM = true;
                    }
                if(mousex >= gBubbleS[0].getPosX() && mousex <= gBubbleS[0].getPosX() + gBubbleS[0].getWidth()
                && mousey >= gBubbleS[0].getPosY() && mousey <= gBubbleS[0].getPosY() + gBubbleS[0].getHeight())
                    {
                        if(Engine::tickS == true) Engine::tickS = false;
                        else Engine::tickS = true;
                    }
            }
        }
    }
}

void Menu::loadSourceInstruc()
{
    gInstruc.loadImage(ins_load);
    gBack[0].loadImage(cback);
    gBack[1].loadImage(cback_button);
    gInstruc.render(0,0,nullptr,0,nullptr,flip);
}

void Menu::renderInstruc()
{
    gBack[0].render(50,50,nullptr,0,nullptr,cbflip);
    if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
        && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
        {
            gBack[1].render(50,50,nullptr,0,nullptr,cbflip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
}

void Menu::mainIns()
{
    runningInstruc = true;
    while(runningInstruc)
    {
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime =0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }

        SDL_GetMouseState(&mousex,&mousey);
        renderInstruc();

        SDL_RenderPresent(Engine::gRenderer);

        while (SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningInstruc = false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
                && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
                    {
                        runningInstruc = false;
                        return ;
                    }
            }
        }
    }
}

void Menu::firstmenu()
{
    //Mix_PlayMusic(gMenu,-1);
    runningMenu = true;
    while (runningMenu)
    {
        if(Engine::tickM == false)
        {
            Mix_HaltMusic();
        }
        else  Mix_PlayMusic(gMenu,-1);
        if(Engine::tickS == false)
        {
            Mix_HaltChannel(-1);
        }
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime = 0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }
        SDL_SetRenderDrawColor(Engine::gRenderer,255,255,255,255);
        SDL_RenderClear(Engine::gRenderer);

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }
        SDL_GetMouseState(&mousex,&mousey);

        renderFish();

        renderButtons();

        SDL_RenderPresent(Engine::gRenderer);

        while(SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningMenu=false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gPlayGame[0].getPosX() && mousex <= gPlayGame[0].getPosX() + gPlayGame[0].getWidth()
                    && mousey >= gPlayGame[0].getPosY() && mousey <= gPlayGame[0].getPosY() + gPlayGame[0].getHeight())
                    {
                        Engine::status=1;
                        runningMenu = false;
                        return;
                    }
                if(mousex >= gInstruction[0].getPosX() && mousex <= gInstruction[0].getPosX() + gInstruction[0].getWidth()
                    && mousey >= gInstruction[0].getPosY() && mousey <= gInstruction[0].getPosY() + gInstruction[0].getHeight())
                    {
                        loadSourceInstruc();
                        mainIns();
                    }
                if(mousex >= gHighScores[0].getPosX() && mousex <= gHighScores[0].getPosX() + gHighScores[0].getWidth()
                    && mousey >= gHighScores[0].getPosY() && mousey <= gHighScores[0].getPosY() + gHighScores[0].getHeight())
                    {
                        Engine::status = 3;
                        runningMenu = false;
                        return;
                    }
                if(mousex >= gOptions[0].getPosX() && mousex <= gOptions[0].getPosX() + gOptions[0].getWidth()
                   && mousey >= gOptions[0].getPosY() && mousey <= gOptions[0].getPosY() + gOptions[0].getHeight())
                    {
                        loadSourceOpts();
                        mainOpts();
                    }
                if(mousex >= gCredits[0].getPosX() && mousex <= gCredits[0].getPosX() + gCredits[0].getWidth()
                   && mousey >= gCredits[0].getPosY() && mousey <= gCredits[0].getPosY() + gCredits[0].getHeight())
                    {
                        Engine::status = 5;
                        runningMenu = false;
                        return;
                    }
                if(mousex >= gQuit[0].getPosX() && mousex <= gQuit[0].getPosX() + gQuit[0].getWidth()
                    && mousey >= gQuit[0].getPosY() && mousey <= gQuit[0].getPosY() + gQuit[0].getHeight())
                    {
                        runningMenu = false;
                        Engine::quitloop = true;
                        return;
                    }
            }
        }

    }
}



