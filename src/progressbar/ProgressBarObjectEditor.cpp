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
	wxFlexGridSizer* FlexGridSizer8;
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
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(420,146), 0, _T("ID_NOTEBOOK1"));
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

	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProgressBarObjectEditor::OnokBtClick);
	//*)

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

    colorsPanel = new ColorSchemePanel(Notebook1, wxID_ANY);
    colorsPanel->AddColorScheme("background", _("Fond"), object.GetBackgroundColorScheme(), CSP_HasUnfocusedColorBt | CSP_HasDisabledColorBt);
    colorsPanel->AddColorScheme("border", _("Bordure"), object.GetBorderColorScheme(), CSP_HasUnfocusedColorBt | CSP_HasDisabledColorBt);
    colorsPanel->AddColorScheme("bar", _("Barre"), object.GetBarColorScheme(), CSP_HasUnfocusedColorBt | CSP_HasDisabledColorBt);

    Notebook1->AddPage(colorsPanel, "Couleurs");
}

ProgressBarObjectEditor::~ProgressBarObjectEditor()
{
	//(*Destroy(ProgressBarObjectEditor)
	//*)
}


void ProgressBarObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    if(ToFloat<std::string>(ToString(valueTextCtrl->GetValue())) > 1
       || ToFloat<std::string>(ToString(valueTextCtrl->GetValue())) < 0)
    {
        wxMessageBox("La valeur est mal entrée.\nIl faut qu'elle soit comprise entre 0 et 1.", "Erreur");
        return;
    }

    object.SetBackgroundColorScheme(colorsPanel->GetColorScheme("background"));
    object.SetBorderColorScheme(colorsPanel->GetColorScheme("border"));
    object.SetBarColorScheme(colorsPanel->GetColorScheme("bar"));

    object.SetBorderWidth(borderWidthSpinCtrl->GetValue());
    object.SetBarBorderWidth(barBorderWidthSpinCtrl->GetValue());

    object.SetValue(ToFloat<std::string>(ToString(valueTextCtrl->GetValue())));

    if(horizontalRadio->GetValue() == true)
        object.SetOrientation(0);
    else
        object.SetOrientation(1);

    EndModal(1);
}

void ProgressBarObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/barre_de_progression");
}

#endif
