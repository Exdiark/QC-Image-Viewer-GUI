#pragma once
#include <wx/wx.h>
#include "Console.h"

class Display_Selector
{
public:
    Display_Selector(wxSizer* sizer, wxWindow* parent, Console* console);
    int getH();
    int getW();
    int getX();
    int getY();

    Console* console;
    wxTextCtrl* x, * y, * w, * h;
};