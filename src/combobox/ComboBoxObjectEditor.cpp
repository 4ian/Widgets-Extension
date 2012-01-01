/*
Widgets Extension
Extension providing graphical widgets.

Copyright (c) 2011 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
    1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/

#if defined(GD_IDE_ONLY)

#include "ComboBoxObjectEditor.h"

//(*InternalHeaders(ComboBoxObjectEditor)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/utils.h>

#include <string>

#include "GDL/Game.h"
#include "ComboBoxObject.h"
#include "GDL/MainEditorCommand.h"
#include "GDL/CommonTools.h"

#include "../WidgetsCommonTools.h"

#include "../colorScheme.h"

#include "../colorSchemePanel.h"

//(*IdInit(ComboBoxObjectEditor)
const long ComboBoxObjectEditor::ID_STATICTEXT6 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT7 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT10 = wxNewId();
const long ComboBoxObjectEditor::ID_TEXTCTRL1 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT13 = wxNewId();
const long ComboBoxObjectEditor::ID_SPINCTRL4 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT14 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT2 = wxNewId();
const long ComboBoxObjectEditor::ID_TEXTCTRL2 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON4 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT4 = wxNewId();
const long ComboBoxObjectEditor::ID_SPINCTRL1 = wxNewId();
const long ComboBoxObjectEditor::ID_PANEL1 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT1 = wxNewId();
const long ComboBoxObjectEditor::ID_SPINCTRL2 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT9 = wxNewId();
const long ComboBoxObjectEditor::ID_SPINCTRL3 = wxNewId();
const long ComboBoxObjectEditor::ID_PANEL3 = wxNewId();
const long ComboBoxObjectEditor::ID_NOTEBOOK1 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICLINE1 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON3 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ComboBoxObjectEditor,wxDialog)
	//(*EventTable(ComboBoxObjectEditor)
	//*)
END_EVENT_TABLE()

ComboBoxObjectEditor::ComboBoxObjectEditor( wxWindow* parent, Game & game_, ComboBoxObject & object_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_)
{
	//(*Initialize(ComboBoxObjectEditor)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer11;
	
	Create(parent, wxID_ANY, _("Editer la liste déroulante"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer8 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Liste déroulante"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer8->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Permet à l\'utilisateur de choisir un élement parmi d\'autres."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer8->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(564,232), 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer9 = new wxFlexGridSizer(4, 1, 0, 0);
	FlexGridSizer9->AddGrowableCol(0);
	FlexGridSizer9->AddGrowableRow(1);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Liste des éléments séparés par des sauts de ligne :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer9->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	textEdit = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("1er élément\n2ème élément\n3ème élément\n..."), wxDefaultPosition, wxSize(332,78), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer9->Add(textEdit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer11 = new wxFlexGridSizer(1, 3, 0, 0);
	FlexGridSizer11->AddGrowableCol(1);
	StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT13, _("Elément sélectionné :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer11->Add(StaticText13, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	selectedItemSpinCtrl = new wxSpinCtrl(Panel1, ID_SPINCTRL4, _T("-1"), wxDefaultPosition, wxDefaultSize, 0, -1, 100000, -1, _T("ID_SPINCTRL4"));
	selectedItemSpinCtrl->SetValue(_T("-1"));
	FlexGridSizer11->Add(selectedItemSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(Panel1, ID_STATICTEXT14, _("-1 pour ne pas sélectionner d\'éléments"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer11->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(FlexGridSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer10 = new wxFlexGridSizer(4, 2, 0, 0);
	FlexGridSizer10->AddGrowableCol(1);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Police :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer10->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
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
	Notebook1->AddPage(Panel1, _("Contenu"), false);
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
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnfontBtClick);
	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnSizeEditChange);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnokBtClick);
	//*)


	fontEdit->ChangeValue(object.GetFont());
	sizeEdit->SetValue(object.GetCharacterSize());

    borderWidthSpinCtrl->SetValue(object.GetBorderWidth());
    paddingSpinCtrl->SetValue(object.GetPadding());

    //Liste des éléments
    ElementList listOfElement = object.GetAllElements();
    textEdit->Clear();

    for(unsigned int a = 0; a < listOfElement.size(); a++)
    {
        if(a > 0)
            textEdit->AppendText("\n");

        wxString str(listOfElement.at(a));
        textEdit->AppendText(str);
    }

    selectedItemSpinCtrl->SetValue(object.GetSelectedElement());

    colorsPanel = new ColorSchemePanel(Notebook1, wxID_ANY);
    colorsPanel->AddColorScheme("background", _("Fond"), object.GetBackgroundColorScheme());
    colorsPanel->AddColorScheme("border", _("Bordure"), object.GetBorderColorScheme());
    colorsPanel->AddColorScheme("text", _("Texte"), object.GetTextColorScheme());
    colorsPanel->AddColorScheme("arrow", _("Flèche"), object.GetArrowColorScheme());
    colorsPanel->AddColorScheme("highlight", _("Sélection"), object.GetHighlightColorScheme(), CSP_HasAlwaysColorBt);

    Notebook1->AddPage(colorsPanel, "Couleurs");
}

ComboBoxObjectEditor::~ComboBoxObjectEditor()
{
	//(*Destroy(ComboBoxObjectEditor)
	//*)
}


void ComboBoxObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    object.SetFont(std::string(ToString(fontEdit->GetValue())));
    object.SetCharacterSize(sizeEdit->GetValue());

    /*ColorScheme backgroundColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedBackgroundBt->GetBackgroundColour()),
                                      WidgetsCommonTools::GetSfColorFromWxColour(normalBackgroundBt->GetBackgroundColour()),
                                      WidgetsCommonTools::GetSfColorFromWxColour(hoveredBackgroundBt->GetBackgroundColour()),
                                      WidgetsCommonTools::GetSfColorFromWxColour(disabledBackgroundBt->GetBackgroundColour()));*/
    object.SetBackgroundColorScheme(colorsPanel->GetColorScheme("background"));
    object.SetBorderColorScheme(colorsPanel->GetColorScheme("border"));
    object.SetTextColorScheme(colorsPanel->GetColorScheme("text"));
    object.SetArrowColorScheme(colorsPanel->GetColorScheme("arrow"));
    object.SetHighlightColorScheme(colorsPanel->GetColorScheme("highlight"));

    object.SetBorderWidth(borderWidthSpinCtrl->GetValue());
    object.SetPadding(paddingSpinCtrl->GetValue());

    //Liste des éléments
    std::vector<std::string> listOfElement(SplitString<std::string>(std::string(textEdit->GetValue()), '\n'));
    object.ClearAndSetElements(listOfElement);

    object.SelectElement(selectedItemSpinCtrl->GetValue());

    EndModal(1);
}

void ComboBoxObjectEditor::OnfontBtClick(wxCommandEvent& event)
{
    wxFileDialog dialog(this, _("Choisissez une police de caractère ( fichiers ttf, ttc )"), "", "", "Polices (*.ttf, *.ttc)|*.ttf;*.ttc");
    dialog.ShowModal();

    if ( dialog.GetPath() != "" )
    {
        fontEdit->ChangeValue(dialog.GetPath());
    }
}

void ComboBoxObjectEditor::OnSizeEditChange(wxSpinEvent& event)
{
}


void ComboBoxObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/liste_deroulante");
}

#endif
