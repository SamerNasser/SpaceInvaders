//
// Created by samer on 30/03/2020.
//

#include "SDLWindow.h"

SDL::SDLWindow::SDLWindow(): NONSDL::Window()
{
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }

    SDL::SDLWindow::gSpriteSheetTexture = new SDLTexture(SDL::SDLWindow::gRenderer);
    SDL::SDLWindow::gTextTexture = new SDLTexture(SDL::SDLWindow::gRenderer);

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

                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
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

        // Set start screen sprite.
        gSpriteClips[ STARTSCREEN ].x = 38;
        gSpriteClips[ STARTSCREEN ].y = 60;
        gSpriteClips[ STARTSCREEN ].w = 456;
        gSpriteClips[ STARTSCREEN ].h = 190;

        // Set end screen sprite.
        gSpriteClips[ WINNERSCREEN ].x = 65;
        gSpriteClips[ WINNERSCREEN ].y = 295;
        gSpriteClips[ WINNERSCREEN ].w = 424;
        gSpriteClips[ WINNERSCREEN ].h = 60;

        // Set start text sprite.
        gSpriteClips[ STARTTEXT ].x = 572;
        gSpriteClips[ STARTTEXT ].y = 95;
        gSpriteClips[ STARTTEXT ].w = 311;
        gSpriteClips[ STARTTEXT ].h = 25;

        // Set losing screen sprite.
        gSpriteClips[ LOSERSCREEN ].x = 96;
        gSpriteClips[ LOSERSCREEN ].y = 476;
        gSpriteClips[ LOSERSCREEN ].w = 261;
        gSpriteClips[ LOSERSCREEN ].h = 59;

        // Set end text sprite.
        gSpriteClips[ ENDTEXT ].x = 563;
        gSpriteClips[ ENDTEXT ].y = 500;
        gSpriteClips[ ENDTEXT ].w = 311;
        gSpriteClips[ ENDTEXT ].h = 25;

        // Set lives sprite.
        gSpriteClips[ LIFE ].x = 512;
        gSpriteClips[ LIFE ].y = 65;
        gSpriteClips[ LIFE ].w = 36;
        gSpriteClips[ LIFE ].h = 29;

        // Set lives sprite.
        gSpriteClips[ PBONUS ].x = 511;
        gSpriteClips[ PBONUS ].y = 397;
        gSpriteClips[ PBONUS ].w = 25;//536;
        gSpriteClips[ PBONUS ].h = 40;//437;

        // Set lives sprite.
        gSpriteClips[ NBONUS ].x = 583;
        gSpriteClips[ NBONUS ].y = 396;
        gSpriteClips[ NBONUS ].w = 23;
        gSpriteClips[ NBONUS ].h = 37;
    }

    //Open the font
    printf("Test1 \n");
    gFont = TTF_OpenFont( "../Fonts/Bebas-Regular.otf", 28 );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0xFF, 0xFF, 0xFF };
        if( !gTextTexture->loadFromRenderedText( "SCORE: test", textColor, gFont ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
    }


    return success;
}

void SDL::SDLWindow::render(int type, float x, float y, float w, float h){


    int realX = x*NONSDL::SCREEN_WIDTH;
    int realY = y*NONSDL::SCREEN_HEIGHT;
    int realW = w*NONSDL::SCREEN_WIDTH;
    int realH = h*NONSDL::SCREEN_HEIGHT;

    // Render top sprites.
    gSpriteSheetTexture->render( realX, realY, realW, realH, &gSpriteClips[ type ] );

}

void SDL::SDLWindow::renderText(float x, float y, float w, float h){


    int realX = x*NONSDL::SCREEN_WIDTH;
    int realY = y*NONSDL::SCREEN_HEIGHT;
    int realW = w*NONSDL::SCREEN_WIDTH;
    int realH = h*NONSDL::SCREEN_HEIGHT;

    // Render text.
    gTextTexture->renderText(realX, realY, realW, realH);

}

void SDL::SDLWindow::close()
{
    //Free loaded images
    gSpriteSheetTexture->free();

    // Free text.
    gTextTexture->free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    //Quit SDL subsystems
    TTF_Quit();
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