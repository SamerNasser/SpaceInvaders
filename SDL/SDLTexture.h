//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_SDLTEXTURE_H
#define SPACEINVADERSV2_SDLTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "../GameConstants.h"

//Screen dimension constants

namespace SDL {
    class SDLTexture {
    public:
        //Constructor
        SDLTexture(SDL_Renderer* r);

        //Destructor
        ~SDLTexture();

        //Loads image at specified path
        bool loadFromFile(std::string path);

        //Creates image from font string
        bool loadFromRenderedText( std::string textureText, SDL_Color textColor, TTF_Font* f );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(int x, int y, int w, int h, SDL_Rect *clip = nullptr, bool text = true);


    private:
        //The actual hardware image texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;

        // Renderer.
        SDL_Renderer* renderer;

        //The actual hardware image texture
        SDL_Texture* nTexture;

        //Text dimensions
        int nWidth;
        int nHeight;
        TTF_Font * font;
    };
}

#endif //SPACEINVADERSV2_SDLTEXTURE_H
