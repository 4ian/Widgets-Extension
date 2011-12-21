#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"

void Extension::DeclareCheckBox()
{
    DECLARE_OBJECT("CheckBox",
				   _("Case � cocher"),
				   _("Objet permettant � l'utilisateur de s�lectionner \"vrai\" ou \"faux\"."),
				   "res/Widgets/CheckBox_logo_smallO.png",
				   &CreateCheckBoxObject,
				   &DestroyCheckBoxObject,
				   "CheckBoxObject");

		#if defined(GD_IDE_ONLY)

		objInfos.SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");



		DECLARE_OBJECT_ACTION("CheckBox-String",
					   _("Modifier le texte"),
					   _("Modifier le texte d'une case � cocher."),
					   _("Case � cocher: Faire _PARAM2__PARAM1_ au texte de _PARAM0_"),
					   _("Case � cocher"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("string", _("Texte"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetString").SetManipulatedType("string").SetAssociatedGetter("GetString").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("CheckBox-String",
					   _("Tester le texte"),
					   _("Teste le texte d'une case � cocher."),
					   _("Case � cocher: Le texte de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Case � cocher"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("string", _("Texte � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetManipulatedType("string").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_STR_EXPRESSION("CheckBox::String", _("Texte"), _("Texte"), _("Case � cocher"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");
		DECLARE_END_OBJECT_STR_EXPRESSION()

		DECLARE_OBJECT_ACTION("CheckBox-Checked",
					   _("Cocher/D�cocher"),
					   _("Coche ou d�coche la case � cocher."),
					   _("Case � cocher: Cocher _PARAM0_ ? _PARAM1_"),
					   _("Case � cocher"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("yesorno", _("Coch� ou pas"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetChecked").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("CheckBox-Checked",
					   _("Tester si coch�e"),
					   _("Teste si une case � cocher est coch�e."),
					   _("Case � cocher: La case _PARAM0_ est coch�e"),
					   _("Case � cocher"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsChecked").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_EXPRESSION("CheckBox::IsChecked", _("Coch�e ?"), _("Coch�e ?"), _("Case � cocher"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsChecked").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");
		DECLARE_END_OBJECT_EXPRESSION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-BackgroundScheme",
					   _("Modifier la couleur d'arri�re-plan"),
					   _("Modifier la couleur d'arri�re-plan d'un case � cocher.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case � cocher: Changer la couleur d'arri�re-plan de _PARAM0_"),
					   _("Case � cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBackgroundColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-BorderScheme",
					   _("Modifier la couleur de la bordure"),
					   _("Modifier la couleur de la bordure d'un case � cocher.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case � cocher: Changer la couleur de la bordure de _PARAM0_"),
					   _("Case � cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBorderColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-TextScheme",
					   _("Modifier la couleur du texte"),
					   _("Modifier la couleur du texte d'un case � cocher.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case � cocher: Changer la couleur du texte de _PARAM0_"),
					   _("Case � cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetTextColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("CheckBox-Color-CheckScheme",
					   _("Modifier la couleur du signe coch�"),
					   _("Modifier la couleur du signe coch� d'un case � cocher.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Case � cocher: Changer la couleur du signe coch� de _PARAM0_"),
					   _("Case � cocher"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetCheckColorScheme").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("CheckBox-Sig-OnClick",
					   _("Un clic a eu lieu"),
					   _("Est valide uniquement lorsqu'un clic a �t� per�u par le widget."),
					   _("Case � cocher: Un clic a �t� per�u par _PARAM0_"),
					   _("Case � cocher"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le bouton appuy� (\"Left\", \"Right\" ou \"Middle\")"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position X du clic"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position Y du clic"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnClick").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("CheckBox-Sig-OnStateChanged",
					   _("L'�tat du widget a chang�"),
					   _("Est valide uniquement lorsque l'�tat du widget change."),
					   _("Case � cocher: L'�tat de _PARAM0_ a chang�"),
					   _("Case � cocher"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le nouvel �tat du widget (Active = Actif, Hovered = Survol�, Normal, Disabled = D�sactiv�)"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnStateChanged").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("CheckBox-Sig-OnCheckChanged",
					   _("La case � cocher a �t� coch�e/d�coch�e"),
					   _("Est valide uniquement lorsque la case � cocher vient d'�tre coch�e ou d�coch�e."),
					   _("Case � cocher: _PARAM0_ a �t� coch�e ou d�coch�e"),
					   _("Case � cocher"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "CheckBox", false);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnCheckChanged").SetIncludeFile("Widgets/checkbox/CheckBoxObject.h");

		DECLARE_END_OBJECT_CONDITION()

		#endif

	DECLARE_END_OBJECT()
}
