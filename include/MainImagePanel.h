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
    int image_width, image_height, object_width, object_height, display_width, display_height, display_x, display_y;
    bool isMouseDown;

    DECLARE_EVENT_TABLE()

public:
    wxImagePanel(wxPanel* parent, wxString file, int width, int height);
    void loadNewFile(wxString file);
    void render(wxDC& dc);
    wxSize getImageSize();
    void changeDisplay(int x, int y, int w, int h);
    void changeDisplay(int x, int y);
    void nextPage();
    void lastPage();

private:

    void processImage(std::string fileName);
    void processImage2(std::string fileName);
    void highlightPixel(int x, int y);
    void highlightRectangle(int x, int y, int w, int h);
    void highlightRow(int y);
    void highlightColumn(int y);

    unsigned char* getPixel(int x, int y);

    unsigned char* getColumnData(int x);

    unsigned char* getSubImage(int x, int y, int w, int h);
    void paintEvent(wxPaintEvent & evt);
    void OnLeftDown(wxMouseEvent& evt);
    void paintNow();
};