#ifndef GEOMETRYMODULEWINDOW_H
#define GEOMETRYMODULEWINDOW_H

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

#include <list>

#include "wx/mdi.h"
#include "wx/window.h"

#include "messenger.h"
#include "windoweventmanager.h"
#include "mgeom.h"


class GeometryModuleWindow : public wxMDIChildFrame
{
    public:
        GeometryModuleWindow(wxMDIParentFrame* parent, std::list<Handle(MGeom)>&);
        virtual ~GeometryModuleWindow();

    private:
        void init();
        void bindEvents();

    //events
    private:
        void onPaint(const wxPaintEvent& ev);

        void onMouseMove(const wxMouseEvent&);
        void onMouseClick(const wxMouseEvent&);
        void onMouseWheel(const wxMouseEvent&);
        void onWindowMove(const wxMoveEvent&);
        void onWindowResize(const wxSizeEvent&);

    private:
        Handle(V3d_Viewer) m_viewer;
        Handle(V3d_View) m_view;
        Handle(AIS_InteractiveContext) m_context;
        Handle(WindowEventManager) m_eventManager;
        Handle(Aspect_Window) m_aspectwindow;

        //TopoDS_Shape box;

        std::list<Handle(MGeom)> m_geometryobjects;
        //std::vector<TopoDS_Shape> m_shapes;
    //dialog
    private:
        //MGeom_ParaboloidDialog m_dialog;
};

#endif // GEOMETRYMODULEWINDOW_H
