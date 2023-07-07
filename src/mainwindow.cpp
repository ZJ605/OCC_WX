#include "mainwindow.h"

#include "icons/t1.xpm"

int MainWindow::wxID_MMAINWINDOW = 1001;


namespace MainWindowIDs {
    int MainToolBarT1 = 101;
}

MainWindow::MainWindow(const wxString& title):wxMDIParentFrame(nullptr, wxID_ANY, title),
    m_width(900), m_height(500)
{
    this->SetSize(300,300,m_width, m_height);

    setupLayout();

    bindEvents();
    //this->m_drawwindow = new DrawWindow(this);
}

MainWindow::~MainWindow()
{
    //dtor
}

void MainWindow::bindEvents()
{

}

void MainWindow::setupLayout()
{
    setupMainMenu();
    setupToolbars();

    int m_clientwidth = this->GetClientSize().GetWidth();
    int m_clientheight = this->GetClientSize().GetHeight();
}

void MainWindow::setupMainMenu(){

    wxMenu* filemenu = new wxMenu();
    auto filemenunew = filemenu->Append(wxID_NEW);
    auto filemenuopen = filemenu->Append(wxID_OPEN);
    auto filemenusave = filemenu->Append(wxID_SAVE);
    auto filemenusaveas = filemenu->Append(wxID_SAVEAS);
    /*
    wxMenu* geommenu = new wxMenu();
    //auto geommenugeom1 = geommenu->Append(wxID_ANY, "geom1");

    this->Bind(wxEVT_MENU, &MainWindow::geom1, this, geommenu->Append(MainWindow::wxID_MMAINWINDOW, "geom1")->GetId());

    menubar->Append(geommenu, "Geometry");
    */
    wxMenuBar* menubar = new wxMenuBar();
    menubar->Append(filemenu, "File");
    this->SetMenuBar(menubar);
}

void MainWindow::setupToolbars(){

    wxInitAllImageHandlers();

    wxToolBar* toolbar = this->CreateToolBar();

    wxBitmap t1icon(t1_xpm);
    toolbar->AddTool(MainWindowIDs::MainToolBarT1,"t1",t1icon);
    toolbar->Bind(wxEVT_TOOL, &MainWindow::onT1,this);
    toolbar->Realize();
}

void MainWindow::geom1(wxCommandEvent&){
    //std::cout <<"gwom1" << std::endl;
}

void MainWindow::tlbr1(wxCommandEvent&){
    //std::cout <<"tlbr1" << std::endl;
}

void MainWindow::onT1(wxCommandEvent&){
    //std::cout <<"t1 pressed" << std::endl;
}



