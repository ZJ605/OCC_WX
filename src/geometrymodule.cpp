#include "geometrymodule.h"

#include "mainwindow.h"

#include <iostream>

GeometryModule::GeometryModule(wxMDIParentFrame* parent)
{
    m_window = new GeometryModuleWindow(parent, m_geom);
    createToolbars(parent);
}

GeometryModule::~GeometryModule()
{
    //dtor
}
/*
void GeometryModule::createWindow(wxMDIParentFrame* parent)
{

}
*/
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
    m_window->createParaboloid();
}
/*
wxMDIChildFrame* GeometryModule::getWindow()
{
    return (wxMDIChildFrame*)m_window;
}
*/
