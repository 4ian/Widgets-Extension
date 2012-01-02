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

#include "TextAreaObjectEditor.h"

//(*InternalHeaders(TextAreaObjectEditor)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/utils.h>

#include "GDL/Game.h"
#include "TextAreaObject.h"
#include "GDL/MainEditorCommand.h"
#include "GDL/CommonTools.h"

#include "../WidgetsCommonTools.h"

#include "../colorScheme.h"

#include "../colorSchemePanel.h"

//(*IdInit(TextAreaObjectEditor)
const long TextAreaObjectEditor::ID_STATICTEXT6 = wxNewId();
const long TextAreaObjectEditor::ID_STATICTEXT7 = wxNewId();
const long TextAreaObjectEditor::ID_TEXTCTRL1 = wxNewId();
const long TextAreaObjectEditor::ID_CHECKBOX1 = wxNewId();
const long TextAreaObjectEditor::ID_TEXTCTRL3 = wxNewId();
const long TextAreaObjectEditor::ID_CHECKBOX2 = wxNewId();
const long TextAreaObjectEditor::ID_SPINCTRL4 = wxNewId();
const long TextAreaObjectEditor::ID_STATICTEXT2 = wxNewId();
const long TextAreaObjectEditor::ID_TEXTCTRL2 = wxNewId();
const long TextAreaObjectEditor::ID_BUTTON4 = wxNewId();
const long TextAreaObjectEditor::ID_STATICTEXT4 = wxNewId();
const long TextAreaObjectEditor::ID_SPINCTRL1 = wxNewId();
const long TextAreaObjectEditor::ID_PANEL1 = wxNewId();
const long TextAreaObjectEditor::ID_STATICTEXT1 = wxNewId();
const long TextAreaObjectEditor::ID_SPINCTRL2 = wxNewId();
const long TextAreaObjectEditor::ID_STATICTEXT9 = wxNewId();
const long TextAreaObjectEditor::ID_SPINCTRL3 = wxNewId();
const long TextAreaObjectEditor::ID_PANEL3 = wxNewId();
const long TextAreaObjectEditor::ID_NOTEBOOK1 = wxNewId();
const long TextAreaObjectEditor::ID_STATICLINE1 = wxNewId();
const long TextAreaObjectEditor::ID_BUTTON3 = wxNewId();
const long TextAreaObjectEditor::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TextAreaObjectEditor,wxDialog)
	//(*EventTable(TextAreaObjectEditor)
	//*)
END_EVENT_TABLE()

TextAreaObjectEditor::TextAreaObjectEditor( wxWindow* parent, Game & game_, TextAreaObject & object_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_)
{
	//(*Initialize(TextAreaObjectEditor)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer1;
	
	Create(parent, wxID_ANY, _("Editer la zone de texte"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(475,295));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer8 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Zone de texte d\'une seule ligne."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer8->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Permet de saisir du texte sur une seule ligne."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer8->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(519,200), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer9 = new wxFlexGridSizer(2, 1, 0, 0);
	textEdit = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(332,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer9->Add(textEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10 = new wxFlexGridSizer(4, 2, 0, 0);
	isHiddenCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Masquer les caractères par"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	isHiddenCheckBox->SetValue(false);
	FlexGridSizer10->Add(isHiddenCheckBox, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	hideCharacterTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("*"), wxDefaultPosition, wxSize(50,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	hideCharacterTextCtrl->SetMaxLength(1);
	FlexGridSizer10->Add(hideCharacterTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	limitCharCheckBox = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Limiter la taille à"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	limitCharCheckBox->SetValue(false);
	FlexGridSizer10->Add(limitCharCheckBox, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	limitCharSpinCtrl = new wxSpinCtrl(Panel1, ID_SPINCTRL4, _T("10"), wxDefaultPosition, wxSize(50,21), 0, 1, 100000, 10, _T("ID_SPINCTRL4"));
	limitCharSpinCtrl->SetValue(_T("10"));
	FlexGridSizer10->Add(limitCharSpinCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
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
	FlexGridSizer9->Add(FlexGridSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
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
	FlexGridSizer1->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	Button1 = new wxButton(this, ID_BUTTON3, _("Aide sur ce widget"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	okBt = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->SetSizeHints(this);
	
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&TextAreaObjectEditor::OnisHiddenCheckBoxClick);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&TextAreaObjectEditor::OnlimitCharCheckBoxClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextAreaObjectEditor::OnfontBtClick);
	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&TextAreaObjectEditor::OnSizeEditChange);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextAreaObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TextAreaObjectEditor::OnokBtClick);
	//*)

	textEdit->ChangeValue(object.GetString());
	fontEdit->ChangeValue(object.GetFont());
	sizeEdit->SetValue(object.GetCharacterSize());

    borderWidthSpinCtrl->SetValue(object.GetBorderWidth());
    paddingSpinCtrl->SetValue(object.GetPadding());

    if(object.GetHideCharacter() != 0)
    {
        isHiddenCheckBox->SetValue(true);
        sf::String hideChar(object.GetHideCharacter());
        hideCharacterTextCtrl->SetValue(hideChar.ToAnsiString());
        hideCharacterTextCtrl->Enable(true);
    }
    else
    {
        isHiddenCheckBox->SetValue(false);
        hideCharacterTextCtrl->Enable(false);
    }

    if(object.GetMaximumLength() != 0)
    {
        limitCharCheckBox->SetValue(true);
        limitCharSpinCtrl->Enable(true);
        limitCharSpinCtrl->SetValue(object.GetMaximumLength());
    }
    else
    {
        limitCharCheckBox->SetValue(false);
        limitCharSpinCtrl->Enable(false);
    }

    colorsPanel = new ColorSchemePanel(Notebook1, wxID_ANY);
    colorsPanel->AddColorScheme("background", _("Fond"), object.GetBackgroundColorScheme());
    colorsPanel->AddColorScheme("border", _("Bordure"), object.GetBorderColorScheme());
    colorsPanel->AddColorScheme("text", _("Texte"), object.GetTextColorScheme());

    Notebook1->AddPage(colorsPanel, "Couleurs");
}

TextAreaObjectEditor::~TextAreaObjectEditor()
{
	//(*Destroy(TextAreaObjectEditor)
	//*)
}


void TextAreaObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    object.SetString(string(ToString(textEdit->GetValue())));
    object.SetFont(string(ToString(fontEdit->GetValue())));
    object.SetCharacterSize(sizeEdit->GetValue());

    object.SetBackgroundColorScheme(colorsPanel->GetColorScheme("background"));
    object.SetBorderColorScheme(colorsPanel->GetColorScheme("border"));
    object.SetTextColorScheme(colorsPanel->GetColorScheme("text"));

    object.SetBorderWidth(borderWidthSpinCtrl->GetValue());
    object.SetPadding(paddingSpinCtrl->GetValue());

    if(isHiddenCheckBox->GetValue() == true)
    {
        sf::String tmpStr(hideCharacterTextCtrl->GetValue().ToStdWstring());
        object.SetHideCharacter(tmpStr.GetSize() > 0 ? tmpStr[0] : 0);
    }
    else
    {
        object.SetHideCharacter(0);
    }

    if(limitCharCheckBox->GetValue() == true)
    {
        object.SetMaximumLength(limitCharSpinCtrl->GetValue());
    }
    else
    {
        object.SetMaximumLength(0);
    }

    EndModal(1);
}

void TextAreaObjectEditor::OnfontBtClick(wxCommandEvent& event)
{
    wxFileDialog dialog(this, _("Choisissez une police de caractère ( fichiers ttf, ttc )"), "", "", "Polices (*.ttf, *.ttc)|*.ttf;*.ttc");
    dialog.ShowModal();

    if ( dialog.GetPath() != "" )
    {
        fontEdit->ChangeValue(dialog.GetPath());
    }
}

void TextAreaObjectEditor::OnSizeEditChange(wxSpinEvent& event)
{
}


void TextAreaObjectEditor::OnisHiddenCheckBoxClick(wxCommandEvent& event)
{
    if(isHiddenCheckBox->GetValue() == true)
        hideCharacterTextCtrl->Enable(true);
    else
        hideCharacterTextCtrl->Enable(false);
}

void TextAreaObjectEditor::OnlimitCharCheckBoxClick(wxCommandEvent& event)
{
    if(limitCharCheckBox->GetValue() == true)
        limitCharSpinCtrl->Enable(true);
    else
        limitCharSpinCtrl->Enable(false);
}

void TextAreaObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/zone_de_texte_monoligne");
}

#endif
