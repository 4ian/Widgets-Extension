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

#ifndef COLORSCHEMEPANEL_H
#define COLORSCHEMEPANEL_H

#if defined(GD_IDE_ONLY)

#include <wx/panel.h>
#include <wx/button.h>

#include <wx/stattext.h>
#include <wx/sizer.h>

#include <string>
#include <map>
#include <vector>

#include "colorScheme.h"

template <class T>
class DataBitmapButton;

enum ColorSchemeProperties
{
    CSP_HasFocusedColorBt = 1,
    CSP_HasHoveredColorBt = 2,
    CSP_HasUnfocusedColorBt = 4,
    CSP_HasDisabledColorBt = 8,
    CSP_HasAlwaysColorBt = 16,

    CSP_DefautColorBt = (CSP_HasFocusedColorBt | CSP_HasHoveredColorBt | CSP_HasUnfocusedColorBt | CSP_HasDisabledColorBt)
};


class ColorSchemePanel : public wxPanel
{

public:

    ColorSchemePanel() { Init(); }

    ColorSchemePanel(wxWindow *parent,
                    wxWindowID winid,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                    const wxString& name = "CustomColorSchemesPanel")
    {
        Init();

        Create(parent, winid, pos, size, style, name);
    }

    virtual ~ColorSchemePanel() {};

    void AddColorScheme(const std::string &name, const wxString &label, const ColorScheme &defautColor, int properties = CSP_DefautColorBt);
    ColorScheme& GetColorScheme(const std::string &name);
    void SetColorScheme(const std::string &name, const ColorScheme &color);

protected:

    virtual void Init()
    {
        mainGrid = new wxFlexGridSizer(0, 2, 0, 0);
        SetSizer(mainGrid);
    }

    virtual wxSize DoGetBestSize() const
    {
        return wxPanel::DoGetBestSize();
    }

    virtual void OnPaint(wxPaintEvent &ev)
    {
        wxPanel::OnPaint(ev);
    }

    void SetNewColorToButton(wxCommandEvent& event);
    void AdaptFontColor(wxButton *button);

    void CopyColorSchemeContent(wxCommandEvent& event);
    void PasteColorSchemeContent(wxCommandEvent& event);

private:

    std::map< std::string, std::map< std::string, wxButton* > > listOfButtons; ///< Contain the list of buttons. The order is ActiveBt, HoveredBt, NormalBt, DisabledBt
    std::map< std::string, int> listOfProperties;

    wxFlexGridSizer *mainGrid;
};

#endif

#endif
