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

#include "../colorSchemePanel.h"

class Game;
class ProgressBarObject;
class MainEditorCommand;

class ProgressBarObjectEditor: public wxDialog
{
	public:

		ProgressBarObjectEditor( wxWindow* parent, Game & game_, ProgressBarObject & object_, MainEditorCommand & mainEditorCommand_ );
		virtual ~ProgressBarObjectEditor();

		//(*Declarations(ProgressBarObjectEditor)
		wxNotebook* Notebook1;
		wxRadioButton* verticalRadio;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxSpinCtrl* borderWidthSpinCtrl;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxPanel* Panel3;
		wxStaticText* StaticText7;
		wxStaticLine* StaticLine1;
		wxRadioButton* horizontalRadio;
		wxSpinCtrl* barBorderWidthSpinCtrl;
		wxTextCtrl* valueTextCtrl;
		wxStaticText* StaticText4;
		wxButton* okBt;
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
		void OnButton1Click(wxCommandEvent& event);
		//*)

		Game & game;
		MainEditorCommand & mainEditorCommand;
		ProgressBarObject & object;

		ColorSchemePanel *colorsPanel;

		DECLARE_EVENT_TABLE()
};

#endif
#endif
