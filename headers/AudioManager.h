#ifndef AUDIOMANAGER_H_INCLUDED
#define AUDIOMANAGER_H_INCLUDED

#include "include.h"


class Audio
{
    public:

    Audio();

    ~Audio();

    static Mix_Music* gingame;
    static Mix_Music* gMenu;
    static Mix_Chunk* gEatlevel1;
    static Mix_Chunk* gEatlevel2;
    static Mix_Chunk* gEatlevel3;
    static Mix_Chunk* gHavingBeenEaten;
    static Mix_Chunk* gNextLevel;
    static Mix_Chunk* gWinGame;
    static Mix_Chunk* gMenuButton;
    static Mix_Chunk* gLoseGame;
    void MusicInit();

    void ChannelInit();

    void MusicClose();

    void ChannelClose();
};

#endif // AUDIOMANAGER_H_INCLUDED
