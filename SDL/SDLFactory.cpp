//
// Created by samer on 30/03/2020.
//

#include "SDLFactory.h"
#include "SDLPlayerShip.h"
#include "SDLPlayerInput.h"
#include "SDLBullet.h"
#include "SDLWindow.h"
#include "SDLEnemy.h"
#include "SDLProjectile.h"
#include "SDLTimer.h"
#include "SDLPBonus.h"
#include "SDLNBonus.h"
#include "SDLSound.h"

SDL::SDLFactory::SDLFactory()
{

}

SDL::SDLFactory::~SDLFactory()
{

}

NONSDL::PlayerShip* SDL::SDLFactory::createPlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLPlayerShip(xPos, yPos, w, h, xSpeed, ySpeed);
}

NONSDL::PlayerInput* SDL::SDLFactory::createPlayerInput()
{
    return new SDL::SDLPlayerInput();
}

NONSDL::Bullet* SDL::SDLFactory::createBullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLBullet(xPos, yPos, w, h, xSpeed, ySpeed);
}

NONSDL::Enemy* SDL::SDLFactory::createEnemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLEnemy(xPos, yPos, w, h, xSpeed, ySpeed);
}

NONSDL::Projectile* SDL::SDLFactory::createProjectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLProjectile(xPos, yPos, w, h, xSpeed, ySpeed);
}

NONSDL::BonusEntity* SDL::SDLFactory::createPBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLPBonus(xPos, yPos, w, h, xSpeed, ySpeed);
}

NONSDL::BonusEntity* SDL::SDLFactory::createNBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLNBonus(xPos, yPos, w, h, xSpeed, ySpeed);
}

NONSDL::Timer* SDL::SDLFactory::createTimer()
{
    return new SDL::SDLTimer();
}

NONSDL::Window* SDL::SDLFactory::createWindow()
{
    return new SDL::SDLWindow();
}

NONSDL::Sound* SDL::SDLFactory::createSound()
{
    return new SDL::SDLSound();
}


