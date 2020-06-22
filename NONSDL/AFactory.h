//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_AFACTORY_H
#define SPACEINVADERSV2_AFACTORY_H

#include "PlayerShip.h"
#include "PlayerInput.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Timer.h"
#include "Window.h"
#include "BonusEntity.h"
#include "Sound.h"

namespace NONSDL {
    class AFactory {
    public:
        // Destructor.
        virtual ~AFactory()
        {

        }

        // Methods.
        virtual PlayerShip* createPlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed) = 0;

        virtual PlayerInput* createPlayerInput() = 0;

        virtual Bullet* createBullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed) = 0;

        virtual Enemy* createEnemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed) = 0;

        virtual Projectile* createProjectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed) = 0;

        virtual BonusEntity* createPBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed) = 0;

        virtual BonusEntity* createNBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed) = 0;

        virtual Timer* createTimer() = 0;

        virtual Window* createWindow() = 0;

        virtual Sound* createSound() = 0;

    };
}

#endif //SPACEINVADERSV2_AFACTORY_H
