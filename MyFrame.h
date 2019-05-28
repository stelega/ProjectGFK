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
    
    virtual void start_cut_button_clic(wxCommandEvent& event);
    virtual void end_cut_button_clic(wxCommandEvent& event);
    
    /* Zaznaczanie obrazu */
    virtual void Mouse_Left_Down(wxMouseEvent& event);
    virtual void Mouse_Move(wxMouseEvent& event);
    virtual void choiceButtonClic(wxCommandEvent& event);
    /* dostosowywanie rozmiaru */
    virtual void adjustEvent(wxCommandEvent& event);
    
    void Repaint();
    void Repaint_miniatures();
    void Repaint_minature(wxImage* miniaturka, wxClientDC *dc, wxSize main_panel_size, int which_min);
    void wybierz_tlo();
    void wczytaj(int which_button);
    void wybierz(int which_button);
    void zaladuj_miniaturke();
    void zaktualizuj_powiekszenie();
    void dopasuj_szerokosc();
    void dopasuj_wysokosc();
    void zmiesc_na_ekranie();
    void na_maksa();
    void uzupelnij_bitmape();
    
    void rysuj_kwadrat(wxDC& dc);
    void rysuj_krzywa_zamknieta();
    void rysuj_krzywa_zamknieta_gladka();
    
    
    void WxPanelMiniaturek_Repaint(wxPaintEvent& event);
    void WxPanel_Repaint(wxPaintEvent& event);
    
    // Skalowanie do wielkosci miniaturki z zachowaniem proporcji
    wxSize skalowanie_do_rozmiaru_z_zachowaniem_proporcji(wxSize rozmiar, wxSize do_skalowania);
    wxPoint wysrodkowanie(wxSize size, int width, int height);
    
    
private:
    static int helpfull;
    double scale_x, scale_y;
    // Wektory, w każdym znajdują się punkty z których tworzony jest kwadrat
    // pierwsze 4 punkty to pierwszy kwadrar, drugie 4 punkty to drugi kwadrat itp.
    std::vector<wxPoint *> m_kwadrat_1;
    std::vector<wxPoint *> m_kwadrat_2;
    std::vector<wxPoint *> m_kwadrat_3;
    std::vector<wxPoint *> m_kwadrat_4;
    std::vector<wxPoint *> m_kwadrat_5;
    std::vector<std::vector<wxPoint *>> m_kwadraty;
    
    
    // Kolor tła
    wxColour m_background_color;
    // Miniaturki
    wxImage *m_no_photo_selected;
    wxImage *m_main;
    wxImage *m_background_image;
    wxImage *m_image_to_print;
    std::vector<wxImage *> m_miniaturka;
    
    std::vector<wxRadioButton *> m_Radio;
    std::vector<wxRadioButton *> m_Radio_powiekszenie;
    
    static constexpr int miniaturka_size_x{ 150 };
    static constexpr int miniaturka_size_y{ 120 };
    
    
};
