#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wx/wx.h"

class MainWindow : public wxFrame
{
    public:
        MainWindow(const wxString& title);
        virtual ~MainWindow();
    protected:
        void setupMainMenu();
        void setupToolbars();
    private:
        void geom1(wxCommandEvent&);
        void tlbr1(wxCommandEvent&);

};

#endif // MAINWINDOW_H
