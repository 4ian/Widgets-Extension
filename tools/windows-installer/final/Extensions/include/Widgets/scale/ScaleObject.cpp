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

#include "SFGUI/Scale.hpp"
#include "SFGUI/Engine.hpp"
#include "SFGUI/Context.hpp"

#include "../WidgetWrapper.h"

#include <string>
#include "ScaleObject.h"

#include "../colorScheme.h"
#include "../Manager.h"
#include "../WidgetsCommonTools.h"

#if defined(GD_IDE_ONLY)
#include <wx/wx.h>
#include "GDL/ArbitraryResourceWorker.h"
#include "GDL/MainEditorCommand.h"
#include "ScaleObjectEditor.h"
#endif

ScaleObject::ScaleObject(std::string name_) :
Object(name_),
orientation(0),
borderWidth(1),
troughWidth(5)
{
    //Create the SFGUI Button object
    sfg::Scale::Ptr tmpObj = sfg::Scale::Create(0, 100, 10, sfg::Scale::HORIZONTAL);
    obje = new WidgetWrapper<sfg::Scale>(tmpObj);

    //WidgetManager::getInstance()->mainWidget->Pack(obje->Get());

    //Default size of the object
    SetWidth(180);
    SetHeight(24);

    //Colors "Schemes"
    borderColor = new ColorScheme(sf::Color(146, 147, 151, 255),
                                  sf::Color(146, 147, 151, 255),
                                  sf::Color(146, 147, 151, 255),
                                  sf::Color(173, 173, 173, 255));

    troughColor = new ColorScheme(sf::Color(255, 255, 255, 255),
                                      sf::Color(201, 201, 201, 255),
                                      sf::Color(230, 230, 230, 255),
                                      sf::Color(140, 140, 140, 255));

    sliderColor = new ColorScheme(sf::Color(100, 100, 100, 255),
                                sf::Color(100, 100, 100, 255),
                                sf::Color(100, 100, 100, 255),
                                sf::Color(150, 150, 150, 255));

    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    obje->Get()->SetId(ToString<void*>(this));

    ConnectSignals();
    ResetEventInformations();

    UpdateProperties();
}

ScaleObject::ScaleObject(const ScaleObject &other) : Object(other)
{
    Init(other);
}

ScaleObject& ScaleObject::operator=(const ScaleObject &other)
{
    Object::operator=(other);

    if( (this) != &other )
        Init(other);

    return *this;
}

void ScaleObject::Init(const ScaleObject &other)
{
    position = other.position;
    sfg::Scale::Ptr tmpObj = sfg::Scale::Create(other.obje->Get()->GetAdjustment()->GetLower(), other.obje->Get()->GetAdjustment()->GetUpper(), other.obje->Get()->GetAdjustment()->GetMinorStep(), other.obje->Get()->GetOrientation());
    obje = new WidgetWrapper<sfg::Scale>(tmpObj);
    troughColor = new ColorScheme(*(other.troughColor));
    borderColor = new ColorScheme(*(other.borderColor));
    sliderColor = new ColorScheme(*(other.sliderColor));
    width = other.width;
    height = other.height;
    borderWidth = other.borderWidth;
    troughWidth = other.troughWidth;
    orientation = other.orientation;

    SetValue(other.GetValue());

    obje->Get()->SetId(ToString<void*>(this));
    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );

    ConnectSignals();
    ResetEventInformations();

    UpdateSize();
    UpdateProperties();
}

void ScaleObject::RecreateWidget()
{
    if(!obje->Get())
        return;

    float value = GetValue();

    sfg::Scale::Ptr tmpObj = sfg::Scale::Create(GetMinimum(), GetMaximum(), GetIncrement(), orientation == 0 ? sfg::Scale::HORIZONTAL : sfg::Scale::VERTICAL);
    obje = new WidgetWrapper<sfg::Scale>(tmpObj);

    obje->Get()->SetId(ToString<void*>(this));
    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );
    obje->Get()->SetValue(value);

    ConnectSignals();
    ResetEventInformations();

    UpdateSize();
    UpdateProperties();
}

void ScaleObject::ConnectSignals()
{
    obje->Get()->OnMouseButtonRelease.Connect(&ScaleObject::OnMouseClick, this);
    obje->Get()->OnStateChange.Connect(&ScaleObject::OnStateChanged, this);
}

bool ScaleObject::SIG_OnStateChanged(const std::string &newStateVar, RuntimeScene &scene)
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

bool ScaleObject::SIG_OnClick(const std::string &mouseButtonVar, const std::string &xPosVar, const std::string &yPosVar, RuntimeScene &scene)
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

void ScaleObject::OnMouseClick()
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

void ScaleObject::OnStateChanged()
{
    eventsInformations.stateChanged.fired = true;
}

void ScaleObject::ResetEventInformations()
{
    eventsInformations.mouseClick.fired = false;
    eventsInformations.stateChanged.fired = false;
}

ScaleObject::~ScaleObject()
{
    delete borderColor;
    delete troughColor;
    delete sliderColor;

    delete obje;
}

void ScaleObject::UpdateSize()
{
    obje->Get()->SetRequisition();
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
    obje->Get()->SetAllocation(sf::FloatRect(GetX(), GetY(), GetWidth(), GetHeight()));
}

void ScaleObject::LoadFromXml(const TiXmlElement * elem)
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

    //Trough Scheme
    if ( elem->FirstChildElement( "TroughColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load trough color full scheme.";
    }
    else
    {
        troughColor->LoadFromXml(elem->FirstChildElement( "TroughColorScheme" ));
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
    if ( elem->FirstChildElement( "SliderColorScheme" ) == NULL )
    {
        cout << "Widgets Extension Warning : Unable to load slider color full scheme.";
    }
    else
    {
        sliderColor->LoadFromXml(elem->FirstChildElement( "SliderColorScheme" ));
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

    float min = 0;
    float max = 100;
    float incr = 10;
    GD_CURRENT_ELEMENT_LOAD_ATTRIBUTE_FLOAT("Minimum", min);
    GD_CURRENT_ELEMENT_LOAD_ATTRIBUTE_FLOAT("Maximum", max);
    GD_CURRENT_ELEMENT_LOAD_ATTRIBUTE_FLOAT("Increment", incr);
    SetMaximum(max);
    SetMinimum(min);
    SetIncrement(incr);

    int troughWid = 5;
    GD_CURRENT_ELEMENT_LOAD_ATTRIBUTE_INT("TroughWidth", troughWid);
    SetTroughWidth(troughWid);

    int ori = 5;
    GD_CURRENT_ELEMENT_LOAD_ATTRIBUTE_INT("Orientation", ori);
    SetOrientation(ori);

    UpdateProperties();
}

#if defined(GD_IDE_ONLY)
void ScaleObject::SaveToXml(TiXmlElement * elem)
{
    TiXmlElement * str = new TiXmlElement( "Value" );
    elem->LinkEndChild( str );
    str->SetAttribute("value", GetValue());

    TiXmlElement * troughColorElem = new TiXmlElement( "TroughColorScheme" );
    elem->LinkEndChild( troughColorElem );
    troughColor->SaveToXml(troughColorElem);

    TiXmlElement * borderColorElem = new TiXmlElement( "BorderColorScheme" );
    elem->LinkEndChild( borderColorElem );
    borderColor->SaveToXml(borderColorElem);

    TiXmlElement * sliderColorElem = new TiXmlElement( "SliderColorScheme" );
    elem->LinkEndChild( sliderColorElem );
    sliderColor->SaveToXml(sliderColorElem);

    TiXmlElement * borderWidthElem = new TiXmlElement( "BorderWidth" );
    elem->LinkEndChild( borderWidthElem );
    borderWidthElem->SetAttribute("value", GetBorderWidth());

    GD_CURRENT_ELEMENT_SAVE_ATTRIBUTE_FLOAT("Minimum", GetMinimum());
    GD_CURRENT_ELEMENT_SAVE_ATTRIBUTE_FLOAT("Maximum", GetMaximum());
    GD_CURRENT_ELEMENT_SAVE_ATTRIBUTE_FLOAT("Increment", GetIncrement());
    GD_CURRENT_ELEMENT_SAVE_ATTRIBUTE_FLOAT("TroughWidth", GetTroughWidth());
    GD_CURRENT_ELEMENT_SAVE_ATTRIBUTE_FLOAT("Orientation", GetOrientation());
}
#endif

bool ScaleObject::LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

bool ScaleObject::LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr )
{
    m_scene = &scene;

    return true;
}

/**
 * Update animation and direction from the inital position
 */
bool ScaleObject::InitializeFromInitialPosition(const InitialPosition & position)
{
    return true;
}

/**
 * Render object at runtime
 */
bool ScaleObject::Draw( sf::RenderTarget & renderTarget )
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
bool ScaleObject::DrawEdittime(sf::RenderTarget & renderTarget)
{
    /*sf::Shape backgroundShape = sf::Shape::Rectangle(GetX(),
                                                     GetY(),
                                                     GetWidth(),
                                                     GetHeight(),
                                                     backgroundColor->unfocusedColor,
                                                     GetBorderWidth(),
                                                     borderColor->unfocusedColor);

    sf::Text text(GetString());
    text.SetCharacterSize(GetCharacterSize());
    text.SetColor(sliderColor->unfocusedColor);
    text.SetPosition(GetX() + GetPadding(), GetY() + GetPadding());

    renderTarget.Draw(backgroundShape);
    renderTarget.Draw(text);*/

    obje->Get()->Expose(renderTarget);

    return true;
}

void ScaleObject::ExposeResources(ArbitraryResourceWorker & worker)
{

}

bool ScaleObject::GenerateThumbnail(const Game & game, wxBitmap & thumbnail)
{
    thumbnail = wxBitmap("res/Widgets/Scale_logo_small.png", wxBITMAP_TYPE_ANY);

    return true;
}

void ScaleObject::EditObject( wxWindow* parent, Game & game, MainEditorCommand & mainEditorCommand )
{
    ScaleObjectEditor dialog(parent, game, *this, mainEditorCommand);
    dialog.ShowModal();

    UpdateProperties();
    UpdateSize();
}

wxPanel * ScaleObject::CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position )
{
    return NULL;
}

void ScaleObject::UpdateInitialPositionFromPanel(wxPanel * panel, InitialPosition & position)
{
}

void ScaleObject::GetPropertyForDebugger(unsigned int propertyNb, string & name, string & value) const
{
    if      ( propertyNb == 0 ) {name = _("Valeur");                     value = ToString<float>(GetValue());}
    else if ( propertyNb == 1 ) {name = _("Minimum");                     value = ToString<float>(GetMinimum());}
    else if ( propertyNb == 2 ) {name = _("Maximum");                     value = ToString<float>(GetMaximum());}
    else if ( propertyNb == 3 ) {name = _("Ecart");                     value = ToString<float>(GetIncrement());}
    else if ( propertyNb == 4 )
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

}

bool ScaleObject::ChangeProperty(unsigned int propertyNb, string newValue)
{
    if      ( propertyNb == 0 ) { SetValue(ToFloat<std::string>(newValue)); return true; }
    else if      ( propertyNb == 1 ) { SetMinimum(ToFloat<std::string>(newValue)); return true; }
    else if      ( propertyNb == 2 ) { SetMaximum(ToFloat<std::string>(newValue)); return true; }
    else if      ( propertyNb == 3 ) { SetIncrement(ToFloat<std::string>(newValue)); return true; }
    return true;
}

unsigned int ScaleObject::GetNumberOfProperties() const
{
    return 5;
}
#endif

void ScaleObject::OnPositionChanged()
{
    obje->Get()->SetPosition( sf::Vector2f( GetX(), GetY() ) );
    obje->Get()->SetRequisition( sf::Vector2f( GetWidth() , GetHeight() ) );
}

void ScaleObject::SetValue(float v)
{
    obje->Get()->SetValue(v);
}

double ScaleObject::GetValue() const
{
    return obje->Get()->GetValue();
}

void ScaleObject::SetMinimum(float min)
{
    obje->Get()->GetAdjustment()->SetLower(min);
}

float ScaleObject::GetMinimum() const
{
    return obje->Get()->GetAdjustment()->GetLower();
}

void ScaleObject::SetMaximum(float max)
{
    obje->Get()->GetAdjustment()->SetUpper(max);
}

float ScaleObject::GetMaximum() const
{
    return obje->Get()->GetAdjustment()->GetUpper();
}

void ScaleObject::SetIncrement(float incre)
{
    obje->Get()->GetAdjustment()->SetMinorStep(incre);
}

float ScaleObject::GetIncrement() const
{
    return obje->Get()->GetAdjustment()->GetMinorStep();
}

/**
 * ScaleObject provides a basic bounding box.
 */
std::vector<RotatedRectangle> ScaleObject::GetHitBoxes() const
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
float ScaleObject::GetDrawableX() const
{
    return GetX();
}

/**
 * Get the real Y position of the text
 */
float ScaleObject::GetDrawableY() const
{
    return GetY();
}

/**
 * Width is the width of the current sprite.
 */
/*float ScaleObject::GetWidth() const
{
    return text.GetRect().Width;
}*/

/**
 * Height is the height of the current sprite.
 */
/*float ScaleObject::GetHeight() const
{
    return text.GetRect().Height;
}*/

/**
 * X center is computed with text rectangle
 */
float ScaleObject::GetCenterX() const
{
    return GetWidth() / 2;
}

/**
 * Y center is computed with text rectangle
 */
float ScaleObject::GetCenterY() const
{
    return GetHeight() / 2;
}

void ScaleObject::UpdateTime(float ElapsedTime)
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


void ScaleObject::UpdateProperties()
{
    //Update BackgroundColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId(), "TroughColor", troughColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":PRELIGHT", "TroughColor", troughColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":ACTIVE", "TroughColor", troughColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":INSENSITIVE", "TroughColor", troughColor->disabledColor );

    //Update BorderColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId(), "BorderColor", borderColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":PRELIGHT", "BorderColor", borderColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":ACTIVE", "BorderColor", borderColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":INSENSITIVE", "BorderColor", borderColor->disabledColor );

    //Update sliderColor
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId(), "SliderColor", sliderColor->unfocusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":PRELIGHT", "SliderColor", sliderColor->hoveredColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":ACTIVE", "SliderColor", sliderColor->focusedColor );
    sfg::Context::Get().GetEngine().SetProperty<sf::Color>( "Scale#" + obje->Get()->GetId() + ":INSENSITIVE", "SliderColor", sliderColor->disabledColor );

    //Update border width and padding
    sfg::Context::Get().GetEngine().SetProperty<float>("Scale#" + obje->Get()->GetId(), "BorderWidth", static_cast<float>(GetBorderWidth()));

    //Update trough width
    sfg::Context::Get().GetEngine().SetProperty<float>("Scale#" + obje->Get()->GetId(), "TroughWidth", static_cast<float>(GetTroughWidth()));
}

void ScaleObject::SetDisabled(bool is)
{
    if(is)
        obje->Get()->SetState(sfg::Widget::INSENSITIVE);
    else
        obje->Get()->SetState(sfg::Widget::NORMAL);
}

bool ScaleObject::IsDisabled()
{
    return (obje->Get()->GetState() == sfg::Widget::INSENSITIVE);
}


const ColorScheme& ScaleObject::GetTroughColorScheme() const
{
    return *troughColor;
}

void ScaleObject::SetTroughColorScheme(const ColorScheme &cs)
{
    troughColor->focusedColor = cs.focusedColor;
    troughColor->unfocusedColor = cs.unfocusedColor;
    troughColor->hoveredColor = cs.hoveredColor;
    troughColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ScaleObject::SetTroughColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        troughColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        troughColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        troughColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        troughColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

const ColorScheme& ScaleObject::GetBorderColorScheme() const
{
    return *borderColor;
}

void ScaleObject::SetBorderColorScheme(const ColorScheme &cs)
{
    borderColor->focusedColor = cs.focusedColor;
    borderColor->unfocusedColor = cs.unfocusedColor;
    borderColor->hoveredColor = cs.hoveredColor;
    borderColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ScaleObject::SetBorderColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
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

const ColorScheme& ScaleObject::GetSliderColorScheme() const
{
    return *sliderColor;
}

void ScaleObject::SetSliderColorScheme(const ColorScheme &cs)
{
    sliderColor->focusedColor = cs.focusedColor;
    sliderColor->unfocusedColor = cs.unfocusedColor;
    sliderColor->hoveredColor = cs.hoveredColor;
    sliderColor->disabledColor = cs.disabledColor;

    UpdateProperties();
}

void ScaleObject::SetSliderColorScheme(const std::string &focused, const std::string &hovered, const std::string &unfocused, const std::string &disabled)
{
    if(focused != "")
        sliderColor->focusedColor = WidgetsCommonTools::GetColorFromString(focused, 255);
    if(hovered != "")
        sliderColor->hoveredColor = WidgetsCommonTools::GetColorFromString(hovered, 255);
    if(unfocused != "")
        sliderColor->unfocusedColor = WidgetsCommonTools::GetColorFromString(unfocused, 255);
    if(disabled != "")
        sliderColor->disabledColor = WidgetsCommonTools::GetColorFromString(disabled, 255);

    UpdateProperties();
}

void ScaleObject::SetOrientation(int ori)
{
    orientation = ori;
    RecreateWidget();
}

int ScaleObject::GetOrientation()
{
    return orientation;
}

/**
 * Function destroying an extension Object.
 * Game Develop does not delete directly extension object
 * to avoid overloaded new/delete conflicts.
 */
void DestroyScaleObject(Object * object)
{
    delete object;
}

/**
 * Function creating an extension Object.
 * Game Develop can not directly create an extension object
 */
Object * CreateScaleObject(std::string name)
{
    return new ScaleObject(name);
}

