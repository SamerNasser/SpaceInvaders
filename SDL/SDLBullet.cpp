//
// Created by samer on 09/04/2020.
//

#include "SDLBullet.h"

SDL::SDLBullet::SDLBullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): NONSDL::Bullet(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

SDL::SDLBullet::~SDLBullet()
{

}

void SDL::SDLBullet::visualize(NONSDL::Window* win)
{
    win->render(SDL::SpriteType::BULLET, x,  y, width, height);
}

void SDL::SDLBullet::disappear()
{
    x = 1;
    y = 1;
}