//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_SDLWINDOW_H
#define SPACEINVADERSV2_SDLWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "SDLTexture.h"
#include "../SDLConstants.h"
#include "../NONSDL/Window.h"

namespace SDL {
class SDLWindow : public NONSDL::Window{
    public:
        //Constructor
        SDLWindow();

        //Destructor
        ~SDLWindow();

        //Starts up SDL and creates window
        bool init();

        //Loads media
        bool loadMedia();

        //render
        void render(int type, float x, float y, float w, float h);

        void renderText(float x, float y, float w, float h, std::string text);

        //Frees media and shuts down SDL
        void close();

        void clearWindow();

        void updateWindow();

    private:
        // The window we'll be rendering to.
        SDL_Window* gWindow = nullptr;

        // Scene sprites.
        SDL_Rect gSpriteClips[13];

        // Rendered sprite sheet texture
        SDLTexture* gSpriteSheetTexture;

        // The window renderer.
        SDL_Renderer* gRenderer = nullptr;

        // Globally used font.
        TTF_Font* gFont = nullptr;

        // Rendered text texture
        SDLTexture* gTextTexture;

    };
}

#endif //SPACEINVADERSV2_SDLWINDOW_H
