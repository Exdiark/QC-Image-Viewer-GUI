#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>

class wxImagePanel : public wxPanel
{
    wxImage* image;
    wxBitmap resized;
    int image_width, image_height, object_width, object_height;
    bool isMouseDown;

public:
    wxImagePanel(wxPanel* parent, wxString file, int width, int height);

    void paintEvent(wxPaintEvent& evt);
    void paintNow();
    void loadNewFile(wxString file);
    void render(wxDC& dc);
    wxSize getImageSize();

private:
    void processImage(std::string fileName);
    void mouseDown(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);

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

    DECLARE_EVENT_TABLE()
};