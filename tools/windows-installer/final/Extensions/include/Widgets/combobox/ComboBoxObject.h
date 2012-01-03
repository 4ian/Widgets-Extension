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

#ifndef ComboBoxObject_H
#define ComboBoxObject_H

#include <vector>

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
    class ComboBox;
    class Widget;
}

typedef std::vector<std::string> ElementList;

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
class GD_EXTENSION_API ComboBoxObject : public Object
{
    public :

        ComboBoxObject(std::string name_);
        ComboBoxObject(const ComboBoxObject&);
        ComboBoxObject& operator=(const ComboBoxObject&);

        virtual ~ComboBoxObject();
        virtual ObjSPtr Clone() { return boost::shared_ptr<Object>(new ComboBoxObject(*this));}

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

        const ColorScheme& GetBackgroundColorScheme() const;
        void SetBackgroundColorScheme(const ColorScheme &);
        void SetBackgroundColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetBorderColorScheme() const;
        void SetBorderColorScheme(const ColorScheme &);
        void SetBorderColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetTextColorScheme() const;
        void SetTextColorScheme(const ColorScheme &);
        void SetTextColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetArrowColorScheme() const;
        void SetArrowColorScheme(const ColorScheme &);
        void SetArrowColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetHighlightColorScheme() const;
        void SetHighlightColorScheme(const ColorScheme &);
        void SetHighlightColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        virtual std::vector<RotatedRectangle> GetHitBoxes() const;

        const ElementList& GetAllElements() const;
        void ClearAndSetElements(const ElementList&);

        void LoadElementsFromXml(const TiXmlElement*);
        void SaveElementsToXml(TiXmlElement*);

        int GetSelectedElement() const;
        void SelectElement(unsigned int);

        std::string GetElementString(unsigned int) const;
        void SetElementString(unsigned int, const std::string&);

        unsigned int GetElementsCount() const;

        void AddElement(unsigned int, const std::string&);
        void DeleteElement(unsigned int);

        //Signals (use by conditions)
        bool SIG_OnClick(const std::string&, const std::string&, const std::string&, RuntimeScene&);
        bool SIG_OnStateChanged(const std::string&, RuntimeScene&);


    private:
        //Init
        void Init(const ComboBoxObject&);

        /**
        Connect each signals from the widget with all corresponding functions
        **/
        void ConnectSignals();

        //Signals Management (Slot connected to the sfg::Widget)
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
        sfg::SharedPtr<sfg::ComboBox> obj;

        //Size
        float width; ///< Width of the widget
        float height; ///< Height of the widget

        unsigned int fontSize; ///< Font size
        std::string fontName; ///< Font Name (not used now)

        //Colors
        ColorScheme *borderColor; ///< Color Scheme of the widget's border
        ColorScheme *backgroundColor; ///< Color Scheme of the widget's background
        ColorScheme *textColor; ///< Color Scheme of the widget's text
        ColorScheme *arrowColor; ///< Color Scheme of the widget's arrow
        ColorScheme *highlightColor; ///< Color Scheme of the widget's highlight

        //Border Width
        unsigned int borderWidth; ///< Thickness of the border
        unsigned int padding; ///< Text padding in the widget

        //Scene pointer
        const RuntimeScene *m_scene;
};

void DestroyComboBoxObject(Object * object);
Object * CreateComboBoxObject(std::string name);

#endif // ComboBoxObject_H
