//
// Created by samer on 11/04/2020.
//

#ifndef SPACEINVADERSV2_ENEMY_H
#define SPACEINVADERSV2_ENEMY_H


#include "Entity.h"

namespace NONSDL {
    class Enemy : public Entity {
    public:
        // Constructor.
        Enemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        virtual ~Enemy();

        // Methods.
        virtual void visualize(Window* win) = 0;

        virtual void switchDirection() = 0;

        virtual void shiftDown() = 0;
    };
}

#endif //SPACEINVADERSV2_ENEMY_H
