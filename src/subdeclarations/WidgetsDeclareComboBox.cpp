#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"*

#include "WidgetsDeclareMacros.h"

void Extension::DeclareComboBox()
{
    DECLARE_OBJECT("ComboBox",
				   _("Liste déroulante"),
				   _("Objet au joueur de choisir parmi plusieurs choix."),
				   "res/Widgets/ComboBox_logo_smallO.png",
				   &CreateComboBoxObject,
				   &DestroyComboBoxObject,
				   "ComboBoxObject");

        #if defined(GD_IDE_ONLY)

            objInfos.SetIncludeFile("Widgets/combobox/ComboBoxObject.h");

            DECLARE_OBJECT_ACTION("ComboBox-Index",
					   _("Sélectionner un élément"),
					   _("Sélectionne un des éléments de la liste déroulante.\nAttention : le 1er élément est numéroté 0."),
					   _("Liste déroulante: Sélectionne l'élément _PARAM1_ dans _PARAM0_"),
					   _("Liste déroulante"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Elément à sélectionner (mettez -1 pour ne rien sélectionner)"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SelectElement");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_CONDITION("ComboBox-Index",
					   _("Index de l'élément sélection"),
					   _("Teste la position (index) de l'élément sélection d'une liste déroulante."),
					   _("Liste déroulante: L'index de l'élément sélectionné est _PARAM2__PARAM1_ dans _PARAM0_"),
					   _("Liste déroulante"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Position de l'élément"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetSelectedElement").SetManipulatedType("number");

            DECLARE_END_OBJECT_CONDITION()

            DECLARE_OBJECT_EXPRESSION("ComboBox::SelectedIndex", _("Index élément sélectionné"), _("Index élément sélectionné"), _("Liste déroulante"), "res/texteicon.png")
                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetSelectedElement");
            DECLARE_END_OBJECT_EXPRESSION()

            DECLARE_OBJECT_EXPRESSION("ComboBox::IndexCount", _("Nombre d'éléments (index)"), _("Nombre d'éléments (index)"), _("Liste déroulante"), "res/texteicon.png")
                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetElementsCount");
            DECLARE_END_OBJECT_EXPRESSION()

            DECLARE_OBJECT_STR_EXPRESSION("ComboBox::IndexString", _("Texte d'un index"), _("Texte d'un index"), _("Liste déroulante"), "res/texteicon.png")
                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Index"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetElementString");
            DECLARE_END_OBJECT_STR_EXPRESSION()

            DECLARE_OBJECT_ACTION("ComboBox-AddElement",
					   _("Ajouter un élément"),
					   _("Ajoute un élément à la position voulue et décale les éléments suivants.\nAttention : le 1er élément est numéroté 0."),
					   _("Liste déroulante: Ajoute un élément (_PARAM2_) à l'index _PARAM1_ de _PARAM0_"),
					   _("Liste déroulante"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Position (index)"), "", false);
                instrInfo.AddParameter("string", _("Texte de l'élément"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("AddElement");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_ACTION("ComboBox-DeleteElement",
					   _("Supprime un élément"),
					   _("Supprime un élément.\nAttention : le 1er élément est numéroté 0."),
					   _("Liste déroulante: Supprime l'élément n°_PARAM1_ de _PARAM0_"),
					   _("Liste déroulante"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Position (index)"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("DeleteElement");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_ACTION("ComboBox-State-Disable",
					   _("Active/Désactive le widget"),
					   _("Désactive ou réactive le widget."),
					   _("Liste déroulante: Désactiver le widget _PARAM0_ ? _PARAM1_ "),
					   _("Liste déroulante"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("yesorno", _("Oui pour le désactiver, Non pour l'activer"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetDisabled");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_CONDITION("ComboBox-State-Disable",
					   _("Tester si le widget est désactivé"),
					   _("Teste si le widget est désactivé."),
					   _("Liste déroulante: _PARAM0_ est désactivé"),
					   _("Liste déroulante"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);

                instrInfo.cppCallingInformation.SetFunctionName("IsDisabled");

            DECLARE_END_OBJECT_CONDITION()

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-BackgroundScheme",
                                    _("Modifier la couleur du fond"),
                                    _("Modifier la couleur du fond d'une liste déroulante."),
                                    _("Liste déroulante: Changer la couleur du fond de _PARAM0_"),
                                    _("Liste déroulante"),
                                      "ComboBox",
                                      "SetBackgroundColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-BorderScheme",
                                    _("Modifier la couleur de la bordure"),
                                    _("Modifier la couleur de la bordure d'une liste déroulante."),
                                    _("Liste déroulante: Changer la couleur de la bordure de _PARAM0_"),
                                    _("Liste déroulante"),
                                      "ComboBox",
                                      "SetBorderColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-TextScheme",
                                    _("Modifier la couleur du texte"),
                                    _("Modifier la couleur du texte d'une liste déroulante."),
                                    _("Liste déroulante: Changer la couleur du texte de _PARAM0_"),
                                    _("Liste déroulante"),
                                      "ComboBox",
                                      "SetTextColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-ArrowScheme",
                                    _("Modifier la couleur de la flèche"),
                                    _("Modifier la couleur de la flèche d'une liste déroulante."),
                                    _("Liste déroulante: Changer la couleur de la flèche de _PARAM0_"),
                                    _("Liste déroulante"),
                                      "ComboBox",
                                      "SetArrowColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-HighlightScheme",
                                    _("Modifier la couleur de la sélection"),
                                    _("Modifier la couleur de la sélection d'une liste déroulante."),
                                    _("Liste déroulante: Changer la couleur de la sélection de _PARAM0_"),
                                    _("Liste déroulante"),
                                      "ComboBox",
                                      "SetHighlightColorScheme");

        #endif

    DECLARE_END_OBJECT()
}
