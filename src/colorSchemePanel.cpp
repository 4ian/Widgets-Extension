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

#include "colorSchemePanel.h"

#include "WidgetsCommonTools.h"
#include "GDL/CommonTools.h"

#ifdef CreateDialog
#undef CreateDialog
#endif

#include <wx/colordlg.h>
#include <wx/clipbrd.h>
#include <wx/dataobj.h>
#include <wx/log.h>

#include <algorithm>

#include "customwidgets/DataBitmapButton.h"

void ColorSchemePanel::Init()
{
    //Main Grid initialization
    mainGrid = new wxFlexGridSizer(0, 2, 0, 0);
    SetSizer(mainGrid);

    //Initialize menu providing advanced features
    advanceFeatureMenu = new wxMenu();

    copyBtID = wxNewId();
    pasteBtID = wxNewId();
    generateColorsBtID = wxNewId();

    copyBt = new wxMenuItem(advanceFeatureMenu, copyBtID, "Copier cette ligne");
    pasteBt = new wxMenuItem(advanceFeatureMenu, pasteBtID, "Coller dans cette ligne");
    generateColorsBt = new wxMenuItem(advanceFeatureMenu, generateColorsBtID, "G�n�rer les couleurs automatiquement");

    advanceFeatureMenu->Append(copyBt);
    advanceFeatureMenu->Append(pasteBt);
    advanceFeatureMenu->AppendSeparator();
    advanceFeatureMenu->Append(generateColorsBt);
}

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

    //Bouton de copie
    long advancedButtonID = wxNewId();
    DataBitmapButton<std::string> *advancedButton = new DataBitmapButton<std::string>(this, advancedButtonID, wxBitmap("res/1downarrow1.png", wxBITMAP_TYPE_PNG));
    advancedButton->SetDataStored(name);

    Connect(advancedButtonID,
            wxEVT_COMMAND_BUTTON_CLICKED,
            (wxObjectEventFunction)&ColorSchemePanel::PopupAdvancedFeatureMenu);

    colorSchemeSizer->Add(advancedButton, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);

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

void ColorSchemePanel::SetColorScheme(const std::string &name, const ColorScheme &color)
{
    if(listOfButtons.count(name) == 0)
        return;

    int properties = listOfProperties[name];

    if((properties & CSP_HasAlwaysColorBt) != 0)
    {
        wxASSERT(listOfButtons[name]["always"] != 0);

        listOfButtons[name]["always"]->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(color.unfocusedColor));
    }
    else
    {
        if((properties & CSP_HasFocusedColorBt) != 0)
        {
            listOfButtons[name]["focused"]->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(color.focusedColor));
        }

        if((properties & CSP_HasHoveredColorBt) != 0)
        {
            listOfButtons[name]["hovered"]->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(color.hoveredColor));
        }

        if((properties & CSP_HasUnfocusedColorBt) != 0)
        {
            listOfButtons[name]["normal"]->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(color.unfocusedColor));
        }

        if((properties & CSP_HasDisabledColorBt) != 0)
        {
            listOfButtons[name]["disabled"]->SetBackgroundColour(WidgetsCommonTools::GetWxColourFromSfColor(color.disabledColor));
        }
    }
}

void ColorSchemePanel::PopupAdvancedFeatureMenu(wxCommandEvent& event)
{
    DataBitmapButton<std::string> *button = dynamic_cast<DataBitmapButton<std::string>* >(event.GetEventObject());
    if(!button)
        return;

    wxPoint position(0, button->GetSize().GetHeight() - 1);

    int actionToDo = button->GetPopupMenuSelectionFromUser(*advanceFeatureMenu, position);

    if(actionToDo == copyBtID)
        CopyColorSchemeContent(event);
    else if(actionToDo == pasteBtID)
        PasteColorSchemeContent(event);
    else if(actionToDo == generateColorsBtID)
        GenerateColorScheme(event);
}

void ColorSchemePanel::CopyColorSchemeContent(wxCommandEvent& event)
{
    DataBitmapButton<std::string> *button = dynamic_cast<DataBitmapButton<std::string>* >(event.GetEventObject());
    if(!button)
        return;

    std::string name = button->GetDataStored();

    ColorScheme colorScheme = GetColorScheme(name);

    if(wxTheClipboard->Open())
    {
        wxTheClipboard->Clear();

        wxTheClipboard->SetData(new wxTextDataObject(colorScheme.ToWxString()));
        wxTheClipboard->Close();
    }
}

void ColorSchemePanel::PasteColorSchemeContent(wxCommandEvent& event)
{
    DataBitmapButton<std::string> *button = dynamic_cast<DataBitmapButton<std::string>* >(event.GetEventObject());
    if(!button)
        return;

    std::string name = button->GetDataStored();

    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported( wxDF_TEXT ))
        {
            wxTextDataObject dataStored;
            wxTheClipboard->GetData( dataStored );
            wxString schemeStr = dataStored.GetText();

            ColorScheme newColorScheme(sf::Color(255, 255, 255, 255));
            newColorScheme.FromWxString(schemeStr);

            SetColorScheme(name, newColorScheme);
        }
        wxTheClipboard->Close();
    }
}

void ColorSchemePanel::GenerateColorScheme(wxCommandEvent& event)
{
    DataBitmapButton<std::string> *button = dynamic_cast<DataBitmapButton<std::string>* >(event.GetEventObject());
    if(!button)
        return;

    std::string name = button->GetDataStored();

    wxColour activeColor = wxGetColourFromUser(this, wxColour(255, 255, 255, 255), _("S�lectionnez la couleur � l'�tat actif"));
    if ( !activeColor.IsOk() )
        return;

    wxColour normalColor = wxGetColourFromUser(this, wxColour(255, 255, 255, 255), _("S�lectionnez la couleur � l'�tat normal"));
    if ( !normalColor.IsOk() )
        return;

    //Hovered color generation
    wxColour hoveredColor((normalColor.Red() + activeColor.Red())/2,
                          (normalColor.Green() + activeColor.Green())/2,
                          (normalColor.Blue() + activeColor.Blue())/2,
                          std::max(normalColor.Alpha(), activeColor.Alpha()));

    //Disabled color generation
    wxColour disabledColor(((normalColor.Red() + normalColor.Green() + normalColor.Blue())/3 + 125)/2,
                          ((normalColor.Red() + normalColor.Green() + normalColor.Blue())/3 + 125)/2,
                          ((normalColor.Red() + normalColor.Green() + normalColor.Blue())/3 + 125)/2,
                          normalColor.Alpha());

    ColorScheme scheme(WidgetsCommonTools::GetSfColorFromWxColour(activeColor),
                       WidgetsCommonTools::GetSfColorFromWxColour(normalColor),
                       WidgetsCommonTools::GetSfColorFromWxColour(hoveredColor),
                       WidgetsCommonTools::GetSfColorFromWxColour(disabledColor));

    SetColorScheme(name, scheme);
}

#endif
