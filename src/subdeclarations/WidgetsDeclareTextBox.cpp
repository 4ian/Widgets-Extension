#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"

void Extension::DeclareTextBox()
{
    //Declaration of all objects available
	DECLARE_OBJECT("TextArea",
				   _("Zone de texte"),
				   _("Objet permettant la saisie d'un texte par le joueur en cours de jeu."),
				   "res/Widgets/Entry_logo_smallO.png",
				   &CreateTextAreaObject,
				   &DestroyTextAreaObject,
				   "TextAreaObject");

		#if defined(GD_IDE_ONLY)

		objInfos.SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_OBJECT_ACTION("Entry-String",
					   _("Modifier le texte"),
					   _("Modifier le texte d'une zone de texte."),
					   _("Zone de texte: Faire _PARAM2__PARAM1_ au texte de _PARAM0_"),
					   _("Zone de texte"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("string", _("Texte"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetString").SetManipulatedType("string").SetAssociatedGetter("GetString").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Entry-String",
					   _("Tester le texte"),
					   _("Teste le texte d'une zone de texte."),
					   _("Zone de texte: Le texte de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Zone de texte"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("string", _("Texte � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetManipulatedType("string").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_ACTION("Entry-Color-BackgroundScheme",
					   _("Modifier la couleur d'arri�re-plan"),
					   _("Modifier la couleur d'arri�re-plan d'une zone de texte.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Zone de texte: Changer la couleur d'arri�re-plan de _PARAM0_"),
					   _("Zone de texte"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBackgroundColorScheme").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Entry-Color-BorderScheme",
					   _("Modifier la couleur de la bordure"),
					   _("Modifier la couleur de la bordure de la zone de texte.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Zone de texte: Changer la couleur de la bordure de _PARAM0_"),
					   _("Zone de texte"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetBorderColorScheme").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Entry-Color-TextScheme",
					   _("Modifier la couleur du texte"),
					   _("Modifier la couleur du texte de la zone de texte.\nLes 4 couleurs correspondent aux 4 �tat possibles du widget, cochez uniquement celle(s) que vous souhaitez modifier."),
					   _("Zone de texte: Changer la couleur du texte de _PARAM0_"),
					   _("Zone de texte"),
					   "res/Widgets/color24.png",
					   "res/Widgets/color.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("color", _("Actif"), "", true);
			instrInfo.AddParameter("color", _("Survol� (la souris est dessus)"), "", true);
			instrInfo.AddParameter("color", _("Normal (ni actif, ni survol�)"), "", true);
			instrInfo.AddParameter("color", _("D�sactiv�"), "", true);

			instrInfo.cppCallingInformation.SetFunctionName("SetTextColorScheme").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_ACTION("Entry-State-Focus",
					   _("Donne/Enl�ve le focus"),
					   _("Donne ou enl�ve le focus � un widget."),
					   _("Zone de texte: Donner le focus � _PARAM0_ ? _PARAM1_ "),
					   _("Zone de texte"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("yesorno", _("Oui pour donner le focus, Non pour lui enlever"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetActive").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Entry-State-Focus",
					   _("Tester si le widget a le focus"),
					   _("Teste si le widget a le focus."),
					   _("Zone de texte: _PARAM0_ a le focus"),
					   _("Zone de texte"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsActive").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_ACTION("Entry-State-Disable",
					   _("Active/D�sactive le widget"),
					   _("D�sactive ou r�active le widget."),
					   _("Zone de texte: D�sactiver le widget _PARAM0_ ? _PARAM1_ "),
					   _("Zone de texte"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("yesorno", _("Oui pour le d�sactiver, Non pour l'activer"), "", false);

			instrInfo.cppCallingInformation.SetFunctionName("SetDisabled").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Entry-State-Disable",
					   _("Tester si le widget est d�sactiv�"),
					   _("Teste si le widget est d�sactiv�."),
					   _("Zone de texte: _PARAM0_ est d�sactiv�"),
					   _("Zone de texte"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);

			instrInfo.cppCallingInformation.SetFunctionName("IsDisabled").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("Entry-Sig-OnTextEntered",
					   _("Du texte a �t� entr�"),
					   _("Est valide uniquement lorsque du texte vient d'�tre entr�."),
					   _("Zone de texte: Du texte vient d'�tre entr� dans _PARAM0_"),
					   _("Zone de texte"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnTextEntered").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("Entry-Sig-OnClick",
					   _("Un clic a eu lieu"),
					   _("Est valide uniquement lorsqu'un clic a �t� per�u par le widget."),
					   _("Zone de texte: Un clic a �t� per�u par _PARAM0_"),
					   _("Zone de texte"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le bouton appuy� (\"Left\", \"Right\" ou \"Middle\")"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position X du clic"), "", true);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker la position Y du clic"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnClick").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_CONDITION()

		DECLARE_OBJECT_CONDITION("Entry-Sig-OnStateChanged",
					   _("L'�tat du widget a chang�"),
					   _("Est valide uniquement lorsque l'�tat du widget change."),
					   _("Zone de texte: L'�tat de _PARAM0_ a chang�"),
					   _("Zone de texte"),
					   "res/Widgets/signal24.png",
					   "res/Widgets/signal.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("scenevar", _("Variable o� stocker le nouvel �tat du widget (Active = Actif, Hovered = Survol�, Normal, Disabled = D�sactiv�)"), "", true);
			instrInfo.AddCodeOnlyParameter("currentScene", "0");

			instrInfo.cppCallingInformation.SetFunctionName("SIG_OnStateChanged").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_CONDITION()

		/*DECLARE_OBJECT_ACTION("Entry-Font",
					   _("Police de caract�re"),
					   _("Modifie la police de caract�re du texte."),
					   _("Changer la police de _PARAM0_ en _PARAM1_"),
					   _("Police"),
					   "res/actions/font24.png",
					   "res/actions/font.png");

			instrInfo.AddParameter("object", _("Objet"), "Text", false);
			instrInfo.AddParameter("police", _("Valeur"), "", false);


			instrInfo.cppCallingInformation.SetFunctionName("SetFont").SetManipulatedType("string").SetIncludeFile("TextObject/TextObject.h");

		DECLARE_END_OBJECT_ACTION()*/

		DECLARE_OBJECT_ACTION("Entry-Size",
					   _("Taille"),
					   _("Modifie la taille du texte."),
					   _("Zone de texte: Faire _PARAM2__PARAM1_ � la taille du texte de _PARAM0_"),
					   _("Zone de texte"),
					   "res/actions/characterSize24.png",
					   "res/actions/characterSize.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("expression", _("Valeur"), "", false);
			instrInfo.AddParameter("operator", _("Signe de la modification"), "", false);


			instrInfo.cppCallingInformation.SetFunctionName("SetCharacterSize").SetManipulatedType("number").SetAssociatedGetter("GetCharacterSize").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_ACTION()

		DECLARE_OBJECT_CONDITION("Entry-Size",
					   _("Taille"),
					   _("Teste la taille du texte."),
					   _("Zone de texte: La taille du texte de _PARAM0_ est _PARAM2_ � _PARAM1_"),
					   _("Zone de texte"),
					   "res/conditions/characterSize24.png",
					   "res/conditions/characterSize.png");

			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);
			instrInfo.AddParameter("expression", _("Taille � tester"), "", false);
			instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);


			instrInfo.cppCallingInformation.SetFunctionName("GetCharacterSize").SetManipulatedType("number").SetIncludeFile("Widgets/textbox/TextAreaObject.h");

		DECLARE_END_OBJECT_CONDITION()


		DECLARE_OBJECT_STR_EXPRESSION("Entry::String", _("Texte"), _("Texte"), _("Zone de texte"), "res/texteicon.png")
			instrInfo.AddParameter("object", _("Objet"), "TextArea", false);

			instrInfo.cppCallingInformation.SetFunctionName("GetString").SetIncludeFile("Widgets/textbox/TextAreaObject.h");
		DECLARE_END_OBJECT_STR_EXPRESSION()

	#endif
	DECLARE_END_OBJECT()
}
