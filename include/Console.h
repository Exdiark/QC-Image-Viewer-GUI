#pragma once
#include <wx/wx.h>

class Console : public wxTextCtrl
{
public:
	Console(wxWindow* parent, wxPoint position, wxSize size);
	void log(wxString msg);
	void logWB(wxString msg);
	void logNB(wxString msg);
	wxTextCtrl* window;
};