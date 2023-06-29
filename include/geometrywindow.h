#ifndef GEOMETRYWINDOW_H
#define GEOMETRYWINDOW_H

#include "Aspect_Window.hxx"
#include "AIS_InteractiveContext.hxx"
#include "V3d_Viewer.hxx"
#include "V3d_View.hxx"
#include "OpenGl_GraphicDriver.hxx"
#include "Aspect_DisplayConnection.hxx"
#include "Aspect_Handle.hxx"
#include "WNT_Window.hxx"
#include "V3d_AmbientLight.hxx"
#include "V3d_DirectionalLight.hxx"
#include "TopoDS_Shape.hxx"
#include "Quantity_Color.hxx"

#include <list>

#include "wx/mdi.h"
#include "wx/window.h"
#include "wx/treectrl.h"

#include "messenger.h"
#include "windoweventmanager.h"
#include "mgeom.h"
#include "geometrywindow.h"
#include "geometrytreewindow.h"

class GeometryWindow : public wxPanel
{
    public:
        GeometryWindow(wxWindow* parent, std::list<Handle(MGeom)>&);
        virtual ~GeometryWindow();

    public:
        void addGeometry(Handle(MGeom));

    private:
        void bindEvents();
        void init(); //initialize AIS window and connects it to wxwindow m_goemetrypanel

    private:
        Handle(V3d_Viewer) m_viewer;
        Handle(V3d_View) m_view;
        Handle(AIS_InteractiveContext) m_context;
        Handle(WindowEventManager) m_eventManager;
        Handle(Aspect_Window) m_aspectwindow;

    //events
    private:
        void onPaint(const wxPaintEvent& ev);
        void onMouseMove(const wxMouseEvent&);
        void onMouseClick(const wxMouseEvent&);
        void onMouseWheel(const wxMouseEvent&);
        void onWindowMove(const wxMoveEvent&);
        void onWindowResize(const wxSizeEvent&);


    private:
        std::list<Handle(MGeom)> m_geometryobjects;
};

#endif // GEOMETRYWINDOW_H
