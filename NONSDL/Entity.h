//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_ENTITY_H
#define SPACEINVADERSV2_ENTITY_H

#include "Window.h"

namespace NONSDL {
    class Entity {
    public:
        //default constructor
        Entity();

        //constructor
        Entity(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~Entity();

        // Getters.
        float getX();

        float getY();

        float getXSpeed();

        float getYSpeed();

        float getWidth();

        float getHeight();

        // Setters.
        void setX(float newX);

        void setY(float newY);

        void setXSpeed(float newDX);

        void setYSpeed(float newDY);

        // Update position.
        void updatePosition();

        // Collision detection.
        bool collision(Entity* e);

        // Make visible.
        virtual void visualize(Window* win) = 0;


    protected:
        //variables
        float x;
        float y;
        float width;
        float height;
        float dx;
        float dy;

    };
}

#endif //SPACEINVADERSV2_ENTITY_H
