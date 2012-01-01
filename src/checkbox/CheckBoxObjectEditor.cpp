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

#include "CheckBoxObjectEditor.h"

//(*InternalHeaders(CheckBoxObjectEditor)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>
#include <wx/filedlg.h>

#include "GDL/Game.h"
#include "CheckBoxObject.h"
#include "GDL/MainEditorCommand.h"
#include "GDL/CommonTools.h"

#include "../WidgetsCommonTools.h"

#include "../colorScheme.h"

//(*IdInit(CheckBoxObjectEditor)
const long CheckBoxObjectEditor::ID_STATICTEXT6 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT7 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT14 = wxNewId();
const long CheckBoxObjectEditor::ID_TEXTCTRL1 = wxNewId();
const long CheckBoxObjectEditor::ID_CHECKBOX1 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT1 = wxNewId();
const long CheckBoxObjectEditor::ID_SPINCTRL2 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT11 = wxNewId();
const long CheckBoxObjectEditor::ID_SPINCTRL4 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT12 = wxNewId();
const long CheckBoxObjectEditor::ID_SPINCTRL5 = wxNewId();
const long CheckBoxObjectEditor::ID_PANEL2 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT9 = wxNewId();
const long CheckBoxObjectEditor::ID_SPINCTRL3 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT2 = wxNewId();
const long CheckBoxObjectEditor::ID_TEXTCTRL2 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON4 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT4 = wxNewId();
const long CheckBoxObjectEditor::ID_SPINCTRL1 = wxNewId();
const long CheckBoxObjectEditor::ID_PANEL4 = wxNewId();
const long CheckBoxObjectEditor::ID_NOTEBOOK1 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICLINE1 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON19 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CheckBoxObjectEditor,wxDialog)
	//(*EventTable(CheckBoxObjectEditor)
	//*)
END_EVENT_TABLE()

CheckBoxObjectEditor::CheckBoxObjectEditor( wxWindow* parent, Game & game_, CheckBoxObject & object_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_)
{
	//(*Initialize(CheckBoxObjectEditor)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Editer la case à cocher"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer8 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Case à cocher"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer8->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Permet à l\'utilisateur de choisir \"oui\" ou \"non\"."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer8->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(546,202), 0, _T("ID_NOTEBOOK1"));
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer10 = new wxFlexGridSizer(6, 2, 0, 0);
	FlexGridSizer10->AddGrowableCol(1);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(Panel2, ID_STATICTEXT14, _("Texte :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer10->Add(StaticText14, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	textEdit = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(308,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer10->Add(textEdit, 0, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 3);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	isCheckedCheckBox = new wxCheckBox(Panel2, ID_CHECKBOX1, _("La case est cochée"), wxDefaultPosition, wxSize(274,20), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	isCheckedCheckBox->SetValue(false);
	FlexGridSizer10->Add(isCheckedCheckBox, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Epaisseur de la bordure:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer10->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	borderWidthSpinCtrl = new wxSpinCtrl(Panel2, ID_SPINCTRL2, _T("1"), wxDefaultPosition, wxSize(200,21), 0, 0, 10000, 1, _T("ID_SPINCTRL2"));
	borderWidthSpinCtrl->SetValue(_T("1"));
	FlexGridSizer10->Add(borderWidthSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(Panel2, ID_STATICTEXT11, _("Taille de la case :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer10->Add(StaticText11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	boxSizeSpinCtrl = new wxSpinCtrl(Panel2, ID_SPINCTRL4, _T("14"), wxDefaultPosition, wxDefaultSize, 0, 0, 1000000, 14, _T("ID_SPINCTRL4"));
	boxSizeSpinCtrl->SetValue(_T("14"));
	FlexGridSizer10->Add(boxSizeSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _("Taille du signe coché :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer10->Add(StaticText12, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	checkSignSizeSpinCtrl = new wxSpinCtrl(Panel2, ID_SPINCTRL5, _T("6"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 6, _T("ID_SPINCTRL5"));
	checkSignSizeSpinCtrl->SetValue(_T("6"));
	FlexGridSizer10->Add(checkSignSizeSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2->SetSizer(FlexGridSizer10);
	FlexGridSizer10->Fit(Panel2);
	FlexGridSizer10->SetSizeHints(Panel2);
	Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	StaticText9 = new wxStaticText(Panel4, ID_STATICTEXT9, _("Marges internes :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer3->Add(StaticText9, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	paddingSpinCtrl = new wxSpinCtrl(Panel4, ID_SPINCTRL3, _T("5"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 5, _T("ID_SPINCTRL3"));
	paddingSpinCtrl->SetValue(_T("5"));
	FlexGridSizer3->Add(paddingSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel4, ID_STATICTEXT2, _("Police :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer4->AddGrowableCol(1);
	fontEdit = new wxTextCtrl(Panel4, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer4->Add(fontEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	fontBt = new wxButton(Panel4, ID_BUTTON4, _("Choisir la police"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer4->Add(fontBt, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	StaticText4 = new wxStaticText(Panel4, ID_STATICTEXT4, _("Taille :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer5->AddGrowableCol(0);
	sizeEdit = new wxSpinCtrl(Panel4, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 1000, 0, _T("ID_SPINCTRL1"));
	sizeEdit->SetValue(_T("0"));
	FlexGridSizer5->Add(sizeEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel4->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(Panel4);
	FlexGridSizer3->SetSizeHints(Panel4);
	Notebook1->AddPage(Panel2, _("Case à cocher et texte"), false);
	Notebook1->AddPage(Panel4, _("Police et marges"), false);
	FlexGridSizer1->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
	Button1 = new wxButton(this, ID_BUTTON19, _("Aide sur ce widget"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON19"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	okBt = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnfontBtClick);
	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnSizeEditChange);
	Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnokBtClick);
	//*)

	textEdit->ChangeValue(object.GetString());
	fontEdit->ChangeValue(object.GetFont());
	sizeEdit->SetValue(object.GetCharacterSize());

    borderWidthSpinCtrl->SetValue(object.GetBorderWidth());
    paddingSpinCtrl->SetValue(object.GetPadding());
    boxSizeSpinCtrl->SetValue(object.GetBoxSize());
    checkSignSizeSpinCtrl->SetValue(object.GetCheckSignSize());

    isCheckedCheckBox->SetValue(object.IsChecked());

    colorsPanel = new ColorSchemePanel(Notebook1, wxID_ANY);
    colorsPanel->AddColorScheme("background", _("Fond"), object.GetBackgroundColorScheme());
    colorsPanel->AddColorScheme("border", _("Bordure"), object.GetBorderColorScheme());
    colorsPanel->AddColorScheme("text", _("Texte"), object.GetTextColorScheme());
    colorsPanel->AddColorScheme("checkColor", _("Case"), object.GetCheckColorScheme());

    Notebook1->AddPage(colorsPanel, "Couleurs");
}

CheckBoxObjectEditor::~CheckBoxObjectEditor()
{
	//(*Destroy(CheckBoxObjectEditor)
	//*)
}


void CheckBoxObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    object.SetString(string(ToString(textEdit->GetValue())));
    object.SetFont(string(ToString(fontEdit->GetValue())));
    object.SetCharacterSize(sizeEdit->GetValue());

    object.SetBackgroundColorScheme(colorsPanel->GetColorScheme("background"));
    object.SetBorderColorScheme(colorsPanel->GetColorScheme("border"));
    object.SetTextColorScheme(colorsPanel->GetColorScheme("text"));
    object.SetCheckColorScheme(colorsPanel->GetColorScheme("checkColor"));

    object.SetBorderWidth(borderWidthSpinCtrl->GetValue());
    object.SetPadding(paddingSpinCtrl->GetValue());
    object.SetBoxSize(boxSizeSpinCtrl->GetValue());
    object.SetCheckSignSize(checkSignSizeSpinCtrl->GetValue());

    object.SetChecked(isCheckedCheckBox->GetValue());

    EndModal(1);
}

void CheckBoxObjectEditor::OnfontBtClick(wxCommandEvent& event)
{
    wxFileDialog dialog(this, _("Choisissez une police de caractère ( fichiers ttf, ttc )"), "", "", "Polices (*.ttf, *.ttc)|*.ttf;*.ttc");
    dialog.ShowModal();

    if ( dialog.GetPath() != "" )
    {
        fontEdit->ChangeValue(dialog.GetPath());
    }
}

void CheckBoxObjectEditor::OnSizeEditChange(wxSpinEvent& event)
{
}


void CheckBoxObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/case_a_cocher");
}

#endif










