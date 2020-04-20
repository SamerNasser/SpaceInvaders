//
// Created by samer on 09/04/2020.
//

#ifndef SPACEINVADERSV2_BULLET_H
#define SPACEINVADERSV2_BULLET_H

#include "PlayerEntity.h"

namespace NONSDL {
    class Bullet : public PlayerEntity {
    public:
        //constructor
        Bullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~Bullet();

        //copy constructor
        //Bullet(const Bullet &c);

        //assignment operator
        //Bullet &operator=(const Bullet &c);

        //make visible
        virtual void visualize() = 0;

        virtual void disappear() = 0;
    };
}


#endif //SPACEINVADERSV2_BULLET_H
