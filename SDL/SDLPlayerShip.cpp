//
// Created by samer on 30/03/2020.
//

#include "SDLPlayerShip.h"
#include "../SDLConstants.h"

SDL::SDLPlayerShip::SDLPlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): NONSDL::PlayerShip(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

SDL::SDLPlayerShip::~SDLPlayerShip()
{

}

void SDL::SDLPlayerShip::visualize(NONSDL::Window* win)
{
    win->render(SDL::SpriteType::PLAYER, x,  y, width, height);
}