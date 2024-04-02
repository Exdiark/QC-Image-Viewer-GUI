#pragma once
#include <wx/app.h>
#include "MyFrame.h"
#include "MainImagePanel.h"
#include "DisplaySelector.h"
#include "Console.h"

class MyApp : public wxApp
{
public:
	Display_Selector* disp;
	wxImagePanel* drawPane;
	Console* console;
	virtual bool OnInit();
	wxFrame* frame;
	void InitWindows(wxString fileName);
	void OnButtonClicked(wxCommandEvent& evt);
	void OnMouseClick(wxMouseEvent& evt);
	void log(std::string message);

	wxDECLARE_EVENT_TABLE();
};