//
// Created by samer on 12/04/2020.
//

#ifndef SPACEINVADERSV2_SDLSDLTimer_H
#define SPACEINVADERSV2_SDLSDLTimer_H

#include "../NONSDL/Timer.h"

namespace SDL {
class SDLTimer : public NONSDL::Timer {
    public:
        // Constructor.
        SDLTimer();
        // Destructor.
        ~SDLTimer();
        // Start SDLTimer.
        void start();
        // Duration.
        unsigned int  getDuration();
        // Do nothing.
        void sleep(unsigned long time);
    };
}


#endif //SPACEINVADERSV2_SDLSDLTimer_H
