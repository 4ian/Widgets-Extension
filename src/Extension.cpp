/*
Widgets Extension
Extension providing graphical widgets.

Copyright (c) 2011 Victor Levasseur <victorlevasseur01@orange.fr>

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
    1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
	
/* CONTRIBUTORS
Florian Rival
/
	
*/

#include "Extension.h"

#if defined(GD_IDE_ONLY)
#include "GettingStartedDialog.h"
#endif

WidgetManager *WidgetManager::_singleton = 0;

Extension::Extension()
{
	DECLARE_THE_EXTENSION("Widgets",
						  _("Extension Widgets"),
						  _("Extension permettant d'utiliser des widgets\nVersion : " + WE_VERSION + " (SFGUI Version : " + SFGUI_VERSION + ")"),
						  "Victor Levasseur",
						  "zlib")

    DeclareTextBox();
    DeclareButton();
    DeclareScale();
    DeclareCheckBox();
    DeclareProgressBar();
    DeclareComboBox();

	#if defined(GD_IDE_ONLY)
	supplementaryRuntimeFiles.push_back(std::pair<std::string, std::string>("Windows", "sfgui.dll"));
	supplementaryRuntimeFiles.push_back(std::pair<std::string, std::string>("Linux", "libsfgui.so"));
	#endif

	CompleteCompilationInformation();

    //Declare to SFGUI engine the resource manager in order to make SFGUI loading pictures/fonts from Game Develop data file
	sfg::Context::Get().GetEngine().GetResourceManager().CreateLoader<GDResourceLoader>();
}

void Extension::CompleteCompilationInformation()
{
     #if defined(GD_IDE_ONLY)
     compilationInfo.runtimeOnly = false;
     #else
     compilationInfo.runtimeOnly = true;
     #endif

     #if defined(__GNUC__)
     compilationInfo.gccMajorVersion = __GNUC__;
     compilationInfo.gccMinorVersion = __GNUC_MINOR__;
     compilationInfo.gccPatchLevel = __GNUC_PATCHLEVEL__;
     #endif

     compilationInfo.boostVersion = BOOST_VERSION;

     compilationInfo.sfmlMajorVersion = 2;
     compilationInfo.sfmlMinorVersion = 0;

     #if defined(GD_IDE_ONLY)
     compilationInfo.wxWidgetsMajorVersion = wxMAJOR_VERSION;
     compilationInfo.wxWidgetsMinorVersion = wxMINOR_VERSION;
     compilationInfo.wxWidgetsReleaseNumber = wxRELEASE_NUMBER;
     compilationInfo.wxWidgetsSubReleaseNumber = wxSUBRELEASE_NUMBER;
     #endif

     compilationInfo.gdlVersion = RC_FILEVERSION_STRING;
     compilationInfo.sizeOfpInt = sizeof(int*);

     compilationInfo.informationCompleted = true;
}

extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension() {
    return new Extension;
}

extern "C" void GD_EXTENSION_API DestroyGDExtension(ExtensionBase * p) {
    delete p;
}
