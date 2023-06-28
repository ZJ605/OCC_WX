#include "mgeom_paraboladialog.h"

//(*InternalHeaders(MGeom_ParabolaDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(MGeom_ParabolaDialog)
const long MGeom_ParabolaDialog::ID_STATICTEXT1 = wxNewId();
const long MGeom_ParabolaDialog::ID_TEXTCTRL1 = wxNewId();
const long MGeom_ParabolaDialog::ID_PANEL2 = wxNewId();
const long MGeom_ParabolaDialog::ID_BUTTON1 = wxNewId();
const long MGeom_ParabolaDialog::ID_BUTTON2 = wxNewId();
const long MGeom_ParabolaDialog::ID_PANEL3 = wxNewId();
const long MGeom_ParabolaDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MGeom_ParabolaDialog,wxFrame)
	//(*EventTable(MGeom_ParabolaDialog)
	//*)
END_EVENT_TABLE()

MGeom_ParabolaDialog::MGeom_ParabolaDialog(wxWindow* parent, MGeom_Paraboloid* owner, Handler handler, const wxPoint& pos,const wxSize& size) : m_paraboloid(owner), m_handler(handler)
{
	//(*Initialize(MGeom_ParabolaDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxMINIMIZE_BOX | wxMAXIMIZE_BOX), _T("id"));

	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(296,320), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	txt_focal = new wxStaticText(Panel2, ID_STATICTEXT1, _("Focal distance"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(txt_focal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ln_focal = new wxTextCtrl(Panel2, ID_TEXTCTRL1, _("15"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(ln_focal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel2);
	BoxSizer2->SetSizeHints(Panel2);
	BoxSizer1->Add(Panel2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3 = new wxPanel(Panel1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	btn_apply = new wxButton(Panel3, ID_BUTTON1, _("Apply"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(btn_apply, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btn_cancel = new wxButton(Panel3, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(btn_cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3->SetSizer(BoxSizer3);
	BoxSizer3->Fit(Panel3);
	BoxSizer3->SetSizeHints(Panel3);
	BoxSizer1->Add(Panel3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);

	//Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MGeom_ParabolaDialog::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MGeom_ParabolaDialog::Onbtn_cancelClick);
	//*)

    //m_handler = &handler;
	bindEvents();
}

MGeom_ParabolaDialog::~MGeom_ParabolaDialog()
{
	//(*Destroy(MGeom_ParabolaDialog)
	//*)
	std::cout << "destr" << std::endl;
}


void MGeom_ParabolaDialog::Onbtn_cancelClick(wxCommandEvent& event)
{
    wxCommandEvent ev(DIALOG_UPDATE_EVENT);
    wxPostEvent(this,ev);
}

void MGeom_ParabolaDialog::bindEvents()
{
    Bind(wxEVT_CLOSE_WINDOW, &MGeom_ParabolaDialog::onClose, this);
    Bind(DIALOG_UPDATE_EVENT, &MGeom_ParabolaDialog::updateDialog, this);
}

void MGeom_ParabolaDialog::updateDialog(const wxCommandEvent& e)
{
    if (m_paraboloid && m_handler)
        (m_paraboloid->*m_handler)(e);
}

void MGeom_ParabolaDialog::onClose(const wxCloseEvent&)
{
    this->Hide();
}
