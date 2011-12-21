/**

This file is a part of the "Extension Widgets" distributed as free software.

**/

#if defined(GD_IDE_ONLY)

#ifndef ScaleObjectEditor_H
#define ScaleObjectEditor_H

//(*Headers(ScaleObjectEditor)
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
class ScaleObject;
class MainEditorCommand;

class ScaleObjectEditor: public wxDialog
{
	public:

		ScaleObjectEditor( wxWindow* parent, Game & game_, ScaleObject & object_, MainEditorCommand & mainEditorCommand_ );
		virtual ~ScaleObjectEditor();

		//(*Declarations(ScaleObjectEditor)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxButton* hoveredBackgroundBt;
		wxButton* hoveredTextBt;
		wxButton* focusedTextBt;
		wxNotebook* Notebook1;
		wxSpinCtrl* paddingSpinCtrl;
		wxButton* normalBackgroundBt;
		wxRadioButton* verticalRadio;
		wxTextCtrl* maximumTextCtrl;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxButton* hoveredBorderBt;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxButton* focusedBorderBt;
		wxSpinCtrl* borderWidthSpinCtrl;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxTextCtrl* incrementTextCtrl;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxPanel* Panel3;
		wxTextCtrl* minimumTextCtrl;
		wxButton* disabledBorderBt;
		wxButton* disabledTextBt;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticLine* StaticLine1;
		wxButton* focusedBackgroundBt;
		wxRadioButton* horizontalRadio;
		wxButton* normalBorderBt;
		wxStaticText* StaticText12;
		wxPanel* Panel2;
		wxTextCtrl* valueTextCtrl;
		wxStaticText* StaticText4;
		wxButton* normalTextBt;
		wxButton* okBt;
		wxButton* disabledBackgroundBt;
		wxSpinCtrl* troughWidthSpinCtrl;
		//*)

	protected:

		//(*Identifiers(ScaleObjectEditor)
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT14;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT11;
		static const long ID_TEXTCTRL4;
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
		static const long ID_STATICTEXT9;
		static const long ID_SPINCTRL3;
		static const long ID_PANEL3;
		static const long ID_NOTEBOOK1;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ScaleObjectEditor)
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
		ScaleObject & object;

		void UseCorrectForeground(wxButton*);

		DECLARE_EVENT_TABLE()
};

#endif
#endif
