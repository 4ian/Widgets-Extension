#include "GDL/ExtensionBase.h"
#include "GDL/Version.h"
#include "../Extension.h"*

#include "WidgetsDeclareMacros.h"

void Extension::DeclareComboBox()
{
    DECLARE_OBJECT("ComboBox",
				   _("Liste d�roulante"),
				   _("Objet au joueur de choisir parmi plusieurs choix."),
				   "res/Widgets/ComboBox_logo_smallO.png",
				   &CreateComboBoxObject,
				   &DestroyComboBoxObject,
				   "ComboBoxObject");

        #if defined(GD_IDE_ONLY)

            objInfos.SetIncludeFile("Widgets/combobox/ComboBoxObject.h");

            DECLARE_OBJECT_ACTION("ComboBox-Index",
					   _("S�lectionner un �l�ment"),
					   _("S�lectionne un des �l�ments de la liste d�roulante.\nAttention : le 1er �l�ment est num�rot� 0."),
					   _("Liste d�roulante: S�lectionne l'�l�ment _PARAM1_ dans _PARAM0_"),
					   _("Liste d�roulante"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("El�ment � s�lectionner (mettez -1 pour ne rien s�lectionner)"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SelectElement");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_CONDITION("ComboBox-Index",
					   _("Index de l'�l�ment s�lection"),
					   _("Teste la position (index) de l'�l�ment s�lection d'une liste d�roulante."),
					   _("Liste d�roulante: L'index de l'�l�ment s�lectionn� est _PARAM2__PARAM1_ dans _PARAM0_"),
					   _("Liste d�roulante"),
					   "res/conditions/text24.png",
					   "res/conditions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Position de l'�l�ment"), "", false);
                instrInfo.AddParameter("relationalOperator", _("Signe du test"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetSelectedElement").SetManipulatedType("number");

            DECLARE_END_OBJECT_CONDITION()

            DECLARE_OBJECT_EXPRESSION("ComboBox::SelectedIndex", _("Index �l�ment s�lectionn�"), _("Index �l�ment s�lectionn�"), _("Liste d�roulante"), "res/texteicon.png")
                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetSelectedElement");
            DECLARE_END_OBJECT_EXPRESSION()

            DECLARE_OBJECT_EXPRESSION("ComboBox::IndexCount", _("Nombre d'�l�ments (index)"), _("Nombre d'�l�ments (index)"), _("Liste d�roulante"), "res/texteicon.png")
                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetElementsCount");
            DECLARE_END_OBJECT_EXPRESSION()

            DECLARE_OBJECT_STR_EXPRESSION("ComboBox::IndexString", _("Texte d'un index"), _("Texte d'un index"), _("Liste d�roulante"), "res/texteicon.png")
                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Index"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("GetElementString");
            DECLARE_END_OBJECT_STR_EXPRESSION()

            DECLARE_OBJECT_ACTION("ComboBox-AddElement",
					   _("Ajouter un �l�ment"),
					   _("Ajoute un �l�ment � la position voulue et d�cale les �l�ments suivants.\nAttention : le 1er �l�ment est num�rot� 0."),
					   _("Liste d�roulante: Ajoute un �l�ment (_PARAM2_) � l'index _PARAM1_ de _PARAM0_"),
					   _("Liste d�roulante"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Position (index)"), "", false);
                instrInfo.AddParameter("string", _("Texte de l'�l�ment"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("AddElement");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_ACTION("ComboBox-DeleteElement",
					   _("Supprime un �l�ment"),
					   _("Supprime un �l�ment.\nAttention : le 1er �l�ment est num�rot� 0."),
					   _("Liste d�roulante: Supprime l'�l�ment n�_PARAM1_ de _PARAM0_"),
					   _("Liste d�roulante"),
					   "res/actions/text24.png",
					   "res/actions/text.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("expression", _("Position (index)"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("DeleteElement");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_ACTION("ComboBox-State-Disable",
					   _("Active/D�sactive le widget"),
					   _("D�sactive ou r�active le widget."),
					   _("Liste d�roulante: D�sactiver le widget _PARAM0_ ? _PARAM1_ "),
					   _("Liste d�roulante"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);
                instrInfo.AddParameter("yesorno", _("Oui pour le d�sactiver, Non pour l'activer"), "", false);

                instrInfo.cppCallingInformation.SetFunctionName("SetDisabled");

            DECLARE_END_OBJECT_ACTION()

            DECLARE_OBJECT_CONDITION("ComboBox-State-Disable",
					   _("Tester si le widget est d�sactiv�"),
					   _("Teste si le widget est d�sactiv�."),
					   _("Liste d�roulante: _PARAM0_ est d�sactiv�"),
					   _("Liste d�roulante"),
					   "res/Widgets/focus24.png",
					   "res/Widgets/focus.png");

                instrInfo.AddParameter("object", _("Objet"), "ComboBox", false);

                instrInfo.cppCallingInformation.SetFunctionName("IsDisabled");

            DECLARE_END_OBJECT_CONDITION()

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-BackgroundScheme",
                                    _("Modifier la couleur du fond"),
                                    _("Modifier la couleur du fond d'une liste d�roulante."),
                                    _("Liste d�roulante: Changer la couleur du fond de _PARAM0_"),
                                    _("Liste d�roulante"),
                                      "ComboBox",
                                      "SetBackgroundColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-BorderScheme",
                                    _("Modifier la couleur de la bordure"),
                                    _("Modifier la couleur de la bordure d'une liste d�roulante."),
                                    _("Liste d�roulante: Changer la couleur de la bordure de _PARAM0_"),
                                    _("Liste d�roulante"),
                                      "ComboBox",
                                      "SetBorderColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-TextScheme",
                                    _("Modifier la couleur du texte"),
                                    _("Modifier la couleur du texte d'une liste d�roulante."),
                                    _("Liste d�roulante: Changer la couleur du texte de _PARAM0_"),
                                    _("Liste d�roulante"),
                                      "ComboBox",
                                      "SetTextColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-ArrowScheme",
                                    _("Modifier la couleur de la fl�che"),
                                    _("Modifier la couleur de la fl�che d'une liste d�roulante."),
                                    _("Liste d�roulante: Changer la couleur de la fl�che de _PARAM0_"),
                                    _("Liste d�roulante"),
                                      "ComboBox",
                                      "SetArrowColorScheme");

            DEFINE_COLORSCHEME_ACTION("ComboBox-Color-HighlightScheme",
                                    _("Modifier la couleur de la s�lection"),
                                    _("Modifier la couleur de la s�lection d'une liste d�roulante."),
                                    _("Liste d�roulante: Changer la couleur de la s�lection de _PARAM0_"),
                                    _("Liste d�roulante"),
                                      "ComboBox",
                                      "SetHighlightColorScheme");

        #endif

    DECLARE_END_OBJECT()
}
