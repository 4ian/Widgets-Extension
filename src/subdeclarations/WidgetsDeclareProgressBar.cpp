#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"

void Extension::DeclareProgressBar()
{
    //Declaration of all objects available
	DECLARE_OBJECT("ProgressBar",
				   _("Barre de progression"),
				   _("Objet permattant au jeu d'afficher une progression."),
				   "res/Widgets/ProgressBar_logo_smallO.png",
				   &CreateProgressBarObject,
				   &DestroyProgressBarObject,
				   "ProgressBarObject");

		#if defined(GD_IDE_ONLY)

		objInfos.SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_OBJECT_ACTION("ProgressBar-Value",
					   _("Modifier la valeur"),
					   _("Modifier la valeur de la barre de progression.\nDoit �tre comprise entre 0 et 1."),
					   _("Barre de progression: Faire _PARAM2__PARAM1_ � la valeur de _PARAM0_"),
					   _("Barre de progression"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("expression", _("Valeur"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetValue").SetManipulatedType("number").SetAssociatedGetter("GetValue").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("ProgressBar-Value",
					   _("Tester la valeur"),
					   _("Teste la valeur comprise entre 0 et 1 d'une barre de progression."),
					   _("Barre de progression: La valeur s�lectionn�e de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Barre de progression"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("expression", _("Valeur � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetValue").SetManipulatedType("number").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_EXPRESSION("ProgressBar::Value", _("Valeur"), _("Valeur"), _("Barre de progression"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetValue").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");
		DECLARE_END_OBJECT_EXPRESSION()

		DECLARE_OBJECT_ACTION("ProgressBar-State-Disable",
					   _("Active/D�sactive le widget"),
					   _("D�sactive ou r�active le widget."),
					   _("Barre de progression: D�sactiver le widget _PARAM0_ ? _PARAM1_ "),
					   _("Barre de progression"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("yesorno", _("Oui pour le d�sactiver, Non pour l'activer"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetDisabled").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("ProgressBar-State-Disable",
					   _("Tester si le widget est d�sactiv�"),
					   _("Teste si le widget est d�sactiv�."),
					   _("Barre de progression: _PARAM0_ est d�sactiv�"),
					   _("Barre de progression"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsDisabled").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_ACTION("ProgressBar-Color-BackgroundScheme",
					   _("Modifier la couleur d'arri�re-plan"),
					   _("Modifier la couleur d'arri�re-plan d'une barre de progression.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Barre de progression: Changer la couleur d'arri�re-plan de _PARAM0_"),
					   _("Barre de progression"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBackgroundColorScheme").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("ProgressBar-Color-BorderScheme",
					   _("Modifier la couleur de la bordure"),
					   _("Modifier la couleur de la bordure d'une barre de progression.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Barre de progression: Changer la couleur de la bordure de _PARAM0_"),
					   _("Barre de progression"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBorderColorScheme").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("ProgressBar-Color-BarScheme",
					   _("Modifier la couleur de la barre"),
					   _("Modifier la couleur de la barre (partie indiquant la progression) d'une barre de progression.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Barre de progression: Changer la couleur de la barre de _PARAM0_"),
					   _("Barre de progression"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBarColorScheme").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("ProgressBar-Sig-OnClick",
					   _("Un clic a eu lieu"),
					   _("Est valide uniquement lorsqu'un clic a �t� per�u par le widget."),
					   _("Barre de progression: Un clic a �t� per�u par _PARAM0_"),
					   _("Barre de progression"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le bouton appuy� (\"Left\", \"Right\" ou \"Middle\")"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position X du clic"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position Y du clic"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnClick").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("ProgressBar-Sig-OnStateChanged",
					   _("L'�tat du widget a chang�"),
					   _("Est valide uniquement lorsque l'�tat du widget change."),
					   _("Barre de progression: L'�tat de _PARAM0_ a chang�"),
					   _("Barre de progression"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "ProgressBar", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le nouvel �tat du widget (Active = Actif, Hovered = Survol�, Normal, Disabled = D�sactiv�)"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnStateChanged").SetIncludeFile("Widgets/progressbar/ProgressBarObject.h");

		DECLARE_END_OBJECT_CONDITION()


		#endif
	DECLARE_END_OBJECT()
}
