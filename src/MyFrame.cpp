#include <wx/frame.h>
#include <../MyFrame.h>

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "help")
{
	SetSize(wxSIZE_AUTO, wxSIZE_AUTO, 800, 800);
}