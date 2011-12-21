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
#include <cmath>

//#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GDL/Object.h"

#include "GDL/ImageManager.h"
#include "GDL/tinyxml.h"
#include "GDL/FontManager.h"
#include "GDL/Position.h"
#include "GDL/RotatedRectangle.h"
#include "GDL/RuntimeScene.h"
#include "GDL/CommonTools.h"
#include "GDL/XmlMacros.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>

#include "SFGUI/CheckButton.hpp"
#include "SFGUI/Engine.hpp"
#include "SFGUI/Context.hpp"

#include "../WidgetWrapper.h"

#include <string>
#include "CheckBoxObject.h"

#include "../colorScheme.h"
#include "../Manager.h"
#include "../WidgetsCommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/wx.h>
#include "GDL/ArbitraryResourceWorker.h"
#include "GDL/MainEditorCommand.h"
#include "CheckBoxObjectEditor.h"
#endif

CheckBoxObject::CheckBoxObject(std::string name_) :
Object(name_),
borderWidth(1),
padding(5)
{
    //Create the SFGUI CheckBox object
    sfg::CheckButton::Ptr tmpObj = sfg::CheckButton::Create("Texte");
    obje = new WidgetWrapper<sfg::CheckButton>(tmpObj);

    //WidgetManager::getInstance()->mainWidget->Pack(obje->Get());

    SetString("Case � cocher");

    //Default size of the object
    SetWidth(180);
    SetHeight(24);

    fontSize = 12;

    //Colors "Schemes"
    borderColor = new ColorScheme(sf::Color(146, 147, 151, 255),
                                  sf::Color(146, 147, 151, 255),
                                  sf::Color(146, 147, 151, 255),
                                  sf::Color(173, 173, 173, 255));

    backgroundColor = new ColorScheme(sf::Color(255, 255, 255, 255),
                                      sf::Color(201, 201, 201, 255),
                                      sf::Color(230, 230, 230, 255),
                                      sf::Color(140, 140, 140, 255));

    textColor = new ColorScheme(sf::Color(0, 0, 0, 255),
                                sf::Color(0, 0, 0, 255),
                                sf::Color(0, 0, 0, 255),
                                sf::Color(100, 100, 100, 255));

    checkColor = new ColorScheme(sf::Color(122, 122, 122, 255));

    SetBoxSize(14);
    SetCheckSignSize(6);

    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    obje->Get()->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateProperties();
}

CheckBoxObject::CheckBoxObject(const CheckBoxObject &other) : Object(other)
{
    Init(other);
}

CheckBoxObject& CheckBoxObject::operator=(const CheckBoxObject &other)
{
    Object::operator=(other);

    if( (this) != &other )
        Init(other);

    return *this;
}

void CheckBoxObject::Init(const CheckBoxObject &other)
{
    position = other.position;
    fontName = other.fontName;
    sfg::CheckButton::Ptr tmpObj = sfg::CheckButton::Create(other.obje->Get()->GetLabel());
    obje = new WidgetWrapper<sfg::CheckButton>(tmpObj);
    backgroundColor = new ColorScheme(*(other.backgroundColor));
    borderColor = new ColorScheme(*(other.borderColor));
    textColor = new ColorScheme(*(other.textColor));
    checkColor = new ColorScheme(*(other.checkColor));
    SetChecked(other.IsChecked());
    width = other.width;
    height = other.height;
    fontSize = other.fontSize;
    borderWidth = other.borderWidth;
    padding = other.padding;
    boxSize = other.boxSize;
    checkSignSize = other.checkSignSize;

    obje->Get()->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateSize();
    UpdateProperties();
}

void CheckBoxObject::ConnectSignals()
{
    obje->Get()->OnClick.Connect(&CheckBoxObject::OnMouseClick, this);
    obje->Get()->OnStateChange.Connect(&CheckBoxObject::OnStateChanged, this);
    obje->Get()->OnToggle.Connect(&CheckBoxObject::OnCheckChanged, this);
}

bool CheckBoxObject::SIG_OnStateChanged(const std::string &newStateVar, RuntimeScene &scene)
{
    if(eventsInformations.stateChanged.fired)
    {

        if(newStateVar != "")
        {
            std::string newStateStr = "";
            if(obje->Get()->GetState() == sfg::Widget::ACTIVE)
                newStateStr = "Active";
            else if(obje->Get()->GetState() == sfg::Widget::PRELIGHT)
                newStateStr = "Hovered";
            else if(obje->Get()->GetState() == sfg::Widget::NORMAL)
                newStateStr = "Normal";
            else if(obje->Get()->GetState() == sfg::Widget::INSENSITIVE)
                newStateStr = "Disabled";
            else
                newStateStr = "Unknown";

            scene.variables.ObtainVariable(newStateVar).SetString(newStateStr);
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool CheckBoxObject::SIG_OnClick(const std::string &mouseButtonVar, const std::string &xPosVar, const std::string &yPosVar, RuntimeScene &scene)
{
    if(eventsInformations.mouseClick.fired)
    {
        if(mouseButtonVar != "")
        {
            if(eventsInformations.mouseClick.button == sf::Mouse::Left)
                scene.variables.ObtainVariable(mouseButtonVar).SetString("Left");
            else if(eventsInformations.mouseClick.button == sf::Mouse::Right)
                scene.variables.ObtainVariable(mouseButtonVar).SetString("Right");
            else if(eventsInformations.mouseClick.button == sf::Mouse::Middle)
                scene.variables.ObtainVariable(mouseButtonVar).SetString("Middle");
            else
                scene.variables.ObtainVariable(mouseButtonVar).SetString("Unknown");
        }

        if(xPosVar != "")
            scene.variables.ObtainVariable(xPosVar).SetValue(eventsInformations.mouseClick.x);

        if(yPosVar != "")
            scene.variables.ObtainVariable(yPosVar).SetValue(eventsInformations.mouseClick.y);

        return true;
    }
    else
    {
        return false;
    }
}

bool CheckBoxObject::SIG_OnCheckChanged(RuntimeScene &scene)
{
    if(eventsInformations.checkChanged.fired)
        return true;
    else
        return false;
}

void CheckBoxObject::OnMouseClick()
{
    eventsInformations.mouseClick.fired = true;

    if(sf::Mouse::IsButtonPressed(sf::Mouse::Left))
        eventsInformations.mouseClick.button = sf::Mouse::Left;
    else if(sf::Mouse::IsButtonPressed(sf::Mouse::Right))
        eventsInformations.mouseClick.button = sf::Mouse::Right;
    else
        eventsInformations.mouseClick.button = sf::Mouse::Middle;

    eventsInformations.mouseClick.x = sf::Mouse::GetPosition(*(m_scene->renderWindow)).x;
    eventsInformations.mouseClick.y = sf::Mouse::GetPosition(*(m_scene->renderWindow)).y;
}

void CheckBoxObject::OnStateChanged()
{
    eventsInformations.stateChanged.fired = true;
}

void CheckBoxObject::OnCheckChanged()
{
    eventsInformations.checkChanged.fired = true;
}

void CheckBoxObject::ResetEventInformations()
{
    eventsInformations.mouseClick.fired = false;
    eventsInformations.stateChanged.fired = false;
    eventsInformations.checkChanged.fired = false;
}

CheckBoxObject::~CheckBoxObject()
{
    delete borderColor;
    delete backgroundColor;
    delete textColor;
    delete checkColor;

    delete obje;
}

void CheckBoxObject::UpdateSize()
{
    obje->Get()->SetRequisition();
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
    obje->Get()->SetAllocation(sf::FloatRect(GetX(), GetY(), GetWidth(), GetHeight()));
}

void CheckBoxObject::LoadFromXml(const TiXmlElement * elem)
{
    if ( elem->FirstChildElement( "String" ) == NULL ||
         elem->FirstChildElement( "String" )->Attribute("value") == NULL )
    {
        cout << "Les informations concernant le texte d'un objet Text manquent.";
    }
    else
    {
        SetString(elem->FirstChildElement("String")->Attribute("value"));
    }

    if ( elem->FirstChildElement( "Checked" ) == NULL ||
         elem->FirstChildElement( "Checked" )->Attribute("value") == NULL )
    {
        cout << "Les informations concernant le texte d'un objet Text manquent.";
    }
    else
    {
        int checked = 0;
        elem->FirstChildElement("Checked")->QueryIntAttribute("value", &checked);

        SetChecked(static_cast<bool>(checked));
    }

    if ( elem->FirstChildElement( "Font" ) == NULL ||
         elem->FirstChildElement( "Font" )->Attribute("value") == NULL )
    {
        cout << "Les informations concernant la police d'un objet Text manquent.";
    }
    else
    {
        SetFont(elem->FirstChildElement("Font")->Attribute("value"));
    }

    if ( elem->FirstChildElement( "CharacterSize" ) == NULL ||
         elem->FirstChildElement( "CharacterSize" )->Attribute("value") == NULL )
    {
        cout << "Les informations concernant la taille du texte d'un objet Text manquent.";
    }
    else
    {
        float size = 12;
        elem->FirstChildElement("CharacterSize")->QueryFloatAttribute("value", &size);

        SetCharacterSize(size);
    }

    //Background Scheme
    if ( elem->FirstChildElement( "BackgroundColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load background color full scheme.";
    }
    else
    {
        backgroundColor->LoadFromXml(elem->FirstChildElement( "BackgroundColorScheme" ));
    }

    //Border Scheme
    if ( elem->FirstChildElement( "BorderColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load border color full scheme.";
    }
    else
    {
        borderColor->LoadFromXml(elem->FirstChildElement( "BorderColorScheme" ));
    }

    //Text Scheme
    if ( elem->FirstChildElement( "TextColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load text color full scheme.";
    }
    else
    {
        textColor->LoadFromXml(elem->FirstChildElement( "TextColorScheme" ));
    }

    //Check Scheme
    if ( elem->FirstChildElement( "CheckColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load check color full scheme.";
    }
    else
    {
        checkColor->LoadFromXml(elem->FirstChildElement( "CheckColorScheme" ));
    }

    if ( elem->FirstChildElement( "BorderWidth" ) == NULL ||
         elem->FirstChildElement( "BorderWidth" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load width of border";
    }
    else
    {
        float borderW = 12;
        elem->FirstChildElement("BorderWidth")->QueryFloatAttribute("value", &borderW);

        SetBorderWidth(borderW);
    }

    if ( elem->FirstChildElement( "Padding" ) == NULL ||
         elem->FirstChildElement( "Padding" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load padding";
    }
    else
    {
        float pad = 12;
        elem->FirstChildElement("Padding")->QueryFloatAttribute("value", &pad);

        SetPadding(pad);
    }

    if ( elem->FirstChildElement( "BoxSize" ) == NULL ||
         elem->FirstChildElement( "BoxSize" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load box size";
    }
    else
    {
        int boxS = 14;
        elem->FirstChildElement("BoxSize")->QueryIntAttribute("value", &boxS);

        SetBoxSize(boxS);
    }

    if ( elem->FirstChildElement( "CheckSignSize" ) == NULL ||
         elem->FirstChildElement( "CheckSignSize" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load check sign size";
    }
    else
    {
        int checkS = 6;
        elem->FirstChildElement("CheckSignSize")->QueryIntAttribute("value", &checkS);

        SetCheckSignSize(checkS);
    }

    UpdateProperties();
}

#if defined(GD_IDE_ONLY)
void CheckBoxObject::SaveToXml(TiXmlElement * elem)
{
    TiXmlElement * str = new TiXmlElement( "String" );
    elem->LinkEndChild( str );
    str->SetAttribute("value", GetString().c_str());

    TiXmlElement * checked = new TiXmlElement( "Checked" );
    elem->LinkEndChild( checked );
    checked->SetAttribute("value", static_cast<bool>(IsChecked()));

    TiXmlElement * font = new TiXmlElement( "Font" );
    elem->LinkEndChild( font );
    font->SetAttribute("value", GetFont().c_str());

    TiXmlElement * characterSize = new TiXmlElement( "CharacterSize" );
    elem->LinkEndChild( characterSize );
    characterSize->SetAttribute("value", GetCharacterSize());

    TiXmlElement * backgroundColorElem = new TiXmlElement( "BackgroundColorScheme" );
    elem->LinkEndChild( backgroundColorElem );
    backgroundColor->SaveToXml(backgroundColorElem);

    TiXmlElement * borderColorElem = new TiXmlElement( "BorderColorScheme" );
    elem->LinkEndChild( borderColorElem );
    borderColor->SaveToXml(borderColorElem);

    TiXmlElement * textColorElem = new TiXmlElement( "TextColorScheme" );
    elem->LinkEndChild( textColorElem );
    textColor->SaveToXml(textColorElem);

    TiXmlElement * checkColorElem = new TiXmlElement( "CheckColorScheme" );
    elem->LinkEndChild( checkColorElem );
    checkColor->SaveToXml(checkColorElem);

    TiXmlElement * borderWidthElem = new TiXmlElement( "BorderWidth" );
    elem->LinkEndChild( borderWidthElem );
    borderWidthElem->SetAttribute("value", GetBorderWidth());

    TiXmlElement * paddingElem = new TiXmlElement( "Padding" );
    elem->LinkEndChild( paddingElem );
    paddingElem->SetAttribute("value", GetPadding());

    TiXmlElement * boxSizeElem = new TiXmlElement( "BoxSize" );
    elem->LinkEndChild( boxSizeElem );
    boxSizeElem->SetAttribute("value", GetBoxSize());

    TiXmlElement * checkSignSizeElem = new TiXmlElement( "CheckSignSize" );
    elem->LinkEndChild( checkSignSizeElem );
    checkSignSizeElem->SetAttribute("value", GetCheckSignSize());
}
#endif

bool CheckBoxObject::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

bool CheckBoxObject::LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

/**
 * Update animation and direction from the inital position
 */
bool CheckBoxObject::InitializeFromInitialPosition(const InitialPosition & position)
{
    return true;
}

/**
 * Render object at runtime
 */
bool CheckBoxObject::Draw( sf::RenderTarget & renderTarget )
{
    //Don't draw anything if hidden
    if ( hidden ) return true;

    sfg::CullingTarget renderer(renderTarget);
    renderer.Cull(false);

    obje->Get()->Expose(renderer);

    return true;
}

#if defined(GD_IDE_ONLY)
/**
 * Render object at edittime
 */
bool CheckBoxObject::DrawEdittime(sf::RenderTarget & renderTarget)
{
    sfg::CullingTarget renderer(renderTarget);
    renderer.Cull(false);

    obje->Get()->Expose(renderer);

    return true;
}

void CheckBoxObject::ExposeResources(ArbitraryResourceWorker & worker)
{
    worker.ExposeResource(fontName);
}

bool CheckBoxObject::GenerateThumbnail(const Game & game, wxBitmap & thumbnail)
{
    thumbnail = wxBitmap("res/Widgets/CheckBox_logo_small.png", wxBITMAP_TYPE_ANY);

    return true;
}

void CheckBoxObject::EditObject( wxWindow* parent, Game & game, MainEditorCommand & mainEditorCommand )
{
    CheckBoxObjectEditor dialog(parent, game, *this, mainEditorCommand);
    dialog.ShowModal();

    UpdateProperties();
    UpdateSize();
}

wxPanel * CheckBoxObject::CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position )
{
    return NULL;
}

void CheckBoxObject::UpdateInitialPositionFromPanel(wxPanel * panel, InitialPosition & position)
{
}

void CheckBoxObject::GetPropertyForDebugger(unsigned int propertyNb, string & name, string & value) const
{
    if      ( propertyNb == 0 ) {name = _("Coch�");                     if(IsChecked()) value = "yes"; else value = "no";}
    else if ( propertyNb == 1 ) {name = _("Texte");                     value = GetString();}
    else if ( propertyNb == 2 )
    {
        name = _("Etat");
        if(obje->Get()->GetState() == sfg::Widget::ACTIVE)
            value = _("Actif");
        else if(obje->Get()->GetState() == sfg::Widget::PRELIGHT)
            value = _("Survol�");
        else if(obje->Get()->GetState() == sfg::Widget::NORMAL)
            value = _("Normal");
        else if(obje->Get()->GetState() == sfg::Widget::INSENSITIVE)
            value = _("D�sactiv�");
        else
            value = _("Inconnu");
    }
    else if ( propertyNb == 3 ) {name = _("Taille du texte");           value = ToString<int>(GetCharacterSize());}

}

bool CheckBoxObject::ChangeProperty(unsigned int propertyNb, string newValue)
{
    if      ( propertyNb == 1 ) { SetString(newValue); return true; }
    else if ( propertyNb == 3 ) { SetCharacterSize(ToInt(newValue)); }
    return true;
}

unsigned int CheckBoxObject::GetNumberOfProperties() const
{
    return 4;
}
#endif

void CheckBoxObject::OnPositionChanged()
{
    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
}

void CheckBoxObject::SetString(const std::string &str)
{
    obje->Get()->SetLabel(str);
}

std::string CheckBoxObject::GetString() const
{
    return obje->Get()->GetLabel().ToAnsiString();
}

void CheckBoxObject::SetChecked(bool is)
{
    obje->Get()->SetActive(is);
}

bool CheckBoxObject::IsChecked() const
{
    return obje->Get()->IsActive();
}

/**
 * CheckBoxObject provides a basic bounding box.
 */
std::vector<RotatedRectangle> CheckBoxObject::GetHitBoxes() const
{
    std::vector<RotatedRectangle> boxes;
    RotatedRectangle rectangle;
    rectangle.angle = GetAngle()*3.14/180.0f;
    rectangle.center.x = GetX()+GetCenterX();
    rectangle.center.y = GetY()+GetCenterY();
    rectangle.halfSize.x = GetWidth()/2;
    rectangle.halfSize.y = GetHeight()/2;

    boxes.push_back(rectangle);
    return boxes;
}

/**
 * Get the real X position of the sprite
 */
float CheckBoxObject::GetDrawableX() const
{
    return GetX();
}

/**
 * Get the real Y position of the text
 */
float CheckBoxObject::GetDrawableY() const
{
    return GetY();
}

/**
 * Width is the width of the current sprite.
 */
/*float CheckBoxObject::GetWidth() const
{
    return text.GetRect().Width;
}*/

/**
 * Height is the height of the current sprite.
 */
/*float CheckBoxObject::GetHeight() const
{
    return text.GetRect().Height;
}*/

/**
 * X center is computed with text rectangle
 */
float CheckBoxObject::GetCenterX() const
{
    return GetWidth() / 2;
}

/**
 * Y center is computed with text rectangle
 */
float CheckBoxObject::GetCenterY() const
{
    return GetHeight() / 2;
}

void CheckBoxObject::SetFont(string fontName_)
{
    fontName = fontName_;

    UpdateProperties();

    /*FontManager * fontManager = FontManager::GetInstance();
    text.SetFont(*fontManager->GetFont(fontName));*/
    //text.SetOrigin(text.GetRect().Width/2, text.GetRect().Height/2);
}

void CheckBoxObject::UpdateTime(float ElapsedTime)
{
    ResetEventInformations();

    //Process all events received by the window
    const std::vector<sf::Event> & events = m_scene->GetRenderTargetEvents();
    unsigned int i = 0;
    for (i = 0; i < events.size(); ++i)
    {
        if(events[i].Type == sf::Event::MouseButtonPressed)
        {
            sf::Event event;
            event.Type = sf::Event::MouseButtonPressed;
            event.MouseButton.Button = events[i].MouseButton.Button;
            event.MouseButton.X = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseButton.X, events[i].MouseButton.Y), GetLayer()).x;
            event.MouseButton.Y = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseButton.X, events[i].MouseButton.Y), GetLayer()).y;

            obje->Get()->HandleEvent(event);
        }
        else if(events[i].Type == sf::Event::MouseButtonReleased)
        {
            sf::Event event;
            event.Type = sf::Event::MouseButtonReleased;
            event.MouseButton.Button = events[i].MouseButton.Button;
            event.MouseButton.X = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseButton.X, events[i].MouseButton.Y), GetLayer()).x;
            event.MouseButton.Y = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseButton.X, events[i].MouseButton.Y), GetLayer()).y;

            obje->Get()->HandleEvent(event);
        }
        else if(events[i].Type == sf::Event::MouseMoved)
        {
            sf::Event event;
            event.Type = sf::Event::MouseMoved;
            event.MouseMove.X = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseMove.X, events[i].MouseMove.Y), GetLayer()).x;
            event.MouseMove.Y = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseMove.X, events[i].MouseMove.Y), GetLayer()).y;

            obje->Get()->HandleEvent(event);
        }
        else
            obje->Get()->HandleEvent(events[i]);
    }


}


void CheckBoxObject::UpdateProperties()
{
    //Update BackgroundColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId(), "BackgroundColor", backgroundColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":PRELIGHT", "BackgroundColor", backgroundColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":ACTIVE", "BackgroundColor", backgroundColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":INSENSITIVE", "BackgroundColor", backgroundColor->disabledColor );

    //Update BorderColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId(), "BorderColor", borderColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":PRELIGHT", "BorderColor", borderColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":ACTIVE", "BorderColor", borderColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":INSENSITIVE", "BorderColor", borderColor->disabledColor );

    //Update TextColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + "", "Color", textColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":PRELIGHT", "Color", textColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":ACTIVE", "Color", textColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":INSENSITIVE", "Color", textColor->disabledColor );

    //Update CheckColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + "", "CheckColor", checkColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":PRELIGHT", "CheckColor", checkColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":ACTIVE", "CheckColor", checkColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "CheckButton#" + obje->Get()->GetId() + ":INSENSITIVE", "CheckColor", checkColor->disabledColor );

    //Update font size
    sfg::Context::Get().GetEngine().SetProperty<unsigned int>("CheckButton#" + obje->Get()->GetId() + "", "FontSize", GetCharacterSize());
    sfg::Context::Get().GetEngine().SetProperty<std::string>("CheckButton#" + obje->Get()->GetId(), "FontName", std::string("gdres:") + GetFont());

    //Update border width and padding
    sfg::Context::Get().GetEngine().SetProperty<float>("CheckButton#" + obje->Get()->GetId(), "BorderWidth", static_cast<float>(GetBorderWidth()));
    sfg::Context::Get().GetEngine().SetProperty<float>("CheckButton#" + obje->Get()->GetId(), "Padding", static_cast<float>(GetPadding()));
    sfg::Context::Get().GetEngine().SetProperty<float>("CheckButton#" + obje->Get()->GetId(), "BoxSize", static_cast<float>(GetBoxSize()));
    sfg::Context::Get().GetEngine().SetProperty<float>("CheckButton#" + obje->Get()->GetId(), "CheckSize", static_cast<float>(GetCheckSignSize()));

}

void CheckBoxObject::SetDisabled(bool is)
{
    if(is)
        obje->Get()->SetState(sfg::Widget::INSENSITIVE);
    else
        obje->Get()->SetState(sfg::Widget::NORMAL);
}

bool CheckBoxObject::IsDisabled()
{
    return (obje->Get()->GetState() == sfg::Widget::INSENSITIVE);
}


const ColorScheme& CheckBoxObject::GetBackgroundColorScheme() const
{
    return *backgroundColor;
}

void CheckBoxObject::SetBackgroundColorScheme(const ColorScheme &cs)
{
    backgroundColor->focusedColor = cs.focusedColor;
    backgroundColor->unfocusedColor = cs.unfocusedColor;
    backgroundColor->hoveredColor = cs.hoveredColor;
    backgroundColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void CheckBoxObject::SetBackgroundColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        backgroundColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        backgroundColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        backgroundColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        backgroundColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

const ColorScheme& CheckBoxObject::GetBorderColorScheme() const
{
    return *borderColor;
}

void CheckBoxObject::SetBorderColorScheme(const ColorScheme &cs)
{
    borderColor->focusedColor = cs.focusedColor;
    borderColor->unfocusedColor = cs.unfocusedColor;
    borderColor->hoveredColor = cs.hoveredColor;
    borderColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void CheckBoxObject::SetBorderColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        borderColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        borderColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        borderColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        borderColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

const ColorScheme& CheckBoxObject::GetTextColorScheme() const
{
    return *textColor;
}

void CheckBoxObject::SetTextColorScheme(const ColorScheme &cs)
{
    textColor->focusedColor = cs.focusedColor;
    textColor->unfocusedColor = cs.unfocusedColor;
    textColor->hoveredColor = cs.hoveredColor;
    textColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void CheckBoxObject::SetTextColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        textColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        textColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        textColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        textColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

const ColorScheme& CheckBoxObject::GetCheckColorScheme() const
{
    return *checkColor;
}

void CheckBoxObject::SetCheckColorScheme(const ColorScheme &cs)
{
    checkColor->focusedColor = cs.focusedColor;
    checkColor->unfocusedColor = cs.unfocusedColor;
    checkColor->hoveredColor = cs.hoveredColor;
    checkColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void CheckBoxObject::SetCheckColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        checkColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        checkColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        checkColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        checkColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

/**
 * Function destroying an extension Object.
 * Game Develop does not delete directly extension object
 * to avoid overloaded new/delete conflicts.
 */
void DestroyCheckBoxObject(Object * object)
{
    delete object;
}

/**
 * Function creating an extension Object.
 * Game Develop can not directly create an extension object
 */
Object * CreateCheckBoxObject(std::string name)
{
    return new CheckBoxObject(name);
}

