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
