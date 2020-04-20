//
// Created by samer on 12/04/2020.
//

#include "SDLTimer.h"
#include "SDL2/SDL.h"

SDL::SDLTimer::SDLTimer(): NONSDL::Timer()
{

}

SDL::SDLTimer::~SDLTimer()
{

}

void SDL::SDLTimer::start()
{
    startTime = static_cast<unsigned long>(SDL_GetTicks());
}

unsigned int SDL::SDLTimer::getDuration()
{
    unsigned long duration = static_cast<unsigned long>(SDL_GetTicks() - startTime);
    return duration;
}
