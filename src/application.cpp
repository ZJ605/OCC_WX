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
    return m_mainwin->Show();
}

IMPLEMENT_APP(Application);
