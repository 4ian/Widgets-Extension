/**

This file is a part of the "Extension Widgets" distributed as free software.

**/

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
