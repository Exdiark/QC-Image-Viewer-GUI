#include <wx/colordlg.h>

#include "../include/Header.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)

EVT_PAINT(wxImagePanel::paintEvent)

END_EVENT_TABLE()

// some useful events
/*
 void wxImagePanel::mouseMoved(wxMouseEvent& event) {}
 void wxImagePanel::mouseDown(wxMouseEvent& event) {}
 void wxImagePanel::mouseWheelMoved(wxMouseEvent& event) {}
 void wxImagePanel::mouseReleased(wxMouseEvent& event) {}
 void wxImagePanel::rightClick(wxMouseEvent& event) {}
 void wxImagePanel::mouseLeftWindow(wxMouseEvent& event) {}
 void wxImagePanel::keyPressed(wxKeyEvent& event) {}
 void wxImagePanel::keyReleased(wxKeyEvent& event) {}
 */


wxImagePanel::wxImagePanel(wxPanel* parent, wxString file, int width, int height) : wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(width, height))
{
    object_width = width;
    object_height = height;
    isMouseDown = false;
    loadNewFile(file);
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void wxImagePanel::paintEvent(wxPaintEvent& evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void wxImagePanel::paintNow()
{
    // depending on your system you may need to look at double-buffered dcs
    wxClientDC dc(this);
    render(dc);
}

void wxImagePanel::loadNewFile(wxString file)
{
    processImage(std::string(file));
    Update();
    Refresh();
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void wxImagePanel::render(wxDC& dc)
{
    int neww, newh;
    dc.GetSize(&neww, &newh);

    if (neww != image_width || newh != image_height)
    {
        resized = wxBitmap(image->Scale(neww, newh /*, wxIMAGE_QUALITY_HIGH*/));
        dc.DrawBitmap(resized, 0, 0, false);
    }
    else {
        dc.DrawBitmap(resized, 0, 0, false);
    }
}

wxSize wxImagePanel::getImageSize() 
{
    return wxSize(image_width, image_height);
}

void wxImagePanel::processImage(std::string fileName)
{
    std::vector<unsigned char> decoded_image;

    unsigned width, height;
    unsigned error = lodepng::decode(decoded_image, width, height, fileName);

    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...

    image_width = width;
    image_height = height;

    unsigned char* image2D = (unsigned char*)malloc(width * height * 3);
    unsigned char* ptr = image2D;

    for (int i = 0; i < (width * height); i++) {

        //wxString Foobar;
        //Foobar.Printf(wxT("r is %d g is %d b is %d"), limage[4 * i], limage[4 * i+1], limage[4 * i+2]);
        //wxMessageBox(Foobar);

        *ptr = (decoded_image[4 * i]);
        ptr++;
        *ptr = (decoded_image[4 * i + 1]);
        ptr++;
        *ptr = (decoded_image[4 * i + 2]);
        ptr++;

    }

    image = new wxImage(width, height, image2D);
}

void wxImagePanel::mouseDown(wxMouseEvent& event)
{
    isMouseDown = true;
}

void wxImagePanel::mouseReleased(wxMouseEvent& event)
{
    isMouseDown = false;
}
