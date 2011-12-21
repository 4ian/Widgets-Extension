/**

This file is a part of the "Extension Widgets" developped by Victor Levasseur and distributed as free software.

**/

/**

This file is a part of the "Extension Widgets" distributed as free software.

**/

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
