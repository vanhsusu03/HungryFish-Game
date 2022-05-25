#include "AudioManager.h"

Mix_Music* Audio::gingame = nullptr;
Mix_Music* Audio::gMenu = nullptr;
Mix_Chunk* Audio::gEatlevel1 = nullptr;
Mix_Chunk* Audio::gEatlevel2 = nullptr;
Mix_Chunk* Audio::gEatlevel3 = nullptr;
Mix_Chunk* Audio::gHavingBeenEaten = nullptr;
Mix_Chunk* Audio::gNextLevel = nullptr;
Mix_Chunk* Audio::gWinGame = nullptr;
Mix_Chunk* Audio::gMenuButton = nullptr;
Mix_Chunk* Audio::gLoseGame = nullptr;

Audio::Audio()
{

}

Audio::~Audio()
{

}

void Audio::MusicInit()
{
    gingame = Mix_LoadMUS("audios/Peacefulround.mp3");
    if(gingame == nullptr)
    {
        printf("Could not load GINGAME! %s\n");
        Mix_GetError();
    }

    gMenu = Mix_LoadMUS("audios/Ins_Help_HighS_Setting.mp3");
    if(gMenu == nullptr)
    {
        printf("Could not load GMENU! %s\n");
        Mix_GetError();
    }

}

void Audio::ChannelInit()
{
    gEatlevel1 = Mix_LoadWAV("audios/eatlevel1.wav");
    if(gEatlevel1 == nullptr)
    {
        printf ("Could not load gEat %s\n");
        Mix_GetError();
    }

    gEatlevel2 = Mix_LoadWAV("audios/eatlevel2.wav");
    if(gEatlevel2 == nullptr)
    {
        printf ("Could not load gEat %s\n");
        Mix_GetError();
    }

    gEatlevel3 = Mix_LoadWAV("audios/eatlevel3.wav");
    if(gEatlevel3 == nullptr)
    {
        printf ("Could not load gEat %s\n");
        Mix_GetError();
    }

    gHavingBeenEaten = Mix_LoadWAV("audios/havebeeneaten.wav");
    if(gHavingBeenEaten == nullptr)
    {
        printf ("Could not load gHBEatn %s\n");
        Mix_GetError();
    }

    gNextLevel = Mix_LoadWAV("audios/bigger_nextlevel.wav");
    if(gNextLevel == nullptr)
    {
        printf ("Could not load gNextLevel %s\n");
        Mix_GetError();
    }

    gMenuButton = Mix_LoadWAV("audios/MenuButton.wav");
    if(gMenuButton == nullptr)
    {
        printf("Could not load gMenuButton %s\n");
        Mix_GetError();
    }
    gWinGame = Mix_LoadWAV ("audios/winMenu.wav");

    gLoseGame = Mix_LoadWAV("audios/endMenu.wav");

}
