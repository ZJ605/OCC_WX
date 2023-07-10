#include "application.h"



Application::Application():wxApp(),m_mainwin(nullptr)
{
    m_mainwin = new MainWindow("occ wx");
}

Application::~Application()
{
    //dtor
}

bool Application::OnInit(){

	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	//*)
	//return wxsOK;

    m_geommod = new GeometryModule(this->m_mainwin);
    return m_mainwin->Show();
}

//(*AppHeaders
#include <wx/image.h>
//*)

IMPLEMENT_APP(Application);
