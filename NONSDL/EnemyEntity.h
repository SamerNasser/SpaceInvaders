//
// Created by samer on 11/04/2020.
//

#ifndef SPACEINVADERSV2_ENEMYENTITY_H
#define SPACEINVADERSV2_ENEMYENTITY_H

#include "Entity.h"

namespace NONSDL {
    class EnemyEntity : public Entity {
    public:
        //constructor
        EnemyEntity(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~EnemyEntity();

        //make visible
        virtual void visualize() = 0;
    };
}


#endif //SPACEINVADERSV2_ENEMYENTITY_H
