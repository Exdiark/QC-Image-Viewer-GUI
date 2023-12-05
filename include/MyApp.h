#pragma once
#include <wx/app.h>
#include "MyFrame.h"
#include "MainImagePanel.h"

class MyApp : public wxApp
{
public:
	wxImagePanel* drawPane;
	wxTextCtrl* console;
	virtual bool OnInit();
	wxFrame* frame;
	void InitWindows(wxString fileName);
	void OnButtonClicked(wxCommandEvent& evt);
	void log(std::string message);

	wxDECLARE_EVENT_TABLE();
};