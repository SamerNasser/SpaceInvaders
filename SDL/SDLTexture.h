//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_SDLTEXTURE_H
#define SPACEINVADERSV2_SDLTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "../GameConstants.h"

//Screen dimension constants

namespace SDL {
    class SDLTexture {
    public:
        //Constructor
        SDLTexture(SDL_Renderer *r);

        //Destructor
        ~SDLTexture();

        //Loads image at specified path
        bool loadFromFile(std::string path);

        //Deallocates texture
        void free();

        //Set color modulation
        void setColor(Uint8 red, Uint8 green, Uint8 blue);

        //Set blending
        void setBlendMode(SDL_BlendMode blending);

        //Set alpha modulation
        void setAlpha(Uint8 alpha);

        //Renders texture at given point
        void render(int x, int y, int w, int h, SDL_Rect *clip = NULL);

        //Gets image dimensions
        int getWidth();

        int getHeight();

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
        SDL_Renderer* renderer;
    };
}

#endif //SPACEINVADERSV2_SDLTEXTURE_H
