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

    void AddColorScheme(const std::string &name, const wxString &label, const ColorScheme &defautColor, ColorSchemeProperties properties = CSP_DefautColorBt);
    ColorScheme& GetColorScheme(const std::string &name);

protected:

    virtual void Init()
    {
        mainGrid = new wxFlexGridSizer(0, 1, 0, 0);
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

private:

    std::map< std::string, std::map< std::string, wxButton* > > listOfButtons; ///< Contain the list of buttons. The order is ActiveBt, HoveredBt, NormalBt, DisabledBt
    std::map< std::string, ColorSchemeProperties> listOfProperties;

    wxFlexGridSizer *mainGrid;
};

#endif

#endif
