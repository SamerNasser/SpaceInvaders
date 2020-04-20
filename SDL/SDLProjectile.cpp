//
// Created by samer on 12/04/2020.
//

#include "SDLProjectile.h"

SDL::SDLProjectile::SDLProjectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): NONSDL::Projectile(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

SDL::SDLProjectile::~SDLProjectile()
{

}

void SDL::SDLProjectile::visualize(NONSDL::Window* win)
{
    win->render(SDL::SpriteType::PROJECTILE, x,  y, width, height);
}