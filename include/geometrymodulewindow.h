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
#include "wx/treectrl.h"
#include "wx/splitter.h"

#include "messenger.h"
#include "windoweventmanager.h"
#include "mgeom.h"
#include "geometrywindow.h"
#include "geometrytreewindow.h"
#include "visualsettings.h"


class GeometryModuleWindow : public wxMDIChildFrame
{
    public:
        GeometryModuleWindow(wxMDIParentFrame* parent, std::list<Handle(MGeom)>&);
        virtual ~GeometryModuleWindow();

    private:
        void initLayout();

        void bindEvents();

    private:
        std::list<Handle(MGeom)> m_geometryobjects;
        //std::vector<TopoDS_Shape> m_shapes;

    private:
        void onMaximize(const wxMaximizeEvent&);

    //layout
    private:
        wxSplitterWindow* m_mainsplitter;
        wxBoxSizer* m_mainsizer;
        GeometryWindow* m_geometryWindow;
        GeometryTreeWindow* m_treeWindow;
        //wxPanel* m_treePanel;
        //wxPanel* m_geometryPanel;
};

#endif // GEOMETRYMODULEWINDOW_H
