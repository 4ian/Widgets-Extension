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

#ifndef ProgressBarObject_H
#define ProgressBarObject_H

#include "GDL/Object.h"

#include "SFML/Config.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFGUI/SharedPtr.hpp"

//GD Classes
class ImageManager;
class RuntimeScene;
class ResourceWrapper;
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

//SFGUI Classes
class ColorScheme;

namespace sfg
{
    class ProgressBar;
    class Widget;
}


#if defined(GD_IDE_ONLY)
class wxBitmap;
class Game;
class wxWindow;
class MainEditorCommand;
#endif

/**
 * Progress bar object allowing the game to display a progression
 */
class GD_EXTENSION_API ProgressBarObject : public Object
{
    public :

        ProgressBarObject(std::string name_);
        ProgressBarObject(const ProgressBarObject&);
        ProgressBarObject& operator=(const ProgressBarObject&);

        virtual ~ProgressBarObject();
        virtual ObjSPtr Clone() { return boost::shared_ptr<Object>(new ProgressBarObject(*this));}

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

        void SetValue(float v);
        double GetValue() const;

        void SetOrientation(int ori);
        int GetOrientation();

        void SetBorderWidth(int w) {borderWidth = w; UpdateProperties(); };
        int GetBorderWidth() const {return borderWidth;};

        void SetBarBorderWidth(int w) {barBorderWidth = w; UpdateProperties(); };
        int GetBarBorderWidth() const {return barBorderWidth;};

        void UpdateTime(float);

        void SetDisabled(bool is);
        bool IsDisabled();

        const ColorScheme& GetBackgroundColorScheme() const;
        void SetBackgroundColorScheme(const ColorScheme &);
        void SetBackgroundColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetBorderColorScheme() const;
        void SetBorderColorScheme(const ColorScheme &);
        void SetBorderColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        const ColorScheme& GetBarColorScheme() const;
        void SetBarColorScheme(const ColorScheme &);
        void SetBarColorScheme(const std::string&, const std::string&, const std::string&, const std::string&);

        virtual std::vector<RotatedRectangle> GetHitBoxes() const;

        //Signals (use by conditions)
        bool SIG_OnClick(const std::string&, const std::string&, const std::string&, RuntimeScene&);
        bool SIG_OnStateChanged(const std::string&, RuntimeScene&);


    private:
        //Init
        void Init(const ProgressBarObject&);

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
        sfg::SharedPtr<sfg::ProgressBar> obj;

        //Orientation
        int orientation;

        //Size
        float width; ///< Width of the widget
        float height; ///< Height of the widget

        //Colors
        ColorScheme *borderColor; ///< Color Scheme of the widget's border
        ColorScheme *backgroundColor; ///< Color Scheme of the widget's background
        ColorScheme *barColor; ///< Color Scheme of the widget's slider

        //Border Width
        unsigned int borderWidth; ///< Thickness of the border
        unsigned int barBorderWidth; ///< Thickness of the bar border

        //Scene pointer
        const RuntimeScene *m_scene;
};

void DestroyProgressBarObject(Object * object);
Object * CreateProgressBarObject(std::string name);

#endif // ProgressBarObject_H
