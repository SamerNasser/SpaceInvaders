//
// Created by samer on 11/04/2020.
//

#ifndef SPACEINVADERSV2_ENEMY_H
#define SPACEINVADERSV2_ENEMY_H


#include "EnemyEntity.h"

namespace NONSDL {
    class Enemy : public EnemyEntity {
    public:
        //constructor
        Enemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~Enemy();

        //copy constructor
        //Enemy(const Enemy &c);

        //assignment operator
        //Enemy &operator=(const Enemy &c);

        //make visible
        virtual void visualize(Window* win) = 0;

        virtual void switchDirection() = 0;

        virtual void shiftDown() = 0;
    };
}

#endif //SPACEINVADERSV2_ENEMY_H
