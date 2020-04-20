//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_PLAYERSHIP_H
#define SPACEINVADERSV2_PLAYERSHIP_H
#include "PlayerEntity.h"

namespace NONSDL {
    class PlayerShip : public PlayerEntity {
    public:
        //constructor
        PlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~PlayerShip();

        //copy constructor
        //PlayerShip(const PlayerShip &c);

        //assignment operator
        //PlayerShip &operator=(const PlayerShip &c);

        //make visible
        virtual void visualize(Window* win) = 0;
    };
}


#endif //SPACEINVADERSV2_PLAYERSHIP_H
