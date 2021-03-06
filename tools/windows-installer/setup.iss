; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{BB9ECA48-4F71-4A01-B7AE-B786445D464D}
AppName=Extension Widget
AppVersion=1.1
;AppVerName=Extension Widget 1.1
AppPublisher=Victor Levasseur
AppPublisherURL=http://www.levasseursoftware.net/index.php/extension-widgets
AppSupportURL=http://www.levasseursoftware.net/index.php/extension-widgets
AppUpdatesURL=http://www.levasseursoftware.net/index.php/extension-widgets
DefaultDirName={pf}\Compil Games\Game Develop
DefaultGroupName=Extension Widget
LicenseFile=D:\Développement\GD2\GDLSDK\Extensions\WidgetsExtension\tools\windows-installer\LICENSE-WIDGETEXTENSION-EN.txt
OutputDir=D:\Développement\GD2\GDLSDK\Extensions\WidgetsExtension\tools\windows-installer\dataInstaller
OutputBaseFilename=Data-WidgetsExtension-1.1
WizardImageFile=WidgetsLogo.bmp
WizardSmallImageFile=WidgetsLogoSmall.bmp

Compression=lzma
SolidCompression=yes

[Languages]
Name: "french"; MessagesFile: "French_WIDGET.isl"
Name: "english"; MessagesFile: "Default_WIDGET.isl"

[Files]
Source: "D:\Développement\GD2\GDLSDK\Extensions\WidgetsExtension\tools\windows-installer\final\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\Développement\GD2\GDLSDK\Extensions\WidgetsExtension\tools\windows-installer\LICENSE-WIDGETEXTENSION-FR.txt"; DestDir: "{app}";
Source: "D:\Développement\GD2\GDLSDK\Extensions\WidgetsExtension\tools\windows-installer\LICENSE-WIDGETEXTENSION-EN.txt"; DestDir: "{app}";
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

