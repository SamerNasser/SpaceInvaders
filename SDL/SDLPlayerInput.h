//
// Created by samer on 07/04/2020.
//

#ifndef SPACEINVADERSV2_SDLPLAYERINPUT_H
#define SPACEINVADERSV2_SDLPLAYERINPUT_H

#include "../NONSDL/PlayerInput.h"

namespace SDL {
    class SDLPlayerInput : public NONSDL::PlayerInput {
    public:
        //Constructor
        SDLPlayerInput();

        //Destructor
        ~SDLPlayerInput();

        //Check input from player
        int CheckInput();
    };
}


#endif //SPACEINVADERSV2_SDLPLAYERINPUT_H
