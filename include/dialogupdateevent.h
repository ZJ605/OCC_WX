#ifndef DIALOGUPDATEEVENT_H
#define DIALOGUPDATEEVENT_H

#include "wx/wx.h"

class DialogUpdateEvent : public wxCommandEvent
{
    public:
        DialogUpdateEvent(wxEventType typ, int id);
        virtual wxEvent* Clone() const override;

    private:
};

#endif // DIALOGUPDATEEVENT_H
