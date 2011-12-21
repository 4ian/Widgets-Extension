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

#include "ProgressBarObjectEditor.h"

//(*InternalHeaders(ProgressBarObjectEditor)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

#include "GDL/Game.h"
#include "ProgressBarObject.h"
#include "GDL/MainEditorCommand.h"
#include "GDL/CommonTools.h"

#include "../WidgetsCommonTools.h"

#include "../colorScheme.h"

//(*IdInit(ProgressBarObjectEditor)
const long ProgressBarObjectEditor::ID_STATICTEXT6 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT7 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT14 = wxNewId();
const long ProgressBarObjectEditor::ID_RADIOBUTTON1 = wxNewId();
const long ProgressBarObjectEditor::ID_RADIOBUTTON2 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT2 = wxNewId();
const long ProgressBarObjectEditor::ID_TEXTCTRL1 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT4 = wxNewId();
const long ProgressBarObjectEditor::ID_PANEL1 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT3 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON5 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON2 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON7 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON6 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT5 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON8 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON9 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON10 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON11 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT8 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON12 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON13 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON14 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON15 = wxNewId();
const long ProgressBarObjectEditor::ID_PANEL2 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT1 = wxNewId();
const long ProgressBarObjectEditor::ID_SPINCTRL2 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICTEXT13 = wxNewId();
const long ProgressBarObjectEditor::ID_SPINCTRL1 = wxNewId();
const long ProgressBarObjectEditor::ID_PANEL3 = wxNewId();
const long ProgressBarObjectEditor::ID_NOTEBOOK1 = wxNewId();
const long ProgressBarObjectEditor::ID_STATICLINE1 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON3 = wxNewId();
const long ProgressBarObjectEditor::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ProgressBarObjectEditor,wxDialog)
	//(*EventTable(ProgressBarObjectEditor)
	//*)
END_EVENT_TABLE()

ProgressBarObjectEditor::ProgressBarObjectEditor( wxWindow* parent, Game & game_, ProgressBarObject & object_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_)
{
	//(*Initialize(ProgressBarObjectEditor)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxGridSizer* GridSizer1;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;
	wxGridSizer* GridSizer2;

	Create(parent, wxID_ANY, _("Editer la barre de progression"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer8 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Barre de progression"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer8->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Permet d\'afficher une progression entre 0 et 100 %."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer8->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer4 = new wxFlexGridSizer(2, 1, 0, 0);
	GridSizer2 = new wxGridSizer(1, 3, 0, 0);
	StaticText14 = new wxStaticText(Panel1, ID_STATICTEXT14, _("Orientation :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	GridSizer2->Add(StaticText14, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	horizontalRadio = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Horizontale"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	GridSizer2->Add(horizontalRadio, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	verticalRadio = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Verticale"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	GridSizer2->Add(verticalRadio, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(GridSizer2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer9 = new wxFlexGridSizer(1, 3, 0, 0);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Valeur :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer9->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	valueTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxSize(100,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer9->Add(valueTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Entrez une valeur entre 0 et 1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer9->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel1->SetSizer(FlexGridSizer4);
	FlexGridSizer4->Fit(Panel1);
	FlexGridSizer4->SetSizeHints(Panel1);
	Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer7 = new wxFlexGridSizer(2, 1, 0, 0);
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	FlexGridSizer7->Add(GridSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(3, 5, 0, 0);
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Fond :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer6->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedBackgroundBt = new wxButton(Panel2, ID_BUTTON5, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	focusedBackgroundBt->Disable();
	focusedBackgroundBt->Hide();
	FlexGridSizer6->Add(focusedBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredBackgroundBt = new wxButton(Panel2, ID_BUTTON2, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	hoveredBackgroundBt->Disable();
	hoveredBackgroundBt->Hide();
	FlexGridSizer6->Add(hoveredBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalBackgroundBt = new wxButton(Panel2, ID_BUTTON7, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	FlexGridSizer6->Add(normalBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledBackgroundBt = new wxButton(Panel2, ID_BUTTON6, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	FlexGridSizer6->Add(disabledBackgroundBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Bordure :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer6->Add(StaticText5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedBorderBt = new wxButton(Panel2, ID_BUTTON8, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	focusedBorderBt->Disable();
	focusedBorderBt->Hide();
	FlexGridSizer6->Add(focusedBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredBorderBt = new wxButton(Panel2, ID_BUTTON9, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	hoveredBorderBt->Disable();
	hoveredBorderBt->Hide();
	FlexGridSizer6->Add(hoveredBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalBorderBt = new wxButton(Panel2, ID_BUTTON10, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
	FlexGridSizer6->Add(normalBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledBorderBt = new wxButton(Panel2, ID_BUTTON11, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
	FlexGridSizer6->Add(disabledBorderBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel2, ID_STATICTEXT8, _("Barre :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer6->Add(StaticText8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	focusedTextBt = new wxButton(Panel2, ID_BUTTON12, _("Actif"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
	focusedTextBt->Disable();
	focusedTextBt->Hide();
	FlexGridSizer6->Add(focusedTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	hoveredTextBt = new wxButton(Panel2, ID_BUTTON13, _("Survolé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
	hoveredTextBt->Disable();
	hoveredTextBt->Hide();
	FlexGridSizer6->Add(hoveredTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	normalTextBt = new wxButton(Panel2, ID_BUTTON14, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
	FlexGridSizer6->Add(normalTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	disabledTextBt = new wxButton(Panel2, ID_BUTTON15, _("Désactivé"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
	FlexGridSizer6->Add(disabledTextBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel2->SetSizer(FlexGridSizer7);
	FlexGridSizer7->Fit(Panel2);
	FlexGridSizer7->SetSizeHints(Panel2);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer3 = new wxFlexGridSizer(3, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT1, _("Epaisseur de la bordure:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	borderWidthSpinCtrl = new wxSpinCtrl(Panel3, ID_SPINCTRL2, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 1, _T("ID_SPINCTRL2"));
	borderWidthSpinCtrl->SetValue(_T("1"));
	FlexGridSizer3->Add(borderWidthSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(Panel3, ID_STATICTEXT13, _("Epaisseur de la bordure de la progression :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer3->Add(StaticText13, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	barBorderWidthSpinCtrl = new wxSpinCtrl(Panel3, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 1, _T("ID_SPINCTRL1"));
	barBorderWidthSpinCtrl->SetValue(_T("1"));
	FlexGridSizer3->Add(barBorderWidthSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(Panel3);
	FlexGridSizer3->SetSizeHints(Panel3);
	Notebook1->AddPage(Panel1, _("Valeurs et orientation"), false);
	Notebook1->AddPage(Panel2, _("Couleurs"), false);
	Notebook1->AddPage(Panel3, _("Tailles"), false);
	FlexGridSizer1->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
	Button1 = new wxButton(this, ID_BUTTON3, _("Aide sur ce widget"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	okBt = new wxButton(this, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(okBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnfocusedBackgroundBtClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnhoveredBackgroundBtClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnnormalBackgroundBtClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OndisabledBackgroundBtClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnfocusedBorderBtClick);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnhoveredBorderBtClick);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnnormalBorderBtClick);
	Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OndisabledBorderBtClick);
	Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnfocusedTextBtClick);
	Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnhoveredTextBtClick);
	Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnnormalTextBtClick);
	Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OndisabledTextBtClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnokBtClick);
	//*)

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

    focusedTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBarColorScheme().focusedColor));
	UseCorrectForeground(focusedTextBt);
	hoveredTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBarColorScheme().hoveredColor));
	UseCorrectForeground(hoveredTextBt);
	normalTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBarColorScheme().unfocusedColor));
    UseCorrectForeground(normalTextBt);
    disabledTextBt->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(object.GetBarColorScheme().disabledColor));
    UseCorrectForeground(disabledTextBt);

    borderWidthSpinCtrl->SetValue(object.GetBorderWidth());
    barBorderWidthSpinCtrl->SetValue(object.GetBarBorderWidth());

    valueTextCtrl->SetValue(ToString<float>(object.GetValue()));

    if(object.GetOrientation() == 0)
    {
        horizontalRadio->SetValue(true);
        verticalRadio->SetValue(false);
    }
    else
    {
        horizontalRadio->SetValue(false);
        verticalRadio->SetValue(true);
    }
}

ProgressBarObjectEditor::~ProgressBarObjectEditor()
{
	//(*Destroy(ProgressBarObjectEditor)
	//*)
}

void ProgressBarObjectEditor::UseCorrectForeground(wxButton *bt)
{
    if(bt->GetBackgroundColour().Red() < 128 && bt->GetBackgroundColour().Green() < 128 && bt->GetBackgroundColour().Blue() < 128)
        bt->SetForegroundColour(wxColour(255, 255, 255));
    else
        bt->SetForegroundColour(wxColour(0, 0, 0));
}


void ProgressBarObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    if(ToFloat<std::string>(ToString(valueTextCtrl->GetValue())) > 1
       || ToFloat<std::string>(ToString(valueTextCtrl->GetValue())) < 0)
    {
        wxMessageBox("La valeur est mal entrée.\nIl faut qu'elle soit comprise entre 0 et 1.", "Erreur");
        return;
    }


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

    ColorScheme barColorScheme(WidgetsCommonTools::GetSfColorFromWxColour(focusedTextBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(normalTextBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(hoveredTextBt->GetBackgroundColour()),
                                WidgetsCommonTools::GetSfColorFromWxColour(disabledTextBt->GetBackgroundColour()));
    object.SetBarColorScheme(barColorScheme);

    object.SetBorderWidth(borderWidthSpinCtrl->GetValue());
    object.SetBarBorderWidth(barBorderWidthSpinCtrl->GetValue());

    object.SetValue(ToFloat<std::string>(ToString(valueTextCtrl->GetValue())));

    if(horizontalRadio->GetValue() == true)
        object.SetOrientation(0);
    else
        object.SetOrientation(1);

    EndModal(1);
}

void ProgressBarObjectEditor::OnfocusedBackgroundBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnhoveredBackgroundBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnnormalBackgroundBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OndisabledBackgroundBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnfocusedBorderBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnhoveredBorderBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnnormalBorderBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OndisabledBorderBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnfocusedTextBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnhoveredTextBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnnormalTextBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OndisabledTextBtClick(wxCommandEvent& event)
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

void ProgressBarObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/barre_de_progression");
}

#endif
