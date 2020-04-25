//
// Created by samer on 24/04/2020.
//

#ifndef SPACEINVADERSV2_SOUND_H
#define SPACEINVADERSV2_SOUND_H


namespace NONSDL {
    class Sound {
    public:
        // Constructor.
        Sound();
        // Destructor.
        virtual ~Sound();
        // Shoot Sound.
        virtual void shootSound() = 0;

        virtual void hitSound() = 0;

        virtual void gameOverSound() = 0;

        virtual void winSound() = 0;

        virtual void hurtSound() = 0;

        virtual void NBonusSound() = 0;

        virtual void PBonusSound() = 0;

        virtual void playMusic() = 0;

        virtual void stopMusic() = 0;


    protected:
        unsigned int startTime;
    };
}

#endif //SPACEINVADERSV2_SOUND_H
