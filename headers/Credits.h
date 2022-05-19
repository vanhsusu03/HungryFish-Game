#ifndef CREDITS_H_INCLUDED
#define CREDITS_H_INCLUDED

#include "include.h"
#include "AudioManager.h"
#include "GameEngine.h"
#include "TexturesManager.h"
class Credits
{
    public:

    Credits();

    ~Credits();

    void loadSource();

    void renderCredits();

    void mainCredits();

    private:

    bool runningCredit;

    SDL_Event e;

    int mousex, mousey;

    ManageTexture gCredits;

    ManageTexture gBack[2];

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_RendererFlip cbflip = SDL_FLIP_HORIZONTAL;

    const string cred_load = "textures/credits/MenuBackgr.jpg";
    const string cback = "textures/instruction/Back.png";
    const string cback_button = "textures/instruction/Back_Button.png";
};
#endif // CREDITS_H_INCLUDED
