//
// Created by samer on 30/03/2020.
//

#include "SDLWindow.h"

SDL::SDLWindow::SDLWindow()
{
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    SDL::SDLWindow::gSpriteSheetTexture = new SDLTexture(SDL::SDLWindow::gRenderer);
    if( !loadMedia() )
    {
        printf( "Failed to load media!\n" );
    }
}

SDL::SDLWindow::~SDLWindow()
{
    printf("Er wordt geclosed \n");
    SDL::SDLWindow::close();
}

bool SDL::SDLWindow::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, NONSDL::SCREEN_WIDTH, NONSDL::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == nullptr )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == nullptr )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool SDL::SDLWindow::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if( !gSpriteSheetTexture->loadFromFile( "../SpriteSheets/SpaceInvadersSpriteSheet.png" ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    else
    {
        // Set playership sprite.
        gSpriteClips[ PLAYER ].x = 405;
        gSpriteClips[ PLAYER ].y = 685;
        gSpriteClips[ PLAYER ].w = 70;
        gSpriteClips[ PLAYER ].h = 40;

        // Set Enemy sprite.
        gSpriteClips[ ENEMY ].x = 503;
        gSpriteClips[ ENEMY ].y = 277;
        gSpriteClips[ ENEMY ].w = 45;
        gSpriteClips[ ENEMY ].h = 34;

        // Set Bullet sprite.
        gSpriteClips[ BULLET ].x = 437;
        gSpriteClips[ BULLET ].y = 593;
        gSpriteClips[ BULLET ].w = 4;
        gSpriteClips[ BULLET ].h = 13;

        // Set Projectile sprite.
        gSpriteClips[ PROJECTILE ].x = 582;
        gSpriteClips[ PROJECTILE ].y = 316;
        gSpriteClips[ PROJECTILE ].w = 4;
        gSpriteClips[ PROJECTILE ].h = 13;
    }

    return success;
}

void SDL::SDLWindow::render(SpriteType type, float x, float y, float w, float h){


    int realX = x*NONSDL::SCREEN_WIDTH;
    int realY = y*NONSDL::SCREEN_HEIGHT;
    int realW = w*NONSDL::SCREEN_WIDTH;
    int realH = h*NONSDL::SCREEN_HEIGHT;

    //Render top left sprite
    gSpriteSheetTexture->render( realX, realY, realW, realH, &gSpriteClips[ type ] );

}

void SDL::SDLWindow::close()
{
    //Free loaded images
    gSpriteSheetTexture->free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void SDL::SDLWindow::clearWindow()
{
    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderClear( gRenderer );
}

void SDL::SDLWindow::updateWindow()
{
    //Update screen
    SDL_RenderPresent( gRenderer );
}