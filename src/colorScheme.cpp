#include <iostream>

#include "colorScheme.h"

#include "GDL/tinyxml.h"

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
