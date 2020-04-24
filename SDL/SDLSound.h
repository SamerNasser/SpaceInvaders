//
// Created by samer on 24/04/2020.
//

#ifndef SPACEINVADERSV2_SDLSOUND_H
#define SPACEINVADERSV2_SDLSOUND_H


#include "../NONSDL/Sound.h"
#include <SDL2/SDL_mixer.h>

namespace SDL {
    class SDLSound : public NONSDL::Sound{
    public:
        //Constructor
        SDLSound();

        //Destructor
        ~SDLSound();

        //Starts up SDL and creates window
        bool init();

        //Loads media
        bool loadMedia();

        //Frees media and shuts down SDL
        void close();

        void shootSound();

        void hitSound();

        void gameOverSound();

        void winSound();

        void hurtSound();

        void PBonusSound();

        void NBonusSound();

        void playMusic();

    private:
        // The music that will be played.
        Mix_Music* gMusic = NULL;

        // The sound effects that will be used.
        Mix_Chunk* gShoot = NULL;
        Mix_Chunk* gHit = NULL;
        Mix_Chunk* gGameOver = NULL;
        Mix_Chunk* gWin = NULL;
        Mix_Chunk* gHurt = NULL;
        Mix_Chunk* gPBonus = NULL;
        Mix_Chunk* gNBonus = NULL;

    };
}


#endif //SPACEINVADERSV2_SDLSOUND_H
