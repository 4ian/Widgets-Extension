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
