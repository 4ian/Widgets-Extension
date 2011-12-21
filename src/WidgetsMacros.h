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
