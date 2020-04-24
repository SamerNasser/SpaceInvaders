//
// Created by samer on 20/04/2020.
//

#ifndef SPACEINVADERSV2_WINDOW_H
#define SPACEINVADERSV2_WINDOW_H

#include <string>

namespace NONSDL {
    class Window{
    public:
        //Constructor
        Window();

        //Destructor
        virtual ~Window();

        virtual void render(int type, float x, float y, float w, float h) = 0;

        virtual void renderText(float x, float y, float w, float h, std::string text) = 0;

        virtual void clearWindow() = 0;

        virtual void updateWindow() = 0;
    };
}


#endif //SPACEINVADERSV2_WINDOW_H
