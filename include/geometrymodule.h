#ifndef GEOMETRYMODULE_H
#define GEOMETRYMODULE_H

#include "wx/mdi.h"

#include <list>

#include "TopoDS_Shape.hxx"
#include "BRepPrimAPI_MakeBox.hxx"

#include "geometrymodulewindow.h"
#include "mgeom.h"

class GeometryModule
{
    public:
        GeometryModule(wxMDIParentFrame* parent);
        virtual ~GeometryModule();

        //void createWindow(wxMDIParentFrame* parent);

        void addGeometry(Handle(MGeom) geom);

    private:
        void createToolbars(wxMDIParentFrame* parent);

    //creating geometry
    private:
        void createParaboloid(wxCommandEvent&);

    private:

        GeometryModuleWindow* m_window;

        std::list<Handle(MGeom)> m_geom;
};

#endif // GEOMETRYMODULE_H
