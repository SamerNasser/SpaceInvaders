//
// Created by samer on 07/04/2020.
//

#ifndef SPACEINVADERSV2_PLAYERINPUT_H
#define SPACEINVADERSV2_PLAYERINPUT_H

namespace NONSDL {
class PlayerInput {
    public:
        //Constructor
        PlayerInput();

        //Destructor
        virtual ~PlayerInput();

        //Check input from player
        virtual int CheckInput() = 0;
    };
}


#endif //SPACEINVADERSV2_PLAYERINPUT_H
