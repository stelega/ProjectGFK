#pragma once

#include <wx/wx.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/filedlg.h>
#include <wx/tglbtn.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/statbox.h>


#include "noname.h"
#include <vector>

class MyFrame : public GeneratedFrame {
public:
    MyFrame(wxWindow * parent);
    ~MyFrame();
    
    /* wczytywanie do odpowiednich miniaturek obrazkow */
    virtual void loadImage1(wxCommandEvent& event);
    virtual void loadImage2(wxCommandEvent& event);
    virtual void loadImage3(wxCommandEvent& event);
    virtual void loadImage4(wxCommandEvent& event);
    virtual void loadImage5(wxCommandEvent& event);
    
    /* wczytywanie odpowiednich obrazkow na tlo */
    virtual void backgroundDraw1(wxCommandEvent& event);
    virtual void backgroundDraw2(wxCommandEvent& event);
    virtual void backgroundDraw3(wxCommandEvent& event);
    virtual void backgroundDraw4(wxCommandEvent& event);
    virtual void backgroundDraw5(wxCommandEvent& event);
    
    virtual void startCutButtonClic(wxCommandEvent& event);
    virtual void endCutButtonClic(wxCommandEvent& event);
    
    /* Zaznaczanie obrazu */
    virtual void mouseLeftDown(wxMouseEvent& event);
    virtual void mouseMove(wxMouseEvent& event);
    virtual void choiceButtonClic(wxCommandEvent& event);
    /* dostosowywanie rozmiaru */
    virtual void adjustEvent(wxCommandEvent& event);
    
    void repaint();
    void repaintMiniatures();
    void repaintMinature(wxImage* miniaturka, wxClientDC *dc, wxSize main_panel_size, int which_min);
    void chooseBackground();
    void load(int which_button);
    void choose(int which_button);
    void loadMinature();
    void updateSizeOfPhoto(wxImage &image);
    void updateMain();
    void updateActualSizeAndCenter();
    void fitWidth(wxImage &image);
    void fitHeight(wxImage &image);
    void fitOnScreen(wxImage &image);
    void fullSize(wxImage &image);
    void uzupelnij_bitmape();
    void transformRectangleVector();
    
    
    void drawRectangle(wxDC& dc);
    //void drawBrokenCurve();
    //void rysuj_krzywa_zamknieta_gladka();
    
    
    void WxPanelMiniaturekRepaint(wxPaintEvent& event);
    void WxPanelRepaint(wxPaintEvent& event);
    
    // Skalowanie do wielkosci miniaturki z zachowaniem proporcji
    wxSize scaleWithProportion(wxSize rozmiar, wxSize do_skalowania);
    wxPoint centering(wxSize size, int width, int height);
    
    
private:
    int which_min;
    int m_helpfull;
    double m_scaleX, m_scaleY;
    // punkt w ktorym trzeba umiescic zdjecie na wxPanel aby było wysrodkowane
    std::vector<wxPoint> m_actualCenter;
    std::vector<wxPoint> m_startCenter;
    
    std::vector<wxSize> m_startSize;
    std::vector<wxSize> m_actualSize;
    //
    wxPoint mMinatureCenter;
    // Wektory, w każdym znajdują się punkty z których tworzony jest kwadrat
    // pierwsze 4 punkty to pierwszy kwadrar, drugie 4 punkty to drugi kwadrat itp.
    std::vector<wxPoint *> m_kwadrat1;
    std::vector<wxPoint *> m_kwadrat2;
    std::vector<wxPoint *> m_kwadrat3;
    std::vector<wxPoint *> m_kwadrat4;
    std::vector<wxPoint *> m_kwadrat5;
    std::vector<std::vector<wxPoint *>> m_kwadraty;
    
    std::vector<wxPoint> m_kwadrat1Copy;
    std::vector<wxPoint> m_kwadrat2Copy;
    std::vector<wxPoint> m_kwadrat3Copy;
    std::vector<wxPoint> m_kwadrat4Copy;
    std::vector<wxPoint> m_kwadrat5Copy;
    std::vector<std::vector<wxPoint>> m_kwadratyCopy;
    
    
    // Kolor tła
    wxColour m_backgroundColor;
    // Miniaturki
    wxImage *m_noSelectedPhoto;
    wxImage *m_main;
    wxImage *m_BackgroundImage;
    wxImage *m_ImageToPrint;
    std::vector<wxImage *> m_miniaturka;
    
    std::vector<wxRadioButton *> m_Radio;
    std::vector<wxRadioButton *> m_RadioPowiekszenie;
    
    static constexpr int m_miniaturkaSizeX{ 150 };
    static constexpr int m_miniaturkaSizeY{ 120 };
    
    
};
