#include "GettingStartedDialog.h"

#include "version.h"

#if defined(GD_IDE_ONLY)

//(*InternalHeaders(GettingStartedDialog)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(GettingStartedDialog)
const long GettingStartedDialog::ID_STATICBITMAP1 = wxNewId();
const long GettingStartedDialog::ID_STATICLINE1 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT5 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT6 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT1 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT4 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT3 = wxNewId();
const long GettingStartedDialog::ID_BUTTON3 = wxNewId();
const long GettingStartedDialog::ID_BUTTON2 = wxNewId();
const long GettingStartedDialog::ID_PANEL1 = wxNewId();
const long GettingStartedDialog::ID_BITMAPBUTTON1 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT7 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT8 = wxNewId();
const long GettingStartedDialog::ID_PANEL2 = wxNewId();
const long GettingStartedDialog::ID_NOTEBOOK1 = wxNewId();
const long GettingStartedDialog::ID_STATICTEXT2 = wxNewId();
const long GettingStartedDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GettingStartedDialog,wxDialog)
	//(*EventTable(GettingStartedDialog)
	//*)
END_EVENT_TABLE()

GettingStartedDialog::GettingStartedDialog(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(GettingStartedDialog)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Extension Widgets - Guide de démarrage"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(334,261));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("res/Widgets/WidgetsLogo.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	FlexGridSizer1->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Version : "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	FlexGridSizer4->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	versionText = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer4->Add(versionText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(420,219), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Vous venez d\'installer l\'extension Widgets."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("L\'extension Widgets vous permet de placer différents éléments d\'interface graphique dans votre jeu. De nombreux widgets sont disponibles et extrêmement personnalisables."), wxDefaultPosition, wxSize(402,42), wxST_NO_AUTORESIZE, _T("ID_STATICTEXT4"));
	FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Informations utiles :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	FlexGridSizer3->Add(StaticText3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Sujet sur le forum de Compil Games pour consulter les dernières news"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(Button3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Documentation de l\'extension"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(Button2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(Panel1);
	FlexGridSizer3->SetSizeHints(Panel1);
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer5 = new wxFlexGridSizer(2, 2, 0, 0);
	FlexGridSizer5->AddGrowableCol(1);
	BitmapButton1 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("res/Widgets/SFGUI.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	BitmapButton1->SetDefault();
	FlexGridSizer5->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT7, _("SFGUI est une bibliothèque d\'interface graphique pour SFML.\nMerci à TankOs, binary1248 et les autres contributeurs pour avoir développer SFGUI."), wxDefaultPosition, wxSize(316,41), wxST_NO_AUTORESIZE, _T("ID_STATICTEXT7"));
	FlexGridSizer5->Add(StaticText6, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(Panel2, ID_STATICTEXT8, _("Merci à 4ian pour avoir créer Game Develop et pour son aide.\nMerci aussi à toute la communauté de Game Develop."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer5->Add(StaticText7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2->SetSizer(FlexGridSizer5);
	FlexGridSizer5->Fit(Panel2);
	FlexGridSizer5->SetSizeHints(Panel2);
	Notebook1->AddPage(Panel1, _("Extension Widgets"), false);
	Notebook1->AddPage(Panel2, _("Remerciements"), false);
	FlexGridSizer1->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Cet écran s\'affiche uniquement après l\'installation de l\'extension Widgets\nou d\'une nouvelle version de cette dernière."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_ITALIC,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	Button1 = new wxButton(this, ID_BUTTON1, _("Continuer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont Button1Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GettingStartedDialog::OnButton3Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GettingStartedDialog::OnButton2Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GettingStartedDialog::OnButton1Click);
	//*)

	versionText->SetLabel(WE_VERSION);
}

GettingStartedDialog::~GettingStartedDialog()
{
	//(*Destroy(GettingStartedDialog)
	//*)
}


void GettingStartedDialog::OnButton3Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://forum.compilgames.net/viewtopic.php?f=4&t=2893");
}

void GettingStartedDialog::OnButton2Click(wxCommandEvent& event)
{
   wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets");
}

void GettingStartedDialog::OnButton1Click(wxCommandEvent& event)
{
    EndModal(0);
}

#endif
