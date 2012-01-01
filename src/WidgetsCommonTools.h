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
