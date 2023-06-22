#ifndef GEOMETRYMODULE_H
#define GEOMETRYMODULE_H

#include "wx/mdi.h"

#include "geometrymodulewindow.h"

class GeometryModule
{
    public:
        GeometryModule();
        virtual ~GeometryModule();

        void createWindow(wxMDIParentFrame* parent);
        //wxMDIChildFrame* getWindow();

    protected:

    private:

        GeometryModuleWindow* m_window;
};

#endif // GEOMETRYMODULE_H
