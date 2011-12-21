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

#include "SFGUI/Box.hpp"

#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H


class GD_EXTENSION_API WidgetManager
{
    public:

    //Méthode de singleton
    static WidgetManager *getInstance ()
    {
        if (0 == _singleton)
        {
            _singleton =  new WidgetManager;
        }

        return _singleton;
    }

    static void kill ()
    {
        if (0 != _singleton)
        {
            delete _singleton;
            _singleton = 0;
        }
    }

    void *focusedWidget;

    static WidgetManager *_singleton;

    private:
    WidgetManager()
    {
        focusedWidget = 0;
    };
    ~WidgetManager() {};
};

#endif
