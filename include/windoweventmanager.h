#ifndef WINDOWEVENTMANAGER_H
#define WINDOWEVENTMANAGER_H

#include "AIS_ViewController.hxx"
#include "Aspect_Window.hxx"
#include <TColgp_Array1OfPnt2d.hxx>
#include <TCollection_AsciiString.hxx>

#include "wx/wx.h"

#include "mgeom.h"

namespace {
    static Aspect_VKeyMouse wxMouseButtons2VKeys(const wxMouseEvent& ev){
        Aspect_VKeyMouse buttons = Aspect_VKeyMouse_NONE;
        if (ev.LeftIsDown())
            buttons |= Aspect_VKeyMouse_LeftButton;
        if (ev.MiddleIsDown())
            buttons |= Aspect_VKeyMouse_MiddleButton;
        if (ev.RightIsDown())
            buttons |= Aspect_VKeyMouse_RightButton;
        return buttons;
    }
    static Aspect_VKeyFlags wxMouseKeyFlags2VKeyFlags(const wxMouseEvent& ev){
        Aspect_VKeyFlags flags = Aspect_VKeyFlags_NONE;
        if (ev.ControlDown())
        {
            flags |= Aspect_VKeyFlags_CTRL;
        }
        if (ev.ShiftDown())
        {
            flags |= Aspect_VKeyFlags_SHIFT;
        }
        if (ev.AltDown())
        {
            flags |= Aspect_VKeyFlags_ALT;
        }
        return flags;
    }
}

class WindowEventManager : public AIS_ViewController, public Standard_Transient
{
    DEFINE_STANDARD_RTTI_INLINE(WindowEventManager, Standard_Transient)

    public:
        WindowEventManager(const Handle(V3d_View)& view, const Handle(AIS_InteractiveContext)& ctx);
        virtual ~WindowEventManager();

    public:
        //virtual bool UpdateMousePosition(const Graphic3d_Vec2i& point, Aspect_VKeyMouse buttons, Aspect_VKeyFlags modifiers, bool isEmulated) Standard_OVERRIDE;
        virtual bool UpdateMouseButtons(const Graphic3d_Vec2i& thePoint, Aspect_VKeyMouse theButtons, Aspect_VKeyFlags theModifiers, bool theIsEmulated) Standard_OVERRIDE;
        virtual void OnSelectionChanged(const Handle(AIS_InteractiveContext) &theCtx, const Handle(V3d_View) &theView) override;

    private:
        Handle(V3d_View) m_view;
        Handle(AIS_InteractiveContext) m_context;
};

#endif // WINDOWEVENTMANAGER_H
