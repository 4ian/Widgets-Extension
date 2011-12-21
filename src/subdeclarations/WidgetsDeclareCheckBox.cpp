#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"

void Extension::DeclareCheckBox()
{
    DECLARE_OBJECT("CheckBox",
				   _("Case à cocher"),
				   _("Objet permettant à l'utilisateur de sélectionner \"vrai\" ou \"faux\"."),
				   "res/Widgets/CheckBox_logo_smallO.png",
				   &CreateCheckBoxObject,
				   &DestroyCheckBoxObject,
				   "CheckBoxObject");

		#if defined(GD_IDE_ONLY)

		objInfos.SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");



		DECLARE_OBJECT_ACTION("CheckBox-String",
					   _("Modifier le texte"),
					   _("Modifier le texte d'une case à cocher."),
					   _("Case à cocher: Faire _PARAM2__PARAM1_ au texte de _PARAM0_"),
					   _("Case à cocher"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("string", _("Texte"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetString").SetManipulatedType("string").SetAssociatedGetter("GetString").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("CheckBox-String",
					   _("Tester le texte"),
					   _("Teste le texte d'une case à cocher."),
					   _("Case à cocher: Le texte de _PARAM0_ est _PARAM2_ à _PARAM1_"),
					   _("Case à cocher"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("string", _("Texte à tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetManipulatedType("string").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_STR_EXPRESSION("CheckBox::String", _("Texte"), _("Texte"), _("Case à cocher"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");
		DECLARE_END_OBJECT_STR_EXPRESSION()

		DECLARE_OBJECT_ACTION("CheckBox-Checked",
					   _("Cocher/Décocher"),
					   _("Coche ou décoche la case à cocher."),
					   _("Case à cocher: Cocher _PARAM0_ ? _PARAM1_"),
					   _("Case à cocher"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("yesorno", _("Coché ou pas"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetChecked").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("CheckBox-Checked",
					   _("Tester si cochée"),
					   _("Teste si une case à cocher est cochée."),
					   _("Case à cocher: La case _PARAM0_ est cochée"),
					   _("Case à cocher"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsChecked").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_EXPRESSION("CheckBox::IsChecked", _("Cochée ?"), _("Cochée ?"), _("Case à cocher"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsChecked").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");
		DECLARE_END_OBJECT_EXPRESSION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-BackgroundScheme",
					   _("Modifier la couleur d'arrière-plan"),
					   _("Modifier la couleur d'arrière-plan d'un case à cocher.\nLes 4 couleurs correspondent aux 4 état possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case à cocher: Changer la couleur d'arrière-plan de _PARAM0_"),
					   _("Case à cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survolé (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survolé)"), "", true);
			instrInfo.AddParameter("color", _("Désactivé"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBackgroundColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-BorderScheme",
					   _("Modifier la couleur de la bordure"),
					   _("Modifier la couleur de la bordure d'un case à cocher.\nLes 4 couleurs correspondent aux 4 état possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case à cocher: Changer la couleur de la bordure de _PARAM0_"),
					   _("Case à cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survolé (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survolé)"), "", true);
			instrInfo.AddParameter("color", _("Désactivé"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBorderColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-TextScheme",
					   _("Modifier la couleur du texte"),
					   _("Modifier la couleur du texte d'un case à cocher.\nLes 4 couleurs correspondent aux 4 état possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case à cocher: Changer la couleur du texte de _PARAM0_"),
					   _("Case à cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survolé (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survolé)"), "", true);
			instrInfo.AddParameter("color", _("Désactivé"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetTextColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-CheckScheme",
					   _("Modifier la couleur du signe coché"),
					   _("Modifier la couleur du signe coché d'un case à cocher.\nLes 4 couleurs correspondent aux 4 état possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case à cocher: Changer la couleur du signe coché de _PARAM0_"),
					   _("Case à cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survolé (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survolé)"), "", true);
			instrInfo.AddParameter("color", _("Désactivé"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetCheckColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("CheckBox-Sig-OnClick",
					   _("Un clic a eu lieu"),
					   _("Est valide uniquement lorsqu'un clic a été perçu par le widget."),
					   _("Case à cocher: Un clic a été perçu par _PARAM0_"),
					   _("Case à cocher"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("scenevar", _("Variable où stocker le bouton appuyé (\"Left\", \"Right\" ou \"Middle\")"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable où stocker la position X du clic"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable où stocker la position Y du clic"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnClick").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("CheckBox-Sig-OnStateChanged",
					   _("L'état du widget a changé"),
					   _("Est valide uniquement lorsque l'état du widget change."),
					   _("Case à cocher: L'état de _PARAM0_ a changé"),
					   _("Case à cocher"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("scenevar", _("Variable où stocker le nouvel état du widget (Active = Actif, Hovered = Survolé, Normal, Disabled = Désactivé)"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnStateChanged").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("CheckBox-Sig-OnCheckChanged",
					   _("La case à cocher a été cochée/décochée"),
					   _("Est valide uniquement lorsque la case à cocher vient d'être cochée ou décochée."),
					   _("Case à cocher: _PARAM0_ a été cochée ou décochée"),
					   _("Case à cocher"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnCheckChanged").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		#endif

	DECLARE_END_OBJECT()
}
