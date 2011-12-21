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
#include "GDL/RessourcesLoader.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>

#include "SFGUI/Button.hpp"
#include "SFGUI/Image.hpp"
#include "SFGUI/Engine.hpp"
#include "SFGUI/Context.hpp"

#include "../WidgetWrapper.h"

#include <string>
#include "ButtonObject.h"

#include "../colorScheme.h"
#include "../Manager.h"
#include "../WidgetsCommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/wx.h>
#include "GDL/ArbitraryResourceWorker.h"
#include "GDL/MainEditorCommand.h"
#include "ButtonObjectEditor.h"
#endif

ButtonObject::ButtonObject(std::string name_) :
Object(name_),
imageName(""),
borderWidth(1),
padding(5)
{
    //Create the SFGUI Button object
    //obje->Get() = ;
    sfg::Button::Ptr tmpObj = sfg::Button::Create("Texte");
    obje = new WidgetWrapper<sfg::Button>(tmpObj);

    //WidgetManager::getInstance()->mainWidget->Pack(obje->Get());

    SetString("Bouton");

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

    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    obje->Get()->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateProperties();
}

ButtonObject::ButtonObject(const ButtonObject &other) : Object(other)
{
    Init(other);
}

ButtonObject& ButtonObject::operator=(const ButtonObject &other)
{
    Object::operator=(other);

    if( (this) != &other )
        Init(other);

    return *this;
}

void ButtonObject::Init(const ButtonObject &other)
{
    position = other.position;
    fontName = other.fontName;
    sfg::Button::Ptr tmpObj = sfg::Button::Create(other.obje->Get()->GetLabel());
    obje = new WidgetWrapper<sfg::Button>(tmpObj);
    backgroundColor = new ColorScheme(*(other.backgroundColor));
    borderColor = new ColorScheme(*(other.borderColor));
    textColor = new ColorScheme(*(other.textColor));
    width = other.width;
    height = other.height;
    fontSize = other.fontSize;
    borderWidth = other.borderWidth;
    padding = other.padding;
    imageName = other.imageName;

    obje->Get()->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateSize();
    UpdateProperties();
}

void ButtonObject::ConnectSignals()
{
    obje->Get()->OnClick.Connect(&ButtonObject::OnMouseClick, this);
    obje->Get()->OnStateChange.Connect(&ButtonObject::OnStateChanged, this);
}

bool ButtonObject::SIG_OnStateChanged(const std::string &newStateVar, RuntimeScene &scene)
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

bool ButtonObject::SIG_OnClick(const std::string &mouseButtonVar, const std::string &xPosVar, const std::string &yPosVar, RuntimeScene &scene)
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

void ButtonObject::OnMouseClick()
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

void ButtonObject::OnStateChanged()
{
    eventsInformations.stateChanged.fired = true;
}

void ButtonObject::ResetEventInformations()
{
    eventsInformations.mouseClick.fired = false;
    eventsInformations.stateChanged.fired = false;
}

ButtonObject::~ButtonObject()
{
    delete borderColor;
    delete backgroundColor;
    delete textColor;

    delete obje;
}

void ButtonObject::UpdateSize()
{
    obje->Get()->SetRequisition();
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
    obje->Get()->SetAllocation(sf::FloatRect(GetX(), GetY(), GetWidth(), GetHeight()));
}

void ButtonObject::LoadFromXml(const TiXmlElement * elem)
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

    if ( elem->FirstChildElement( "Picture" ) == NULL ||
         elem->FirstChildElement( "Picture" )->Attribute("value") == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load picture name";
    }
    else
    {
        SetPictureName(elem->FirstChildElement("Picture")->Attribute("value"));
    }

    UpdateProperties();
}

#if defined(GD_IDE_ONLY)
void ButtonObject::SaveToXml(TiXmlElement * elem)
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

    TiXmlElement * imageElem = new TiXmlElement( "Picture" );
    elem->LinkEndChild( imageElem );
    imageElem->SetAttribute("value", GetPictureName().c_str());
}
#endif

bool ButtonObject::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;
    LoadPicture(*(scene.game->imageManager));

    return true;
}

bool ButtonObject::LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;
    LoadPicture(*(scene.game->imageManager));

    return true;
}

/**
 * Update animation and direction from the inital position
 */
bool ButtonObject::InitializeFromInitialPosition(const InitialPosition & position)
{
    return true;
}

/**
 * Render object at runtime
 */
bool ButtonObject::Draw( sf::RenderTarget & renderTarget )
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
bool ButtonObject::DrawEdittime(sf::RenderTarget & renderTarget)
{
    sfg::CullingTarget renderer(renderTarget);
    renderer.Cull(false);

    obje->Get()->Expose(renderer);

    return true;
}

void ButtonObject::ExposeResources(ArbitraryResourceWorker & worker)
{
    worker.ExposeResource(fontName);
    worker.ExposeImage(imageName);
}

bool ButtonObject::GenerateThumbnail(const Game & game, wxBitmap & thumbnail)
{
    thumbnail = wxBitmap("res/Widgets/Button_logo_small.png", wxBITMAP_TYPE_ANY);

    return true;
}

void ButtonObject::EditObject( wxWindow* parent, Game & game, MainEditorCommand & mainEditorCommand )
{
    ButtonObjectEditor dialog(parent, game, *this, mainEditorCommand);
    dialog.ShowModal();

    UpdateProperties();
    UpdateSize();
}

wxPanel * ButtonObject::CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position )
{
    return NULL;
}

void ButtonObject::UpdateInitialPositionFromPanel(wxPanel * panel, InitialPosition & position)
{
}

void ButtonObject::GetPropertyForDebugger(unsigned int propertyNb, string & name, string & value) const
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

bool ButtonObject::ChangeProperty(unsigned int propertyNb, string newValue)
{
    if      ( propertyNb == 0 ) { SetString(newValue); return true; }
    else if ( propertyNb == 2 ) { SetCharacterSize(ToInt(newValue)); }
    return true;
}

unsigned int ButtonObject::GetNumberOfProperties() const
{
    return 3;
}
#endif

float ButtonObject::GetWidth() const
{
    return obje->Get()->GetAllocation().Width;
}

float ButtonObject::GetHeight() const
{
    return obje->Get()->GetAllocation().Height;
}

void ButtonObject::SetWidth(float s)
{
    width = s;
    obje->Get()->SetAllocation(sf::FloatRect(GetX(), GetY(), s, GetHeight()));
}

void ButtonObject::SetHeight(float s)
{
    height = s;
    obje->Get()->SetAllocation(sf::FloatRect(GetX(), GetY(), GetWidth(), s));
}

void ButtonObject::OnPositionChanged()
{
    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
}

void ButtonObject::SetString(const std::string &str)
{
    obje->Get()->SetLabel(str);
}

std::string ButtonObject::GetString() const
{
    return obje->Get()->GetLabel().ToAnsiString();
}

/**
 * ButtonObject provides a basic bounding box.
 */
std::vector<RotatedRectangle> ButtonObject::GetHitBoxes() const
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
float ButtonObject::GetDrawableX() const
{
    return GetX();
}

/**
 * Get the real Y position of the text
 */
float ButtonObject::GetDrawableY() const
{
    return GetY();
}

/**
 * Width is the width of the current sprite.
 */
/*float ButtonObject::GetWidth() const
{
    return text.GetRect().Width;
}*/

/**
 * Height is the height of the current sprite.
 */
/*float ButtonObject::GetHeight() const
{
    return text.GetRect().Height;
}*/

/**
 * X center is computed with text rectangle
 */
float ButtonObject::GetCenterX() const
{
    return GetWidth() / 2;
}

/**
 * Y center is computed with text rectangle
 */
float ButtonObject::GetCenterY() const
{
    return GetHeight() / 2;
}

void ButtonObject::SetFont(string fontName_)
{
    fontName = fontName_;

    UpdateProperties();

    /*FontManager * fontManager = FontManager::GetInstance();
    text.SetFont(*fontManager->GetFont(fontName));*/
    //text.SetOrigin(text.GetRect().Width/2, text.GetRect().Height/2);
}

void ButtonObject::UpdateTime(float ElapsedTime)
{
    ResetEventInformations();

    if(obje->Get()->GetState() == sfg::Widget::INSENSITIVE)
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


void ButtonObject::UpdateProperties()
{
    //Update BackgroundColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId(), "BackgroundColor", backgroundColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":PRELIGHT", "BackgroundColor", backgroundColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":ACTIVE", "BackgroundColor", backgroundColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":INSENSITIVE", "BackgroundColor", backgroundColor->disabledColor );

    //Update BorderColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId(), "BorderColor", borderColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":PRELIGHT", "BorderColor", borderColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":ACTIVE", "BorderColor", borderColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":INSENSITIVE", "BorderColor", borderColor->disabledColor );

    //Update TextColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + "", "Color", textColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":PRELIGHT", "Color", textColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":ACTIVE", "Color", textColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Button#" + obje->Get()->GetId() + ":INSENSITIVE", "Color", textColor->disabledColor );

    //Update font size
    sfg::Context::Get().GetEngine().SetProperty<unsigned int>("Button#" + obje->Get()->GetId() + "", "FontSize", GetCharacterSize());
    sfg::Context::Get().GetEngine().SetProperty<std::string>("Button#" + obje->Get()->GetId(), "FontName", std::string("gdres:") + GetFont());

    //Update border width and padding
    sfg::Context::Get().GetEngine().SetProperty<float>("Button#" + obje->Get()->GetId(), "BorderWidth", static_cast<float>(GetBorderWidth()));
    sfg::Context::Get().GetEngine().SetProperty<float>("Button#" + obje->Get()->GetId(), "Padding", static_cast<float>(GetPadding()));

}

void ButtonObject::SetDisabled(bool is)
{
    if(is)
        obje->Get()->SetState(sfg::Widget::INSENSITIVE);
    else
        obje->Get()->SetState(sfg::Widget::NORMAL);
}

bool ButtonObject::IsDisabled()
{
    return (obje->Get()->GetState() == sfg::Widget::INSENSITIVE);
}


const std::string& ButtonObject::GetPictureName() const
{
    return imageName;
}

void ButtonObject::SetPictureName(const std::string &_name)
{
    imageName = _name;
}

void ButtonObject::LoadPicture(const ImageManager &imgMan)
{
    if(imageName == "" || !(imgMan.HasImage(imageName)))
    {
        obje->Get()->ClearImage();
    }
    else
    {
        boost::shared_ptr<SFMLTextureWrapper> imgPtr = imgMan.GetSFMLTexture(imageName);

        sfg::Image::Ptr tempImg = sfg::Image::Create(imgPtr->image);
        buttonPic = new WidgetWrapper<sfg::Image>(tempImg);

        obje->Get()->SetImage(buttonPic->Get());
    }

    UpdateSize();
    obje->Get()->Refresh();
}


const ColorScheme& ButtonObject::GetBackgroundColorScheme() const
{
    return *backgroundColor;
}

void ButtonObject::SetBackgroundColorScheme(const ColorScheme &cs)
{
    backgroundColor->focusedColor = cs.focusedColor;
    backgroundColor->unfocusedColor = cs.unfocusedColor;
    backgroundColor->hoveredColor = cs.hoveredColor;
    backgroundColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ButtonObject::SetBackgroundColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ButtonObject::GetBorderColorScheme() const
{
    return *borderColor;
}

void ButtonObject::SetBorderColorScheme(const ColorScheme &cs)
{
    borderColor->focusedColor = cs.focusedColor;
    borderColor->unfocusedColor = cs.unfocusedColor;
    borderColor->hoveredColor = cs.hoveredColor;
    borderColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ButtonObject::SetBorderColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ButtonObject::GetTextColorScheme() const
{
    return *textColor;
}

void ButtonObject::SetTextColorScheme(const ColorScheme &cs)
{
    textColor->focusedColor = cs.focusedColor;
    textColor->unfocusedColor = cs.unfocusedColor;
    textColor->hoveredColor = cs.hoveredColor;
    textColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ButtonObject::SetTextColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

/**
 * Function destroying an extension Object.
 * Game Develop does not delete directly extension object
 * to avoid overloaded new/delete conflicts.
 */
void DestroyButtonObject(Object * object)
{
    delete object;
}

/**
 * Function creating an extension Object.
 * Game Develop can not directly create an extension object
 */
Object * CreateButtonObject(std::string name)
{
    return new ButtonObject(name);
}

