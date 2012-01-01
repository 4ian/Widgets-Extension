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
#ifndef DATABITMAPBUTTON_H
#define DATABITMAPBUTTON_H

#include <string>
#include <wx/bmpbuttn.h>

template<class T>
class DataBitmapButton : public wxBitmapButton
{
    public:
    DataBitmapButton() { Init(); }

    DataBitmapButton(wxWindow *parent,
                    wxWindowID winid,
                    const wxBitmap &bitmap,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = 0,
                    const wxValidator& val = wxDefaultValidator,
                    const wxString& name = "DataBitmapButton")
    {
        Init();

        Create(parent, winid, bitmap, pos, size, style, val, name);
    }

    const T& GetDataStored();
    void SetDataStored(const T data);

protected:

    void Init() {
        // init widget's internals...
    }

    virtual wxSize DoGetBestSize() const {
        return wxBitmapButton::DoGetBestSize();
    }

    void OnPaint(wxPaintEvent &ev) {
        wxBitmapButton::OnPaint(ev);
    }

private:

    T dataStorage;
};


#include "DataBitmapButton.inl"

#endif
#endif
