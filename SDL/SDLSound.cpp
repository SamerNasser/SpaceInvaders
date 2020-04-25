//
// Created by samer on 24/04/2020.
//

#include "SDLSound.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

SDL::SDLSound::SDLSound(): NONSDL::Sound()
{
    init();
    loadMedia();
}

SDL::SDLSound::~SDLSound()
{
    SDL::SDLSound::close();
}

bool SDL::SDLSound::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
    }
}

bool SDL::SDLSound::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load music
    gMusic = Mix_LoadMUS( "../Sounds/Interplanetary Odyssey.ogg" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    //Load sound effects
    gShoot = Mix_LoadWAV( "../Sounds/shoot.wav" );
    if( gShoot == NULL )
    {
        printf( "Failed to load shooting sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gHit = Mix_LoadWAV( "../Sounds/invaderkilled.wav" );
    if( gHit == NULL )
    {
        printf( "Failed to load enemy hit sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gGameOver = Mix_LoadWAV( "../Sounds/explosion.wav" );
    if( gGameOver == NULL )
    {
        printf( "Failed to load game over sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }


    gWin = Mix_LoadWAV( "../Sounds/TaDa.wav" );
    if( gWin == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gHurt = Mix_LoadWAV( "../Sounds/hurt.mp3" );
    if( gWin == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gPBonus = Mix_LoadWAV( "../Sounds/PBonus.mp3" );
    if( gWin == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gNBonus = Mix_LoadWAV( "../Sounds/NBonus.mp3" );
    if( gWin == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }





    return success;
}

void SDL::SDLSound::close()
{
    // Free the sound effects.
    Mix_FreeChunk( gShoot );
    Mix_FreeChunk( gHit);
    Mix_FreeChunk( gGameOver );
    Mix_FreeChunk( gWin );
    Mix_FreeChunk( gHurt );
    Mix_FreeChunk( gPBonus );
    Mix_FreeChunk( gNBonus );
    gShoot = nullptr;
    gHit = nullptr;
    gGameOver = nullptr;
    gWin = nullptr;
    gHurt = nullptr;
    gPBonus = nullptr;
    gNBonus = nullptr;


    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = nullptr;

    //Quit SDL subsystem
    Mix_Quit();
}

void SDL::SDLSound::shootSound()
{
    Mix_PlayChannel( -1, gShoot, 0 );
}

void SDL::SDLSound::hitSound()
{
    Mix_PlayChannel( -1, gHit, 0 );
}

void SDL::SDLSound::hurtSound()
{
    Mix_PlayChannel( -1, gHurt, 0 );
}

void SDL::SDLSound::gameOverSound()
{
    Mix_PlayChannel( -1, gGameOver, 0 );
}

void SDL::SDLSound::winSound()
{
    Mix_PlayChannel( -1, gWin, 0 );
}

void SDL::SDLSound::NBonusSound()
{
    Mix_PlayChannel( -1, gNBonus, 0 );
}

void SDL::SDLSound::PBonusSound()
{
    Mix_PlayChannel( -1, gPBonus, 0 );
}

void SDL::SDLSound::playMusic()
{
    Mix_PlayMusic( gMusic, -1 );
}

void SDL::SDLSound::stopMusic()
{
    Mix_PauseMusic();
}