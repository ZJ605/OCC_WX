#ifndef MEVENT_H
#define MEVENT_H

#include "wx/wx.h"

wxDECLARE_EVENT(DIALOG_UPDATE_EVENT, wxCommandEvent);

class MEvent
{
    public:
        MEvent();
        virtual ~MEvent();

    private:
};

#endif // MEVENT_H
