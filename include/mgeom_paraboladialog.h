#ifndef MGEOM_PARABOLADIALOG_H
#define MGEOM_PARABOLADIALOG_H

//(*Headers(MGeom_ParabolaDialog)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "mevent.h"
#include "mgeom_paraboloid.h"

class MGeom_Paraboloid;

class MGeom_ParabolaDialog: public wxFrame
{
    public:
        typedef void (MGeom_Paraboloid::*Handler)(const wxCommandEvent&);

	public:

		MGeom_ParabolaDialog(wxWindow* parent, MGeom_Paraboloid* owner, Handler handler, const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MGeom_ParabolaDialog();

		//(*Declarations(MGeom_ParabolaDialog)
		wxButton* btn_apply;
		wxButton* btn_cancel;
		wxPanel* Panel1;
		wxPanel* Panel2;
		wxPanel* Panel3;
		wxStaticText* txt_focal;
		wxTextCtrl* ln_focal;
		//*)

	protected:

		//(*Identifiers(MGeom_ParabolaDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(MGeom_ParabolaDialog)
		void Onbtn_cancelClick(wxCommandEvent& event);
		//*)

		void onClose(const wxCloseEvent&);
        void bindEvents();
        void updateDialog(const wxCommandEvent&);

        //void Close() override;

		DECLARE_EVENT_TABLE()

		//event handler from mgeom_paraboloid

		MGeom_Paraboloid* m_paraboloid;
		Handler m_handler;
};

#endif
