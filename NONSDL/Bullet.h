//
// Created by samer on 09/04/2020.
//

#ifndef SPACEINVADERSV2_BULLET_H
#define SPACEINVADERSV2_BULLET_H

#include "Entity.h"

namespace NONSDL {
    class Bullet : public Entity {
    public:
        // Constructor.
        Bullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        virtual ~Bullet();

        // Methods.
        virtual void visualize(Window* win) = 0;

        virtual void disappear() = 0;
    };
}


#endif //SPACEINVADERSV2_BULLET_H
