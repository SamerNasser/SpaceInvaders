//
// Created by samer on 11/04/2020.
//

#include "Enemy.h"

NONSDL::Enemy::Enemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed): EnemyEntity(xPos, yPos, w, h, xSpeed, ySpeed)
{

}

NONSDL::Enemy::~Enemy()
{

}

/* NONSDL::Enemy::Enemy(const Enemy& g):PlayerEntity(g)
{

}

NONSDL::Enemy& NONSDL::Enemy::operator=(const Enemy& g)
{

}
 */