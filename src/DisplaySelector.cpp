#include "../include/Header.h"
using namespace std;

Display_Selector::Display_Selector(wxSizer* sizer, wxWindow* parent, Console* con)
{
    x = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));
    y = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));
    w = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));
    h = new wxTextCtrl(parent, wxID_ANY, "", wxPoint(0, 0), wxSize(100, 25));

    button = new wxButton(parent, 2, "Load SubImage", wxPoint(0, 0), wxSize(100, 25));
    this->console=con;
    parentSizer=sizer;

    console->log("Display Selector Initialized Successfully");
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

void Display_Selector::addSizer() 
{
    parentSizer->Add(x);
    parentSizer->Add(y);
    parentSizer->Add(w);
    parentSizer->Add(h);
    parentSizer->Add(button);
}