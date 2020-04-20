//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_SDLFACTORY_H
#define SPACEINVADERSV2_SDLFACTORY_H

#include "../NONSDL/PlayerShip.h"
#include "../NONSDL/AFactory.h"
#include "SDLWindow.h"


namespace SDL {
    class SDLFactory : public NONSDL::AFactory {
    public:
        //constructor
        SDLFactory();

        //destructor
        ~SDLFactory();

        //Methods
        NONSDL::PlayerShip* createPlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        NONSDL::PlayerInput* createPlayerInput();

        NONSDL::Bullet* createBullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        NONSDL::Enemy* createEnemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        NONSDL::Projectile* createProjectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        NONSDL::Timer* createTimer();

        NONSDL::Window* createWindow();

    };
}


#endif //SPACEINVADERSV2_SDLFACTORY_H
