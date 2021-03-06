/*
Widgets Extension
Extension providing graphical widgets.

Copyright (c) 2011-2012 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
    1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/

#if defined(GD_IDE_ONLY)

#include "ButtonObjectEditor.h"

//(*InternalHeaders(ButtonObjectEditor)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

#include "GDL/Game.h"
#include "ButtonObject.h"
#include "GDL/MainEditorCommand.h"
#include "GDL/CommonTools.h"
#include "GDL/ResourcesEditor.h"

#include <boost/shared_ptr.hpp>

#include "../WidgetsCommonTools.h"

#include "../colorScheme.h"

//(*IdInit(ButtonObjectEditor)
const long ButtonObjectEditor::ID_STATICTEXT6 = wxNewId();
const long ButtonObjectEditor::ID_STATICTEXT7 = wxNewId();
const long ButtonObjectEditor::ID_STATICTEXT10 = wxNewId();
const long ButtonObjectEditor::ID_TEXTCTRL1 = wxNewId();
const long ButtonObjectEditor::ID_STATICTEXT11 = wxNewId();
const long ButtonObjectEditor::ID_TEXTCTRL3 = wxNewId();
const long ButtonObjectEditor::ID_BUTTON16 = wxNewId();
const long ButtonObjectEditor::ID_STATICTEXT2 = wxNewId();
const long ButtonObjectEditor::ID_TEXTCTRL2 = wxNewId();
const long ButtonObjectEditor::ID_BUTTON4 = wxNewId();
const long ButtonObjectEditor::ID_STATICTEXT4 = wxNewId();
const long ButtonObjectEditor::ID_SPINCTRL1 = wxNewId();
const long ButtonObjectEditor::ID_PANEL1 = wxNewId();
const long ButtonObjectEditor::ID_STATICTEXT1 = wxNewId();
const long ButtonObjectEditor::ID_SPINCTRL2 = wxNewId();
const long ButtonObjectEditor::ID_STATICTEXT9 = wxNewId();
const long ButtonObjectEditor::ID_SPINCTRL3 = wxNewId();
const long ButtonObjectEditor::ID_PANEL3 = wxNewId();
const long ButtonObjectEditor::ID_NOTEBOOK1 = wxNewId();
const long ButtonObjectEditor::ID_BUTTON3 = wxNewId();
const long ButtonObjectEditor::ID_BUTTON1 = wxNewId();
const long ButtonObjectEditor::ID_PANEL5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ButtonObjectEditor,wxDialog)
	//(*EventTable(ButtonObjectEditor)
	//*)
END_EVENT_TABLE()

ButtonObjectEditor::ButtonObjectEditor( wxWindow* parent, Game & game_, ButtonObject & object_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_)
{
	//(*Initialize(ButtonObjectEditor)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer13;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer11;

	Create(parent, wxID_ANY, _("Editer le bouton"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(482,301));
	FlexGridSizer1 = new wxFlexGridSizer(1, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	Core = new wxPanel(this, ID_PANEL5, wxDefaultPosition, wxSize(475,301), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	FlexGridSizer11 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer11->AddGrowableCol(0);
	FlexGridSizer11->AddGrowableRow(1);
	FlexGridSizer8 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText6 = new wxStaticText(Core, ID_STATICTEXT6, _("Bouton"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer8->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(Core, ID_STATICTEXT7, _("Permet de capter le clic de l\'utilisateur sur ce dernier."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer8->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer11->Add(FlexGridSizer8, 1, wxTOP|wxLEFT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	Notebook1 = new wxNotebook(Core, ID_NOTEBOOK1, wxDefaultPosition, wxSize(577,237), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer9 = new wxFlexGridSizer(5, 1, 0, 0);
	FlexGridSizer9->AddGrowableCol(0);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Texte :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer9->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	textEdit = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(332,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer9->Add(textEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Image : (prochainement disponible)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	StaticText11->Disable();
	FlexGridSizer9->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer13 = new wxFlexGridSizer(1, 2, 0, 0);
	FlexGridSizer13->AddGrowableCol(0);
	imageNameTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	imageNameTextCtrl->Disable();
	FlexGridSizer13->Add(imageNameTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxBitmapButton(Panel1, ID_BUTTON16, wxBitmap(wxImage(_T("res/addfromimagebanque.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BUTTON16"));
	Button2->Disable();
	FlexGridSizer13->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(FlexGridSizer13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer10 = new wxFlexGridSizer(2, 2, 0, 0);
	FlexGridSizer10->AddGrowableCol(1);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Police :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer10->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer4->AddGrowableCol(1);
	fontEdit = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer4->Add(fontEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	fontBt = new wxButton(Panel1, ID_BUTTON4, _("Choisir la police"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer4->Add(fontBt, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Taille :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer10->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer5->AddGrowableCol(0);
	sizeEdit = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 1000, 0, _T("ID_SPINCTRL1"));
	sizeEdit->SetValue(_T("0"));
	FlexGridSizer5->Add(sizeEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer9->Add(FlexGridSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(FlexGridSizer9);
	FlexGridSizer9->Fit(Panel1);
	FlexGridSizer9->SetSizeHints(Panel1);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT1, _("Epaisseur de la bordure:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	borderWidthSpinCtrl = new wxSpinCtrl(Panel3, ID_SPINCTRL2, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 1, _T("ID_SPINCTRL2"));
	borderWidthSpinCtrl->SetValue(_T("1"));
	FlexGridSizer3->Add(borderWidthSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("Marges internes :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer3->Add(StaticText9, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	paddingSpinCtrl = new wxSpinCtrl(Panel3, ID_SPINCTRL3, _T("5"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 5, _T("ID_SPINCTRL3"));
	paddingSpinCtrl->SetValue(_T("5"));
	FlexGridSizer3->Add(paddingSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(Panel3);
	FlexGridSizer3->SetSizeHints(Panel3);
	Notebook1->AddPage(Panel1, _("Texte"), false);
	Notebook1->AddPage(Panel3, _("Tailles"), false);
	FlexGridSizer11->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
	Button1 = new wxButton(Core, ID_BUTTON3, _("Aide sur ce widget"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	okBt = new wxButton(Core, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer11->Add(FlexGridSizer2, 1, wxBOTTOM|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	Core->SetSizer(FlexGridSizer11);
	FlexGridSizer11->SetSizeHints(Core);
	FlexGridSizer1->Add(Core, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ButtonObjectEditor::OnfontBtClick);
	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&ButtonObjectEditor::OnSizeEditChange);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ButtonObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ButtonObjectEditor::OnokBtClick);
	//*)

	Connect(ID_NOTEBOOK1,wxEVT_COMMAND_BOOKCTRL_PAGE_CHANGED,(wxObjectEventFunction)&ButtonObjectEditor::OnNotebook1PageChanged);
	Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ButtonObjectEditor::OnButton2Click);

	fontEdit->ChangeValue(object.GetFont());
	sizeEdit->SetValue(object.GetCharacterSize());

    borderWidthSpinCtrl->SetValue(object.GetBorderWidth());
    paddingSpinCtrl->SetValue(object.GetPadding());

    imageNameTextCtrl->SetValue(object.GetPictureName());

    textEdit->ChangeValue(object.GetString());

    //Init the image bank editor
    editorImagesPnl = new ResourcesEditor( this, game, mainEditorCommand );
    editorImagesPnl->Refresh();

	//Init wxAuiManager with two pane : the editor and the image bank editor
    m_mgr.SetManagedWindow( this );
    m_mgr.AddPane( Core, wxAuiPaneInfo().Name( wxT( "Core" ) ).Center().CaptionVisible(false) );
    m_mgr.AddPane( editorImagesPnl, wxAuiPaneInfo().Name( wxT( "EI" ) ).Right().Caption( _T( "Editeur de la banque d'images" ) ).MaximizeButton( true ).MinimizeButton( false ).Show(false).MinSize(150, 100) );
    m_mgr.SetFlags( wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_TRANSPARENT_HINT
                    | wxAUI_MGR_TRANSPARENT_DRAG | wxAUI_MGR_HINT_FADE | wxAUI_MGR_NO_VENETIAN_BLINDS_FADE );
    m_mgr.Update();

    colorsPanel = new ColorSchemePanel(Notebook1, wxID_ANY);
    colorsPanel->AddColorScheme("background", _("Fond"), object.GetBackgroundColorScheme());
    colorsPanel->AddColorScheme("border", _("Bordure"), object.GetBorderColorScheme());
    colorsPanel->AddColorScheme("text", _("Texte"), object.GetTextColorScheme());

    Notebook1->AddPage(colorsPanel, "Couleurs");
}

ButtonObjectEditor::~ButtonObjectEditor()
{
    m_mgr.UnInit();
	//(*Destroy(ButtonObjectEditor)
	//*)
}


void ButtonObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    object.SetFont(string(ToString(fontEdit->GetValue().mb_str())));
    object.SetCharacterSize(sizeEdit->GetValue());

    object.SetBackgroundColorScheme(colorsPanel->GetColorScheme("background"));
    object.SetBorderColorScheme(colorsPanel->GetColorScheme("border"));
    object.SetTextColorScheme(colorsPanel->GetColorScheme("text"));

    object.SetBorderWidth(borderWidthSpinCtrl->GetValue());
    object.SetPadding(paddingSpinCtrl->GetValue());

    object.SetPictureName(ToString(imageNameTextCtrl->GetValue()));
    object.SetString(string(ToString(textEdit->GetValue())));

    EndModal(1);
}

void ButtonObjectEditor::OnfontBtClick(wxCommandEvent& event)
{
    wxFileDialog dialog(this, _("Choisissez une police de caract�re ( fichiers ttf, ttc )"), "", "", "Polices (*.ttf, *.ttc)|*.ttf;*.ttc");
    dialog.ShowModal();

    if ( dialog.GetPath() != "" )
    {
        fontEdit->ChangeValue(dialog.GetPath());
    }
}

void ButtonObjectEditor::OnSizeEditChange(wxSpinEvent& event)
{
}


void ButtonObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/bouton");
}

void ButtonObjectEditor::OnNotebook1PageChanged(wxNotebookEvent& event)
{
    /*if(Notebook1->GetSelection() == 0)
    {
        m_mgr.GetPane(editorImagesPnl).Show(true);
    }
    else
    {
        m_mgr.GetPane(editorImagesPnl).Show(false);
    }
    m_mgr.Update();*/
}

void ButtonObjectEditor::OnButton2Click(wxCommandEvent& event)
{
    if(!editorImagesPnl->m_itemSelected.IsOk())
        return;

    boost::shared_ptr<Resource> tempResource(editorImagesPnl->resourceSelected);
    imageNameTextCtrl->SetValue(tempResource->name);
}

#endif



