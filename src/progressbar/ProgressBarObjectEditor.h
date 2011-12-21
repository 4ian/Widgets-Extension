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

#ifndef ProgressBarObjectEditor_H
#define ProgressBarObjectEditor_H

//(*Headers(ProgressBarObjectEditor)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
class Game;
class ProgressBarObject;
class MainEditorCommand;

class ProgressBarObjectEditor: public wxDialog
{
	public:

		ProgressBarObjectEditor( wxWindow* parent, Game & game_, ProgressBarObject & object_, MainEditorCommand & mainEditorCommand_ );
		virtual ~ProgressBarObjectEditor();

		//(*Declarations(ProgressBarObjectEditor)
		wxButton* hoveredBackgroundBt;
		wxButton* hoveredTextBt;
		wxButton* focusedTextBt;
		wxNotebook* Notebook1;
		wxButton* normalBackgroundBt;
		wxRadioButton* verticalRadio;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxButton* hoveredBorderBt;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxButton* focusedBorderBt;
		wxSpinCtrl* borderWidthSpinCtrl;
		wxStaticText* StaticText8;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxPanel* Panel3;
		wxButton* disabledBorderBt;
		wxButton* disabledTextBt;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticLine* StaticLine1;
		wxButton* focusedBackgroundBt;
		wxRadioButton* horizontalRadio;
		wxButton* normalBorderBt;
		wxPanel* Panel2;
		wxSpinCtrl* barBorderWidthSpinCtrl;
		wxTextCtrl* valueTextCtrl;
		wxStaticText* StaticText4;
		wxButton* normalTextBt;
		wxButton* okBt;
		wxButton* disabledBackgroundBt;
		//*)

	protected:

		//(*Identifiers(ProgressBarObjectEditor)
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT14;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT4;
		static const long ID_PANEL1;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON5;
		static const long ID_BUTTON2;
		static const long ID_BUTTON7;
		static const long ID_BUTTON6;
		static const long ID_STATICTEXT5;
		static const long ID_BUTTON8;
		static const long ID_BUTTON9;
		static const long ID_BUTTON10;
		static const long ID_BUTTON11;
		static const long ID_STATICTEXT8;
		static const long ID_BUTTON12;
		static const long ID_BUTTON13;
		static const long ID_BUTTON14;
		static const long ID_BUTTON15;
		static const long ID_PANEL2;
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT13;
		static const long ID_SPINCTRL1;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ProgressBarObjectEditor)
		void OnokBtClick(wxCommandEvent& event);
		void OncancelBtClick(wxCommandEvent& event);
		void OnfocusedBackgroundBtClick(wxCommandEvent& event);
		void OnhoveredBackgroundBtClick(wxCommandEvent& event);
		void OnnormalBackgroundBtClick(wxCommandEvent& event);
		void OndisabledBackgroundBtClick(wxCommandEvent& event);
		void OnfocusedBorderBtClick(wxCommandEvent& event);
		void OnhoveredBorderBtClick(wxCommandEvent& event);
		void OnnormalBorderBtClick(wxCommandEvent& event);
		void OndisabledBorderBtClick(wxCommandEvent& event);
		void OnfocusedTextBtClick(wxCommandEvent& event);
		void OnhoveredTextBtClick(wxCommandEvent& event);
		void OnnormalTextBtClick(wxCommandEvent& event);
		void OndisabledTextBtClick(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		Game & game;
		MainEditorCommand & mainEditorCommand;
		ProgressBarObject & object;

		void UseCorrectForeground(wxButton*);

		DECLARE_EVENT_TABLE()
};

#endif
#endif
