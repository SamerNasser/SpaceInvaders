//
// Created by samer on 30/03/2020.
//

#include "Game.h"
#include <iostream>
#include <vector>
#include "../GameConstants.h"

NONSDL::Game* NONSDL::Game::game = nullptr;

NONSDL::Game::Game(AFactory* f)
{
    afact = f;
}

NONSDL::Game::~Game()
{

}

void NONSDL::Game::run()
{

    // Main loop flag.
    bool running = true;

    // Flag for shooting bullet.
    bool shooting = false;

    // Flag for winning.
    bool win = false;

    // Flag for moving bonus item.
    bool bonusVisible = false;

    // Set game state to start state.
    GameState gameState = START;

    // Create vector of enemies.
    std::vector<Enemy*> enemies;

    // Create vector of projectiles.
    std::vector<Projectile*> pj;

    // Create a text string for text visualization.
    std::string text;

    // Create a bonus entity for using NBonuses and PBonuses.
    BonusEntity* bonus;

    // Make score variable.
    int score = 0;

    // Make lives variable.
    int lives = 3;

    // Number of milliseconds between enemies shooting.
    unsigned int shootTime = 500;

    // Create window.
    Window* window = afact->createWindow();

    // Clear window.
    window->clearWindow();

    // Make PlayerInput object
    PlayerInput* input = afact->createPlayerInput();

    // Make playership.
    PlayerShip* ps = afact->createPlayerShip(NONSDL::PLAYERX, NONSDL::PLAYERY, NONSDL::PLAYERWIDTH, NONSDL::PLAYERHEIGHT, NONSDL::PLAYERXSPEED, NONSDL::PLAYERYSPEED);

    // Make bullet.
    Bullet* bul = afact->createBullet(NONSDL::BULLETX, NONSDL::BULLETY, NONSDL::BULLETWIDTH, NONSDL::BULLETHEIGHT, NONSDL::BULLETXSPEED, NONSDL::BULLETYSPEED);

    // Make music.
    Sound* music = afact->createSound();

    // Make sound effect.
    Sound* effect = afact->createSound();

    // Make timer for frames.
    Timer* t1 = afact->createTimer();

    // Make timer for projectiles
    Timer* t2 = afact->createTimer();

    // Make timer for bonus spawning.
    Timer* t3 = afact->createTimer();

    // Make timer for Bonus active time.
    Timer* t4 = afact->createTimer();


    // Fill enemy vector.
    for (int i = 0; i <= NONSDL::NUMBEROFCOLUMNS - 1; i++){
        for (int j = 2; j <= NONSDL::NUMBEROFROWS + 1; j++){
        enemies.push_back(afact->createEnemy(((i*(NONSDL::ENEMYWIDTH + 0.01))), ((j*(NONSDL::ENEMYHEIGHT + 0.01)) + 0.02), NONSDL::ENEMYWIDTH, NONSDL::ENEMYHEIGHT, NONSDL::ENEMYXSPEED, NONSDL::ENEMYYSPEED ));
        }
    }

    // Random number used for enemy shooting.
    int r = rand() % enemies.size();

    // Random number used for bonus.
    int ran;

    // Start timer for projectiles.
    t2->start();

    // Start timer for bonus spawning.
    t3->start();

    // Start music.
    music->playMusic();


    // While application is running.
    while( running ) {

//===================================================START STATE========================================================

        while(gameState == START){

            // HANDLE USER INPUT---------------------------------------------------------------------------------------

            // Press space bar to start the game.
            int temp = input->CheckInput();
            if (temp == 0) {
                gameState = END;
                running = false;
            }
            else if (temp == 3) {
                gameState = PLAYING;
            }


            //RENDER START SCREEN--------------------------------------------------------------------------------------

            window->clearWindow();
            window->render(4, 0.25, 0.15, 0.5, 0.5); // NOG AANPASSEN
            window->render(7, 0.3, 0.75, 0.4, 0.05);
            window->updateWindow();


        }

//==================================================PLAYING STATE=======================================================

        while (gameState == PLAYING) {

            // Start timer for frames.
            t1->start();

            // HANDLE USER INPUT.--------------------------------------------------------------------------------------

            int temp = input->CheckInput();
            if (temp == 0) {
                gameState = END;
                running = false;
            } else if (temp == 1) {
                ps->setXSpeed(-1 * 0.015);
            } else if (temp == 2) {
                ps->setXSpeed(0.015);
            } else if (temp == 3) {
                if (!shooting) {
                    shooting = true;
                    bul->setYSpeed(NONSDL::BULLETYSPEED);
                    bul->setX(ps->getX() + (NONSDL::PLAYERWIDTH / 2));
                    bul->setY(NONSDL::BULLETY);
                    effect->shootSound();
                }
            } else {
                ps->setXSpeed(0);
            }


            // UPDATE POSITIONS.---------------------------------------------------------------------------------------

            // Playership's position is updated.
            ps->updatePosition();

            if (ps->getX() >= 1-NONSDL::ENEMYHEIGHT){
                ps->setX(1-NONSDL::ENEMYHEIGHT);
            }

            if (ps->getX() <= 0){
                ps->setX(0);
            }

            // When shooting, the bullet's position is updated.
            if (shooting) {
                bul->updatePosition();
            }

            // Bullet stops moving when it crosses the top of the screen.
            if (bul->getY() <= 0) {
                shooting = false;
                bul->setYSpeed(0);
            }

            // Move projectiles.
            if (t2->getDuration() > shootTime) {
                r = rand() % enemies.size();
                pj.push_back(afact->createProjectile(((enemies[r]->getX()) + (NONSDL::ENEMYWIDTH / 2)),
                                                     ((enemies[r]->getY()) + NONSDL::ENEMYHEIGHT),
                                                     NONSDL::PROJECTILEWIDTH, NONSDL::PROJECTILEHEIGHT,
                                                     NONSDL::PROJECTILEXSPEED, NONSDL::PROJECTILEYSPEED));
                t2->start();
            }

            // Move bonus
            if (t3->getDuration() > NONSDL::BONUSTIME) {
                ran = rand() % 95;
                if (ran % 2 == 0) {
                    bonus = afact->createPBonus(((float) ran / 100) + 0.05, NONSDL::BONUSY, NONSDL::BONUSWIDTH,
                                                NONSDL::BONUSHEIGHT, NONSDL::BONUSXSPEED, NONSDL::BONUSYSPEED);
                    bonusVisible = true;
                } else {
                    bonus = afact->createNBonus(((float) ran / 100) + 0.05, NONSDL::BONUSY, NONSDL::BONUSWIDTH,
                                                NONSDL::BONUSHEIGHT, NONSDL::BONUSXSPEED, NONSDL::BONUSYSPEED);
                    bonusVisible = true;
                }
                t3->start();
            }

            // Move bonus.
            if (bonusVisible) {
                bonus->updatePosition();
            }

            // End of bonus action time.
            if (t4->getDuration() > NONSDL::BONUSACTIONTIME){
                shootTime = 500;
                t2->start();
                t4->start();
            }

            // Move projectiles.
            for (const auto &p: pj) {
                p->updatePosition();
            }

            // Move enemies.
            for (const auto &enemy: enemies) {
                enemy->updatePosition();
            }

            /*
            for (const auto &enemy: enemies){           // At first I initiated the rows and columns the other way around
                if (enemy->getX() < maxLeftPos){        // and then these lines were needed to decide which enemy was
                    maxLeftPos = enemy->getX();         // the most right or left.
                    leftEnemy = enemy;
                }
            }
            for (const auto &enemy: enemies){
                if (enemy->getX() > maxRightPos){
                    maxRightPos = enemy->getX();
                    rightEnemy = enemy;
                }
            }
             */

            // Shift enemies down and in other direction.
            if ((enemies.back()->getX() >= (1 - NONSDL::ENEMYWIDTH)) or (enemies.front()->getX() <= 0)) {
                for (const auto &enemy: enemies) {
                    enemy->switchDirection();
                    enemy->shiftDown();
                }
            }


            // COLLISION DETECTION.------------------------------------------------------------------------------------

            // Collisions of projectiles.
            auto pIt = pj.begin();
            while (pIt != pj.end()) {
                if (((*pIt)->getY() > 1) || ((*pIt)->collision(ps))) {
                    if ((*pIt)->collision(ps)) {
                        ps->setX(NONSDL::PLAYERX);
                        lives--;
                        score -= 100;
                        effect->hurtSound();
                    }
                    delete (*pIt);
                    pIt = pj.erase(pIt);
                } else pIt++;
            }

            if (lives < 1) {
                gameState = END;
                win = false;
                effect->gameOverSound();
                music->stopMusic();
            }

            // Collisions of enemies.
            auto eIt = enemies.begin();
            while (eIt != enemies.end()) {
                if (bul->collision(*eIt)) {
                    shooting = false;
                    bul->disappear();
                    delete (*eIt);
                    eIt = enemies.erase(eIt);
                    score  += 50;
                    effect->hitSound();
                }
                else if ((*eIt)->collision(ps)){
                    gameState = END;
                    eIt = enemies.end();
                    win = false;
                    effect->gameOverSound();
                    music->stopMusic();
                }
                else eIt++;
            }

            // Collision of bonuses.
            if (bonusVisible) {
                if (bonus->getY() > 1 || (bonus->collision(ps))) {
                    if (bonus->collision(ps)) {
                        if (ran % 2 == 0) {
                            shootTime = 1500;
                            t2->start();
                            score += 200;
                            effect->PBonusSound();
                        } else{
                            shootTime = 250;
                            t2->start();
                            score -= 200;
                            effect->NBonusSound();
                        }

                    }
                    t4->start();
                    bonusVisible = false;
                    delete bonus;
                }
            }

            // When all enemies are killed, go to winning screen.
            if (enemies.empty()) {
                gameState = END;
                win = true;
                effect->winSound();
                music->stopMusic();
            }

            // RENDER OBJECTS.-----------------------------------------------------------------------------------------

            window->clearWindow();
            window->render(12, 0, 0, 1, 1);
            ps->visualize(window);
            // Bonus will be visualized.
            if (bonusVisible) {
                bonus->visualize(window);
            }
            // When shooting, the bullet will be visualized.
            if (shooting) {
                bul->visualize(window);
            }

            if (!pj.empty()) {
                for (const auto &p: pj) {
                    p->visualize(window);
                }
            }

            if (!enemies.empty()) {
                for (const auto &enemy: enemies) {
                    enemy->visualize(window);
                }
            }

            for(int i = 0; i < lives; i++){
                window->render(9, (0.8 + (i*NONSDL::ENEMYWIDTH + 0.01)), NONSDL::ENEMYHEIGHT/2 , NONSDL::ENEMYWIDTH, NONSDL::ENEMYHEIGHT);
            }

            text = ("score: " + std::to_string(score));
            window->renderText(0.02, NONSDL::ENEMYWIDTH/2, 0.2, NONSDL::ENEMYHEIGHT, text);

            window->updateWindow();


            while (t1->getDuration() < NONSDL::FRAMETIMEMS) {
                // Wait.
            }
        }

//=======================================================END STATE======================================================

        while(running && gameState == END){

            // CHECK INPUT---------------------------------------------------------------------------------------------

            int temp = input->CheckInput();     // Press escape to leave the game.
            if (temp == 0) {
                running = false;
            }
            else if (temp == 4) {
                running = false;
            }


            // RENDER SCREENS.-----------------------------------------------------------------------------------------

            window->clearWindow();
            if(win) {
                window->render(5, 0.25, 0.15, 0.5, 0.3);
                text = ("Your score was: " + std::to_string(score));
                window->renderText(0.32, 0.68, 0.35, 0.035, text);
            }
            else {
                window->render(6, 0.25, 0.15, 0.5, 0.5);
                text = ("Your score was: " + std::to_string(score));
                window->renderText(0.32, 0.68, 0.35, 0.035, text);
            }
            window->render(8, 0.35, 0.8, 0.35, 0.035);
            window->updateWindow();
        }
    }

//======================================================================================================================

    // Delete all instances.
    delete ps;
    delete bul;
    for (const auto &p: pj){
        delete p;
    }
    for (const auto &enemy: enemies){
        delete enemy;
    }
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete music;
    delete effect;
    delete window;
}

// Make sure there can only be one game instance.
NONSDL::Game* NONSDL::Game::gameInstance(AFactory* afact)
{
    if(game == NULL){
        game = new Game(afact);
    }

    return game;
}