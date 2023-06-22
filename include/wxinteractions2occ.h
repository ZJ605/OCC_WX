#ifndef WXINTERACTIONS2OCC_H
#define WXINTERACTIONS2OCC_H

#include <AIS_ViewController.hxx>
#include <Aspect_DisplayConnection.hxx>
//#include <V3d_View.hxx>

#include "wx/event.h"

class WXInteractions2OCC
{
    public:
        static void test();
        static Aspect_VKeyMouse MouseButtons2VKeys(const wxMouseEvent&)
        {
             Aspect_VKeyMouse buttons = Aspect_VKeyMouse_NONE;
            return buttons;
        }

    private:
        WXInteractions2OCC();
};

#endif // WXINTERACTIONS2OCC_H
