//
// Created by samer on 30/03/2020.
//

#include "SDLTexture.h"

SDL::SDLTexture::SDLTexture(SDL_Renderer* r)
{
    //Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    renderer = r;
}

SDL::SDLTexture::~SDLTexture()
{
    //Deallocate
    free();
}

bool SDL::SDLTexture::loadFromFile( std::string path )
{
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == nullptr )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != nullptr;
}

void SDL::SDLTexture::free()
{
    //Free texture if it exists
    if( mTexture != nullptr )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

void SDL::SDLTexture::render( int x, int y, int w, int h, SDL_Rect* clip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != nullptr )
    {
        renderQuad.w = w;
        renderQuad.h = h;
    }

    //Render to screen
    SDL_RenderCopy( renderer, mTexture, clip, &renderQuad );
}

int SDL::SDLTexture::getWidth()
{
    return mWidth;
}

int SDL::SDLTexture::getHeight()
{
    return mHeight;
}