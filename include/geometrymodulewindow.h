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

#include "messenger.h"
#include "windoweventmanager.h"


class GeometryModuleWindow : public wxMDIChildFrame
{
    public:
        GeometryModuleWindow(wxMDIParentFrame* parent);
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

    private:
        Handle(V3d_Viewer) m_viewer;
        Handle(V3d_View) m_view;
        Handle(AIS_InteractiveContext) m_context;
        Handle(WindowEventManager) m_eventManager;
        Handle(Aspect_Window) m_aspectwindow;

        TopoDS_Shape box;

        std::list<TopoDS_Shape> m_shapes;
        //std::vector<TopoDS_Shape> m_shapes;
};

#endif // GEOMETRYMODULEWINDOW_H
