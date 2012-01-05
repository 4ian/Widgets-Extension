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

#ifndef TEXTAREAObject_H
#define TEXTAREAObject_H

#include "GDL/Object.h"
#include "GDL/ResourceWrapper.h"
#include "SFML/Config.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFGUI/SharedPtr.hpp"

//GD Classes
class ImageManager;
class RuntimeScene;
class Object;
class ImageManager;
class InitialPosition;

//SFML Classes
class RenderTexture;
namespace sf
{
    class Text;
    class Color;
    class RenderWindow;
}

//Custom Classes
class ColorScheme;

namespace sfg
{
    class Entry;
    class Widget;
}

#if defined(GD_IDE_ONLY)
class wxBitmap;
class Game;
class wxWindow;
class MainEditorCommand;
class ResourcesMergingHelper;
#endif

/**
 * Text Area Object used to receive text from user.
 */
class GD_EXTENSION_API TextAreaObject : public Object
{
    public :

        TextAreaObject(std::string name_);
        TextAreaObject(const TextAreaObject&);
        TextAreaObject& operator=(const TextAreaObject&);

        virtual ~TextAreaObject();
        virtual ObjSPtr Clone() { return boost::shared_ptr<Object>(new TextAreaObject(*this));}

        virtual bool LoadRuntimeResources(const RuntimeScene & scene, const ImageManager & imageMgr );
        virtual bool LoadResources(const RuntimeScene & scene, const ImageManager & imageMgr );
        virtual bool InitializeFromInitialPosition(const InitialPosition & position);

        virtual bool Draw(sf::RenderTarget & renderTarget);

        #if defined(GD_IDE_ONLY)
        virtual bool DrawEdittime(sf::RenderTarget & renderTarget);
        virtual void ExposeResources(ArbitraryResourceWorker & worker);
        virtual bool GenerateThumbnail(const Game & game, wxBitmap & thumbnail);

        virtual void EditObject( wxWindow* parent, Game & game_, MainEditorCommand & mainEditorCommand_ );
        virtual wxPanel * CreateInitialPositionPanel( wxWindow* parent, const Game & game_, const Scene & scene_, const InitialPosition & position );
        virtual void UpdateInitialPositionFromPanel(wxPanel * panel, InitialPosition & position);

        virtual void GetPropertyForDebugger (unsigned int propertyNb, std::string & name, std::string & value) const;
        virtual bool ChangeProperty(unsigned int propertyNb, std::string newValue);
        virtual unsigned int GetNumberOfProperties() const;
        #endif

        virtual void LoadFromXml(const TiXmlElement * elemScene);
        #if defined(GD_IDE_ONLY)
        virtual void SaveToXml(TiXmlElement * elemScene);
        #endif

        virtual void OnPositionChanged();

        virtual float GetWidth() const {return width;};
        virtual float GetHeight() const {return height;};

        void UpdateSize();
        virtual void SetWidth(float s) {width = s; UpdateSize();};
        virtual void SetHeight(float s) {height = s; UpdateSize();};

        void UpdateProperties();

        virtual float GetDrawableX() const;
        virtual float GetDrawableY() const;

        virtual float GetCenterX() const;
        virtual float GetCenterY() const;

        void SetString(const std::string &str);
        std::string GetString() const;

        inline void SetCharacterSize(float size) { fontSize = size; UpdateProperties(); };
        inline float GetCharacterSize() const { return fontSize; };

        void SetFont(std::string fontName_);
        inline std::string GetFont() const {return fontName;};

        void SetBorderWidth(int w) {borderWidth = w; UpdateProperties(); };
        int GetBorderWidth() const {return borderWidth;};

        void UpdateTime(float);

        void SetActive(bool is);
        bool IsActive();

        void SetDisabled(bool is);
        bool IsDisabled();

        int GetPadding() {return padding;};
        void SetPadding(int v) {padding = v;};

        sf::Uint32 GetHideCharacter() const;
        void SetHideCharacter(sf::Uint32);

        int GetMaximumLength() const;
        void SetMaximumLength(int s);

        const ColorScheme& GetBackgroundColorScheme() const;
        void SetBackgroundColorScheme(const ColorScheme &);
        void SetBackgroundColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetBorderColorScheme() const;
        void SetBorderColorScheme(const ColorScheme &);
        void SetBorderColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetTextColorScheme() const;
        void SetTextColorScheme(const ColorScheme &);
        void SetTextColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        virtual std::vector<RotatedRectangle> GetHitBoxes() const;

        //Signals (use by conditions)
        bool SIG_OnTextEntered(RuntimeScene&);
        bool SIG_OnClick(const std::string&, const std::string&, const std::string&, RuntimeScene&);
        bool SIG_OnStateChanged(const std::string&, RuntimeScene&);


    private:
        //Init
        void Init(const TextAreaObject&);

        /**
        Connect each signals from the widget with all corresponding functions
        **/
        void ConnectSignals();

        //Signals Management (Slot connected to the sfg::Widget)
        void OnTextEntered();
        void OnMouseClick();
        void OnStateChanged();

        //Signals informations storage
        /**
        Contain all information for each event type (Text entered, Mouse clicked, ...)
        "fired" member of each sub-struct equals true if the event has been fired, otherwise false.
        The other members contain information about the event.
        **/
        struct
        {
            struct
            {
                bool fired;

            } textEntered;

            struct
            {
                bool fired;
                int button;
                int x;
                int y;

            } mouseClick;

            struct
            {
                bool fired;
            } stateChanged;

        } eventsInformations;
        void ResetEventInformations();

        //Object position
        sf::Vector2f position; ///< Contains the position

        //Object
        sfg::SharedPtr<sfg::Entry> obj;

        //Size
        float width; ///< Width of the widget
        float height; ///< Height of the widget

        unsigned int fontSize; ///< Font size
        std::string fontName; ///< Font Name (not used now)

        //Colors
        ColorScheme *borderColor; ///< Color Scheme of the widget's border
        ColorScheme *backgroundColor; ///< Color Scheme of the widget's background
        ColorScheme *textColor; ///< Color Scheme of the widget's text

        //Border Width
        unsigned int borderWidth; ///< Thickness of the border
        unsigned int padding; ///< Text padding in the widget

        //Scene pointer
        const RuntimeScene *m_scene;
};

void DestroyTextAreaObject(Object * object);
Object * CreateTextAreaObject(std::string name);

#endif // TextAreaObject_H
