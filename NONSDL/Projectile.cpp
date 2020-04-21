//
// Created by samer on 12/04/2020.
//

#include "Projectile.h"

NONSDL::Projectile::Projectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): Entity(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

NONSDL::Projectile::~Projectile()
{

}

/* NONSDL::Projectile::Projectile(const Projectile& g):PlayerEntity(g)
{

}

NONSDL::Projectile& NONSDL::Projectile::operator=(const Projectile& g)
{

}
 */