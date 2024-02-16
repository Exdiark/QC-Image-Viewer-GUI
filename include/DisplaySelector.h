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
    void addSizer();

    wxSizer* parentSizer;
    wxButton* button;
    Console* console;
    wxTextCtrl* x, * y, * w, * h;
};