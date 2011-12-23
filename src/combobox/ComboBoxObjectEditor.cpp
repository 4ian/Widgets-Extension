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
const long ComboBoxObjectEditor::ID_STATICTEXT3 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON5 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON2 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON7 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON6 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT5 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON8 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON9 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON10 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON11 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT8 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON12 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON13 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON14 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON15 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT11 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON16 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON17 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON18 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON19 = wxNewId();
const long ComboBoxObjectEditor::ID_STATICTEXT12 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON20 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON21 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON22 = wxNewId();
const long ComboBoxObjectEditor::ID_BUTTON23 = wxNewId();
const long ComboBoxObjectEditor::ID_PANEL2 = wxNewId();
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
	wxFlexGridSizer* FlexGridSizer7;
	wxGridSizer* GridSizer1;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer6;
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
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
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
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer7 = new wxFlexGridSizer(2, 1, 0, 0);
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	FlexGridSizer7->Add(GridSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(5, 5, 0, 0);
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Fond :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer6->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedBackgroundBt = new wxButton(Panel2, ID_BUTTON5, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer6->Add(focusedBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredBackgroundBt = new wxButton(Panel2, ID_BUTTON2, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer6->Add(hoveredBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalBackgroundBt = new wxButton(Panel2, ID_BUTTON7, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	FlexGridSizer6->Add(normalBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledBackgroundBt = new wxButton(Panel2, ID_BUTTON6, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	FlexGridSizer6->Add(disabledBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Bordure :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer6->Add(StaticText5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedBorderBt = new wxButton(Panel2, ID_BUTTON8, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	FlexGridSizer6->Add(focusedBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredBorderBt = new wxButton(Panel2, ID_BUTTON9, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	FlexGridSizer6->Add(hoveredBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalBorderBt = new wxButton(Panel2, ID_BUTTON10, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
	FlexGridSizer6->Add(normalBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledBorderBt = new wxButton(Panel2, ID_BUTTON11, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
	FlexGridSizer6->Add(disabledBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel2, ID_STATICTEXT8, _("Texte :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer6->Add(StaticText8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedTextBt = new wxButton(Panel2, ID_BUTTON12, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
	FlexGridSizer6->Add(focusedTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredTextBt = new wxButton(Panel2, ID_BUTTON13, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
	FlexGridSizer6->Add(hoveredTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalTextBt = new wxButton(Panel2, ID_BUTTON14, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
	FlexGridSizer6->Add(normalTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledTextBt = new wxButton(Panel2, ID_BUTTON15, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
	FlexGridSizer6->Add(disabledTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(Panel2, ID_STATICTEXT11, _("Flèche :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer6->Add(StaticText11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedArrowBt = new wxButton(Panel2, ID_BUTTON16, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
	FlexGridSizer6->Add(focusedArrowBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredArrowBt = new wxButton(Panel2, ID_BUTTON17, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
	FlexGridSizer6->Add(hoveredArrowBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalArrowBt = new wxButton(Panel2, ID_BUTTON18, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON18"));
	FlexGridSizer6->Add(normalArrowBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledArrowBt = new wxButton(Panel2, ID_BUTTON19, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON19"));
	FlexGridSizer6->Add(disabledArrowBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _("Sélection :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer6->Add(StaticText12, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedHighlightBt = new wxButton(Panel2, ID_BUTTON20, _("Tout le temps"), wxDefaultPosition, wxSize(82,23), 0, wxDefaultValidator, _T("ID_BUTTON20"));
	FlexGridSizer6->Add(focusedHighlightBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredHighlightBt = new wxButton(Panel2, ID_BUTTON21, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON21"));
	hoveredHighlightBt->Disable();
	hoveredHighlightBt->Hide();
	FlexGridSizer6->Add(hoveredHighlightBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalHighlightBt = new wxButton(Panel2, ID_BUTTON22, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON22"));
	normalHighlightBt->Disable();
	normalHighlightBt->Hide();
	FlexGridSizer6->Add(normalHighlightBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	dsiabledHighlightBt = new wxButton(Panel2, ID_BUTTON23, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON23"));
	dsiabledHighlightBt->Disable();
	dsiabledHighlightBt->Hide();
	FlexGridSizer6->Add(dsiabledHighlightBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel2->SetSizer(FlexGridSizer7);
	FlexGridSizer7->Fit(Panel2);
	FlexGridSizer7->SetSizeHints(Panel2);
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
	Notebook1->AddPage(Panel2, _("Couleurs"), false);
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
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnfocusedBackgroundBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnhoveredBackgroundBtClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnnormalBackgroundBtClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OndisabledBackgroundBtClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnfocusedBorderBtClick);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnhoveredBorderBtClick);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnnormalBorderBtClick);
	Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OndisabledBorderBtClick);
	Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnfocusedTextBtClick);
	Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnhoveredTextBtClick);
	Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnnormalTextBtClick);
	Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OndisabledTextBtClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnokBtClick);
	//*)

	Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnfocusedArrowBtClick);
	Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnhoveredArrowBtClick);
	Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnnormalArrowBtClick);
	Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OndisabledArrowBtClick);
	Connect(ID_BUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnfocusedHighlightBtClick);
	Connect(ID_BUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnhoveredHighlightBtClick);
	Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OnnormalHighlightBtClick);
	Connect(ID_BUTTON23,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ComboBoxObjectEditor::OndsiabledHighlightBtClick);



	fontEdit->ChangeValue(object.GetFont());
	sizeEdit->SetValue(object.GetCharacterSize());

	focusedBackgroundBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBackgroundColorScheme().focusedColor));
	UseCorrectForeground(focusedBackgroundBt);
	hoveredBackgroundBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBackgroundColorScheme().hoveredColor));
	UseCorrectForeground(hoveredBackgroundBt);
	normalBackgroundBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBackgroundColorScheme().unfocusedColor));
    UseCorrectForeground(normalBackgroundBt);
    disabledBackgroundBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBackgroundColorScheme().disabledColor));
    UseCorrectForeground(disabledBackgroundBt);

    focusedBorderBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBorderColorScheme().focusedColor));
	UseCorrectForeground(focusedBorderBt);
	hoveredBorderBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBorderColorScheme().hoveredColor));
	UseCorrectForeground(hoveredBorderBt);
	normalBorderBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBorderColorScheme().unfocusedColor));
    UseCorrectForeground(normalBorderBt);
    disabledBorderBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBorderColorScheme().disabledColor));
    UseCorrectForeground(disabledBorderBt);

    focusedTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetTextColorScheme().focusedColor));
	UseCorrectForeground(focusedTextBt);
	hoveredTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetTextColorScheme().hoveredColor));
	UseCorrectForeground(hoveredTextBt);
	normalTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetTextColorScheme().unfocusedColor));
    UseCorrectForeground(normalTextBt);
    disabledTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetTextColorScheme().disabledColor));
    UseCorrectForeground(disabledTextBt);

    focusedArrowBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetArrowColorScheme().focusedColor));
	UseCorrectForeground(focusedArrowBt);
	hoveredArrowBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetArrowColorScheme().hoveredColor));
	UseCorrectForeground(hoveredArrowBt);
	normalArrowBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetArrowColorScheme().unfocusedColor));
    UseCorrectForeground(normalArrowBt);
    disabledArrowBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetArrowColorScheme().disabledColor));
    UseCorrectForeground(disabledArrowBt);

    focusedHighlightBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetHighlightColorScheme().focusedColor));
	UseCorrectForeground(focusedHighlightBt);
	hoveredHighlightBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetHighlightColorScheme().hoveredColor));
	UseCorrectForeground(hoveredHighlightBt);
	normalHighlightBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetHighlightColorScheme().unfocusedColor));
    UseCorrectForeground(normalHighlightBt);
    dsiabledHighlightBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetHighlightColorScheme().disabledColor));
    UseCorrectForeground(dsiabledHighlightBt);

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
}

ComboBoxObjectEditor::~ComboBoxObjectEditor()
{
	//(*Destroy(ComboBoxObjectEditor)
	//*)
}

void ComboBoxObjectEditor::UseCorrectForeground(wxButton *bt)
{
    if(bt->GetBackgroundColour().Red() < 128 && bt->GetBackgroundColour().Green() < 128 && bt->GetBackgroundColour().Blue() < 128)
        bt->SetForegroundColour(wxColour(255, 255, 255));
    else
        bt->SetForegroundColour(wxColour(0, 0, 0));
}


void ComboBoxObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    object.SetFont(std::string(ToString(fontEdit->GetValue())));
    object.SetCharacterSize(sizeEdit->GetValue());

    ColorScheme backgroundColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedBackgroundBt->GetBackgroundColour()),
                                      WidgetsCommonTools::GetSfColorFromWxColour(normalBackgroundBt->GetBackgroundColour()),
                                      WidgetsCommonTools::GetSfColorFromWxColour(hoveredBackgroundBt->GetBackgroundColour()),
                                      WidgetsCommonTools::GetSfColorFromWxColour(disabledBackgroundBt->GetBackgroundColour()));
    object.SetBackgroundColorScheme(backgroundColorScheme);

    ColorScheme borderColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedBorderBt->GetBackgroundColour()),
                                  WidgetsCommonTools::GetSfColorFromWxColour(normalBorderBt->GetBackgroundColour()),
                                  WidgetsCommonTools::GetSfColorFromWxColour(hoveredBorderBt->GetBackgroundColour()),
                                  WidgetsCommonTools::GetSfColorFromWxColour(disabledBorderBt->GetBackgroundColour()));
    object.SetBorderColorScheme(borderColorScheme);

    ColorScheme textColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedTextBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(normalTextBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(hoveredTextBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(disabledTextBt->GetBackgroundColour()));
    object.SetTextColorScheme(textColorScheme);

    ColorScheme arrowColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedArrowBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(normalArrowBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(hoveredArrowBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(disabledArrowBt->GetBackgroundColour()));
    object.SetArrowColorScheme(arrowColorScheme);

    ColorScheme highlightColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedHighlightBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(normalHighlightBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(hoveredHighlightBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(dsiabledHighlightBt->GetBackgroundColour()));
    object.SetHighlightColorScheme(highlightColorScheme);

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

void ComboBoxObjectEditor::OnfocusedBackgroundBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, focusedBackgroundBt->GetBackgroundColour());
    if ( color.IsOk() )
        focusedBackgroundBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            focusedBackgroundBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            focusedBackgroundBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnhoveredBackgroundBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, hoveredBackgroundBt->GetBackgroundColour());
    if ( color.IsOk() )
        hoveredBackgroundBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            hoveredBackgroundBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            hoveredBackgroundBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnnormalBackgroundBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, normalBackgroundBt->GetBackgroundColour());
    if ( color.IsOk() )
        normalBackgroundBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            normalBackgroundBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            normalBackgroundBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OndisabledBackgroundBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, disabledBackgroundBt->GetBackgroundColour());
    if ( color.IsOk() )
        disabledBackgroundBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            disabledBackgroundBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            disabledBackgroundBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnfocusedBorderBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, focusedBorderBt->GetBackgroundColour());
    if ( color.IsOk() )
        focusedBorderBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            focusedBorderBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            focusedBorderBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnhoveredBorderBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, hoveredBorderBt->GetBackgroundColour());
    if ( color.IsOk() )
        hoveredBorderBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            hoveredBorderBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            hoveredBorderBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnnormalBorderBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, normalBorderBt->GetBackgroundColour());
    if ( color.IsOk() )
        normalBorderBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            normalBorderBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            normalBorderBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OndisabledBorderBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, disabledBorderBt->GetBackgroundColour());
    if ( color.IsOk() )
        disabledBorderBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            disabledBorderBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            disabledBorderBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnfocusedTextBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, focusedTextBt->GetBackgroundColour());
    if ( color.IsOk() )
        focusedTextBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            focusedTextBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            focusedTextBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnhoveredTextBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, hoveredTextBt->GetBackgroundColour());
    if ( color.IsOk() )
        hoveredTextBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            hoveredTextBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            hoveredTextBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void ComboBoxObjectEditor::OnnormalTextBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, normalTextBt->GetBackgroundColour());
    if ( color.IsOk() )
        normalTextBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            normalTextBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            normalTextBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}



COLOR_BUTTON_FUNCTION_IMPLEMENT(disabledTextBt, ComboBoxObjectEditor, OndisabledTextBtClick)

COLOR_BUTTON_FUNCTION_IMPLEMENT(focusedArrowBt, ComboBoxObjectEditor, OnfocusedArrowBtClick)
COLOR_BUTTON_FUNCTION_IMPLEMENT(hoveredArrowBt, ComboBoxObjectEditor, OnhoveredArrowBtClick)
COLOR_BUTTON_FUNCTION_IMPLEMENT(normalArrowBt, ComboBoxObjectEditor, OnnormalArrowBtClick)
COLOR_BUTTON_FUNCTION_IMPLEMENT(disabledArrowBt, ComboBoxObjectEditor, OndisabledArrowBtClick)

COLOR_BUTTON_FUNCTION_IMPLEMENT(focusedHighlightBt, ComboBoxObjectEditor, OnfocusedHighlightBtClick)
COLOR_BUTTON_FUNCTION_IMPLEMENT(hoveredHighlightBt, ComboBoxObjectEditor, OnhoveredHighlightBtClick)
COLOR_BUTTON_FUNCTION_IMPLEMENT(normalHighlightBt, ComboBoxObjectEditor, OnnormalHighlightBtClick)
COLOR_BUTTON_FUNCTION_IMPLEMENT(dsiabledHighlightBt, ComboBoxObjectEditor, OndsiabledHighlightBtClick)


void ComboBoxObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/zone_de_texte_monoligne");
}

#endif
