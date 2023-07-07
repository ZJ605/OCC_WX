#include "geometrymodule.h"

#include "mainwindow.h"

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
    createToolbars(parent);
}

void GeometryModule::addGeometry(Handle(MGeom) shape)
{
    m_geom.push_back(shape);
}

void GeometryModule::createToolbars(wxMDIParentFrame* parent)
{
    wxMenu* geommenu = new wxMenu();
    parent->Bind(wxEVT_MENU, &GeometryModule::createParaboloid, this, geommenu->Append(wxID_ANY, "Paraboloid")->GetId());

    wxMenuBar* menubar = parent->GetMenuBar();
    menubar->Insert(1,geommenu,"Geometry");
    menubar->Refresh();

}

void GeometryModule::createParaboloid(wxCommandEvent&)
{
    m_window->
}
/*
wxMDIChildFrame* GeometryModule::getWindow()
{
    return (wxMDIChildFrame*)m_window;
}
*/
