#ifndef HIGHSCORES_H_INCLUDED
#define HIGHSCORES_H_INCLUDED

#include "include.h"
#include "GameEngine.h"
#include "TexturesManager.h"

class HighScores
{
    public:

    HighScores();

    ~HighScores();

    void loadSourceHighsc();

    void renderHighsc();

    void mainHS();

    private:

    SDL_Event e;

    bool runningHS;

    int mousex, mousey;

    ManageTexture gHS;

    ManageTexture gBack[2];

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_RendererFlip cbflip = SDL_FLIP_HORIZONTAL;

    const string highsc_load = "textures/instruction/2_game_background.png";
    const string cback = "textures/instruction/Back.png";
    const string cback_button = "textures/instruction/Back_Button.png";
};

#endif // HIGHSCORES_H_INCLUDED
