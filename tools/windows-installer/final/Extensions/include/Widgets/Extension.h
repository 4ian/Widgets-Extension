/*
Widgets Extension
Extension providing graphical widgets.
*/

#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H

#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "textbox/TextAreaObject.h"
#include "button/ButtonObject.h"
#include "checkbox/CheckBoxObject.h"
#include "scale/ScaleObject.h"
#include "progressbar/ProgressBarObject.h"
#include "combobox/ComboBoxObject.h"

#include "Manager.h"
#include "GDResourceLoader.h"
#include "SFGUI/Context.hpp"
#include "SFGUI/Engine.hpp"

#include <boost/version.hpp>

#include "version.h"

/**
 * This class declare information about the extension.
 */
class Extension : public ExtensionBase
{
    public:

        /**
         * Constructor of an extension declares everything the extension contains : Objects, actions, conditions and expressions.
         */
        Extension();

        virtual ~Extension() {};

    protected:
    private:

        /**
         * This function is called by Game Develop so
         * as to complete information about how the extension was compiled ( which libs... )
         * -- Do not need to be modified. --
         */
        void CompleteCompilationInformation();

        void DeclareTextBox();
        void DeclareButton();
        void DeclareScale();
        void DeclareCheckBox();
        void DeclareProgressBar();
        void DeclareComboBox();

};

/**
 * Used by Game Develop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension();

/**
 * Used by Game Develop to destroy the extension class
 * -- Do not need to be modified. --
 */
extern "C" void GD_EXTENSION_API DestroyGDExtension(ExtensionBase * p);
#endif

