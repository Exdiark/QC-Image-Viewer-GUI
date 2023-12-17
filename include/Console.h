#pragma once
#include <wx/wx.h>

class Console : public wxTextCtrl
{
public:
	Console(wxWindow* parent, wxPoint position, wxSize size);
	void log(std::string msg);
	void log(wxString msg);

private:
};