#ifndef GETTINGSTARTEDDIALOG_H
#define GETTINGSTARTEDDIALOG_H

#if defined(GD_IDE_ONLY)

//(*Headers(GettingStartedDialog)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class GettingStartedDialog: public wxDialog
{
	public:

		GettingStartedDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~GettingStartedDialog();

		//(*Declarations(GettingStartedDialog)
		wxNotebook* Notebook1;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxStaticBitmap* StaticBitmap1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxBitmapButton* BitmapButton1;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* versionText;
		wxStaticLine* StaticLine1;
		wxPanel* Panel2;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(GettingStartedDialog)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON3;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		static const long ID_BITMAPBUTTON1;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_PANEL2;
		static const long ID_NOTEBOOK1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(GettingStartedDialog)
		void OnButton3Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

#endif
