//
// Created by samer on 21/04/2020.
//

#include "SDLNBonus.h"
#include "../SDLConstants.h"

SDL::SDLNBonus::SDLNBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): NONSDL::BonusEntity(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

SDL::SDLNBonus::~SDLNBonus()
{

}

void SDL::SDLNBonus::visualize(NONSDL::Window* win)
{
    win->render(SDL::SpriteType::NBONUS, x,  y, width, height);
}

void SDL::SDLNBonus::disappear()
{
    x = 1;
    y = 1;
}