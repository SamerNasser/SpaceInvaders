//
// Created by samer on 12/04/2020.
//

#include "SDLProjectile.h"

SDL::SDLProjectile::SDLProjectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed, SDL::SDLWindow* win): NONSDL::Projectile(xPos, yPos, w, h, xSpeed, ySpeed)
{
    window = win;
}

SDL::SDLProjectile::~SDLProjectile()
{

}

void SDL::SDLProjectile::visualize()
{
    window->render(SDL::SpriteType::PROJECTILE, x,  y, width, height);
}