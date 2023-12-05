#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <cstdlib>
#include <iostream>

#include "../include/Header.h"

wxBEGIN_EVENT_TABLE(MyApp,wxApp)
    EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

bool MyApp::OnInit()
{

    wxInitAllImageHandlers();
    InitWindows(wxT("../resources/Example.png"));
	return true;
}

void MyApp::InitWindows(wxString fileName) {
    
    /*
    * layout:
    *   sizer (sizer) for a panel (panel) that encompasses entire frame
    *       Parent: frame
    *       Children: leftpanel,rightpanel
    *   sizer (buttons), contains leftpanel
    *       Parent: sizer
    *       Children: img_btn
    *   sizer (stuff), contains rightpanel
    *       Parent: sizer
    *       Children: drawPane, consoleHeader, console
    */

    frame = new wxFrame(NULL, wxID_ANY, wxT("hot dog"), wxPoint(50, 200), wxSize(1000, 800));
    frame->SetBackgroundColour(wxColour(*wxWHITE));

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL); //main sizer for entire frame
    wxBoxSizer* buttons = new wxBoxSizer(wxHORIZONTAL); // sizer for buttons and other stuff
    wxBoxSizer* stuff = new wxBoxSizer(wxVERTICAL); //sizer for image and console

    

    wxPanel* leftpanel = new wxPanel(frame, wxID_ANY, wxPoint(25, 25), wxSize(100, 800));
    leftpanel->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
    leftpanel->SetSizer(buttons);

    wxPanel* rightpanel = new wxPanel(frame, wxID_ANY, wxPoint(100, 25), wxSize(890, 800));
    rightpanel->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
    rightpanel->SetSizer(stuff);

    sizer->Add(leftpanel);
    sizer->AddSpacer(10);
    sizer->Add(rightpanel,1,wxEXPAND);
    

    wxButton* img_btn = new wxButton(leftpanel, 10001, "Load Image", wxPoint(0, 0), wxSize(100, 25));
    buttons->Add(img_btn,1,wxCenter);

    drawPane = new wxImagePanel(rightpanel, "Image", 0, 0);
    stuff->Add(drawPane, 1, wxEXPAND);

    wxTextCtrl* consoleHeader = new wxTextCtrl(rightpanel, wxID_ANY, "Event Log", wxPoint(500, 70), wxSize(850, 25), wxTE_READONLY);
    stuff->Add(consoleHeader, 0, wxCENTER);
    console = new wxTextCtrl(rightpanel, wxID_ANY, "", wxPoint(500, 70), wxSize(850 , 200),wxTE_READONLY | wxTE_MULTILINE);
    stuff->Add(console,0,wxCENTER);

    log("Program successfully initialized");

    frame->SetSizer(sizer);
    frame->Show(true);

}

void MyApp::OnButtonClicked(wxCommandEvent& evt) {

    log("Attempting to load in new PNG file...");

    wxFileDialog openFileDialog(frame, _("Open a PNG file"), "", "",
            "PNG files (*.png)|*.png", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());
    log("File path: " + std::string(openFileDialog.GetPath()) + " selected");

    if (!input_stream.IsOk())
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }
    
    drawPane->loadNewFile(openFileDialog.GetPath());
    log( "Initialized new image with width " + std::to_string(drawPane->getImageSize().GetX()) + " and height " + std::to_string(drawPane->getImageSize().GetY()));
}

void MyApp::log(std::string message) {
    *console << message << "\r\n";
}