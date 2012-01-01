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

#ifndef ButtonObjectEditor_H
#define ButtonObjectEditor_H

//(*Headers(ButtonObjectEditor)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include <wx/aui/aui.h>

#include "../colorSchemePanel.h"

class Game;
class ButtonObject;
class MainEditorCommand;
class ResourcesEditor;

class ButtonObjectEditor: public wxDialog
{
	public:

		ButtonObjectEditor( wxWindow* parent, Game & game_, ButtonObject & object_, MainEditorCommand & mainEditorCommand_ );
		virtual ~ButtonObjectEditor();

		//(*Declarations(ButtonObjectEditor)
		wxStaticText* StaticText10;
		wxPanel* Core;
		wxStaticText* StaticText9;
		wxSpinCtrl* sizeEdit;
		wxNotebook* Notebook1;
		wxSpinCtrl* paddingSpinCtrl;
		wxStaticText* StaticText2;
		wxTextCtrl* textEdit;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxSpinCtrl* borderWidthSpinCtrl;
		wxStaticText* StaticText11;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxPanel* Panel3;
		wxButton* fontBt;
		wxStaticText* StaticText7;
		wxBitmapButton* Button2;
		wxTextCtrl* fontEdit;
		wxStaticText* StaticText4;
		wxButton* okBt;
		wxTextCtrl* imageNameTextCtrl;
		//*)

		ResourcesEditor * editorImagesPnl;

	protected:

		//(*Identifiers(ButtonObjectEditor)
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT11;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON16;
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
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		static const long ID_PANEL5;
		//*)

	private:

		//(*Handlers(ButtonObjectEditor)
		void OnokBtClick(wxCommandEvent& event);
		void OnfontBtClick(wxCommandEvent& event);
		void OnSizeEditChange(wxSpinEvent& event);
		void OncancelBtClick(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnNotebook1PageChanged(wxNotebookEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		Game & game;
		MainEditorCommand & mainEditorCommand;
		ButtonObject & object;

		wxAuiManager m_mgr;

		ColorSchemePanel *colorsPanel;

		DECLARE_EVENT_TABLE()
};

#endif
#endif
