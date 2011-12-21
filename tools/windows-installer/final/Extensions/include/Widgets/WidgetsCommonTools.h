/**

This file is a part of the "Extension Widgets" distributed as free software.

**/

#ifndef WIDGETCOMMONTOOLS_H
#define WIDGETCOMMONTOOLS_H

#include <string>
#include <vector>
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"

#include "GDL/RuntimeGame.h"

class RuntimeScene;

#if defined(GD_IDE_ONLY)
class wxColour;
#endif

namespace WidgetsCommonTools
{
    sf::Color GetColorFromString(const std::string &colorString, const unsigned int alpha = 255);

    /**
     * This function return the real position (using Views) of a position relative to Window.
     * \param A reference to the scene
     * \param The position of the point relative to the window
     * \param The name of the layer of the object
     **/
    sf::Vector2f GetViewsPosition(const RuntimeScene&, const sf::Vector2f&, const std::string&);

    /**
     * Overload function to use Vector2i instead of Vector2f.
     **/
    sf::Vector2f GetViewsPosition(const RuntimeScene&, const sf::Vector2i&, const std::string&);

    #if defined(GD_IDE_ONLY)
    const wxColour& GetWxColourFromSfColor(const sf::Color &color);
    const sf::Color& GetSfColorFromWxColour(const wxColour &color);
    #endif
}

#endif
