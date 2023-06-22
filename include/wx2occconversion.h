#ifndef WX2OCCCONVERSION_H
#define WX2OCCCONVERSION_H

#include "Aspect_Display.hxx"
#include <AIS_InteractiveContext.hxx>
#include <AIS_ViewController.hxx>

class WX2OCCConversion
{
    private:
        WX2OCCConversion();

    public:
        static Aspect_VKeyMouse wxMouseEvent2OCC(){
            Aspect_VKeyMouse buttons = Aspect_VKeyMouse_NONE;
            return buttons;
        }
        static Aspect_VKeyFlags wxKeyFlags2OCC(){
            Aspect_VKeyFlags flags = Aspect_VKeyFlags_NONE;
            return flags;
        }
};

#endif // WX2OCCCONVERSION_H
