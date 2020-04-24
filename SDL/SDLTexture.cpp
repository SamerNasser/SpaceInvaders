//
// Created by samer on 30/03/2020.
//

#include "SDLTexture.h"

SDL::SDLTexture::SDLTexture(SDL_Renderer* r )
{
    //Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    renderer = r;
    font = nullptr;
}

SDL::SDLTexture::~SDLTexture()
{
    //Deallocate
    free();
}

bool SDL::SDLTexture:: loadFromFile( std::string path )
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

bool SDL::SDLTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor, TTF_Font* f )
{
    //Get rid of preexisting texture
    free();

    font = f;

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
    if( textSurface == nullptr )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        nTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( nTexture == nullptr )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            nWidth = textSurface->w;
            nHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return nTexture != nullptr;
}

void SDL::SDLTexture::free()
{
    //Free mTexture if it exists
    if( mTexture != nullptr )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }

    // Free nTexture if it exists
    if( nTexture != nullptr )
    {
        SDL_DestroyTexture( mTexture );
        nTexture = nullptr;
        nWidth = 0;
        nHeight = 0;
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

void SDL::SDLTexture::renderText( int x, int y, int w, int h, SDL_Rect* clip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad2 = { x, y, nWidth, nHeight };

    renderQuad2.w = w;
    renderQuad2.h = h;

    // Render text to screen.
    SDL_RenderCopy( renderer, nTexture, clip, &renderQuad2 );
}



