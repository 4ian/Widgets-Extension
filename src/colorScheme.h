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

#ifndef COLORSCHEME_H
#define COLORSCHEME_H

#include "SFML/Graphics/Color.hpp"

class TiXmlElement;

/**
 * Class ColorScheme
 *
 * This class manage a scheme of 4 colors each representing one widget's state.
 */
class ColorScheme
{
    public:

    sf::Color focusedColor;
    sf::Color unfocusedColor;
    sf::Color hoveredColor;
    sf::Color disabledColor;

    ColorScheme(sf::Color focused, sf::Color unfocused, sf::Color hovered, sf::Color disabled = sf::Color(0, 0, 0, 255));
    ColorScheme(sf::Color all);

    /**
     * Read the color scheme from a XML element.
     **/
    void LoadFromXml(const TiXmlElement*);

    #if defined(GD_IDE_ONLY)
    /**
     * Save the color scheme into a XML element.
     * Only defined for Edittime compilation.
     **/
    void SaveToXml(TiXmlElement * elem);
    #endif

};

#endif
