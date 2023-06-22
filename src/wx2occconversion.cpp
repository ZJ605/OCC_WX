#include "wx2occconversion.h"

WX2OCCConversion::WX2OCCConversion()
{}

static Aspect_VKeyMouse WX2OCCConversion::wxMouseEvent2OCC()
{
    Aspect_VKeyMouse buttons = Aspect_VKeyMouse_NONE;
    return buttons;
}

static Aspect_VKeyMouse WX2OCCConversion::wxKeyFlags2OCC()
{
    Aspect_VKeyFlags flags = Aspect_VKeyFlags_NONE;
    return flags;
}
