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

#ifndef WIDGETSDECLAREMACROS_H
#define WIDGETSDECLAREMACROS_H

#define DEFINE_COLORSCHEME_ACTION(_id, _smallDesc, _bigDesc, _visibleStr, _categorie, _type, _functionName) \
        DECLARE_OBJECT_ACTION(_id , \
					   _smallDesc , \
					   _bigDesc + _("\nLes 4 couleurs correspondent aux 4 état possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."), \
					   _visibleStr , \
					   _categorie , \
					   "res/Widgets/color24.png", \
					   "res/Widgets/color.png"); \
\
			instrInfo.AddParameter("object", _("Objet"), _type , false);\
			instrInfo.AddParameter("color", _("Actif"), "", true);\
			instrInfo.AddParameter("color", _("Survolé (la souris est dessus)"), "", true);\
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survolé)"), "", true);\
			instrInfo.AddParameter("color", _("Désactivé"), "", true);\
\
			instrInfo.cppCallingInformation.SetFunctionName( _functionName );\
\
		DECLARE_END_OBJECT_ACTION()

#endif
