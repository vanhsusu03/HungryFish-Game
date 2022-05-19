#ifndef AUDIOMANAGER_H_INCLUDED
#define AUDIOMANAGER_H_INCLUDED

#include "include.h"


class Audio
{
    public:

    Audio();

    ~Audio();

    static Mix_Music* gingame;
    static Mix_Chunk* gEatlevel1;
    static Mix_Chunk* gEatlevel2;
    static Mix_Chunk* gEatlevel3;
    static Mix_Chunk* gHavingBeenEaten;
    static Mix_Chunk* gNextLevel;
    static Mix_Chunk* gWin1Game;
    static Mix_Chunk* gMenuButton;

    void AudioInit();

    void stopAudio();

    bool checkAudio();

    void AudioClose();
};

#endif // AUDIOMANAGER_H_INCLUDED
