#include "wxinteractions2occ.h"

#include <iostream>

WXInteractions2OCC::WXInteractions2OCC()
{
    //ctor
}

void WXInteractions2OCC::test()
{
    std::cout << "asdf" << std::endl;
}

static Aspect_VKeyMouse WXInteractions2OCC::MouseButtons2VKeys(const wxMouseEvent& b)
{
    Aspect_VKeyMouse buttons = Aspect_VKeyMouse_NONE;

    return buttons;
}

