//
// Created by samer on 12/04/2020.
//

#ifndef SPACEINVADERSV2_PROJECTILE_H
#define SPACEINVADERSV2_PROJECTILE_H


#include "Entity.h"

namespace NONSDL {
    class Projectile : public Entity {
    public:
        // Constructor.
        Projectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        virtual ~Projectile();

        // Make visible.
        virtual void visualize(Window* win) = 0;
    };
}

#endif //SPACEINVADERSV2_PROJECTILE_H
