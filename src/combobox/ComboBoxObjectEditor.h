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

#ifndef ComboBoxObjectEDITOR_H
#define ComboBoxObjectEDITOR_H

//(*Headers(ComboBoxObjectEditor)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "../WidgetsMacros.h"

class Game;
class ComboBoxObject;
class MainEditorCommand;

class ComboBoxObjectEditor: public wxDialog
{
	public:

		ComboBoxObjectEditor( wxWindow* parent, Game & game_, ComboBoxObject & object_, MainEditorCommand & mainEditorCommand_ );
		virtual ~ComboBoxObjectEditor();

		//(*Declarations(ComboBoxObjectEditor)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxButton* disabledArrowBt;
		wxButton* hoveredArrowBt;
		wxSpinCtrl* sizeEdit;
		wxButton* hoveredBackgroundBt;
		wxButton* hoveredTextBt;
		wxButton* focusedTextBt;
		wxNotebook* Notebook1;
		wxSpinCtrl* paddingSpinCtrl;
		wxButton* normalBackgroundBt;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxButton* hoveredBorderBt;
		wxTextCtrl* textEdit;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxButton* focusedBorderBt;
		wxSpinCtrl* borderWidthSpinCtrl;
		wxSpinCtrl* selectedItemSpinCtrl;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxButton* focusedHighlightBt;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* dsiabledHighlightBt;
		wxPanel* Panel3;
		wxButton* fontBt;
		wxButton* disabledBorderBt;
		wxButton* disabledTextBt;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticLine* StaticLine1;
		wxButton* focusedBackgroundBt;
		wxButton* normalBorderBt;
		wxButton* normalArrowBt;
		wxStaticText* StaticText12;
		wxButton* focusedArrowBt;
		wxPanel* Panel2;
		wxButton* normalHighlightBt;
		wxTextCtrl* fontEdit;
		wxStaticText* StaticText4;
		wxButton* normalTextBt;
		wxButton* okBt;
		wxButton* disabledBackgroundBt;
		wxButton* hoveredHighlightBt;
		//*)

	protected:

		//(*Identifiers(ComboBoxObjectEditor)
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT13;
		static const long ID_SPINCTRL4;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRL1;
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
		static const long ID_STATICTEXT11;
		static const long ID_BUTTON16;
		static const long ID_BUTTON17;
		static const long ID_BUTTON18;
		static const long ID_BUTTON19;
		static const long ID_STATICTEXT12;
		static const long ID_BUTTON20;
		static const long ID_BUTTON21;
		static const long ID_BUTTON22;
		static const long ID_BUTTON23;
		static const long ID_PANEL2;
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT9;
		static const long ID_SPINCTRL3;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ComboBoxObjectEditor)
		void OnokBtClick(wxCommandEvent& event);
		void OnfontBtClick(wxCommandEvent& event);
		void OnSizeEditChange(wxSpinEvent& event);
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
		void OnfocusedArrowBtClick(wxCommandEvent& event);
		void OnhoveredArrowBtClick(wxCommandEvent& event);
		void OnnormalArrowBtClick(wxCommandEvent& event);
		void OndisabledArrowBtClick(wxCommandEvent& event);
		void OnfocusedArrowBtClick1(wxCommandEvent& event);
		void OnfocusedArrowBtClick2(wxCommandEvent& event);
		void OnfocusedHighlightBtClick(wxCommandEvent& event);
		void OnhoveredHighlightBtClick(wxCommandEvent& event);
		void OnnormalHighlightBtClick(wxCommandEvent& event);
		void OndsiabledHighlightBtClick(wxCommandEvent& event);
		//*)

		Game & game;
		MainEditorCommand & mainEditorCommand;
		ComboBoxObject & object;

		void UseCorrectForeground(wxButton*);

		DECLARE_EVENT_TABLE()
};

#endif
#endif
