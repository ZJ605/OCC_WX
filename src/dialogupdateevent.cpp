#include "dialogupdateevent.h"

//wxDEFINE_EVENT(DIALOG_UPDATE_EVENT, wxCommandEvent);

DialogUpdateEvent::DialogUpdateEvent(wxEventType typ, int id):wxCommandEvent(typ, id)
{
    //ctor
}

wxEvent* DialogUpdateEvent::Clone() const
{
    return new DialogUpdateEvent(*this);
}
