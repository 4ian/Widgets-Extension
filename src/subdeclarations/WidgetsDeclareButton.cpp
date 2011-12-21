#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"

void Extension::DeclareButton()
{
    DECLARE_OBJECT("Button",
				   _("Bouton"),
				   _("Objet permettant de capter un clic du joueur sur ce dernier."),
				   "res/Widgets/Button_logo_smallO.png",
				   &CreateButtonObject,
				   &DestroyButtonObject,
				   "ButtonObject");

	#if defined(GD_IDE_ONLY)

		objInfos.SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_OBJECT_ACTION("Button-String",
					   _("Modifier le texte"),
					   _("Modifier le texte d'un bouton"),
					   _("Bouton: Faire _PARAM2__PARAM1_ au texte de _PARAM0_"),
					   _("Bouton"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("string", _("Texte"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetString").SetManipulatedType("string").SetAssociatedGetter("GetString").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Button-String",
					   _("Tester le texte"),
					   _("Teste le texte d'un bouton."),
					   _("Bouton: Le texte de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Bouton"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("string", _("Texte � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetManipulatedType("string").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_ACTION("Button-Color-BackgroundScheme",
					   _("Modifier la couleur d'arri�re-plan"),
					   _("Modifier la couleur d'arri�re-plan d'un bouton.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Bouton: Changer la couleur d'arri�re-plan de _PARAM0_"),
					   _("Bouton"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBackgroundColorScheme").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Button-Color-BorderScheme",
					   _("Modifier la couleur de la bordure"),
					   _("Modifier la couleur de la bordure d'un bouton.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Bouton: Changer la couleur de la bordure de _PARAM0_"),
					   _("Bouton"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBorderColorScheme").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Button-Color-TextScheme",
					   _("Modifier la couleur du texte"),
					   _("Modifier la couleur du texte d'un bouton.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Bouton: Changer la couleur du texte de _PARAM0_"),
					   _("Bouton"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetTextColorScheme").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Button-State-Disable",
					   _("Active/D�sactive le widget"),
					   _("D�sactive ou r�active le widget."),
					   _("Bouton: D�sactiver le widget _PARAM0_ ? _PARAM1_ "),
					   _("Bouton"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("yesorno", _("Oui pour le d�sactiver, Non pour l'activer"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetDisabled").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Button-State-Disable",
					   _("Tester si le widget est d�sactiv�"),
					   _("Teste si le widget est d�sactiv�."),
					   _("Bouton: _PARAM0_ est d�sactiv�"),
					   _("Bouton"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsDisabled").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("Button-Sig-OnClick",
					   _("Un clic a eu lieu"),
					   _("Est valide uniquement lorsqu'un clic a �t� per�u par le widget."),
					   _("Bouton: Un clic a �t� per�u par _PARAM0_"),
					   _("Bouton"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le bouton appuy� (\"Left\", \"Right\" ou \"Middle\")"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position X du clic"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position Y du clic"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnClick").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("Button-Sig-OnStateChanged",
					   _("L'�tat du widget a chang�"),
					   _("Est valide uniquement lorsque l'�tat du widget change."),
					   _("Bouton: L'�tat de _PARAM0_ a chang�"),
					   _("Bouton"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le nouvel �tat du widget (Active = Actif, Hovered = Survol�, Normal, Disabled = D�sactiv�)"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnStateChanged").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_ACTION("Button-Size",
					   _("Taille"),
					   _("Modifie la taille du texte."),
					   _("Bouton: Faire _PARAM2__PARAM1_ � la taille du texte de _PARAM0_"),
					   _("Bouton"),
					   "res/actions/characterSize24.png",
					   "res/actions/characterSize.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("expression", _("Valeur"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);


			instrInfo.cppCallingInformation.SetFunctionName("SetCharacterSize").SetManipulatedType("number").SetAssociatedGetter("GetCharacterSize").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Button-Size",
					   _("Taille"),
					   _("Teste la taille du texte."),
					   _("Bouton: La taille du texte de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Bouton"),
					   "res/conditions/characterSize24.png",
					   "res/conditions/characterSize.png");

			instrInfo.AddParameter("object", _("Objet"), "Button", false);
			instrInfo.AddParameter("expression", _("Taille � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


			instrInfo.cppCallingInformation.SetFunctionName("GetCharacterSize").SetManipulatedType("number").SetIncludeFile("Widgets/button/ButtonObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_STR_EXPRESSION("Button::String", _("Texte"), _("Texte"), _("Bouton"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "Button", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetIncludeFile("Widgets/button/ButtonObject.h");
		DECLARE_END_OBJECT_STR_EXPRESSION()


	#endif

	DECLARE_END_OBJECT()
}
