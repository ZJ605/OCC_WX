#include "drawwindow.h"

DrawWindow::DrawWindow(wxMDIParentFrame* parent) : wxMDIChildFrame(parent, wxID_ANY, "draw")
{
    this->init();
    this->bindEvents();
}

DrawWindow::~DrawWindow()
{

}

void DrawWindow::init()
{
    static Handle(Aspect_DisplayConnection) dispconnection;
}

void DrawWindow::bindEvents()
{
    //Bind(wxEVT_MOTION, &DrawWindow::onMouseMove, this);
    //Bind(EVT_MOUSE_EVENTS, &DrawWindow::onMouseEvent, this);
}

void DrawWindow::onMouseEvent(const wxMouseEvent&)
{
    std::cout << "mouse" << std::endl;
}

void DrawWindow::onMouseMove(const wxMouseEvent&)
{
    std::cout << "mouse move" << std::endl;
}

void DrawWindow::onMouseClick(const wxMouseEvent&)
{
    std::cout << "mouse click" << std::endl;
}

