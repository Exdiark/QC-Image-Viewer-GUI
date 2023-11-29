#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <cstdlib>
#include <iostream>

#include <../MyFrame.h>
#include <../MyApp.h>
#include <../MainImagePanel.h>
#include <../lodepng.h>

wxBEGIN_EVENT_TABLE(MyApp,wxApp)
    EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

bool MyApp::OnInit()
{

    wxInitAllImageHandlers();
    InitWindows(wxT("example.png"));
	return true;
}

void MyApp::InitWindows(wxString fileName) {
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    frame = new wxFrame(NULL, wxID_ANY, wxT("hot dog"), wxPoint(50, 200), wxSize(800, 600));

    wxButton* img_btn = new wxButton(frame, 10001, "Load Image", wxPoint(10, 10), wxSize(100, 25));

    drawPane = new wxImagePanel(frame, fileName, wxBITMAP_TYPE_JPEG);
    sizer->Add(drawPane, 1, wxEXPAND);
    frame->SetSizer(sizer);
    frame->Show(true);
}

void MyApp::OnButtonClicked(wxCommandEvent& evt) {


    wxFileDialog
        openFileDialog(frame, _("Open a PNG file"), "", "",
            "PNG files (*.png)|*.png", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());

    if (!input_stream.IsOk())
    {
        wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }

    frame->Destroy();
    drawPane->Destroy();
    InitWindows(openFileDialog.GetPath());
}