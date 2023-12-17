#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include "Console.h"

class wxImagePanel : public wxPanel
{
    wxImage* image;
    wxImage* display;
    wxBitmap resized;
    Console* console;
    int image_width, image_height, object_width, object_height, display_width, display_height;
    bool isMouseDown;

    DECLARE_EVENT_TABLE()

public:
    wxImagePanel(wxPanel* parent, wxString file, int width, int height);

    void paintEvent(wxPaintEvent& evt);
    void OnLeftDown(wxMouseEvent& evt);
    void paintNow();
    void loadNewFile(wxString file);
    void render(wxDC& dc);
    wxSize getImageSize();

    void changeDisplay(int x, int y, int w, int h);

    

    

private:
    void processImage(std::string fileName);
    unsigned char* getSubImage(int x, int y, int w, int h);

    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */
};