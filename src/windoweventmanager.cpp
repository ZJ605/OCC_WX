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

void WindowEventManager::OnSelectionChanged(const Handle(AIS_InteractiveContext) &theCtx, const Handle(V3d_View) &theView)
{
    std::cout << m_context->NbCurrents() << std::endl;
    //TopoDS_Shape s = m_context->SelectedShape();
    //std::cout << .get_type_name() << std::endl;
    //MGeom g = static_cast<MGeom>(s);

}
