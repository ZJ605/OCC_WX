#include "geometrymodulewindow.h"

#include "wxinteractions2occ.h"

#include "BRepPrimAPI_MakeBox.hxx"
#include "AIS_Shape.hxx"
#include "mgeom_lens.h"
#include "mgeom_paraboloid.h"

#include <iostream>


GeometryModuleWindow::GeometryModuleWindow(wxMDIParentFrame* parent, std::list<Handle(MGeom)>& geoms) : wxMDIChildFrame(parent, wxID_ANY, "draw"), m_geometryobjects(geoms)
{
    wxSize siz = this->GetParent()->GetSize();
    siz.SetWidth(siz.GetWidth()*0.8);
    siz.SetHeight(siz.GetHeight()*0.8);
    //this->SetSize(siz);
    //std::cout << "width "<< (int)(siz.GetWidth()) << " height "<< (int)(siz.GetHeight()) << std::endl;
    //this->SetSize(50,50,(int)(siz.GetWidth()*0.8),(int)(siz.GetHeight()*0.8));
    this->Maximize();

    initLayout();

    //initTree();

    bindEvents();

    //Handle(MGeom_Lens) l = new MGeom_Lens();
    //m_geometryobjects.push_back(l);


        //m_geometryobjects.push_back(par);

}

GeometryModuleWindow::~GeometryModuleWindow()
{
    //dtor
}

void GeometryModuleWindow::initLayout()
{
    m_mainsplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE | wxSP_3D);

    m_geometryWindow = new GeometryWindow(m_mainsplitter, m_geometryobjects);
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
    //std::cout << "max" << std::endl;

}
