//
// Created by samer on 30/03/2020.
//

#include "SDLPlayerShip.h"
#include "../SDLConstants.h"

SDL::SDLPlayerShip::SDLPlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed, SDL::SDLWindow* win): NONSDL::PlayerShip(xPos, yPos, w, h, xSpeed, ySpeed)
{
    window = win;
}

SDL::SDLPlayerShip::~SDLPlayerShip()
{

}

void SDL::SDLPlayerShip::visualize()
{
    window->render(SDL::SpriteType::PLAYER, x,  y, width, height);
}