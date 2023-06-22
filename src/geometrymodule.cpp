#include "geometrymodule.h"

GeometryModule::GeometryModule()
{

}

GeometryModule::~GeometryModule()
{
    //dtor
}

void GeometryModule::createWindow(wxMDIParentFrame* parent)
{
    m_window = new GeometryModuleWindow(parent);
}
/*
wxMDIChildFrame* GeometryModule::getWindow()
{
    return (wxMDIChildFrame*)m_window;
}
*/
