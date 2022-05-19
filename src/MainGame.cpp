#include "MainGame.h"


MainGame::MainGame()
{
    gBackground.loadImage(background);
    gPaused.loadImage(pau);
    gResume[0].loadImage(res);
    gResume[1].loadImage(res_but);
    gHome[0].loadImage(home);
    gHome[1].loadImage(home_but);
    border.loadImage(bord);
    colorText = {176,0,0,255};
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
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
    if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
        && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
        {
            gHome[1].render(475,440,nullptr,0,nullptr,flipp);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
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
                    pausedgame = false;
                    gameT.unpause();
                    return;
                }
                if(mousex >= gHome[0].getPosX() && mousex <= gHome[0].getPosX() + gHome[0].getWidth()
                && mousey >= gHome[0].getPosY() && mousey <= gHome[0].getPosY() + gHome[0].getHeight())
                {
                    pausedgame=false;
                    quitgame = true;
                    Engine::status =0;
                    return;
                }
            }
        }
    }
}
void MainGame::playGame()
{
    if(Engine::tickM == false) Mix_HaltMusic();
        else Mix_PlayMusic(Audio::gingame,-1);
    if(Engine::tickS == false) Mix_Paused(-1);
    quitgame = false;
    gameT.start();
    while (!quitgame)
        {
        cout<<gameT.get_ticks()<<endl;
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

        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quitgame =true;
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

        timeText<<"Time  "<<"0"<<(startTime - gameT.get_ticks()/1000)/60 << ":";

        if(((startTime - gameT.get_ticks()/1000)%60) < 10) timeText<<"0"<<(startTime - gameT.get_ticks()/1000)%60;
        else timeText<<(startTime - gameT.get_ticks()/1000)%60;

        //Render background
        gBackground.render(0,0,nullptr,0,nullptr,flipp);

        clock.loadFromRenderedText(timeText.str().c_str(),colorText);

        border.render(10,5,nullptr,0,nullptr,flipp);

        clock.render(20,20,nullptr,0,nullptr,flipp);

        fishmain.checkCollision_L1();
        fishmain.checkCollision_L2();
        fishmain.checkCollision_L3();
        fishmain.checkCollision_L2toL1();
        fishmain.checkCollision_L3toL1L2();

        fishmain.moveMainFish();

        fishmain.renderMainFish();

        //Update screen
        SDL_RenderPresent( Engine::gRenderer );
        }
}
