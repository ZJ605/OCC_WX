#include "geometrymodulewindow.h"

#include "wxinteractions2occ.h"

#include "BRepPrimAPI_MakeBox.hxx"
#include "AIS_Shape.hxx"
#include "mgeom_lens.h"
#include "mgeom_paraboloid.h"

#include <iostream>


GeometryModuleWindow::GeometryModuleWindow(wxMDIParentFrame* parent, std::list<Handle(MGeom)>& geoms) : wxMDIChildFrame(parent, wxID_ANY, "draw", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxMINIMIZE_BOX | wxCLOSE_BOX)), m_geometryobjects(geoms)
    , nic(true)
{
    this->Maximize();

    initLayout();

    bindEvents();

    m_geometryWindow->setGeometryModuleWindow(this);
}

GeometryModuleWindow::~GeometryModuleWindow()
{
}

void GeometryModuleWindow::initLayout()
{
    m_mainsplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE | wxSP_3D);

    m_geometryWindow = new GeometryWindow(m_mainsplitter, this, m_geometryobjects);
    m_geometryWindow->SetBackgroundColour(VisualSettings::WindowBackgroundColor);
    m_geometryWindow->SetSize(wxSize(200,1000));
    m_treeWindow = new GeometryTreeWindow(m_mainsplitter);
    m_treeWindow->SetBackgroundColour(VisualSettings::WindowBackgroundColor);
    m_treeWindow->SetSize(wxSize(200,1000));

    //m_mainsplitter->SetMinimumPaneSize(200);
    m_mainsplitter->SplitVertically(m_treeWindow, m_geometryWindow);
    m_mainsplitter->SetSashGravity(0.3);

}

void GeometryModuleWindow::bindEvents()
{
    Bind(wxEVT_MAXIMIZE, &GeometryModuleWindow::onMaximize, this);

}

void GeometryModuleWindow::onMaximize(const wxMaximizeEvent& ev)
{

}

void GeometryModuleWindow::onSelectGeometry(Handle(MGeom) geom)
{
    geom->showDialog();

}

void GeometryModuleWindow::onUpdateGeometry()
{

}

void GeometryModuleWindow::createParaboloid()
{
    m_geometryWindow->createParaboloid();
}
