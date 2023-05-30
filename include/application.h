#ifndef APPLICATION_H
#define APPLICATION_H

#include "wx/wx.h"

#include "mainwindow.h"

class Application : public wxApp
{
    public:
        Application();
        virtual ~Application();

        virtual bool OnInit() override;

    private:
    MainWindow* m_mainwin;
};

#endif // APPLICATION_H
