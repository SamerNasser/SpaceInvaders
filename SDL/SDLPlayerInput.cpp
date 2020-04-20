//
// Created by samer on 07/04/2020.
//

#include "SDLPlayerInput.h"
#include <SDL2/SDL.h>
#include "../SDLConstants.h"

SDL::SDLPlayerInput::SDLPlayerInput()
{

}

SDL::SDLPlayerInput::~SDLPlayerInput()
{

}

int SDL::SDLPlayerInput::CheckInput()
{
    int input = -1;
    //Event handler
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        //User requests quit
        if (e.type == SDL_QUIT) {
            input = 0;
            return input;
    }
            //User presses a key
        else if( e.type == SDL_KEYDOWN )
        {
            //Select actions based on key press
            switch( e.key.keysym.sym) {
                case SDLK_LEFT:
                    input = 1;
                    return input;

                case SDLK_RIGHT:
                    input = 2;
                    return input;

                case SDLK_SPACE:
                    input = 3;
                    return input;

                default:
                    return input;
            }
        }
    }
    return input;
}