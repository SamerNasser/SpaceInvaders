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

SDL::SDLFactory::SDLFactory()
{
    window = new SDLWindow();
}

SDL::SDLFactory::~SDLFactory()
{
    printf("Window is being deleted \n");
    delete window;
}

NONSDL::PlayerShip* SDL::SDLFactory::createPlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLPlayerShip(xPos, yPos, w, h, xSpeed, ySpeed, window);
}

NONSDL::PlayerInput* SDL::SDLFactory::createPlayerInput()
{
    return new SDL::SDLPlayerInput();
}

NONSDL::Bullet* SDL::SDLFactory::createBullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLBullet(xPos, yPos, w, h, xSpeed, ySpeed, window);
}

NONSDL::Enemy* SDL::SDLFactory::createEnemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLEnemy(xPos, yPos, w, h, xSpeed, ySpeed, window);
}

NONSDL::Projectile* SDL::SDLFactory::createProjectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    return new SDL::SDLProjectile(xPos, yPos, w, h, xSpeed, ySpeed, window);
}

NONSDL::Timer* SDL::SDLFactory::createTimer()
{
    return new SDL::SDLTimer();
}

void SDL::SDLFactory::clearWindow()
{
    window->clearWindow();
}

void SDL::SDLFactory::updateWindow()
{
    window->updateWindow();
}