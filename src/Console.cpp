#include "../include/Header.h"
using namespace std;

Console::Console(wxWindow* parent, wxPoint position, wxSize size) : wxTextCtrl(parent, wxID_ANY, "", position, size, wxTE_READONLY | wxTE_MULTILINE)
{

};

void Console::log(std::string msg)
{
	ostream stream(this);
	stream << msg << "\r\n";
}

void Console::log(wxString msg)
{
	ostream stream(this);
	stream << msg << "\r\n";
}
