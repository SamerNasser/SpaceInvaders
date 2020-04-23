//
// Created by samer on 11/04/2020.
//

#include "SDLEnemy.h"

SDL::SDLEnemy::SDLEnemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): NONSDL::Enemy(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

SDL::SDLEnemy::~SDLEnemy()
{

}

void SDL::SDLEnemy::visualize(NONSDL::Window* win)
{
    win->render(SpriteType::ENEMY, x,  y, width, height);
}

void SDL::SDLEnemy::switchDirection()
{
    setXSpeed(-1*(getXSpeed()));
}

void SDL::SDLEnemy::shiftDown()
{
    setY((getY()) + (NONSDL::ENEMYHEIGHT*0.75));
}