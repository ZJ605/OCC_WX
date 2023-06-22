#include "geometrymodulewindow.h"

#include "wxinteractions2occ.h"

#include "BRepPrimAPI_MakeBox.hxx"
#include "AIS_Shape.hxx"
#include <iostream>

GeometryModuleWindow::GeometryModuleWindow(wxMDIParentFrame* parent) : wxMDIChildFrame(parent, wxID_ANY, "draw"), box(BRepPrimAPI_MakeBox(10,20,30))
{
    init();
    bindEvents();

    m_shapes.push_front(box);
}

GeometryModuleWindow::~GeometryModuleWindow()
{
    //dtor
}

void GeometryModuleWindow::init()
{
 	Handle(Aspect_DisplayConnection) displayconnection = new Aspect_DisplayConnection();
	Handle(OpenGl_GraphicDriver) driver = new OpenGl_GraphicDriver(displayconnection);

	HWND win = this->GetHWND();
	Handle(WNT_Window) winhandle = new WNT_Window(win);

	m_viewer = new V3d_Viewer(driver);
	m_view = m_viewer->CreateView();
	m_view->SetWindow(winhandle);
	if (!winhandle->IsMapped()) winhandle->Map();
	m_context = new AIS_InteractiveContext(m_viewer);
	m_viewer->SetDefaultLights();
	m_viewer->SetLightOn();

	m_view->SetBackgroundColor(Quantity_NOC_BLACK);
	m_view->MustBeResized();
	m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);

	m_context->SetDisplayMode(AIS_Shaded, Standard_True);

	m_eventManager = new WindowEventManager(m_view, m_context);
    //std::cout << (int)win << std::endl;


    /*
    Handle(V3d_DirectionalLight) LightDir = new V3d_DirectionalLight(V3d_Zneg, Quantity_Color (Quantity_NOC_GRAY97), 1);
    Handle(V3d_AmbientLight)     LightAmb = new V3d_AmbientLight();
    LightDir->SetDirection(1.0, -2.0, -10.0);
    m_viewer->AddLight(LightDir);
    m_viewer->AddLight(LightAmb);
    m_viewer->SetLightOn(LightDir);
    m_viewer->SetLightOn(LightAmb);

    m_context = new AIS_InteractiveContext(m_viewer);
    m_view = m_viewer->CreateView();
    m_aspectwindow = new WNT_Window((HWND)this->GetHWND());

    m_view->SetWindow(m_aspectwindow, nullptr);

    if (m_aspectwindow->IsMapped())
    {
        m_aspectwindow->Map();
    }
    */
}

void GeometryModuleWindow::bindEvents()
{
    Bind(wxEVT_PAINT, &GeometryModuleWindow::onPaint,this);
    Bind(wxEVT_MOTION, &GeometryModuleWindow::onMouseMove, this);
    Bind(wxEVT_LEFT_DOWN, &GeometryModuleWindow::onMouseClick, this);
    Bind(wxEVT_LEFT_UP, &GeometryModuleWindow::onMouseClick, this);
    Bind(wxEVT_MIDDLE_DOWN, &GeometryModuleWindow::onMouseClick, this);
    Bind(wxEVT_MIDDLE_UP, &GeometryModuleWindow::onMouseClick, this);
    Bind(wxEVT_RIGHT_DOWN, &GeometryModuleWindow::onMouseClick, this);
    Bind(wxEVT_RIGHT_UP, &GeometryModuleWindow::onMouseClick, this);
    Bind(wxEVT_MOUSEWHEEL, &GeometryModuleWindow::onMouseWheel, this);
}

void GeometryModuleWindow::onPaint(const wxPaintEvent&)
{
    for (auto sh : m_shapes)
    {
        Handle(AIS_Shape) shape = new AIS_Shape(box);
        m_context->Display(shape, false);
    }
    m_view->Redraw();

}

void GeometryModuleWindow::onMouseMove(const wxMouseEvent& ev)
{
    int posx = 0;
    int posy = 0;
    ev.GetPosition(&posx,&posy);
    const Graphic3d_Vec2i pos(posx,posy);
    const Aspect_VKeyFlags buttons = ::wxMouseButtons2VKeys(ev);
    const Aspect_VKeyFlags flags = ::wxMouseKeyFlags2VKeyFlags(ev);
    if (!m_eventManager.IsNull())
        m_eventManager->UpdateMousePosition(pos, buttons, flags, false);
        m_eventManager->FlushViewEvents(m_context, m_view, true);
}

void GeometryModuleWindow::onMouseClick(const wxMouseEvent& ev)
{
    int posx = 0;
    int posy = 0;
    ev.GetPosition(&posx,&posy);
    const Graphic3d_Vec2i pos(posx,posy);
    const Aspect_VKeyFlags flags = ::wxMouseKeyFlags2VKeyFlags(ev);
    Aspect_VKeyMouse button = Aspect_VKeyMouse_NONE;

    if (ev.LeftDown() || ev.LeftUp())
        button = Aspect_VKeyMouse_LeftButton;
    else if (ev.MiddleDown() || ev.MiddleUp())
        button = Aspect_VKeyMouse_MiddleButton;
    else
        button = Aspect_VKeyMouse_RightButton;

    if ( ev.LeftDown() || ev.MiddleDown() || ev.RightDown() )
    {

        //SetFocus((HWND)this->GetHWND());
        //SetCapture(this->GetHWND());
        if (!m_eventManager.IsNull())
            m_eventManager->PressMouseButton(pos, button, flags, false);
    }
    else
    {
        //ReleaseCapture();
        if (!m_eventManager.IsNull())
            m_eventManager->ReleaseMouseButton(pos, button, flags, false);
    }

    m_eventManager->FlushViewEvents(m_context, m_view, true);
}
void GeometryModuleWindow::onMouseWheel(const wxMouseEvent& ev)
{
       //std::cout << "g" <<std::endl;

    const double delta = double(ev.GetWheelRotation())/(double)ev.GetWheelDelta();
    const Aspect_VKeyFlags flags = ::wxMouseKeyFlags2VKeyFlags(ev);
    int posx = 0;
    int posy = 0;
    ev.GetPosition(&posx,&posy);
    const Graphic3d_Vec2i pos(posx,posy);
    if ( !m_eventManager.IsNull() )
      {
        m_eventManager->UpdateMouseScroll( Aspect_ScrollDelta(pos, delta, flags) );
        m_eventManager->FlushViewEvents(m_context, m_view, true);
      }
}

