//
// Created by samer on 30/03/2020.
//

#include "Entity.h"

NONSDL::Entity::Entity()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    dx = 0;
    dy = 0;
}

NONSDL::Entity::Entity(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed)
{
    x = xPos;
    y = yPos;
    width = w;
    height = h;
    dx = xSpeed;
    dy = ySpeed;
}

NONSDL::Entity::~Entity()
{

}

float NONSDL::Entity::getX()
{
    return x;
}

float NONSDL::Entity::getY()
{
    return y;
}

float NONSDL::Entity::getXSpeed()
{
    return dx;
}

float NONSDL::Entity::getYSpeed()
{
    return dy;
}

float NONSDL::Entity::getWidth()
{
    return width;
}

float NONSDL::Entity::getHeight()
{
    return height;
}

void NONSDL::Entity::setX(float newX)
{
    x = newX;
}

void NONSDL::Entity::setY(float newY)
{
    y = newY;
}

void NONSDL::Entity::setXSpeed(float newDX)
{
    dx = newDX;
}

void NONSDL::Entity::setYSpeed(float newDY)
{
    dy = newDY;
}

void NONSDL::Entity::updatePosition()
{
    x = x + dx;
    y = y + dy;
}

bool NONSDL::Entity::collision(Entity* e)
{
    //Let's examine the x axis first:
    //If the leftmost or rightmost point of the first sprite lies somewhere inside the second, continue.
    if( (x >= e->getX() && x <= (e->getX() + e->getWidth())) ||
        ((x + width) >= e->getX() && (x + width) <= (e->getX() + e->getWidth())) ){
        //Now we look at the y axis:
        if( (y >= e->getY() && y <= (e->getY() + e->getHeight())) ||
            ((y + height) >= e->getY() && (y + height) <= (e->getY() + e->getHeight())) ){
            //The sprites appear to overlap.
            return true;
        }
    }
    //The sprites do not overlap:
    return false;

}




