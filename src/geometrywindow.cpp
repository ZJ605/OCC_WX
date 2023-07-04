#include "geometrywindow.h"

#include "wxinteractions2occ.h"

#include "BRepPrimAPI_MakeBox.hxx"
#include "AIS_Shape.hxx"
#include "mgeom_lens.h"
#include "mgeom_paraboloid.h"

#include <iostream>

GeometryWindow::GeometryWindow(wxWindow* parent, GeometryModuleWindow* win, std::list<Handle(MGeom)>& geoms) : wxPanel(parent, wxID_ANY), m_geometryobjects(geoms), m_geometrymodulewindow(win)
{
    init();
    bindEvents();

    m_geometrymodulewindow = win;

    Handle(MGeom_Paraboloid) par = new MGeom_Paraboloid(this);
    if (par->calculate())
        addGeometry(par);

    Handle(MGeom_Paraboloid) par2 = new MGeom_Paraboloid(this);
    par2->setFocalDistance(40);
    if (par2->calculate())
        addGeometry(par2);
}

GeometryWindow::~GeometryWindow()
{
    //dtor
}

void GeometryWindow::init()
{
    Handle(Aspect_DisplayConnection) displayconnection = new Aspect_DisplayConnection();
	Handle(OpenGl_GraphicDriver) driver = new OpenGl_GraphicDriver(displayconnection);

	//HWND win = this->GetHWND();
	HWND win = this->GetHWND();
    Handle(WNT_Window) winhandle = new WNT_Window(win);

	m_viewer = new V3d_Viewer(driver);
	m_view = m_viewer->CreateView();
	m_view->SetWindow(winhandle);
	if (!winhandle->IsMapped()) winhandle->Map();

	m_context = new AIS_InteractiveContext(m_viewer);
    m_selectionmode = TopAbs_FACE;

	m_viewer->SetDefaultLights();
	m_viewer->SetLightOn();
    Handle(V3d_DirectionalLight) LightDir = new V3d_DirectionalLight(V3d_Zneg, Quantity_Color (Quantity_NOC_GRAY97), 1);
    Handle(V3d_AmbientLight)     LightAmb = new V3d_AmbientLight();
    LightDir->SetDirection(1.0, -2.0, -10.0);
    m_viewer->AddLight(LightDir);
    m_viewer->AddLight(LightAmb);
    m_viewer->SetLightOn(LightDir);
    m_viewer->SetLightOn(LightAmb);

	m_view->SetBackgroundColor(Quantity_NOC_BLACK);
	m_view->MustBeResized();
	m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);

	m_context->SetDisplayMode(AIS_Shaded, Standard_True);
    //m_context->SetSelectionModeActive();
	m_eventManager = new WindowEventManager(m_view, m_context, this->m_geometrymodulewindow);
    //std::cout << (int)win << std::endl;

    //m_context->ActivateStandardMode(TopAbs_Shape);
}


void GeometryWindow::bindEvents()
{
    Bind(wxEVT_PAINT, &GeometryWindow::onPaint,this);
    Bind(wxEVT_MOTION, &GeometryWindow::onMouseMove, this);
    Bind(wxEVT_LEFT_DOWN, &GeometryWindow::onMouseClick, this);
    Bind(wxEVT_LEFT_UP, &GeometryWindow::onMouseClick, this);
    Bind(wxEVT_MIDDLE_DOWN, &GeometryWindow::onMouseClick, this);
    Bind(wxEVT_MIDDLE_UP, &GeometryWindow::onMouseClick, this);
    Bind(wxEVT_RIGHT_DOWN, &GeometryWindow::onMouseClick, this);
    Bind(wxEVT_RIGHT_UP, &GeometryWindow::onMouseClick, this);
    Bind(wxEVT_MOUSEWHEEL, &GeometryWindow::onMouseWheel, this);
    Bind(wxEVT_MOVE, &GeometryWindow::onWindowMove, this);
    Bind(wxEVT_SIZE, &GeometryWindow::onWindowResize, this);
}

void GeometryWindow::setGeometryModuleWindow(GeometryModuleWindow* win)
{
    this->m_geometrymodulewindow = win;
    //this->m_geometrymodulewindow = win
}
void GeometryWindow::onPaint(const wxPaintEvent&)
{

    //m_context->Activate(m_selectionmode);
    m_context->Activate(m_selectionmode, Standard_True);

    for (Handle(MGeom) sh : m_geometryobjects)
    {
        //Handle(AIS_Shape) shape = new AIS_Shape(sh->getShape());
        Handle(MAIS_Shape) shape = new MAIS_Shape(sh);
        m_context->Display(shape, 0x0001,AIS_SelectionModesConcurrency_Single,true, PrsMgr_DisplayStatus_Displayed);
    }
    m_view->FitAll();
    m_view->Redraw();

}

void GeometryWindow::onWindowMove(const wxMoveEvent&)
{
}

void GeometryWindow::onWindowResize(const wxSizeEvent&)
{
    //std::cout << "resize " << std::endl;
    m_view->MustBeResized();
    m_view->Update();
    //m_treePanel->SetSize(200,);
}

void GeometryWindow::onMouseMove(const wxMouseEvent& ev)
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

void GeometryWindow::onMouseClick(const wxMouseEvent& ev)
{
    if (ev.LeftDClick())
    {
        m_eventManager->onLeftMouseDClick();

    }
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
void GeometryWindow::onMouseWheel(const wxMouseEvent& ev)
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

void GeometryWindow::addGeometry(Handle(MGeom) g)
{
    m_geometryobjects.push_back(g);
}


