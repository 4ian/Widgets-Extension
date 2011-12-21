/**

This file is a part of the "Extension Widgets" distributed as free software.

**/

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
		wxButton* hoveredBackgroundBt;
		wxButton* hoveredTextBt;
		wxButton* focusedTextBt;
		wxNotebook* Notebook1;
		wxSpinCtrl* paddingSpinCtrl;
		wxButton* normalBackgroundBt;
		wxStaticText* StaticText2;
		wxButton* hoveredBorderBt;
		wxTextCtrl* textEdit;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxButton* focusedBorderBt;
		wxSpinCtrl* borderWidthSpinCtrl;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxPanel* Panel3;
		wxButton* fontBt;
		wxButton* disabledBorderBt;
		wxButton* disabledTextBt;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxButton* focusedBackgroundBt;
		wxBitmapButton* Button2;
		wxButton* normalBorderBt;
		wxPanel* Panel2;
		wxTextCtrl* fontEdit;
		wxStaticText* StaticText4;
		wxButton* normalTextBt;
		wxButton* okBt;
		wxButton* disabledBackgroundBt;
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
		void OnNotebook1PageChanged(wxNotebookEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		Game & game;
		MainEditorCommand & mainEditorCommand;
		ButtonObject & object;

		wxAuiManager m_mgr;

		void UseCorrectForeground(wxButton*);

		DECLARE_EVENT_TABLE()
};

#endif
#endif
