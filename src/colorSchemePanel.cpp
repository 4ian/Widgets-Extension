#if defined(GD_IDE_ONLY)

#include "colorSchemePanel.h"

#include "WidgetsCommonTools.h"

#ifdef CreateDialog
#undef CreateDialog
#endif

#include <wx/colordlg.h>

void ColorSchemePanel::AddColorScheme(const std::string &name, const wxString &label, const ColorScheme &defautColor, int properties)
{
    listOfProperties[name] = properties;
    listOfButtons[name].clear();

    wxFlexGridSizer *colorSchemeSizer = new wxFlexGridSizer(0, 0, 0, 0);

    wxStaticText *label_ = new wxStaticText(this, wxID_ANY, label + " :");
    mainGrid->Add(label_, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);

    if((properties & CSP_HasFocusedColorBt) != 0)
    {
        long buttonID = wxNewId();
        wxButton *button = new wxButton(this, buttonID, _("Actif"));
        button->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(defautColor.focusedColor));
        AdaptFontColor(button);


        Connect(buttonID,
                wxEVT_COMMAND_BUTTON_CLICKED,
                (wxObjectEventFunction)&ColorSchemePanel::SetNewColorToButton);

        colorSchemeSizer->Add(button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
        listOfButtons[name]["focused"] = button;
    }

    if((properties & CSP_HasHoveredColorBt) != 0)
    {
        long buttonID = wxNewId();
        wxButton *button = new wxButton(this, buttonID, _("Survol�"));
        button->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(defautColor.hoveredColor));
        AdaptFontColor(button);


        Connect(buttonID,
                wxEVT_COMMAND_BUTTON_CLICKED,
                (wxObjectEventFunction)&ColorSchemePanel::SetNewColorToButton);

        colorSchemeSizer->Add(button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
        listOfButtons[name]["hovered"] = button;
    }

    if((properties & CSP_HasUnfocusedColorBt) != 0)
    {
        long buttonID = wxNewId();
        wxButton *button = new wxButton(this, buttonID, _("Normal"));
        button->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(defautColor.unfocusedColor));
        AdaptFontColor(button);


        Connect(buttonID,
                wxEVT_COMMAND_BUTTON_CLICKED,
                (wxObjectEventFunction)&ColorSchemePanel::SetNewColorToButton);

        colorSchemeSizer->Add(button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
        listOfButtons[name]["normal"] = button;
    }

    if((properties & CSP_HasDisabledColorBt) != 0)
    {
        long buttonID = wxNewId();
        wxButton *button = new wxButton(this, buttonID, _("D�sactiv�"));
        button->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(defautColor.disabledColor));
        AdaptFontColor(button);


        Connect(buttonID,
                wxEVT_COMMAND_BUTTON_CLICKED,
                (wxObjectEventFunction)&ColorSchemePanel::SetNewColorToButton);

        colorSchemeSizer->Add(button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
        listOfButtons[name]["disabled"] = button;
    }

    if((properties & CSP_HasAlwaysColorBt) != 0)
    {
        long buttonID = wxNewId();
        wxButton *button = new wxButton(this, buttonID, _("Tout le temps"));
        button->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(defautColor.unfocusedColor));
        AdaptFontColor(button);


        Connect(buttonID,
                wxEVT_COMMAND_BUTTON_CLICKED,
                (wxObjectEventFunction)&ColorSchemePanel::SetNewColorToButton);

        colorSchemeSizer->Add(button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5);
        listOfButtons[name]["always"] = button;

        colorSchemeSizer->AddGrowableRow(0);
    }

    mainGrid->Add(colorSchemeSizer);
}

void ColorSchemePanel::SetNewColorToButton(wxCommandEvent& event)
{
    wxButton *button = dynamic_cast<wxButton*>(event.GetEventObject());
    if(!button)
        return;

    wxColour color = wxGetColourFromUser(this, button->GetBackgroundColour());
    if ( color.IsOk() )
        button->SetBackgroundColour(color);

    if ( color.IsOk() )
    {
        AdaptFontColor(button);
    }
}

void ColorSchemePanel::AdaptFontColor(wxButton *button)
{
    wxColor color = button->GetBackgroundColour();

    if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)
        button->SetForegroundColour(wxColour(255, 255, 255));
    else
        button->SetForegroundColour(wxColour(0, 0, 0));
}

ColorScheme& ColorSchemePanel::GetColorScheme(const std::string &name)
{
    static ColorScheme newColorScheme(sf::Color(255, 255, 255, 255));

    int properties = listOfProperties[name];

    if((properties & CSP_HasAlwaysColorBt) != 0)
    {
        wxASSERT(listOfButtons[name]["always"] != 0);

        newColorScheme.focusedColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["always"]->GetBackgroundColour());
        newColorScheme.hoveredColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["always"]->GetBackgroundColour());
        newColorScheme.unfocusedColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["always"]->GetBackgroundColour());
        newColorScheme.disabledColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["always"]->GetBackgroundColour());
    }
    else
    {
        //First, we add the focused color
        if((properties & CSP_HasFocusedColorBt) != 0)
        {
            newColorScheme.focusedColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["focused"]->GetBackgroundColour());
        }
        else if((properties & CSP_HasHoveredColorBt) != 0)
        {
            newColorScheme.focusedColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["hovered"]->GetBackgroundColour());
        }
        else if((properties & CSP_HasUnfocusedColorBt) != 0)
        {
            newColorScheme.focusedColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["normal"]->GetBackgroundColour());
        }

        //Then, the hovered color
        if((properties & CSP_HasHoveredColorBt) != 0)
        {
            newColorScheme.hoveredColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["hovered"]->GetBackgroundColour());
        }
        else if((properties & CSP_HasUnfocusedColorBt) != 0)
        {
            newColorScheme.hoveredColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["normal"]->GetBackgroundColour());
        }

        //Then, the normal color
        if((properties & CSP_HasUnfocusedColorBt) != 0)
        {
            newColorScheme.unfocusedColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["normal"]->GetBackgroundColour());
        }

        //Finally, the disabled color
        if((properties & CSP_HasDisabledColorBt) != 0)
        {
            newColorScheme.disabledColor = WidgetsCommonTools::GetSfColorFromWxColour(listOfButtons[name]["disabled"]->GetBackgroundColour());
        }
    }

    return newColorScheme;
}

#endif
