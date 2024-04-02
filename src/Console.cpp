#include "../include/Header.h"
using namespace std;

Console::Console(wxWindow* parent, wxPoint position, wxSize size) : wxTextCtrl(parent, wxID_ANY, "", position, size, wxTE_READONLY | wxTE_MULTILINE)
{
	/*
	wxTextCtrl* win = new wxTextCtrl(parent, wxID_ANY, "", position, size, wxTE_READONLY | wxTE_MULTILINE);
	window-win;
	*/
	log("Console Initialized");
}

void Console::log(wxString msg)
{
	ostream stream(this);
	stream << msg << "\r";
}

void Console::logWB(wxString msg)
{
	ostream stream(this);
	stream << msg << "\r\n";
}