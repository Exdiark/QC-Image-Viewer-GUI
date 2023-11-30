#pragma once
#include <wx/app.h>
#include <MyFrame.h>
#include <MainImagePanel.h>

class MyApp : public wxApp
{
public:
	wxImagePanel* drawPane;
	wxString current_file;
	virtual bool OnInit();
	wxFrame* frame;
	void InitWindows(wxString fileName);
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};