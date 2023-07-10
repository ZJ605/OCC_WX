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
#include "mais_shape.h"

class GeometryModuleWindow;
class WindowEventManager;
class GeometryEventManager;

class GeometryWindow : public wxPanel, public Standard_Transient
{
    DEFINE_STANDARD_RTTI_INLINE(GeometryWindow, Standard_Transient)

    public:
        GeometryWindow(wxWindow* parent, GeometryModuleWindow* win, std::list<Handle(MGeom)>&);
        virtual ~GeometryWindow();

        void setGeometryModuleWindow(GeometryModuleWindow*);

    public:
        void addGeometry(Handle(MGeom));

        void onUpdateGeometry();

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

        void onSelectGeometry(); //selected geometry from geometrywindow

    //create geometry
    public:
        void createParaboloid();

    private:
        std::list<Handle(MGeom)> m_geometryobjects;

        TopAbs_ShapeEnum m_selectionmode; //

        GeometryModuleWindow* m_geometrymodulewindow;
};

#endif // GEOMETRYWINDOW_H
