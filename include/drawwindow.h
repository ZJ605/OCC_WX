#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include "Aspect_Window.hxx"
#include "AIS_InteractiveContext.hxx"
#include "V3d_Viewer.hxx"
#include "V3d_View.hxx"

#include "wx/mdi.h"

#include "windoweventmanager.h"

class DrawWindow : public wxMDIChildFrame
{
    public:
        DrawWindow(wxMDIParentFrame * parent);
        virtual ~DrawWindow();
    protected:

    private:
        void init();
        void bindEvents();

    //events
    private:
        void onMouseEvent(const wxMouseEvent&);
        void onMouseMove(const wxMouseEvent&);
        void onMouseClick(const wxMouseEvent&);

    private:
        Handle(V3d_Viewer) m_viewer;
        Handle(V3d_View) m_view;
        Handle(AIS_InteractiveContext) m_context;
        Handle(WindowEventManager) m_eventManager;

};

#endif // DRAWWINDOW_H
