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

#if defined(GD_IDE_ONLY)

#define COLOR_BUTTON_FUNCTION_IMPLEMENT(_button_, _class_, _functionName_) void _class_::_functionName_ (wxCommandEvent& event)\
{\
    wxColour color = wxGetColourFromUser(this, _button_ ->GetBackgroundColour());\
    if ( color.IsOk() )\
        _button_ ->SetBackgroundColour(color);\
\
    if ( color.IsOk() )\
    {\
        if(color.Red() < 128 && color.Green() < 128 && color.Blue() < 128)\
            _button_ ->SetForegroundColour(wxColour(255, 255, 255));\
        else\
            _button_ ->SetForegroundColour(wxColour(0, 0, 0));\
    }\
\
    return;\
}

#endif
