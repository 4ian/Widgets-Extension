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
#include <memory>
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
#include "GDL/ResourceWrapper.h"
#include "GDL/XmlMacros.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>

#include "SFGUI/ProgressBar.hpp"
#include "SFGUI/Engine.hpp"
#include "SFGUI/Context.hpp"
#include "SFGUI/CullingTarget.hpp"

#include "../WidgetWrapper.h"

#include <string>
#include "ProgressBarObject.h"

#include "../colorScheme.h"
#include "../Manager.h"
#include "../WidgetsCommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/wx.h>
#include "GDL/ArbitraryResourceWorker.h"
#include "GDL/MainEditorCommand.h"
#include "ProgressBarObjectEditor.h"
#endif

ProgressBarObject::ProgressBarObject(std::string name_) :
Object(name_),
orientation(0),
borderWidth(1),
barBorderWidth(1)
{
    //Create the SFGUI Button object
    obj = sfg::ProgressBar::Create(sfg::ProgressBar::HORIZONTAL);

    //Default size of the object
    SetWidth(180);
    SetHeight(24);

    //Colors "Schemes"
    borderColor = new ColorScheme(sf::Color(146, 147, 151, 255),
                                  sf::Color(146, 147, 151, 255),
                                  sf::Color(146, 147, 151, 255),
                                  sf::Color(173, 173, 173, 255));

    backgroundColor = new ColorScheme(sf::Color(255, 255, 255, 255),
                                      sf::Color(255, 255, 255, 255),
                                      sf::Color(255, 255, 255, 255),
                                      sf::Color(140, 140, 140, 255));

    barColor = new ColorScheme(sf::Color(100, 100, 100, 255),
                                sf::Color(100, 100, 100, 255),
                                sf::Color(100, 100, 100, 255),
                                sf::Color(150, 150, 150, 255));

    obj->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    obj->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateProperties();
}

ProgressBarObject::ProgressBarObject(const ProgressBarObject &other) : Object(other)
{
    Init(other);
}

ProgressBarObject& ProgressBarObject::operator=(const ProgressBarObject &other)
{
    Object::operator=(other);

    if( (this) != &other )
        Init(other);

    return *this;
}

void ProgressBarObject::Init(const ProgressBarObject &other)
{
    position = other.position;
    obj = sfg::ProgressBar::Create(other.obj->GetOrientation());
    backgroundColor = new ColorScheme(*(other.backgroundColor));
    borderColor = new ColorScheme(*(other.borderColor));
    barColor = new ColorScheme(*(other.barColor));
    width = other.width;
    height = other.height;
    borderWidth = other.borderWidth;
    barBorderWidth = other.barBorderWidth;
    orientation = other.orientation;

    SetValue(other.GetValue());

    obj->SetId(ToString<void*>(this));
    obj->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    ConnectSignals();
    ResetEventInformations();

    UpdateSize();
    UpdateProperties();
}

void ProgressBarObject::ConnectSignals()
{
    obj->OnMouseButtonRelease.Connect(&ProgressBarObject::OnMouseClick, this);
    obj->OnStateChange.Connect(&ProgressBarObject::OnStateChanged, this);
}

bool ProgressBarObject::SIG_OnStateChanged(const std::string &newStateVar, RuntimeScene &scene)
{
    if(eventsInformations.stateChanged.fired)
    {

        if(newStateVar != "")
        {
            std::string newStateStr = "";
            if(obj->GetState() == sfg::Widget::ACTIVE)
                newStateStr = "Active";
            else if(obj->GetState() == sfg::Widget::PRELIGHT)
                newStateStr = "Hovered";
            else if(obj->GetState() == sfg::Widget::NORMAL)
                newStateStr = "Normal";
            else if(obj->GetState() == sfg::Widget::INSENSITIVE)
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

bool ProgressBarObject::SIG_OnClick(const std::string &mouseButtonVar, const std::string &xPosVar, const std::string &yPosVar, RuntimeScene &scene)
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

void ProgressBarObject::OnMouseClick()
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

void ProgressBarObject::OnStateChanged()
{
    eventsInformations.stateChanged.fired = true;
}

void ProgressBarObject::ResetEventInformations()
{
    eventsInformations.mouseClick.fired = false;
    eventsInformations.stateChanged.fired = false;
}

ProgressBarObject::~ProgressBarObject()
{
    delete borderColor;
    delete backgroundColor;
    delete barColor;
}

void ProgressBarObject::UpdateSize()
{
    obj->SetRequisition();
    obj->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
    obj->SetAllocation(sf::FloatRect(GetX(), GetY(), GetWidth(), GetHeight()));
}

void ProgressBarObject::LoadFromXml(const TiXmlElement * elem)
{
    if ( elem->FirstChildElement( "Value" ) == NULL ||
         elem->FirstChildElement( "Value" )->Attribute("value") == NULL )
    {
        cout << "Les informations concernant le texte d'un objet Text manquent.";
    }
    else
    {
        float val = 0;
        elem->FirstChildElement("Value")->QueryFloatAttribute("value", &val);

        SetValue(val);
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

    //Bar Scheme
    if ( elem->FirstChildElement( "BarColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load bar color full scheme.";
    }
    else
    {
        barColor->LoadFromXml(elem->FirstChildElement( "BarColorScheme" ));
    }

    if ( elem->FirstChildElement( "BorderWidth" ) == NULL ||
         elem->FirstChildElement( "BorderWidth" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load width of border";
    }
    else
    {
        float borderW = 1;
        elem->FirstChildElement("BorderWidth")->QueryFloatAttribute("value", &borderW);

        SetBorderWidth(borderW);
    }

    if ( elem->FirstChildElement( "BarBorderWidth" ) == NULL ||
         elem->FirstChildElement( "BarBorderWidth" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load width of bar border";
    }
    else
    {
        float borderW = 1;
        elem->FirstChildElement("BarBorderWidth")->QueryFloatAttribute("value", &borderW);

        SetBarBorderWidth(borderW);
    }

    int ori = 5;
    GD_CURRENT_ELEMENT_LOAD_ATTRIBUTE_INT("Orientation", ori);
    SetOrientation(ori);

    UpdateProperties();
}

#if defined(GD_IDE_ONLY)
void ProgressBarObject::SaveToXml(TiXmlElement * elem)
{
    TiXmlElement * str = new TiXmlElement( "Value" );
    elem->LinkEndChild( str );
    str->SetAttribute("value", GetValue());

    TiXmlElement * backgroundColorElem = new TiXmlElement( "BackgroundColorScheme" );
    elem->LinkEndChild( backgroundColorElem );
    backgroundColor->SaveToXml(backgroundColorElem);

    TiXmlElement * borderColorElem = new TiXmlElement( "BorderColorScheme" );
    elem->LinkEndChild( borderColorElem );
    borderColor->SaveToXml(borderColorElem);

    TiXmlElement * barColorElem = new TiXmlElement( "BarColorScheme" );
    elem->LinkEndChild( barColorElem );
    barColor->SaveToXml(barColorElem);

    TiXmlElement * borderWidthElem = new TiXmlElement( "BorderWidth" );
    elem->LinkEndChild( borderWidthElem );
    borderWidthElem->SetAttribute("value", GetBorderWidth());

    TiXmlElement * barBorderWidthElem = new TiXmlElement( "BarBorderWidth" );
    elem->LinkEndChild( barBorderWidthElem );
    barBorderWidthElem->SetAttribute("value", GetBarBorderWidth());

    GD_CURRENT_ELEMENT_SAVE_ATTRIBUTE_FLOAT("Orientation", GetOrientation());
}
#endif

bool ProgressBarObject::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

bool ProgressBarObject::LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

/**
 * Update animation and direction from the inital position
 */
bool ProgressBarObject::InitializeFromInitialPosition(const InitialPosition & position)
{
    return true;
}

/**
 * Render object at runtime
 */
bool ProgressBarObject::Draw( sf::RenderTarget & renderTarget )
{
    //Don't draw anything if hidden
    if ( hidden ) return true;


    sfg::CullingTarget renderer(renderTarget);
    renderer.Cull(false);

    obj->Expose(renderer);

    return true;
}

#if defined(GD_IDE_ONLY)
/**
 * Render object at edittime
 */
bool ProgressBarObject::DrawEdittime(sf::RenderTarget & renderTarget)
{
    sfg::CullingTarget renderer(renderTarget);
    renderer.Cull(false);

    obj->Expose(renderer);

    return true;
}

void ProgressBarObject::ExposeResources(ArbitraryResourceWorker & worker)
{

}

bool ProgressBarObject::GenerateThumbnail(const Game & game, wxBitmap & thumbnail)
{
    thumbnail = wxBitmap("res/Widgets/ProgressBar_logo_small.png", wxBITMAP_TYPE_ANY);

    return true;
}

void ProgressBarObject::EditObject( wxWindow* parent, Game & game, MainEditorCommand & mainEditorCommand )
{
    ProgressBarObjectEditor dialog(parent, game, *this, mainEditorCommand);
    dialog.ShowModal();

    UpdateProperties();
    UpdateSize();
}

wxPanel * ProgressBarObject::CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position )
{
    return NULL;
}

void ProgressBarObject::UpdateInitialPositionFromPanel(wxPanel * panel, InitialPosition & position)
{
}

void ProgressBarObject::GetPropertyForDebugger(unsigned int propertyNb, string & name, string & value) const
{
    if      ( propertyNb == 0 ) {name = _("Valeur");                     value = ToString<float>(GetValue());}
}

bool ProgressBarObject::ChangeProperty(unsigned int propertyNb, string newValue)
{
    if      ( propertyNb == 0 ) { SetValue(ToFloat<std::string>(newValue)); return true; }
    return true;
}

unsigned int ProgressBarObject::GetNumberOfProperties() const
{
    return 1;
}
#endif

void ProgressBarObject::OnPositionChanged()
{
    obj->SetPosition( sf::Vector2f( GetX(), GetY() ) );
    obj->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
}

void ProgressBarObject::SetValue(float v)
{
    obj->SetFraction(v);
}

double ProgressBarObject::GetValue() const
{
    return obj->GetFraction();
}

/**
 * ProgressBarObject provides a basic bounding box.
 */
std::vector<RotatedRectangle> ProgressBarObject::GetHitBoxes() const
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
float ProgressBarObject::GetDrawableX() const
{
    return GetX();
}

/**
 * Get the real Y position of the text
 */
float ProgressBarObject::GetDrawableY() const
{
    return GetY();
}

/**
 * Width is the width of the current sprite.
 */
/*float ProgressBarObject::GetWidth() const
{
    return text.GetRect().Width;
}*/

/**
 * Height is the height of the current sprite.
 */
/*float ProgressBarObject::GetHeight() const
{
    return text.GetRect().Height;
}*/

/**
 * X center is computed with text rectangle
 */
float ProgressBarObject::GetCenterX() const
{
    return GetWidth() / 2;
}

/**
 * Y center is computed with text rectangle
 */
float ProgressBarObject::GetCenterY() const
{
    return GetHeight() / 2;
}

void ProgressBarObject::UpdateTime(float ElapsedTime)
{
    ResetEventInformations();

    if(obj->GetState() == sfg::Widget::INSENSITIVE)
        return;

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

            obj->HandleEvent(event);
        }
        else if(events[i].Type == sf::Event::MouseButtonReleased)
        {
            sf::Event event;
            event.Type = sf::Event::MouseButtonReleased;
            event.MouseButton.Button = events[i].MouseButton.Button;
            event.MouseButton.X = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseButton.X, events[i].MouseButton.Y), GetLayer()).x;
            event.MouseButton.Y = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseButton.X, events[i].MouseButton.Y), GetLayer()).y;

            obj->HandleEvent(event);
        }
        else if(events[i].Type == sf::Event::MouseMoved)
        {
            sf::Event event;
            event.Type = sf::Event::MouseMoved;
            event.MouseMove.X = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseMove.X, events[i].MouseMove.Y), GetLayer()).x;
            event.MouseMove.Y = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Vector2i(events[i].MouseMove.X, events[i].MouseMove.Y), GetLayer()).y;

            obj->HandleEvent(event);
        }
        else
            obj->HandleEvent(events[i]);
    }


}


void ProgressBarObject::UpdateProperties()
{
    //Update BackgroundColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId(), "BackgroundColor", backgroundColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":PRELIGHT", "BackgroundColor", backgroundColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":ACTIVE", "BackgroundColor", backgroundColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":INSENSITIVE", "BackgroundColor", backgroundColor->disabledColor );

    //Update BorderColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId(), "BorderColor", borderColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":PRELIGHT", "BorderColor", borderColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":ACTIVE", "BorderColor", borderColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":INSENSITIVE", "BorderColor", borderColor->disabledColor );

    //Update BarColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId(), "BarColor", barColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":PRELIGHT", "BarColor", barColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":ACTIVE", "BarColor", barColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":INSENSITIVE", "BarColor", barColor->disabledColor );

    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId(), "BarBorderColor", barColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":PRELIGHT", "BarBorderColor", barColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":ACTIVE", "BarBorderColor", barColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ProgressBar#" + obj->GetId() + ":INSENSITIVE", "BarBorderColor", barColor->disabledColor );

    //Update border width and padding
    sfg::Context::Get().GetEngine().SetProperty<float>("ProgressBar#" + obj->GetId(), "BorderWidth", static_cast<float>(GetBorderWidth()));
    sfg::Context::Get().GetEngine().SetProperty<float>("ProgressBar#" + obj->GetId(), "BarBorderWidth", static_cast<float>(GetBarBorderWidth()));
}

void ProgressBarObject::SetDisabled(bool is)
{
    if(is)
        obj->SetState(sfg::Widget::INSENSITIVE);
    else
        obj->SetState(sfg::Widget::NORMAL);
}

bool ProgressBarObject::IsDisabled()
{
    return (obj->GetState() == sfg::Widget::INSENSITIVE);
}


const ColorScheme& ProgressBarObject::GetBackgroundColorScheme() const
{
    return *backgroundColor;
}

void ProgressBarObject::SetBackgroundColorScheme(const ColorScheme &cs)
{
    backgroundColor->focusedColor = cs.focusedColor;
    backgroundColor->unfocusedColor = cs.unfocusedColor;
    backgroundColor->hoveredColor = cs.hoveredColor;
    backgroundColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ProgressBarObject::SetBackgroundColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ProgressBarObject::GetBorderColorScheme() const
{
    return *borderColor;
}

void ProgressBarObject::SetBorderColorScheme(const ColorScheme &cs)
{
    borderColor->focusedColor = cs.focusedColor;
    borderColor->unfocusedColor = cs.unfocusedColor;
    borderColor->hoveredColor = cs.hoveredColor;
    borderColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ProgressBarObject::SetBorderColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ProgressBarObject::GetBarColorScheme() const
{
    return *barColor;
}

void ProgressBarObject::SetBarColorScheme(const ColorScheme &cs)
{
    barColor->focusedColor = cs.focusedColor;
    barColor->unfocusedColor = cs.unfocusedColor;
    barColor->hoveredColor = cs.hoveredColor;
    barColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ProgressBarObject::SetBarColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        barColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        barColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        barColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        barColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

void ProgressBarObject::SetOrientation(int ori)
{
    obj->SetOrientation(static_cast<sfg::ProgressBar::Orientation>(ori));
}

int ProgressBarObject::GetOrientation()
{
    return static_cast<int>(obj->GetOrientation());
}

/**
 * Function destroying an extension Object.
 * Game Develop does not delete directly extension object
 * to avoid overloaded new/delete conflicts.
 */
void DestroyProgressBarObject(Object * object)
{
    delete object;
}

/**
 * Function creating an extension Object.
 * Game Develop can not directly create an extension object
 */
Object * CreateProgressBarObject(std::string name)
{
    return new ProgressBarObject(name);
}

