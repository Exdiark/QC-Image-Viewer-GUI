#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <cstdlib>
#include <iostream>

#include "../include/Header.h"
using namespace std;

wxBEGIN_EVENT_TABLE(MyApp,wxApp)
    EVT_BUTTON(1, OnButtonClicked)
    EVT_BUTTON(2, OnButtonClicked)
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
    *   sizer (left_sizer), contains leftpanel
    *       Parent: sizer
    *       Children: img_btn
    *   sizer (right_sizer), contains rightpanel
    *       Parent: sizer
    *       Children: drawPane, consoleHeader, console
    */

    frame = new wxFrame(NULL, wxID_ANY, wxT("hot dog"), wxPoint(50, 200), wxSize(1000, 800));
    frame->SetBackgroundColour(wxColour(*wxWHITE));

    wxBoxSizer* main_sizer = new wxBoxSizer(wxHORIZONTAL); //main sizer for entire frame
    wxBoxSizer* left_sizer = new wxBoxSizer(wxVERTICAL); // sizer for left_sizer and other right_sizer
    wxBoxSizer* right_sizer = new wxBoxSizer(wxVERTICAL); //sizer for image and console
    
    //initialize two panels
    wxPanel* leftpanel = new wxPanel(frame, wxID_ANY, wxPoint(25, 25), wxSize(100, 800));
    leftpanel->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
    leftpanel->SetSizer(left_sizer);

    wxPanel* rightpanel = new wxPanel(frame, wxID_ANY, wxPoint(100, 25), wxSize(890, 800));
    rightpanel->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
    rightpanel->SetSizer(right_sizer);

    console = new wxTextCtrl(rightpanel, wxID_ANY, "", wxPoint(500, 70), wxSize(850 , 200),wxTE_READONLY | wxTE_MULTILINE);
    drawPane = new wxImagePanel(rightpanel, "Image", 0, 0);
    wxTextCtrl* consoleHeader = new wxTextCtrl(rightpanel, wxID_ANY, "Event Log", wxPoint(500, 70), wxSize(850, 25), wxTE_READONLY);

    right_sizer->Add(drawPane, 1, wxEXPAND);
    right_sizer->Add(consoleHeader, 0, wxCENTER);
    right_sizer->Add(console,0,wxCENTER);


    main_sizer->Add(leftpanel);
    main_sizer->AddSpacer(10);
    main_sizer->Add(rightpanel,1,wxEXPAND);

    
    left_sizer->AddSpacer(10);

    wxButton* img_btn = new wxButton(leftpanel, 1, "Load Image", wxPoint(0, 0), wxSize(100, 25));
    left_sizer->Add(img_btn,0,wxCenter);

    left_sizer->AddSpacer(10);

    disp = new Display_Selector(left_sizer, leftpanel, NULL);

    log("Program successfully initialized");

    frame->SetSizer(main_sizer);
    frame->Show(true);

}

void MyApp::OnButtonClicked(wxCommandEvent& evt) 
{

    int id = evt.GetId();

    log("Button ID:" + to_string(id) + " clicked");

    if(id==1)
    {
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
        log("Initialized new image with width " + std::to_string(drawPane->getImageSize().GetX()) + " and height " + std::to_string(drawPane->getImageSize().GetY()));
    }
    
    else if(id==2)
    {
        int x = disp->getX();
        int y = disp->getY();
        int w = disp->getW();
        int h = disp->getH();
        
        log("Displaying subimage with parameters X:" + to_string(disp->getX()) + " Y: " + to_string(disp->getY()) + " Width: " + to_string(disp->getW()) + " Height: " + to_string(disp->getH()));

        drawPane->changeDisplay(x, y, w, h);
        
    }

}

void MyApp::log(std::string message) {
    *console << message << "\r\n";
}