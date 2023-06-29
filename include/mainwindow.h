#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wx/wx.h"
#include "wx/mdi.h"

#include "geometrymodulewindow.h"

#include "BRepPrimAPI_MakeBox.hxx"

class MainWindow : public wxMDIParentFrame
{
    static int wxID_MMAINWINDOW;

    public:
        MainWindow(const wxString& title);
        virtual ~MainWindow();
    protected:
        void bindEvents();

        void setupLayout();
        void setupMainMenu();
        void setupToolbars();
    private:
        void geom1(wxCommandEvent&);
        void tlbr1(wxCommandEvent&);

        void onT1(wxCommandEvent&);

    //events
    private:


    private:
        int m_width;
        int m_height;

        int m_clientwidth;
        int m_clientheight;

};

#endif // MAINWINDOW_H
