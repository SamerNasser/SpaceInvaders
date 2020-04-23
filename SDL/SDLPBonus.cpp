//
// Created by samer on 21/04/2020.
//

#include "SDLPBonus.h"
#include "../SDLConstants.h"

SDL::SDLPBonus::SDLPBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): NONSDL::PBonus(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

SDL::SDLPBonus::~SDLPBonus()
{

}

void SDL::SDLPBonus::visualize(NONSDL::Window* win)
{
    win->render(SDL::SpriteType::PBONUS, x,  y, width, height);
}

void SDL::SDLPBonus::disappear()
{
    x = 1;
    y = 1;
}