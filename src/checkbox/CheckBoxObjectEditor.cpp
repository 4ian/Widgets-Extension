/**

Game Develop - Text Object Extension
Copyright (c) 2008-2011 Florian Rival (Florian.Rival@gmail.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

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
const long CheckBoxObjectEditor::ID_STATICTEXT3 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON5 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON2 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON7 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON6 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT5 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON8 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON9 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON10 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON11 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT8 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON12 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON13 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON14 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON15 = wxNewId();
const long CheckBoxObjectEditor::ID_STATICTEXT10 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON3 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON16 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON17 = wxNewId();
const long CheckBoxObjectEditor::ID_BUTTON18 = wxNewId();
const long CheckBoxObjectEditor::ID_PANEL3 = wxNewId();
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
	wxFlexGridSizer* FlexGridSizer7;
	wxGridSizer* GridSizer1;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer6;
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
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer10 = new wxFlexGridSizer(6, 2, 0, 0);
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
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer7 = new wxFlexGridSizer(2, 1, 0, 0);
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	FlexGridSizer7->Add(GridSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(4, 5, 0, 0);
	StaticText3 = new wxStaticText(Panel3, ID_STATICTEXT3, _("Fond :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer6->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedBackgroundBt = new wxButton(Panel3, ID_BUTTON5, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer6->Add(focusedBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredBackgroundBt = new wxButton(Panel3, ID_BUTTON2, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer6->Add(hoveredBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalBackgroundBt = new wxButton(Panel3, ID_BUTTON7, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	FlexGridSizer6->Add(normalBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledBackgroundBt = new wxButton(Panel3, ID_BUTTON6, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	FlexGridSizer6->Add(disabledBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT5, _("Bordure :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer6->Add(StaticText5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedBorderBt = new wxButton(Panel3, ID_BUTTON8, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	FlexGridSizer6->Add(focusedBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredBorderBt = new wxButton(Panel3, ID_BUTTON9, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	FlexGridSizer6->Add(hoveredBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalBorderBt = new wxButton(Panel3, ID_BUTTON10, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
	FlexGridSizer6->Add(normalBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledBorderBt = new wxButton(Panel3, ID_BUTTON11, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
	FlexGridSizer6->Add(disabledBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel3, ID_STATICTEXT8, _("Texte :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer6->Add(StaticText8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedTextBt = new wxButton(Panel3, ID_BUTTON12, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
	FlexGridSizer6->Add(focusedTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredTextBt = new wxButton(Panel3, ID_BUTTON13, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
	FlexGridSizer6->Add(hoveredTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalTextBt = new wxButton(Panel3, ID_BUTTON14, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
	FlexGridSizer6->Add(normalTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledTextBt = new wxButton(Panel3, ID_BUTTON15, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
	FlexGridSizer6->Add(disabledTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(Panel3, ID_STATICTEXT10, _("Couleur de la case :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer6->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	focusedCheckBt = new wxButton(Panel3, ID_BUTTON3, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer6->Add(focusedCheckBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredCheckBt = new wxButton(Panel3, ID_BUTTON16, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
	FlexGridSizer6->Add(hoveredCheckBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalCheckBt = new wxButton(Panel3, ID_BUTTON17, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
	FlexGridSizer6->Add(normalCheckBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledCheckBt = new wxButton(Panel3, ID_BUTTON18, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON18"));
	FlexGridSizer6->Add(disabledCheckBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel3->SetSizer(FlexGridSizer7);
	FlexGridSizer7->Fit(Panel3);
	FlexGridSizer7->SetSizeHints(Panel3);
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
	Notebook1->AddPage(Panel3, _("Couleurs"), false);
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

	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnfocusedBackgroundBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnhoveredBackgroundBtClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnnormalBackgroundBtClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OndisabledBackgroundBtClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnfocusedBorderBtClick);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnhoveredBorderBtClick);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnnormalBorderBtClick);
	Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OndisabledBorderBtClick);
	Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnfocusedTextBtClick);
	Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnhoveredTextBtClick);
	Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnnormalTextBtClick);
	Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OndisabledTextBtClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnfocusedCheckBtClick);
	Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnhoveredCheckBtClick);
	Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnnormalCheckBtClick);
	Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OndisabledCheckBtClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnfontBtClick);
	Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnSizeEditChange);
	Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckBoxObjectEditor::OnokBtClick);
	//*)

	textEdit->ChangeValue(object.GetString());
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

    focusedCheckBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetCheckColorScheme().focusedColor));
	UseCorrectForeground(focusedCheckBt);
	hoveredCheckBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetCheckColorScheme().hoveredColor));
	UseCorrectForeground(hoveredCheckBt);
	normalCheckBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetCheckColorScheme().unfocusedColor));
    UseCorrectForeground(normalCheckBt);
    disabledCheckBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetCheckColorScheme().disabledColor));
    UseCorrectForeground(disabledCheckBt);

    borderWidthSpinCtrl->SetValue(object.GetBorderWidth());
    paddingSpinCtrl->SetValue(object.GetPadding());
    boxSizeSpinCtrl->SetValue(object.GetBoxSize());
    checkSignSizeSpinCtrl->SetValue(object.GetCheckSignSize());

    isCheckedCheckBox->SetValue(object.IsChecked());
}

CheckBoxObjectEditor::~CheckBoxObjectEditor()
{
	//(*Destroy(CheckBoxObjectEditor)
	//*)
}

void CheckBoxObjectEditor::UseCorrectForeground(wxButton *bt)
{
    if(bt->GetBackgroundColour().Red() < 128 && bt->GetBackgroundColour().Green() < 128 && bt->GetBackgroundColour().Blue() < 128)
        bt->SetForegroundColour(wxColour(255, 255, 255));
    else
        bt->SetForegroundColour(wxColour(0, 0, 0));
}


void CheckBoxObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    object.SetString(string(ToString(textEdit->GetValue())));
    object.SetFont(string(ToString(fontEdit->GetValue())));
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

    ColorScheme checkColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedCheckBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(normalCheckBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(hoveredCheckBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(disabledCheckBt->GetBackgroundColour()));
    object.SetCheckColorScheme(checkColorScheme);


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

void CheckBoxObjectEditor::OnfocusedBackgroundBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnhoveredBackgroundBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnnormalBackgroundBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OndisabledBackgroundBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnfocusedBorderBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnhoveredBorderBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnnormalBorderBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OndisabledBorderBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnfocusedTextBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnhoveredTextBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OnnormalTextBtClick(wxCommandEvent& event)
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

void CheckBoxObjectEditor::OndisabledTextBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, disabledTextBt->GetBackgroundColour());
    if ( color.IsOk() )
        disabledTextBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            disabledTextBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            disabledTextBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void CheckBoxObjectEditor::OnfocusedCheckBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, focusedCheckBt->GetBackgroundColour());
    if ( color.IsOk() )
        focusedCheckBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            focusedCheckBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            focusedCheckBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void CheckBoxObjectEditor::OnhoveredCheckBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, hoveredCheckBt->GetBackgroundColour());
    if ( color.IsOk() )
        hoveredCheckBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            hoveredCheckBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            hoveredCheckBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void CheckBoxObjectEditor::OnnormalCheckBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, normalCheckBt->GetBackgroundColour());
    if ( color.IsOk() )
        normalCheckBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            normalCheckBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            normalCheckBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void CheckBoxObjectEditor::OndisabledCheckBtClick(wxCommandEvent& event)
{
    wxColour color = wxGetColourFromUser(this, disabledCheckBt->GetBackgroundColour());
    if ( color.IsOk() )
        disabledCheckBt->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
            disabledCheckBt->SetForegroundColour(wxColour(255, 255, 255));
        else
            disabledCheckBt->SetForegroundColour(wxColour(0, 0, 0));
    }

    return;
}

void CheckBoxObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/case_a_cocher");
}

#endif










