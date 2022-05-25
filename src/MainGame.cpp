#include "MainGame.h"


MainGame::MainGame()
{
    gBackground.loadImage(background);
    gEndBackgr.loadImage(menu);
    gPaused.loadImage(pau);
    gResume[0].loadImage(res);
    gResume[1].loadImage(res_but);
    gHome[0].loadImage(home);
    gHome[1].loadImage(home_but);
    border.loadImage(bord);
    board.loadImage(board_game);
    gLogo1.loadImage(fishlv1_logo);
    gLogo2.loadImage(fishlv2_logo);
    gLogo3.loadImage(fishlv3_logo);
    colorText = {10,55,84,255};
}

MainGame::~MainGame()
{

}

void MainGame::renderButtonPaused()
{
    gPaused.render(275,175,nullptr,0,nullptr,flipp);
    gResume[0].render(475,325,nullptr,0,nullptr,flipp);
    gHome[0].render(475,440,nullptr,0,nullptr,flipp);

    if(mousex >= gResume[0].getPosX() && mousex <= gResume[0].getPosX() + gResume[0].getWidth()
        && mousey >= gResume[0].getPosY() && mousey <= gResume[0].getPosY() + gResume[0].getHeight())
        {
            gResume[1].render(475,325,nullptr,0,nullptr,flipp);
        }
    if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
        && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
        {
            gHome[1].render(475,440,nullptr,0,nullptr,flipp);
        }
}
void MainGame::pausedGame()
{
    pausedgame = true;
    gameT.pause();
    while(pausedgame)
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

        renderButtonPaused();

        SDL_RenderPresent(Engine::gRenderer);

        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gResume[0].getPosX() && mousex <= gResume[0].getPosX() + gResume[0].getWidth()
                && mousey >= gResume[0].getPosY() && mousey <= gResume[0].getPosY() + gResume[0].getHeight())
                {
                    Mix_PlayChannel(-1,Audio::gMenuButton,0);
                    pausedgame = false;
                    gameT.unpause();
                    return;
                }
                if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
                && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
                {
                    Mix_PlayChannel(-1,Audio::gMenuButton,0);
                    pausedgame=false;
                    quitgame = true;
                    Engine::status =0;
                    return;
                }
            }
        }
    }
}

void MainGame::endGame()
{
    //WIN
    if((startTime - gameT.get_ticks()/1000) == 0 && Engine::stillAlive == true)
        {
            Mix_HaltMusic();
            Mix_PlayChannel(-1,Audio::gWinGame,0);
            gWinGame[0].loadImage("textures/menu/endMenu/Y.png");
            gWinGame[1].loadImage("textures/menu/endMenu/O.png");
            gWinGame[2].loadImage("textures/menu/endMenu/U.png");
            gWinGame[3].loadImage("textures/menu/endMenu/W.png");
            gWinGame[4].loadImage("textures/menu/endMenu/I.png");
            gWinGame[5].loadImage("textures/menu/endMenu/N.png");
            gWinGame[6].loadImage("textures/menu/endMenu/!.png");
            for(int i=0;i<7;i++)
            {
                gWinGame[i].render(160 + 130*i, 200, nullptr, 0, nullptr, flipp);
            }
            SDL_RenderPresent(Engine::gRenderer);
            SDL_Delay(6000);
            SDL_RenderClear(Engine::gRenderer);

            menuWin = true;
            gTextScore.loadFromRenderedText("Your Score: ", {255,240,220});
            gSumScore.loadFromRenderedText(gYourScore.str().c_str(),{186,0,0});
            gBestScore.loadFromRenderedText("Best Score is: " , {255,240,220});
            if(score > Engine::readBest())
            {
                SDL_RWops *file = SDL_RWFromFile("text/score.bin", "w+b");
                SDL_RWwrite(file, &score, sizeof(int), 1);
                SDL_RWclose(file);
            }
            bestScore.loadFromRenderedText(to_string(Engine::readBest()), {206,0,0});
            while (menuWin)
            {
            while(SDL_PollEvent(&e) != 0)
            {
                if(e.type == SDL_QUIT)
                {
                    quitgame = true;
                    Engine::quitloop  = true;
                    SDL_Quit();
                    return;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN)
                {
                    SDL_GetMouseState(&mousex,&mousey);
                    if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
                    && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                    menuWin = false;
                    quitgame = true;
                    Engine::status = 0;
                    return;
                    }
                }
                SDL_GetMouseState(&mousex,&mousey);
            }

            SDL_RenderClear(Engine::gRenderer);

            gEndBackgr.render(0,0,nullptr,0,nullptr,flipp);

            for(int i=0;i<7;i++)
            {
                gWinGame[i].render(160 + 130*i, 80, nullptr, 0, nullptr, flipp);
            }

            gTextScore.render (420, 220,nullptr,0,nullptr,flipp);
            gSumScore.render ( 420 + gTextScore.getWidth(),220,nullptr,0,nullptr,flipp);
            gBestScore.render(420 , 300,nullptr,0,nullptr,flipp);
            bestScore.render(420 + gBestScore.getWidth(), 300,nullptr,0,nullptr,flipp);
            gHome[0].render (475,420,nullptr,0,nullptr,flipp);
            if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
                && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
                {
                    gHome[1].render (475,420,nullptr,0,nullptr,flipp);
                }
            SDL_RenderPresent(Engine::gRenderer);
            }
        }
    //LOSE
    if(Engine::stillAlive == false)
    {
            Mix_HaltMusic();
            Mix_PlayChannel(-1,Audio::gLoseGame,0);
            gLoseGame[0].loadImage("textures/menu/endMenu/Y.png");
            gLoseGame[1].loadImage("textures/menu/endMenu/O.png");
            gLoseGame[2].loadImage("textures/menu/endMenu/U.png");
            gLoseGame[3].loadImage("textures/menu/endMenu/L.png");
            gLoseGame[4].loadImage("textures/menu/endMenu/O.png");
            gLoseGame[5].loadImage("textures/menu/endMenu/S.png");
            gLoseGame[6].loadImage("textures/menu/endMenu/E.png");
            gLoseGame[7].loadImage("textures/menu/endMenu/!.png");
            for(int i=0;i<8;i++)
            {
                gLoseGame[i].render(160 + 130*i, 200, nullptr, 0, nullptr, flipp);
            }
            SDL_RenderPresent(Engine::gRenderer);
            SDL_Delay(6000);
            SDL_RenderClear(Engine::gRenderer);

            menuLose = true;
            gTextScore.loadFromRenderedText("Your Score: ", {255,240,220});
            gSumScore.loadFromRenderedText(gYourScore.str().c_str(),{186,0,0});
            gBestScore.loadFromRenderedText("Best Score:  " , {255,240,220});
            if(score > Engine::readBest())
            {
                SDL_RWops *file = SDL_RWFromFile("text/score.bin", "w+b");
                SDL_RWwrite(file, &score, sizeof(int), 1);
                SDL_RWclose(file);
            }
            bestScore.loadFromRenderedText(to_string(Engine::readBest()), {206,0,0});
            while (menuLose)
            {
            while(SDL_PollEvent(&e) != 0)
            {
                if(e.type == SDL_QUIT)
                {
                    menuLose = false;
                    quitgame = true;
                    Engine::quitloop  = true;
                    SDL_Quit();
                    return;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN)
                {
                    SDL_GetMouseState(&mousex,&mousey);
                    if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
                    && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                    menuLose = false;
                    quitgame = true;
                    Engine::status = 0;
                    return;
                    }
                }
                SDL_GetMouseState(&mousex,&mousey);
            }

            SDL_RenderClear(Engine::gRenderer);

            gEndBackgr.render(0,0,nullptr,0,nullptr,flipp);

            for(int i=0;i<8;i++)
            {
                gLoseGame[i].render(160 + 130*i, 80, nullptr, 0, nullptr, flipp);
            }

            gTextScore.render (420, 220,nullptr,0,nullptr,flipp);
            gSumScore.render ( 420 + gTextScore.getWidth(),220,nullptr,0,nullptr,flipp);
            gBestScore.render(420 , 300,nullptr,0,nullptr,flipp);
            bestScore.render(420 + gBestScore.getWidth(), 300,nullptr,0,nullptr,flipp);
            gHome[0].render (475,420,nullptr,0,nullptr,flipp);
            if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
                && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
                {
                    gHome[1].render (475,420,nullptr,0,nullptr,flipp);
                }
            SDL_RenderPresent(Engine::gRenderer);
            }
    }
}

void MainGame::playGame()
{
    Mix_PlayMusic(Audio::gingame,-1);
    quitgame = false;
    gameT.start();
    Engine::stillAlive = true;
    fishmain.updateGame();
    while (!quitgame)
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

        if(Engine::tickM == false)
        {
            Mix_HaltMusic();
        }
        if(Engine::tickS == false)
        {
            Mix_HaltChannel(-1);
        }
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quitgame =true;
                Engine::quitloop = true;
                return;
            }

            if(e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym == SDLK_ESCAPE)
                {
                    pausedGame();
                }
            }
            fishmain.handleEventMainFish(e);
        }

        //Clear screen
        SDL_SetRenderDrawColor( Engine::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( Engine::gRenderer );

        timeText.str("");
        gFish1.str("");
        gFish2.str("");
        gFish3.str("");
        gYourScore.str("");

        if(Engine::countl1 < 10) gFish1<<"0"<<Engine::countl1;
        else gFish1<<Engine::countl1;
        if(Engine::countl2 < 10) gFish2<<"0"<<Engine::countl2;
        else gFish2<<Engine::countl2;
        if(Engine::countl3 < 10) gFish3<<"0"<<Engine::countl3;
        else gFish3<<Engine::countl3;

        score = 5*Engine::countl1 + 10*Engine::countl2 + 20*Engine::countl3;
        if(score < 10) gYourScore<<"0";
        gYourScore<<score;

        timeText<<"0"<<(startTime - gameT.get_ticks()/1000)/60 << ":";

        if(((startTime - gameT.get_ticks()/1000)%60) < 10) timeText<<"0"<<(startTime - gameT.get_ticks()/1000)%60;
        else timeText<<(startTime - gameT.get_ticks()/1000)%60;

        //Render background
        gBackground.render(0,0,nullptr,0,nullptr,flipp);

        board.render(0,0,nullptr,0,nullptr,flipp);

        clock.loadFromRenderedText(timeText.str().c_str(),colorText);

        gScore1.loadFromRenderedText(gFish1.str().c_str(),colorText);
        gScore2.loadFromRenderedText(gFish2.str().c_str(),colorText);
        gScore3.loadFromRenderedText(gFish3.str().c_str(),colorText);
        gTextScore.loadFromRenderedText("Your Score: ", {186,0,0});
        gSumScore.loadFromRenderedText(gYourScore.str().c_str(),{0,165,102});

        border.render(5,2,nullptr,0,nullptr,flipp);

        clock.render(45,8,nullptr,0,nullptr,flipp);

        gLogo1.render(340,25,nullptr,0,nullptr,flipp);
        gScore1.render(400,6,nullptr,0,nullptr,flipp);

        gLogo2.render(485,25,nullptr,0,nullptr,flipp);
        gScore2.render(555,6,nullptr,0,nullptr,flipp);

        gLogo3.render(665,12,nullptr,0,nullptr,flipp);
        gScore3.render(765,6,nullptr,0,nullptr,flipp);

        gTextScore.render(850,6,nullptr,0,nullptr,flipp);
        gSumScore.render(1080,6,nullptr,0,nullptr,flipp);

        fishmain.checkCollision_L1();
        fishmain.checkCollision_L2();
        fishmain.checkCollision_L3();
        fishmain.checkCollision_L2toL1();
        fishmain.checkCollision_L3toL1L2();

        fishmain.renderMainFish();
        endGame();

        //Update screen
        SDL_RenderPresent( Engine::gRenderer );
        }
}
