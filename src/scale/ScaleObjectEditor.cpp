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

#include "ScaleObjectEditor.h"

//(*InternalHeaders(ScaleObjectEditor)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>

#include "GDL/Game.h"
#include "ScaleObject.h"
#include "GDL/MainEditorCommand.h"
#include "GDL/CommonTools.h"

#include "../WidgetsCommonTools.h"

#include "../colorScheme.h"
#include "../colorSchemePanel.h"

//(*IdInit(ScaleObjectEditor)
const long ScaleObjectEditor::ID_STATICTEXT6 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT7 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT14 = wxNewId();
const long ScaleObjectEditor::ID_RADIOBUTTON1 = wxNewId();
const long ScaleObjectEditor::ID_RADIOBUTTON2 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT4 = wxNewId();
const long ScaleObjectEditor::ID_TEXTCTRL2 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT10 = wxNewId();
const long ScaleObjectEditor::ID_TEXTCTRL3 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT2 = wxNewId();
const long ScaleObjectEditor::ID_TEXTCTRL1 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT12 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT11 = wxNewId();
const long ScaleObjectEditor::ID_TEXTCTRL4 = wxNewId();
const long ScaleObjectEditor::ID_PANEL1 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT1 = wxNewId();
const long ScaleObjectEditor::ID_SPINCTRL2 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT13 = wxNewId();
const long ScaleObjectEditor::ID_SPINCTRL1 = wxNewId();
const long ScaleObjectEditor::ID_STATICTEXT9 = wxNewId();
const long ScaleObjectEditor::ID_SPINCTRL3 = wxNewId();
const long ScaleObjectEditor::ID_PANEL3 = wxNewId();
const long ScaleObjectEditor::ID_NOTEBOOK1 = wxNewId();
const long ScaleObjectEditor::ID_STATICLINE1 = wxNewId();
const long ScaleObjectEditor::ID_BUTTON3 = wxNewId();
const long ScaleObjectEditor::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ScaleObjectEditor,wxDialog)
	//(*EventTable(ScaleObjectEditor)
	//*)
END_EVENT_TABLE()

ScaleObjectEditor::ScaleObjectEditor( wxWindow* parent, Game & game_, ScaleObject & object_, MainEditorCommand & mainEditorCommand_ ) :
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_)
{
	//(*Initialize(ScaleObjectEditor)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer1;
	wxGridSizer* GridSizer2;
	
	Create(parent, wxID_ANY, _("Editer la glissi�re"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer8 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Glissi�re"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer8->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Permet de s�lectionner un nombre dans un intervalle."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer8->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(453,195), 0, _T("ID_NOTEBOOK1"));
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
	FlexGridSizer9 = new wxFlexGridSizer(3, 4, 0, 0);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Minimum :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer9->Add(StaticText4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	minimumTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(100,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer9->Add(minimumTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Maximum :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer9->Add(StaticText10, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	maximumTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("100"), wxDefaultPosition, wxSize(100,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer9->Add(maximumTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Valeur :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer9->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	valueTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxSize(100,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer9->Add(valueTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT12, _("Il est pr�f�rable de rentrer\nune valeur possible suivant\nl\'�cart des valeurs."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer9->Add(StaticText12, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Cran (Ecart) :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer9->Add(StaticText11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	incrementTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("10"), wxDefaultPosition, wxSize(100,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer9->Add(incrementTextCtrl, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Panel1->SetSizer(FlexGridSizer4);
	FlexGridSizer4->Fit(Panel1);
	FlexGridSizer4->SetSizeHints(Panel1);
	Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer3 = new wxFlexGridSizer(3, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT1, _("Epaisseur de la bordure:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	borderWidthSpinCtrl = new wxSpinCtrl(Panel3, ID_SPINCTRL2, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 1, _T("ID_SPINCTRL2"));
	borderWidthSpinCtrl->SetValue(_T("1"));
	FlexGridSizer3->Add(borderWidthSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(Panel3, ID_STATICTEXT13, _("Epaisseur de la glissi�re :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer3->Add(StaticText13, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	troughWidthSpinCtrl = new wxSpinCtrl(Panel3, ID_SPINCTRL1, _T("5"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 5, _T("ID_SPINCTRL1"));
	troughWidthSpinCtrl->SetValue(_T("5"));
	FlexGridSizer3->Add(troughWidthSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("Marges internes :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer3->Add(StaticText9, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	paddingSpinCtrl = new wxSpinCtrl(Panel3, ID_SPINCTRL3, _T("5"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 5, _T("ID_SPINCTRL3"));
	paddingSpinCtrl->SetValue(_T("5"));
	FlexGridSizer3->Add(paddingSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
	
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ScaleObjectEditor::OnButton1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ScaleObjectEditor::OnokBtClick);
	//*)

    borderWidthSpinCtrl->SetValue(object.GetBorderWidth());

    valueTextCtrl->SetValue(ToString<float>(object.GetValue()));
    minimumTextCtrl->SetValue(ToString<float>(object.GetMinimum()));
    maximumTextCtrl->SetValue(ToString<float>(object.GetMaximum()));
    incrementTextCtrl->SetValue(ToString<float>(object.GetIncrement()));
    troughWidthSpinCtrl->SetValue(object.GetTroughWidth());

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
    colorsPanel->AddColorScheme("trough", _("Glissi�re"), object.GetTroughColorScheme(), CSP_HasUnfocusedColorBt|CSP_HasDisabledColorBt);
    colorsPanel->AddColorScheme("border", _("Bordure"), object.GetBorderColorScheme(), CSP_HasUnfocusedColorBt|CSP_HasDisabledColorBt);
    colorsPanel->AddColorScheme("slider", _("Curseur"), object.GetSliderColorScheme(), CSP_HasUnfocusedColorBt|CSP_HasDisabledColorBt);

    Notebook1->AddPage(colorsPanel, "Couleurs");
}

ScaleObjectEditor::~ScaleObjectEditor()
{
	//(*Destroy(ScaleObjectEditor)
	//*)
}


void ScaleObjectEditor::OnokBtClick(wxCommandEvent& event)
{
    if(ToFloat<std::string>(ToString(minimumTextCtrl->GetValue())) > ToFloat<std::string>(ToString(maximumTextCtrl->GetValue()))
       || ToFloat<std::string>(ToString(minimumTextCtrl->GetValue())) > ToFloat<std::string>(ToString(valueTextCtrl->GetValue()))
       || ToFloat<std::string>(ToString(maximumTextCtrl->GetValue())) < ToFloat<std::string>(ToString(valueTextCtrl->GetValue())))
    {
        wxMessageBox("Les valeurs sont mal renseign�es.\nIl se peut que la valeur d�passe le maximum ou le minimum...", "Erreur");
        return;
    }

    object.SetTroughColorScheme(colorsPanel->GetColorScheme("trough"));
    object.SetBorderColorScheme(colorsPanel->GetColorScheme("border"));
    object.SetSliderColorScheme(colorsPanel->GetColorScheme("slider"));

    object.SetBorderWidth(borderWidthSpinCtrl->GetValue());

    object.SetMinimum(ToFloat<std::string>(ToString(minimumTextCtrl->GetValue())));
    object.SetMaximum(ToFloat<std::string>(ToString(maximumTextCtrl->GetValue())));
    object.SetValue(ToFloat<std::string>(ToString(valueTextCtrl->GetValue())));
    object.SetIncrement(ToFloat<std::string>(ToString(incrementTextCtrl->GetValue())));
    object.SetTroughWidth(troughWidthSpinCtrl->GetValue());

    if(horizontalRadio->GetValue() == true)
        object.SetOrientation(0);
    else
        object.SetOrientation(1);

    EndModal(1);
}

void ScaleObjectEditor::OnButton1Click(wxCommandEvent& event)
{
    wxLaunchDefaultBrowser("http://www.wiki.compilgames.net/doku.php/game_develop/articles/widgets/liste_des_widgets/glissiere");
}

#endif
