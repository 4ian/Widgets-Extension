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

#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"

void Extension::DeclareScale()
{
    DECLARE_OBJECT("Scale",
				   _("Glissi�re"),
				   _("Objet permettant de s�lectionner un nombre sur une glissi�re dans un intervalle."),
				   "res/Widgets/Scale_logo_smallO.png",
				   &CreateScaleObject,
				   &DestroyScaleObject,
				   "ScaleObject");

		#if defined(GD_IDE_ONLY)

		objInfos.SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_OBJECT_ACTION("Scale-Value",
					   _("Modifier la valeur"),
					   _("Modifier la valeur s�lectionn�e de la glissi�re."),
					   _("Glissi�re: Faire _PARAM2__PARAM1_ � la valeur de _PARAM0_"),
					   _("Glissi�re"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Valeur"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetValue").SetManipulatedType("number").SetAssociatedGetter("GetValue").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Scale-Value",
					   _("Tester la valeur"),
					   _("Teste la valeur s�lectionn�e d'une glissi�re."),
					   _("Glissi�re: La valeur s�lectionn�e de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Glissi�re"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetValue").SetManipulatedType("number").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_EXPRESSION("Scale::Value", _("Valeur"), _("Valeur"), _("Glissi�re"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "Scale", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetValue").SetIncludeFile("Widgets/scale/ScaleObject.h");
		DECLARE_END_OBJECT_EXPRESSION()


		DECLARE_OBJECT_ACTION("Scale-Maximum",
					   _("Modifier le maximum"),
					   _("Modifier le maximum de la glissi�re."),
					   _("Glissi�re: Faire _PARAM2__PARAM1_ au maximum de _PARAM0_"),
					   _("Glissi�re"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Maximum"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetMaximum").SetManipulatedType("number").SetAssociatedGetter("GetMaximum").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Scale-Maximum",
					   _("Tester le maximum"),
					   _("Teste le maximum d'une glissi�re."),
					   _("Glissi�re: Le maximum de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Glissi�re"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Maximum � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetMaximum").SetManipulatedType("number").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_EXPRESSION("Scale::Maximum", _("Maximum"), _("Maximum"), _("Glissi�re"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "Scale", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetMaximum").SetIncludeFile("Widgets/scale/ScaleObject.h");
		DECLARE_END_OBJECT_EXPRESSION()

		DECLARE_OBJECT_ACTION("Scale-Minimum",
					   _("Modifier le minimum"),
					   _("Modifier le minimum de la glissi�re."),
					   _("Glissi�re: Faire _PARAM2__PARAM1_ au minimum de _PARAM0_"),
					   _("Glissi�re"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Minimum"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetMinimum").SetManipulatedType("number").SetAssociatedGetter("GetMinimum").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Scale-Minimum",
					   _("Tester le minimum"),
					   _("Teste le minimum d'une glissi�re."),
					   _("Glissi�re: Le minimum de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Glissi�re"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Minimum � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetMinimum").SetManipulatedType("number").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_EXPRESSION("Scale::Minimum", _("Minimum"), _("Minimum"), _("Glissi�re"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "Scale", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetMinimum").SetIncludeFile("Widgets/scale/ScaleObject.h");
		DECLARE_END_OBJECT_EXPRESSION()

		DECLARE_OBJECT_ACTION("Scale-Increment",
					   _("Modifier l'�cart"),
					   _("Modifier l'�cart entre les valeurs de la glissi�re."),
					   _("Glissi�re: Faire _PARAM2__PARAM1_ � l'�cart entre les valeurs de _PARAM0_"),
					   _("Glissi�re"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Ecart entre les valeurs"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetIncrement").SetManipulatedType("number").SetAssociatedGetter("GetIncrement").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Scale-Increment",
					   _("Tester l'�cart entre les valeurs"),
					   _("Teste l'�cart entre les valeurs possibles d'une glissi�re."),
					   _("Glissi�re: L'�cart entre les valeurs de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Glissi�re"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("expression", _("Ecart � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetIncrement").SetManipulatedType("number").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_EXPRESSION("Scale::Increment", _("Ecart entre valeurs"), _("Ecart entre valeurs"), _("Glissi�re"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "Scale", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetIncrement").SetIncludeFile("Widgets/scale/ScaleObject.h");
		DECLARE_END_OBJECT_EXPRESSION()

		DECLARE_OBJECT_CONDITION("Scale-Sig-OnClick",
					   _("Un clic a eu lieu"),
					   _("Est valide uniquement lorsqu'un clic a �t� per�u par le widget."),
					   _("Glissi�re: Un clic a �t� per�u par _PARAM0_"),
					   _("Glissi�re"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le bouton appuy� (\"Left\", \"Right\" ou \"Middle\")"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position X du clic"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position Y du clic"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnClick").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("Scale-Sig-OnStateChanged",
					   _("L'�tat du widget a chang�"),
					   _("Est valide uniquement lorsque l'�tat du widget change."),
					   _("Glissi�re: L'�tat de _PARAM0_ a chang�"),
					   _("Glissi�re"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le nouvel �tat du widget (Active = Actif, Hovered = Survol�, Normal, Disabled = D�sactiv�)"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnStateChanged").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_ACTION("Scale-State-Disable",
					   _("Active/D�sactive le widget"),
					   _("D�sactive ou r�active le widget."),
					   _("Glissi�re: D�sactiver le widget _PARAM0_ ? _PARAM1_ "),
					   _("Glissi�re"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("yesorno", _("Oui pour le d�sactiver, Non pour l'activer"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetDisabled").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Scale-State-Disable",
					   _("Tester si le widget est d�sactiv�"),
					   _("Teste si le widget est d�sactiv�."),
					   _("Glissi�re: _PARAM0_ est d�sactiv�"),
					   _("Glissi�re"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsDisabled").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_ACTION("Scale-Color-TroughScheme",
					   _("Modifier la couleur de la glissi�re"),
					   _("Modifier la couleur de la glissi�re.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Glissi�re: Changer la couleur de la glissi�re de _PARAM0_"),
					   _("Glissi�re"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetTroughColorScheme").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Scale-Color-BorderScheme",
					   _("Modifier la couleur de la bordure"),
					   _("Modifier la couleur de la bordure d'une glissi�re.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Glissi�re: Changer la couleur de la bordure de _PARAM0_"),
					   _("Glissi�re"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBorderColorScheme").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Scale-Color-SliderScheme",
					   _("Modifier la couleur du curseur"),
					   _("Modifier la couleur du curseur d'une glissi�re.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Glissi�re: Changer la couleur du curseur de _PARAM0_"),
					   _("Glissi�re"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "Scale", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetSliderColorScheme").SetIncludeFile("Widgets/scale/ScaleObject.h");

		DECLARE_END_OBJECT_ACTION()

		#endif

	DECLARE_END_OBJECT()
}
