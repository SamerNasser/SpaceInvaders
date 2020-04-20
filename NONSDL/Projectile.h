//
// Created by samer on 12/04/2020.
//

#ifndef SPACEINVADERSV2_PROJECTILE_H
#define SPACEINVADERSV2_PROJECTILE_H


#include "EnemyEntity.h"

namespace NONSDL {
    class Projectile : public EnemyEntity {
    public:
        //constructor
        Projectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~Projectile();

        //copy constructor
        //Projectile(const Projectile &c);

        //assignment operator
        //Projectile &operator=(const Projectile &c);

        //make visible
        virtual void visualize() = 0;
    };
}

#endif //SPACEINVADERSV2_PROJECTILE_H
