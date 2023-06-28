#include "geometrymodule.h"

GeometryModule::GeometryModule()
{
    //TopoDS_Shape box = BRepPrimAPI_MakeBox(10,20,30);
    //m_shapes.push_back(&box);
}

GeometryModule::~GeometryModule()
{
    //dtor
}

void GeometryModule::createWindow(wxMDIParentFrame* parent)
{
    m_window = new GeometryModuleWindow(parent, m_geom);
}

void GeometryModule::addGeometry(Handle(MGeom) shape)
{
    m_geom.push_back(shape);
}
/*
wxMDIChildFrame* GeometryModule::getWindow()
{
    return (wxMDIChildFrame*)m_window;
}
*/
