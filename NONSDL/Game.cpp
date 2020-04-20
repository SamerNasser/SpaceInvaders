//
// Created by samer on 30/03/2020.
//

#include "Game.h"
#include <stdio.h>
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

/*NONSDL::Game::Game(const Game& g)
{

}

NONSDL::Game& NONSDL::Game::operator=(const Game& g)
{

}
 */

void NONSDL::Game::run()
{

    // Main loop flag.
    bool running = true;

    GameState gameState = START;

    bool shooting = false;

    std::vector<Enemy*> enemies;

    std::vector<Projectile*> pj;

    Enemy* leftEnemy;

    Enemy* rightEnemy;

    int maxLeftPos = 2;

    int maxRightPos = -1;

    int lives = 3;

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

    // Make timer for frames.
    Timer* t1 = afact->createTimer();

    // Make timer for projectiles
    Timer* t2 = afact->createTimer();


    // Create enemies.
    for (int i = 0; i <= NONSDL::NUMBEROFCOLUMNS - 1; i++){
        for (int j = 0; j <= NONSDL::NUMBEROFROWS - 1; j++){
        enemies.push_back(afact->createEnemy(((i*(NONSDL::ENEMYWIDTH + 0.01))), ((j*(NONSDL::ENEMYHEIGHT + 0.01)) + 0.02), NONSDL::ENEMYWIDTH, NONSDL::ENEMYHEIGHT, NONSDL::ENEMYXSPEED, NONSDL::ENEMYYSPEED ));
        }
    }

    // Random number used for enemy shooting.
    int r = rand() % enemies.size();

    // Start timer for projectiles.
    t2->start();


    // While application is running.
    while( running ) {
        while(gameState == START){          // Press space bar to start the game.

            // HANDLE USER INPUT

            int temp = input->CheckInput();
            if (temp == 3) {
                gameState = PLAYING;
            }


            //RENDER START SCREEN



        }
        while (gameState == PLAYING) {

            // Start timer for frames.
            t1->start();

            // HANDLE USER INPUT.

            int temp = input->CheckInput();
            //printf("%d", temp);
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
                }
            } else {
                ps->setXSpeed(0);
            }


            // UPDATE POSITIONS.

            // Playership's position is updated.
            ps->updatePosition();
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
            if (t2->getDuration() > (NONSDL::SHOOTTIME)) {
                r = rand() % enemies.size();
                pj.push_back(afact->createProjectile(((enemies[r]->getX()) + (NONSDL::ENEMYWIDTH / 2)),
                                                     ((enemies[r]->getY()) + NONSDL::ENEMYHEIGHT),
                                                     NONSDL::PROJECTILEWIDTH, NONSDL::PROJECTILEHEIGHT,
                                                     NONSDL::PROJECTILEXSPEED, NONSDL::PROJECTILEYSPEED));
                t2->start();
            }
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


            // COLLISION DETECTION.

            // Collisions of projectiles.
            auto pIt = pj.begin();
            while (pIt != pj.end()) {
                if (((*pIt)->getY() > 1) || ((*pIt)->collision(ps))) {
                    if ((*pIt)->collision(ps)) {
                        lives--;
                    }
                    delete (*pIt);
                    pIt = pj.erase(pIt);
                } else pIt++;
            }
            if (lives < 1) {
                gameState = END;
            }

            // Collisions of enemies.
            auto eIt = enemies.begin();
            while (eIt != enemies.end()) {
                if (bul->collision(*eIt)) {
                    shooting = false;
                    bul->disappear();
                    delete (*eIt);
                    eIt = enemies.erase(eIt);
                } else eIt++;
            }
            if (enemies.empty()) {
                running = false;
            }



            // RENDER OBJECTS.

            window->clearWindow();
            ps->visualize(window);
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

            window->updateWindow();


            while (t1->getDuration() < NONSDL::FRAMETIMEMS) {
                // Wait.
            }
        }

        if(gameState == END){               // Press space bar to leave the game.
            int temp = input->CheckInput();
            if (temp == 3) {
                running = false;
            }
        }
    }

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
    delete window;




    /*for(alle playerentities p){
        for(alle Enemyentities e){
            if p.collisionDetection(e)
            {
                p.hascollision(e);
            }
        }
        for(alle bonussen b){
            if p.collisionDetection(b)
            {
                p.hascollision(b);
            }
        }
    } */
}


NONSDL::Game* NONSDL::Game::gameInstance(AFactory* afact)
{
    if(game == NULL){
        game = new Game(afact);
    }

    return game;
}