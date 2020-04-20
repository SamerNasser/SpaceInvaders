//
// Created by samer on 09/04/2020.
//

#include "SDLBullet.h"

SDL::SDLBullet::SDLBullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed, SDL::SDLWindow* win): NONSDL::Bullet(xPos, yPos, w, h, xSpeed, ySpeed)
{
    window = win;
}

SDL::SDLBullet::~SDLBullet()
{

}

void SDL::SDLBullet::visualize()
{
    window->render(SDL::SpriteType::BULLET, x,  y, width, height);
}

void SDL::SDLBullet::disappear()
{
    x = NONSDL::SCREEN_WIDTH;
    y = NONSDL::SCREEN_HEIGHT;
}