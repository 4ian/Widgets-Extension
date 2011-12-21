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

#include "SFGUI/Entry.hpp"
#include "SFGUI/Engine.hpp"
#include "SFGUI/Context.hpp"

#include "../WidgetWrapper.h"

#include <string>
#include "TextAreaObject.h"

#include "../colorScheme.h"
#include "../Manager.h"
#include "../WidgetsCommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/wx.h>
#include "GDL/ArbitraryResourceWorker.h"
#include "GDL/MainEditorCommand.h"
#include "TextAreaObjectEditor.h"
#endif

TextAreaObject::TextAreaObject(std::string name_) :
Object(name_),
borderWidth(1),
padding(5)
{
    //Create the SFGUI Entry object
    sfg::Entry::Ptr tmpObj = sfg::Entry::Create("Texte");
    obje = new WidgetWrapper<sfg::Entry>(tmpObj);

    //WidgetManager::getInstance()->mainWidget->Pack(obje->Get());

    SetString("Tapez du texte");

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

    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    obje->Get()->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateProperties();
}

TextAreaObject::TextAreaObject(const TextAreaObject &other) : Object(other)
{
    Init(other);
}

TextAreaObject& TextAreaObject::operator=(const TextAreaObject &other)
{
    Object::operator=(other);

    if( (this) != &other )
        Init(other);

    return *this;
}

void TextAreaObject::Init(const TextAreaObject &other)
{
    position = other.position;
    fontName = other.fontName;
    sfg::Entry::Ptr tmpObj = sfg::Entry::Create(other.obje->Get()->GetText());
    obje = new WidgetWrapper<sfg::Entry>(tmpObj);
    backgroundColor = new ColorScheme(*(other.backgroundColor));
    borderColor = new ColorScheme(*(other.borderColor));
    textColor = new ColorScheme(*(other.textColor));
    width = other.width;
    height = other.height;
    fontSize = other.fontSize;
    borderWidth = other.borderWidth;
    padding = other.padding;

    obje->Get()->SetId(ToString<void*>(this));
    SetHideCharacter(other.GetHideCharacter());
    SetMaximumLength(other.GetMaximumLength());

    ConnectSignals();
    ResetEventInformations();

    UpdateSize();
    UpdateProperties();
}

void TextAreaObject::ConnectSignals()
{
    obje->Get()->OnText.Connect(&TextAreaObject::OnTextEntered, this);
    obje->Get()->OnMouseButtonRelease.Connect(&TextAreaObject::OnMouseClick, this);
    obje->Get()->OnStateChange.Connect(&TextAreaObject::OnStateChanged, this);
}

bool TextAreaObject::SIG_OnTextEntered(RuntimeScene &scene)
{
    if(eventsInformations.textEntered.fired)
    {

        return true;
    }
    else
    {
        return false;
    }
}

bool TextAreaObject::SIG_OnStateChanged(const std::string &newStateVar, RuntimeScene &scene)
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

bool TextAreaObject::SIG_OnClick(const std::string &mouseButtonVar, const std::string &xPosVar, const std::string &yPosVar, RuntimeScene &scene)
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

void TextAreaObject::OnTextEntered()
{
    eventsInformations.textEntered.fired = true;
}

void TextAreaObject::OnMouseClick()
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

void TextAreaObject::OnStateChanged()
{
    eventsInformations.stateChanged.fired = true;
}

void TextAreaObject::ResetEventInformations()
{
    eventsInformations.textEntered.fired = false;
    eventsInformations.mouseClick.fired = false;
    eventsInformations.stateChanged.fired = false;
}

TextAreaObject::~TextAreaObject()
{
    delete borderColor;
    delete backgroundColor;
    delete textColor;

    delete obje;
}

void TextAreaObject::UpdateSize()
{
    obje->Get()->SetRequisition();
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
    obje->Get()->SetAllocation(sf::FloatRect(GetX(), GetY(), GetWidth(), GetHeight()));
}

void TextAreaObject::LoadFromXml(const TiXmlElement * elem)
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

    if ( elem->FirstChildElement( "HideCharacter" ) == NULL ||
         elem->FirstChildElement( "HideCharacter" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load hideChar";
    }
    else
    {
        int hideChar = 0;
        elem->FirstChildElement("HideCharacter")->QueryIntAttribute("value", &hideChar);

        SetHideCharacter(hideChar);
    }

    if ( elem->FirstChildElement( "MaximumLength" ) == NULL ||
         elem->FirstChildElement( "MaximumLength" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load maxLength";
    }
    else
    {
        int maxLength = 0;
        elem->FirstChildElement("MaximumLength")->QueryIntAttribute("value", &maxLength);

        SetMaximumLength(maxLength);
    }

    UpdateProperties();
}

#if defined(GD_IDE_ONLY)
void TextAreaObject::SaveToXml(TiXmlElement * elem)
{
    TiXmlElement * str = new TiXmlElement( "String" );
    elem->LinkEndChild( str );
    str->SetAttribute("value", GetString().c_str());

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

    TiXmlElement * borderWidthElem = new TiXmlElement( "BorderWidth" );
    elem->LinkEndChild( borderWidthElem );
    borderWidthElem->SetAttribute("value", GetBorderWidth());

    TiXmlElement * paddingElem = new TiXmlElement( "Padding" );
    elem->LinkEndChild( paddingElem );
    paddingElem->SetAttribute("value", GetPadding());

    TiXmlElement * hideCharElem = new TiXmlElement( "HideCharacter" );
    elem->LinkEndChild( hideCharElem );
    hideCharElem->SetAttribute("value", GetHideCharacter());

    TiXmlElement * maxLengthElem = new TiXmlElement( "MaximumLength" );
    elem->LinkEndChild( maxLengthElem );
    maxLengthElem->SetAttribute("value", GetMaximumLength());
}
#endif

bool TextAreaObject::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

bool TextAreaObject::LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

/**
 * Update animation and direction from the inital position
 */
bool TextAreaObject::InitializeFromInitialPosition(const InitialPosition & position)
{
    return true;
}

/**
 * Render object at runtime
 */
bool TextAreaObject::Draw( sf::RenderTarget & renderTarget )
{
    //Don't draw anything if hidden
    if ( hidden ) return true;

    obje->Get()->Expose(renderTarget);

    return true;
}

#if defined(GD_IDE_ONLY)
/**
 * Render object at edittime
 */
bool TextAreaObject::DrawEdittime(sf::RenderTarget & renderTarget)
{
    obje->Get()->Expose(renderTarget);

    return true;
}

void TextAreaObject::ExposeResources(ArbitraryResourceWorker & worker)
{
    worker.ExposeResource(fontName);
}

bool TextAreaObject::GenerateThumbnail(const Game & game, wxBitmap & thumbnail)
{
    thumbnail = wxBitmap("res/Widgets/Entry_logo_small.png", wxBITMAP_TYPE_ANY);

    return true;
}

void TextAreaObject::EditObject( wxWindow* parent, Game & game, MainEditorCommand & mainEditorCommand )
{
    TextAreaObjectEditor dialog(parent, game, *this, mainEditorCommand);
    dialog.ShowModal();

    UpdateProperties();
    UpdateSize();
}

wxPanel * TextAreaObject::CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position )
{
    return NULL;
}

void TextAreaObject::UpdateInitialPositionFromPanel(wxPanel * panel, InitialPosition & position)
{
}

void TextAreaObject::GetPropertyForDebugger(unsigned int propertyNb, string & name, string & value) const
{
    if      ( propertyNb == 0 ) {name = _("Texte");                     value = GetString();}
    else if ( propertyNb == 1 )
    {
        name = _("Etat");
        if(obje->Get()->GetState() == sfg::Widget::ACTIVE)
            value = _("Actif");
        else if(obje->Get()->GetState() == sfg::Widget::PRELIGHT)
            value = _("Survolé");
        else if(obje->Get()->GetState() == sfg::Widget::NORMAL)
            value = _("Normal");
        else if(obje->Get()->GetState() == sfg::Widget::INSENSITIVE)
            value = _("Désactivé");
        else
            value = _("Inconnu");
    }
    else if ( propertyNb == 2 ) {name = _("Taille du texte");           value = ToString<int>(GetCharacterSize());}

}

bool TextAreaObject::ChangeProperty(unsigned int propertyNb, string newValue)
{
    if      ( propertyNb == 0 ) { SetString(newValue); return true; }
    else if ( propertyNb == 2 ) { SetCharacterSize(ToInt(newValue)); }
    return true;
}

unsigned int TextAreaObject::GetNumberOfProperties() const
{
    return 3;
}
#endif

void TextAreaObject::OnPositionChanged()
{
    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
}

void TextAreaObject::SetString(const std::string &str)
{
    obje->Get()->SetText(str);
}

std::string TextAreaObject::GetString() const
{
    return obje->Get()->GetText().ToAnsiString();
}

/**
 * TextAreaObject provides a basic bounding box.
 */
std::vector<RotatedRectangle> TextAreaObject::GetHitBoxes() const
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
float TextAreaObject::GetDrawableX() const
{
    return GetX();
}

/**
 * Get the real Y position of the text
 */
float TextAreaObject::GetDrawableY() const
{
    return GetY();
}

/**
 * Width is the width of the current sprite.
 */
/*float TextAreaObject::GetWidth() const
{
    return text.GetRect().Width;
}*/

/**
 * Height is the height of the current sprite.
 */
/*float TextAreaObject::GetHeight() const
{
    return text.GetRect().Height;
}*/

/**
 * X center is computed with text rectangle
 */
float TextAreaObject::GetCenterX() const
{
    return GetWidth() / 2;
}

/**
 * Y center is computed with text rectangle
 */
float TextAreaObject::GetCenterY() const
{
    return GetHeight() / 2;
}

void TextAreaObject::SetFont(string fontName_)
{
    fontName = fontName_;

    UpdateProperties();

    /*FontManager * fontManager = FontManager::GetInstance();
    text.SetFont(*fontManager->GetFont(fontName));*/
    //text.SetOrigin(text.GetRect().Width/2, text.GetRect().Height/2);
}

void TextAreaObject::UpdateTime(float ElapsedTime)
{
    ResetEventInformations();

    //Manual Management of focus because doesn't use any containers
    if(sf::Mouse::IsButtonPressed(sf::Mouse::Left))
    {

        sf::Rect<float> widgetPos(GetX(), GetY(), GetWidth(), GetHeight());

        float mouseX = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Mouse::GetPosition(*(m_scene->renderWindow)), GetLayer()).x;
        float mouseY = WidgetsCommonTools::GetViewsPosition(*m_scene, sf::Mouse::GetPosition(*(m_scene->renderWindow)), GetLayer()).y;

        if(!(widgetPos.Contains(sf::Vector2f(mouseX, mouseY))) && obje->Get()->GetState() == sfg::Widget::ACTIVE)
        {
            obje->Get()->SetState(sfg::Widget::NORMAL);
        }
        if(widgetPos.Contains(sf::Vector2f(mouseX, mouseY)) && obje->Get()->GetState() != sfg::Widget::INSENSITIVE && obje->Get()->GetState() != sfg::Widget::ACTIVE)
        {
            obje->Get()->SetState(sfg::Widget::ACTIVE);

            sf::Event event;
            event.Type = sf::Event::MouseButtonPressed;
            event.MouseButton.Button = sf::Mouse::Left;
            event.MouseButton.X = mouseX;
            event.MouseButton.Y = mouseY;
            obje->Get()->HandleEvent(event);
        }
    }

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


void TextAreaObject::UpdateProperties()
{
    //Update BackgroundColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId(), "BackgroundColor", backgroundColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":PRELIGHT", "BackgroundColor", backgroundColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":ACTIVE", "BackgroundColor", backgroundColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":INSENSITIVE", "BackgroundColor", backgroundColor->disabledColor );

    //Update BorderColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId(), "BorderColor", borderColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":PRELIGHT", "BorderColor", borderColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":ACTIVE", "BorderColor", borderColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":INSENSITIVE", "BorderColor", borderColor->disabledColor );

    //Update TextColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId(), "Color", textColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":PRELIGHT", "Color", textColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":ACTIVE", "Color", textColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Entry#" + obje->Get()->GetId() + ":INSENSITIVE", "Color", textColor->disabledColor );

    //Update font size
    sfg::Context::Get().GetEngine().SetProperty<unsigned int>("Entry#" + obje->Get()->GetId(), "FontSize", GetCharacterSize());
    sfg::Context::Get().GetEngine().SetProperty<std::string>("Entry#" + obje->Get()->GetId(), "FontName", std::string("gdres:") + GetFont());

    //Update border width and padding
    sfg::Context::Get().GetEngine().SetProperty<float>("Entry#" + obje->Get()->GetId(), "BorderWidth", static_cast<float>(GetBorderWidth()));
    sfg::Context::Get().GetEngine().SetProperty<float>("Entry#" + obje->Get()->GetId(), "Padding", static_cast<float>(GetPadding()));

}

void TextAreaObject::SetActive(bool is)
{
    if(obje->Get()->GetState() != sfg::Widget::INSENSITIVE && is)
        obje->Get()->SetState(sfg::Widget::ACTIVE);
    else if(obje->Get()->GetState() != sfg::Widget::INSENSITIVE && !is)
        obje->Get()->SetState(sfg::Widget::NORMAL);
}

bool TextAreaObject::IsActive()
{
    return (obje->Get()->GetState() == sfg::Widget::ACTIVE);
}

void TextAreaObject::SetDisabled(bool is)
{
    if(is)
        obje->Get()->SetState(sfg::Widget::INSENSITIVE);
    else
        obje->Get()->SetState(sfg::Widget::NORMAL);
}

bool TextAreaObject::IsDisabled()
{
    return (obje->Get()->GetState() == sfg::Widget::INSENSITIVE);
}


const ColorScheme& TextAreaObject::GetBackgroundColorScheme() const
{
    return *backgroundColor;
}

void TextAreaObject::SetBackgroundColorScheme(const ColorScheme &cs)
{
    backgroundColor->focusedColor = cs.focusedColor;
    backgroundColor->unfocusedColor = cs.unfocusedColor;
    backgroundColor->hoveredColor = cs.hoveredColor;
    backgroundColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void TextAreaObject::SetBackgroundColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& TextAreaObject::GetBorderColorScheme() const
{
    return *borderColor;
}

void TextAreaObject::SetBorderColorScheme(const ColorScheme &cs)
{
    borderColor->focusedColor = cs.focusedColor;
    borderColor->unfocusedColor = cs.unfocusedColor;
    borderColor->hoveredColor = cs.hoveredColor;
    borderColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void TextAreaObject::SetBorderColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& TextAreaObject::GetTextColorScheme() const
{
    return *textColor;
}

void TextAreaObject::SetTextColorScheme(const ColorScheme &cs)
{
    textColor->focusedColor = cs.focusedColor;
    textColor->unfocusedColor = cs.unfocusedColor;
    textColor->hoveredColor = cs.hoveredColor;
    textColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void TextAreaObject::SetTextColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

sf::Uint32 TextAreaObject::GetHideCharacter() const
{
    return obje->Get()->GetHideCharacter();
}

void TextAreaObject::SetHideCharacter(sf::Uint32 charac)
{
    obje->Get()->HideText(charac);
}

int TextAreaObject::GetMaximumLength() const
{
    return obje->Get()->GetMaximumLength();
}

void TextAreaObject::SetMaximumLength(int s)
{
    obje->Get()->SetMaximumLength(s);
}

/**
 * Function destroying an extension Object.
 * Game Develop does not delete directly extension object
 * to avoid overloaded new/delete conflicts.
 */
void DestroyTextAreaObject(Object * object)
{
    delete object;
}

/**
 * Function creating an extension Object.
 * Game Develop can not directly create an extension object
 */
Object * CreateTextAreaObject(std::string name)
{
    return new TextAreaObject(name);
}

