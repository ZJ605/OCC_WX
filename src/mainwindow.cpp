#include "mainwindow.h"

MainWindow::MainWindow(const wxString& title):wxFrame(nullptr, wxID_ANY, title)
{
    //this->SetMinSize(wxSize(600,500));
    //this->SetMaxSize(800,600);

    setupMainMenu();
    setupToolbars();
}

MainWindow::~MainWindow()
{
    //dtor
}

void MainWindow::setupMainMenu(){

    wxMenu* filemenu = new wxMenu();
    auto filemenunew = filemenu->Append(wxID_NEW);
    auto filemenuopen = filemenu->Append(wxID_OPEN);
    auto filemenusave = filemenu->Append(wxID_SAVE);
    auto filemenusaveas = filemenu->Append(wxID_SAVEAS);

    wxMenu* geommenu = new wxMenu();
    //auto geommenugeom1 = geommenu->Append(wxID_ANY, "geom1");

    this->Bind(wxEVT_MENU, &MainWindow::geom1, this, geommenu->Append(wxID_ANY, "geom1")->GetId());

    wxMenuBar* menubar = new wxMenuBar();
    menubar->Append(filemenu, "File");
    menubar->Append(geommenu, "Geometry");

    this->SetMenuBar(menubar);

}

void MainWindow::setupToolbars(){
    //wxToolBar* toolbar = new wxToolBar(this, wxID_ANY);
    //toolbar->AddTool();
}

void MainWindow::geom1(wxCommandEvent&){
    std::cout <<"gwom1" << std::endl;
}

void MainWindow::tlbr1(wxCommandEvent&){
    std::cout <<"tlbr1" << std::endl;
}
