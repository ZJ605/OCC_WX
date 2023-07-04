#include "windoweventmanager.h"

#include <Aspect_Grid.hxx>
#include <AIS_AnimationCamera.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <V3d_View.hxx>

WindowEventManager::WindowEventManager(const Handle(V3d_View)& view, const Handle(AIS_InteractiveContext)& ctx, GeometryModuleWindow* win) :
    m_view(view), m_context(ctx), m_geometrymodulewindow(win), m_leftMouseDClicked(false)
{

}

WindowEventManager::~WindowEventManager()
{

}
bool WindowEventManager::UpdateMouseButtons(const Graphic3d_Vec2i& pnt, Aspect_VKeyMouse buttons, Aspect_VKeyFlags flags, bool emulated){
    //int a = PressedMouseButtons();
    //std::cout << "mods " << a << std::endl;
    return AIS_ViewController::UpdateMouseButtons(pnt, buttons, flags, emulated);
}

void WindowEventManager::OnSelectionChanged(const Handle(AIS_InteractiveContext) &theCtx, const Handle(V3d_View) &theView)
{
    if (m_leftMouseDClicked)
    {
        m_leftMouseDClicked = false;
    }

    if (m_context->NbCurrents() > 0)
    {
        Handle(AIS_InteractiveObject) o = m_context->FirstSelectedObject();
        MAIS_Shape* moo = (MAIS_Shape*)(o.get());
        m_geometrymodulewindow->onSelectGeometry(moo->getMGeomHandle());
    }
}

void WindowEventManager::onLeftMouseDClick()
{
    m_leftMouseDClicked = true;
    m_leftMouseDClickedTime = AIS_ViewController::myMouseClickTimer.GetWallClockTime();
}

