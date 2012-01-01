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
class ColorSchemePanel;

class ComboBoxObjectEditor: public wxDialog
{
	public:

		ComboBoxObjectEditor( wxWindow* parent, Game & game_, ComboBoxObject & object_, MainEditorCommand & mainEditorCommand_ );
		virtual ~ComboBoxObjectEditor();

		//(*Declarations(ComboBoxObjectEditor)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxSpinCtrl* sizeEdit;
		wxNotebook* Notebook1;
		wxSpinCtrl* paddingSpinCtrl;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxTextCtrl* textEdit;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxSpinCtrl* borderWidthSpinCtrl;
		wxSpinCtrl* selectedItemSpinCtrl;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxPanel* Panel3;
		wxButton* fontBt;
		wxStaticText* StaticText7;
		wxStaticLine* StaticLine1;
		wxTextCtrl* fontEdit;
		wxStaticText* StaticText4;
		wxButton* okBt;
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
		void OnButton1Click(wxCommandEvent& event);
		//*)

		Game & game;
		MainEditorCommand & mainEditorCommand;
		ComboBoxObject & object;

		ColorSchemePanel *colorsPanel;

		DECLARE_EVENT_TABLE()
};

#endif
#endif
