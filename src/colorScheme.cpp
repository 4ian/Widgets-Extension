/*
Widgets Extension
Extension providing graphical widgets.

Copyright (c) 2011 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
    1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
*/

#include <iostream>

#include "colorScheme.h"

#include "GDL/tinyxml.h"
#include "GDL/CommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/string.h>
#endif

using namespace std;

ColorScheme::ColorScheme(sf::Color focused, sf::Color unfocused, sf::Color hovered, sf::Color disabled) :
    focusedColor(focused),
    unfocusedColor(unfocused),
    hoveredColor(hovered),
    disabledColor(disabled)
{

}

ColorScheme::ColorScheme(sf::Color all) :
    focusedColor(all),
    unfocusedColor(all),
    hoveredColor(all),
    disabledColor(all)
{

}

void ColorScheme::LoadFromXml(const TiXmlElement * elem)
{
	//Focused Color
	if ( elem->FirstChildElement( "FocusedColor" ) == NULL ||
			elem->FirstChildElement( "FocusedColor" )->Attribute("r") == NULL ||
			elem->FirstChildElement( "FocusedColor" )->Attribute("g") == NULL ||
			elem->FirstChildElement( "FocusedColor" )->Attribute("b") == NULL )
	{
		cout << "Widgets Extension Warning : Unable to load focused color informations from a color scheme.";
	}
	else
	{
		int r = 0xff;
		int g = 0xff;
		int b = 0xff;

		elem->FirstChildElement("FocusedColor")->QueryIntAttribute("r", &r);
		elem->FirstChildElement("FocusedColor")->QueryIntAttribute("g", &g);
		elem->FirstChildElement("FocusedColor")->QueryIntAttribute("b", &b);

		focusedColor.r = r;
		focusedColor.g = g;
		focusedColor.b = b;
	}

	//Unfocused Color (Normal)
	if ( elem->FirstChildElement( "UnfocusedColor" ) == NULL ||
			elem->FirstChildElement( "UnfocusedColor" )->Attribute("r") == NULL ||
			elem->FirstChildElement( "UnfocusedColor" )->Attribute("g") == NULL ||
			elem->FirstChildElement( "UnfocusedColor" )->Attribute("b") == NULL )
	{
		cout << "Widgets Extension Warning : Unable to load unfocused color informations from a color scheme.";
	}
	else
	{
		int r = 0xff;
		int g = 0xff;
		int b = 0xff;

		elem->FirstChildElement("UnfocusedColor")->QueryIntAttribute("r", &r);
		elem->FirstChildElement("UnfocusedColor")->QueryIntAttribute("g", &g);
		elem->FirstChildElement("UnfocusedColor")->QueryIntAttribute("b", &b);

		unfocusedColor.r = r;
		unfocusedColor.g = g;
		unfocusedColor.b = b;
	}

	//Hovered Color
	if ( elem->FirstChildElement( "HoveredColor" ) == NULL ||
			elem->FirstChildElement( "HoveredColor" )->Attribute("r") == NULL ||
			elem->FirstChildElement( "HoveredColor" )->Attribute("g") == NULL ||
			elem->FirstChildElement( "HoveredColor" )->Attribute("b") == NULL )
	{
		cout << "Widgets Extension Warning : Unable to load hovered color informations from a color scheme.";
	}
	else
	{
		int r = 0xff;
		int g = 0xff;
		int b = 0xff;

		elem->FirstChildElement("HoveredColor")->QueryIntAttribute("r", &r);
		elem->FirstChildElement("HoveredColor")->QueryIntAttribute("g", &g);
		elem->FirstChildElement("HoveredColor")->QueryIntAttribute("b", &b);

		hoveredColor.r = r;
		hoveredColor.g = g;
		hoveredColor.b = b;
	}

	//Disabled Color
	if ( elem->FirstChildElement( "DisabledColor" ) == NULL ||
			elem->FirstChildElement( "DisabledColor" )->Attribute("r") == NULL ||
			elem->FirstChildElement( "DisabledColor" )->Attribute("g") == NULL ||
			elem->FirstChildElement( "DisabledColor" )->Attribute("b") == NULL )
	{
		cout << "Widgets Extension Warning : Unable to load disabled color informations from a color scheme.";
	}
	else
	{
		int r = 0xff;
		int g = 0xff;
		int b = 0xff;

		elem->FirstChildElement("DisabledColor")->QueryIntAttribute("r", &r);
		elem->FirstChildElement("DisabledColor")->QueryIntAttribute("g", &g);
		elem->FirstChildElement("DisabledColor")->QueryIntAttribute("b", &b);

		disabledColor.r = r;
		disabledColor.g = g;
		disabledColor.b = b;
	}
}

#if defined(GD_IDE_ONLY)
void ColorScheme::SaveToXml(TiXmlElement * elem)
{
    //Focused Color
    TiXmlElement * focusedColorElem = new TiXmlElement( "FocusedColor" );
    elem->LinkEndChild( focusedColorElem );
    focusedColorElem->SetAttribute("r", focusedColor.r);
    focusedColorElem->SetAttribute("g", focusedColor.g);
    focusedColorElem->SetAttribute("b", focusedColor.b);

    //Unfocused Color
    TiXmlElement * unfocusedColorElem = new TiXmlElement( "UnfocusedColor" );
    elem->LinkEndChild( unfocusedColorElem );
    unfocusedColorElem->SetAttribute("r", unfocusedColor.r);
    unfocusedColorElem->SetAttribute("g", unfocusedColor.g);
    unfocusedColorElem->SetAttribute("b", unfocusedColor.b);

    //Hovered Color
    TiXmlElement * hoveredColorElem = new TiXmlElement( "HoveredColor" );
    elem->LinkEndChild( hoveredColorElem );
    hoveredColorElem->SetAttribute("r", hoveredColor.r);
    hoveredColorElem->SetAttribute("g", hoveredColor.g);
    hoveredColorElem->SetAttribute("b", hoveredColor.b);

    //Disabled Color
    TiXmlElement * disabledColorElem = new TiXmlElement( "DisabledColor" );
    elem->LinkEndChild( disabledColorElem );
    disabledColorElem->SetAttribute("r", disabledColor.r);
    disabledColorElem->SetAttribute("g", disabledColor.g);
    disabledColorElem->SetAttribute("b", disabledColor.b);
}
#endif

#if defined(GD_IDE_ONLY)

const wxString& ColorScheme::ToWxString()
{
    static wxString result;

    result = "";

    result += wxString(ToString<int>(focusedColor.r).c_str()) + ";" + wxString(ToString<int>(focusedColor.g).c_str()) + ";" + wxString(ToString<int>(focusedColor.b).c_str()) + ";" + wxString(ToString<int>(focusedColor.a).c_str()) + "/";
    result += wxString(ToString<int>(hoveredColor.r).c_str()) + ";" + wxString(ToString<int>(hoveredColor.g).c_str()) + ";" + wxString(ToString<int>(hoveredColor.b).c_str()) + ";" + wxString(ToString<int>(hoveredColor.a).c_str()) + "/";
    result += wxString(ToString<int>(unfocusedColor.r).c_str()) + ";" + wxString(ToString<int>(unfocusedColor.g).c_str()) + ";" + wxString(ToString<int>(unfocusedColor.b).c_str()) + ";" + wxString(ToString<int>(unfocusedColor.a).c_str()) + "/";
    result += wxString(ToString<int>(disabledColor.r).c_str()) + ";" + wxString(ToString<int>(disabledColor.g).c_str()) + ";" + wxString(ToString<int>(disabledColor.b).c_str()) + ";" + wxString(ToString<int>(disabledColor.a).c_str());

    return result;
}

void ColorScheme::FromWxString(wxString &str)
{
    std::vector<std::string> colorsVector = SplitString<std::string>(ToString(str), '/');

    for(unsigned int a = 0; a < 4; a++)
    {
        if(colorsVector.size() < a)
            return;

        std::vector<std::string> composantVector = SplitString<std::string>(colorsVector[a], ';');

        if(composantVector.size() < 4)
            return;

        if(a == 0)
        {
            focusedColor.r = ToInt(composantVector[0]);
            focusedColor.g = ToInt(composantVector[1]);
            focusedColor.b = ToInt(composantVector[2]);
            focusedColor.a = ToInt(composantVector[3]);
        }
        else if(a == 1)
        {
            hoveredColor.r = ToInt(composantVector[0]);
            hoveredColor.g = ToInt(composantVector[1]);
            hoveredColor.b = ToInt(composantVector[2]);
            hoveredColor.a = ToInt(composantVector[3]);
        }
        else if(a == 2)
        {
            unfocusedColor.r = ToInt(composantVector[0]);
            unfocusedColor.g = ToInt(composantVector[1]);
            unfocusedColor.b = ToInt(composantVector[2]);
            unfocusedColor.a = ToInt(composantVector[3]);
        }
        else if(a == 3)
        {
            disabledColor.r = ToInt(composantVector[0]);
            disabledColor.g = ToInt(composantVector[1]);
            disabledColor.b = ToInt(composantVector[2]);
            disabledColor.a = ToInt(composantVector[3]);
        }
    }
}

#endif
