//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_PLAYERSHIP_H
#define SPACEINVADERSV2_PLAYERSHIP_H
#include "Entity.h"

namespace NONSDL {
    class PlayerShip : public Entity {
    public:
        // Constructor.
        PlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        virtual ~PlayerShip();

        // Make visible.
        virtual void visualize(Window* win) = 0;
    };
}


#endif //SPACEINVADERSV2_PLAYERSHIP_H
