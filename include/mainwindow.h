#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wx/wx.h"
#include "wx/mdi.h"

#include "drawwindow.h"

#include "BRepPrimAPI_MakeBox.hxx"

class MainWindow : public wxMDIParentFrame
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

        void onT1(wxCommandEvent&);

    private:
        //DrawWindow* m_drawwindow;

        int m_width;
        int m_height;

};

#endif // MAINWINDOW_H
