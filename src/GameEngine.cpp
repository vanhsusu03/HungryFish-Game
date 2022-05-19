#include "GameEngine.h"

SDL_Renderer* Engine::gRenderer = nullptr;
TTF_Font* Engine::gFont = nullptr;
bool Engine::quitloop = false;
int Engine::status = 0;
bool Engine::tickM = true;
bool Engine::tickS = true;
bool Engine::level2 = false;
bool Engine::level3 = false;
double Engine::countl1 = 0;
double Engine::countl2 = 0;
double Engine::countl3 = 0;

bool Engine::initProg()
{
    bool success=true;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Could not init SDL %s\n", SDL_GetError());
        success=false;
    }
    else{
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"))
        {
            printf("Warning: Linear texture filtering not enable ");
        }

        //Create window successfully
        gWindow = SDL_CreateWindow( "Hungry Fish Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer successfully
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				//Initialize SDL_mixer
                    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                    {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                    }
                    else
                    {
                        if(TTF_Init() == -1)
                        {
                            printf("SDL_ttf could not init ttf %n\n", TTF_GetError());
                            success= false;
                        }
                        else Engine::gFont = TTF_OpenFont("fonts/KaushanScript-Regular.otf",30);
                    }
                    audio.AudioInit();
			}
		}
	}
	return success;
}

void Engine::closeProg()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}
