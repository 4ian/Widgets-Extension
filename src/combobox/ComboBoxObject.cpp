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

#include <iostream>

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

#include "SFGUI/ComboBox.hpp"
#include "SFGUI/Engine.hpp"
#include "SFGUI/Context.hpp"

#include <string>
#include "ComboBoxObject.h"

#include "../colorScheme.h"
#include "../Manager.h"
#include "../WidgetsCommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/wx.h>
#include "GDL/ArbitraryResourceWorker.h"
#include "GDL/MainEditorCommand.h"
#include "ComboBoxObjectEditor.h"
#endif

ComboBoxObject::ComboBoxObject(std::string name_) :
Object(name_),
borderWidth(1),
padding(5)
{
    //Create the SFGUI ComboBox object
    obj = sfg::ComboBox::Create();

    //Default size of the object
    SetWidth(250);
    SetHeight(24);

    fontSize = 12;

    //Colors "Schemes"
    borderColor = new ColorScheme(sf::Color(61, 123, 173, 255),
                                  sf::Color(173, 173, 173, 255),
                                  sf::Color(61, 123, 173, 255),
                                  sf::Color(173, 173, 173, 255));

    backgroundColor = new ColorScheme(sf::Color(255, 255, 255, 255),
                                      sf::Color(255, 255, 255, 255),
                                      sf::Color(255, 255, 255, 255),
                                      sf::Color(140, 140, 140, 255));

    textColor = new ColorScheme(sf::Color(0, 0, 0, 255),
                                sf::Color(0, 0, 0, 255),
                                sf::Color(0, 0, 0, 255),
                                sf::Color(100, 100, 100, 255));

    arrowColor = new ColorScheme(sf::Color(0, 0, 0, 255),
                                sf::Color(0, 0, 0, 255),
                                sf::Color(0, 0, 0, 255),
                                sf::Color(100, 100, 100, 255));

    highlightColor = new ColorScheme(sf::Color(61, 123, 173, 255),
                                  sf::Color(173, 173, 173, 255),
                                  sf::Color(61, 123, 173, 255),
                                  sf::Color(173, 173, 173, 255));

    obj->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    obj->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateProperties();
}

ComboBoxObject::ComboBoxObject(const ComboBoxObject &other) : Object(other)
{
    Init(other);
}

ComboBoxObject& ComboBoxObject::operator=(const ComboBoxObject &other)
{
    Object::operator=(other);

    if( (this) != &other )
        Init(other);

    return *this;
}

void ComboBoxObject::Init(const ComboBoxObject &other)
{
    position = other.position;
    fontName = other.fontName;
    obj = sfg::ComboBox::Create();
    backgroundColor = new ColorScheme(*(other.backgroundColor));
    borderColor = new ColorScheme(*(other.borderColor));
    textColor = new ColorScheme(*(other.textColor));
    arrowColor = new ColorScheme(*(other.arrowColor));
    highlightColor = new ColorScheme(*(other.highlightColor));
    width = other.width;
    height = other.height;
    fontSize = other.fontSize;
    borderWidth = other.borderWidth;
    padding = other.padding;

    obj->SetId(ToString<void*>(this));

    ClearAndSetElements(other.GetAllElements());
    SelectElement(other.GetSelectedElement());

    ConnectSignals();
    ResetEventInformations();

    UpdateSize();
    UpdateProperties();
}

void ComboBoxObject::ConnectSignals()
{
    obj->OnMouseButtonRelease.Connect(&ComboBoxObject::OnMouseClick, this);
    obj->OnStateChange.Connect(&ComboBoxObject::OnStateChanged, this);
}

bool ComboBoxObject::SIG_OnStateChanged(const std::string &newStateVar, RuntimeScene &scene)
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

bool ComboBoxObject::SIG_OnClick(const std::string &mouseButtonVar, const std::string &xPosVar, const std::string &yPosVar, RuntimeScene &scene)
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

void ComboBoxObject::OnMouseClick()
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

void ComboBoxObject::OnStateChanged()
{
    eventsInformations.stateChanged.fired = true;
}

void ComboBoxObject::ResetEventInformations()
{
    eventsInformations.textEntered.fired = false;
    eventsInformations.mouseClick.fired = false;
    eventsInformations.stateChanged.fired = false;
}

ComboBoxObject::~ComboBoxObject()
{
    delete borderColor;
    delete backgroundColor;
    delete textColor;
    delete arrowColor;
    delete highlightColor;
}

void ComboBoxObject::UpdateSize()
{
    obj->SetRequisition();
    obj->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
    obj->SetAllocation(sf::FloatRect(GetX(), GetY(), GetWidth(), GetHeight()));
}

void ComboBoxObject::LoadFromXml(const TiXmlElement * elem)
{
    if ( elem->FirstChildElement( "Elements" ) == NULL)
    {
        cout << "La liste des �l�ments est introuvable.";
    }
    else
    {
        LoadElementsFromXml(elem->FirstChildElement("Elements"));
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

    //Arrow Scheme
    if ( elem->FirstChildElement( "ArrowColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load arrow color full scheme.";
    }
    else
    {
        arrowColor->LoadFromXml(elem->FirstChildElement( "ArrowColorScheme" ));
    }

    //Highlight Scheme
    if ( elem->FirstChildElement( "HighlightColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load highlight color full scheme.";
    }
    else
    {
        highlightColor->LoadFromXml(elem->FirstChildElement( "HighlightColorScheme" ));
    }

    //Bordure
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

    if ( elem->FirstChildElement( "Selected" ) == NULL ||
         elem->FirstChildElement( "Selected" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load selection";
    }
    else
    {
        int selectedIndex = -1;
        elem->FirstChildElement("Selected")->QueryIntAttribute("value", &selectedIndex);

        SelectElement(selectedIndex);
    }

    UpdateProperties();
}

#if defined(GD_IDE_ONLY)
void ComboBoxObject::SaveToXml(TiXmlElement * elem)
{
    TiXmlElement * elemList = new TiXmlElement( "Elements" );
    elem->LinkEndChild( elemList );
    SaveElementsToXml(elemList);

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

    TiXmlElement * arrowColorElem = new TiXmlElement( "ArrowColorScheme" );
    elem->LinkEndChild( arrowColorElem );
    arrowColor->SaveToXml(arrowColorElem);

    TiXmlElement * highlightColorElem = new TiXmlElement( "HighlightColorScheme" );
    elem->LinkEndChild( highlightColorElem );
    highlightColor->SaveToXml(highlightColorElem);

    TiXmlElement * borderWidthElem = new TiXmlElement( "BorderWidth" );
    elem->LinkEndChild( borderWidthElem );
    borderWidthElem->SetAttribute("value", GetBorderWidth());

    TiXmlElement * paddingElem = new TiXmlElement( "Padding" );
    elem->LinkEndChild( paddingElem );
    paddingElem->SetAttribute("value", GetPadding());

    TiXmlElement * selectElem = new TiXmlElement( "Selected" );
    elem->LinkEndChild( selectElem );
    selectElem->SetAttribute("value", GetSelectedElement());
}
#endif

bool ComboBoxObject::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

bool ComboBoxObject::LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

/**
 * Update animation and direction from the inital position
 */
bool ComboBoxObject::InitializeFromInitialPosition(const InitialPosition & position)
{
    return true;
}

/**
 * Render object at runtime
 */
bool ComboBoxObject::Draw( sf::RenderTarget & renderTarget )
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
bool ComboBoxObject::DrawEdittime(sf::RenderTarget & renderTarget)
{
    sfg::CullingTarget renderer(renderTarget);
    renderer.Cull(false);

    obj->Expose(renderer);

    return true;
}

void ComboBoxObject::ExposeResources(ArbitraryResourceWorker & worker)
{
    worker.ExposeResource(fontName);
}

bool ComboBoxObject::GenerateThumbnail(const Game & game, wxBitmap & thumbnail)
{
    thumbnail = wxBitmap("res/Widgets/ComboBox_logo_small.png", wxBITMAP_TYPE_ANY);

    return true;
}

void ComboBoxObject::EditObject( wxWindow* parent, Game & game, MainEditorCommand & mainEditorCommand )
{
    ComboBoxObjectEditor dialog(parent, game, *this, mainEditorCommand);
    dialog.ShowModal();

    UpdateProperties();
    UpdateSize();
}

wxPanel * ComboBoxObject::CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position )
{
    return NULL;
}

void ComboBoxObject::UpdateInitialPositionFromPanel(wxPanel * panel, InitialPosition & position)
{
}

void ComboBoxObject::GetPropertyForDebugger(unsigned int propertyNb, string & name, string & value) const
{
    if      ( propertyNb == 0 ) {name = _("Texte");                     value = "";}
    else if ( propertyNb == 1 )
    {
        name = _("Etat");
        if(obj->GetState() == sfg::Widget::ACTIVE)
            value = _("Actif");
        else if(obj->GetState() == sfg::Widget::PRELIGHT)
            value = _("Survol�");
        else if(obj->GetState() == sfg::Widget::NORMAL)
            value = _("Normal");
        else if(obj->GetState() == sfg::Widget::INSENSITIVE)
            value = _("D�sactiv�");
        else
            value = _("Inconnu");
    }
    else if ( propertyNb == 2 ) {name = _("Taille du texte");           value = ToString<int>(GetCharacterSize());}
    else if ( propertyNb == 3 ) {name = _("Index de l'�l�ment s�lectionn�");           value = ToString<int>(GetSelectedElement());}
}

bool ComboBoxObject::ChangeProperty(unsigned int propertyNb, string newValue)
{
    if      ( propertyNb == 0 ) { return true; }
    else if ( propertyNb == 2 ) { SetCharacterSize(ToInt(newValue)); }
    return true;
}

unsigned int ComboBoxObject::GetNumberOfProperties() const
{
    return 4;
}
#endif

void ComboBoxObject::OnPositionChanged()
{
    obj->SetPosition( sf::Vector2f( GetX(), GetY() ) );
    obj->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
}

/**
 * ComboBoxObject provides a basic bounding box.
 */
std::vector<RotatedRectangle> ComboBoxObject::GetHitBoxes() const
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
float ComboBoxObject::GetDrawableX() const
{
    return GetX();
}

/**
 * Get the real Y position of the text
 */
float ComboBoxObject::GetDrawableY() const
{
    return GetY();
}

/**
 * Width is the width of the current sprite.
 */
/*float ComboBoxObject::GetWidth() const
{
    return text.GetRect().Width;
}*/

/**
 * Height is the height of the current sprite.
 */
/*float ComboBoxObject::GetHeight() const
{
    return text.GetRect().Height;
}*/

/**
 * X center is computed with text rectangle
 */
float ComboBoxObject::GetCenterX() const
{
    return GetWidth() / 2;
}

/**
 * Y center is computed with text rectangle
 */
float ComboBoxObject::GetCenterY() const
{
    return GetHeight() / 2;
}

void ComboBoxObject::SetFont(string fontName_)
{
    fontName = fontName_;

    UpdateProperties();

    /*FontManager * fontManager = FontManager::GetInstance();
    text.SetFont(*fontManager->GetFont(fontName));*/
    //text.SetOrigin(text.GetRect().Width/2, text.GetRect().Height/2);
}

void ComboBoxObject::UpdateTime(float ElapsedTime)
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


void ComboBoxObject::UpdateProperties()
{
    //Update BackgroundColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId(), "BackgroundColor", backgroundColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":PRELIGHT", "BackgroundColor", backgroundColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":ACTIVE", "BackgroundColor", backgroundColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":INSENSITIVE", "BackgroundColor", backgroundColor->disabledColor );

    //Update BorderColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId(), "BorderColor", borderColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":PRELIGHT", "BorderColor", borderColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":ACTIVE", "BorderColor", borderColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":INSENSITIVE", "BorderColor", borderColor->disabledColor );

    //Update TextColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId(), "Color", textColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":PRELIGHT", "Color", textColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":ACTIVE", "Color", textColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":INSENSITIVE", "Color", textColor->disabledColor );

    //Update ArrowColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId(), "ArrowColor", arrowColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":PRELIGHT", "ArrowColor", arrowColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":ACTIVE", "ArrowColor", arrowColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId() + ":INSENSITIVE", "ArrowColor", arrowColor->disabledColor );

    //Update HightlightColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "ComboBox#" + obj->GetId(), "HighlightedColor", highlightColor->focusedColor );

    //Update font size
    sfg::Context::Get().GetEngine().SetProperty<unsigned int>("ComboBox#" + obj->GetId(), "FontSize", GetCharacterSize());
    sfg::Context::Get().GetEngine().SetProperty<std::string>("ComboBox#" + obj->GetId(), "FontName", std::string("gdres:") + GetFont());

    //Update border width and padding
    sfg::Context::Get().GetEngine().SetProperty<float>("ComboBox#" + obj->GetId(), "BorderWidth", static_cast<float>(GetBorderWidth()));
    sfg::Context::Get().GetEngine().SetProperty<float>("ComboBox#" + obj->GetId(), "Padding", static_cast<float>(GetPadding()));

}

void ComboBoxObject::SetActive(bool is)
{
    if(obj->GetState() != sfg::Widget::INSENSITIVE && is)
        obj->SetState(sfg::Widget::ACTIVE);
    else if(obj->GetState() != sfg::Widget::INSENSITIVE && !is)
        obj->SetState(sfg::Widget::NORMAL);
}

bool ComboBoxObject::IsActive()
{
    return (obj->GetState() == sfg::Widget::ACTIVE);
}

void ComboBoxObject::SetDisabled(bool is)
{
    if(is)
        obj->SetState(sfg::Widget::INSENSITIVE);
    else
        obj->SetState(sfg::Widget::NORMAL);
}

bool ComboBoxObject::IsDisabled()
{
    return (obj->GetState() == sfg::Widget::INSENSITIVE);
}


const ColorScheme& ComboBoxObject::GetBackgroundColorScheme() const
{
    return *backgroundColor;
}

void ComboBoxObject::SetBackgroundColorScheme(const ColorScheme &cs)
{
    backgroundColor->focusedColor = cs.focusedColor;
    backgroundColor->unfocusedColor = cs.unfocusedColor;
    backgroundColor->hoveredColor = cs.hoveredColor;
    backgroundColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ComboBoxObject::SetBackgroundColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ComboBoxObject::GetBorderColorScheme() const
{
    return *borderColor;
}

void ComboBoxObject::SetBorderColorScheme(const ColorScheme &cs)
{
    borderColor->focusedColor = cs.focusedColor;
    borderColor->unfocusedColor = cs.unfocusedColor;
    borderColor->hoveredColor = cs.hoveredColor;
    borderColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ComboBoxObject::SetBorderColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ComboBoxObject::GetTextColorScheme() const
{
    return *textColor;
}

void ComboBoxObject::SetTextColorScheme(const ColorScheme &cs)
{
    textColor->focusedColor = cs.focusedColor;
    textColor->unfocusedColor = cs.unfocusedColor;
    textColor->hoveredColor = cs.hoveredColor;
    textColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ComboBoxObject::SetTextColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ComboBoxObject::GetArrowColorScheme() const
{
    return *arrowColor;
}

void ComboBoxObject::SetArrowColorScheme(const ColorScheme &cs)
{
    arrowColor->focusedColor = cs.focusedColor;
    arrowColor->unfocusedColor = cs.unfocusedColor;
    arrowColor->hoveredColor = cs.hoveredColor;
    arrowColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ComboBoxObject::SetArrowColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        arrowColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        arrowColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        arrowColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        arrowColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

const ColorScheme& ComboBoxObject::GetHighlightColorScheme() const
{
    return *highlightColor;
}

void ComboBoxObject::SetHighlightColorScheme(const ColorScheme &cs)
{
    highlightColor->focusedColor = cs.focusedColor;
    highlightColor->unfocusedColor = cs.unfocusedColor;
    highlightColor->hoveredColor = cs.hoveredColor;
    highlightColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ComboBoxObject::SetHighlightColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        highlightColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        highlightColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        highlightColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        highlightColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

const ElementList& ComboBoxObject::GetAllElements() const
{
    static ElementList listOfElements;
    listOfElements.clear();

    unsigned int a = 0;
    for (a = 0; a < obj->GetItemCount(); a++)
    {
        listOfElements.push_back(obj->GetItem(a));
    }

    return listOfElements;
}

void ComboBoxObject::ClearAndSetElements(const ElementList &list)
{
    while(obj->GetItemCount() > 0)
    {
        obj->RemoveItem(0);
    }

    unsigned int a = 0;
    for(a = 0; a < list.size(); a++)
    {
        obj->AppendItem(sf::String(list.at(a)));
    }
}

void ComboBoxObject::LoadElementsFromXml(const TiXmlElement *elem)
{
    const TiXmlElement *subElem = elem->FirstChildElement("Element");
    ElementList newList;

    while(subElem != 0)
    {
        newList.push_back(std::string(subElem->GetText()));

        subElem = subElem->NextSiblingElement("Element");
    }

    ClearAndSetElements(newList);
}

void ComboBoxObject::SaveElementsToXml(TiXmlElement *elem)
{
    for(unsigned int a = 0; a < obj->GetItemCount(); a++)
    {
        TiXmlElement *subElem = new TiXmlElement("Element");
        TiXmlText *textElem = new TiXmlText(obj->GetItem(a).ToAnsiString().c_str());
        subElem->LinkEndChild(textElem);

        elem->LinkEndChild(subElem);
    }
}

int ComboBoxObject::GetSelectedElement() const
{
    return obj->GetSelectedItem() != sfg::ComboBox::NONE ? obj->GetSelectedItem() : -1;
}

void ComboBoxObject::SelectElement(unsigned int ele)
{
    obj->SelectItem(ele);
}

std::string ComboBoxObject::GetElementString(unsigned int ele) const
{
    return obj->GetItem(ele).ToAnsiString();
}

void ComboBoxObject::SetElementString(unsigned int ele, const std::string &str)
{
    obj->ChangeItem(ele, sf::String(str));
}

unsigned int ComboBoxObject::GetElementsCount() const
{
    return obj->GetItemCount();
}

void ComboBoxObject::AddElement(unsigned int index, const std::string &str)
{
    if(index <= obj->GetItemCount())
        obj->InsertItem(index, sf::String(str));
}

void ComboBoxObject::DeleteElement(unsigned int index)
{
    if(index < obj->GetItemCount())
        obj->RemoveItem(index);
}

/**
 * Function destroying an extension Object.
 * Game Develop does not delete directly extension object
 * to avoid overloaded new/delete conflicts.
 */
void DestroyComboBoxObject(Object * object)
{
    delete object;
}

/**
 * Function creating an extension Object.
 * Game Develop can not directly create an extension object
 */
Object * CreateComboBoxObject(std::string name)
{
    return new ComboBoxObject(name);
}

