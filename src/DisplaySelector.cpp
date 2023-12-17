#include "../include/Header.h"
using namespace std;

Display_Selector::Display_Selector(wxSizer* sizer, wxWindow* parent, Console* console)
{
    x = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));
    sizer->Add(x);
    y = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));
    sizer->Add(y);
    w = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));
    sizer->Add(w);
    h = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));
    sizer->Add(h);

    wxButton* sub_btn = new wxButton(parent, 2, "Load SubImage", wxPoint(0, 0), wxSize(100, 25));
    sizer->Add(sub_btn);
}

int Display_Selector::getX()
{
    return stoi((const char*)x->GetLineText(0).mb_str());
}

int Display_Selector::getY()
{
    return stoi((const char*)y->GetLineText(0).mb_str());
}

int Display_Selector::getW()
{
    return stoi((const char*)w->GetLineText(0).mb_str());
}

int Display_Selector::getH()
{
    return stoi((const char*)h->GetLineText(0).mb_str());
}