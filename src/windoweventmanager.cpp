#include "windoweventmanager.h"

#include <Aspect_Grid.hxx>
#include <AIS_AnimationCamera.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <V3d_View.hxx>

WindowEventManager::WindowEventManager(const Handle(V3d_View)& view, const Handle(AIS_InteractiveContext)& ctx) :
    m_view(view), m_context(ctx)
{
    //ctor
}

WindowEventManager::~WindowEventManager()
{

}
bool WindowEventManager::UpdateMouseButtons(const Graphic3d_Vec2i& pnt, Aspect_VKeyMouse buttons, Aspect_VKeyFlags flags, bool emulated){
    return AIS_ViewController::UpdateMouseButtons(pnt, buttons, flags, emulated);
}
