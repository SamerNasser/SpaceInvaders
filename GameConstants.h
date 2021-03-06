//
// Created by samer on 09/04/2020.
//

#ifndef SPACEINVADERSV2_GAMECONSTANTS_H
#define SPACEINVADERSV2_GAMECONSTANTS_H

namespace NONSDL {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    // Initial values for player.
    const float PLAYERX = 0.475;
    const float PLAYERY = 0.95;
    const float PLAYERWIDTH = 0.05;
    const float PLAYERHEIGHT = 0.05;
    const float PLAYERXSPEED = 0.01;
    const float PLAYERYSPEED = 0;

    // Initial values for bullet.
    const float BULLETX = 0;
    const float BULLETY = 0.95;
    const float BULLETWIDTH = 0.01;
    const float BULLETHEIGHT = 0.03;
    const float BULLETXSPEED = 0;
    const float BULLETYSPEED = -0.05;

    // Initial values for enemy.
    const float ENEMYX = 0;
    const float ENEMYY = 0;
    const float ENEMYWIDTH = 0.05;
    const float ENEMYHEIGHT = 0.05;
    const float ENEMYXSPEED = 0.002;
    const float ENEMYYSPEED = 0;

    // Initial values for Projectile.
    const float PROJECTILEX = 0;
    const float PROJECTILEY = 0;
    const float PROJECTILEWIDTH = 0.01;
    const float PROJECTILEHEIGHT = 0.03;
    const float PROJECTILEXSPEED = 0;
    const float PROJECTILEYSPEED = 0.008;

    // Initial values for PBonus.
    const float BONUSX = 0;
    const float BONUSY = 0;
    const float BONUSWIDTH = 0.04;
    const float BONUSHEIGHT = 0.04;
    const float BONUSXSPEED = 0;
    const float BONUSYSPEED = 0.003;

    // Number of enemy rows.
    const int NUMBEROFROWS = 4;

    // Number of enemy columns.
    const int NUMBEROFCOLUMNS = 12;

    // Number of milliseconds for 1 frame for 60 fps.
    const unsigned long FRAMETIMEMS = 17;

    // Number of milliseconds between bonuses.
    const unsigned int BONUSTIME = 10000;

    // Number of milliseconds a bonus will be active.
    const unsigned int BONUSACTIONTIME = 5000;

    enum GameState{
        START,
        PLAYING,
        END
    };

}

#endif //SPACEINVADERSV2_GAMECONSTANTS_H
