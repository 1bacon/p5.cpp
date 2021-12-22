#pragma once
#include <string>
#include "p5_math.hpp"

namespace P5{

class PApplet{
    public: 
        virtual void setup();
        virtual void draw();

        virtual void mouseClicked();
        virtual void mousePressed();
        virtual void mouseReleased();
        virtual void mouseDragged();

        virtual void keyPressed();
        virtual void keyReleased();
        virtual void keyTyped();

        void setLocation(int _x,int _y);
        void setResizeable(bool _resizeable);
        void setTitle(std::string);

        void loop();
        void noLoop();

        void push();
        void pop();
        void pushStyle();
        void popStyle();
};

}