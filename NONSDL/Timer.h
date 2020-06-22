//
// Created by samer on 12/04/2020.
//

#ifndef SPACEINVADERSV2_TIMER_H
#define SPACEINVADERSV2_TIMER_H

namespace NONSDL {
    class Timer {
    public:
        // Constructor.
        Timer();

        // Destructor.
        virtual ~Timer();

        // Start timer.
        virtual void start() = 0;

        // Duration.
        virtual unsigned int  getDuration() = 0;
    protected:
        unsigned int startTime;
    };
}

#endif //SPACEINVADERSV2_TIMER_H
