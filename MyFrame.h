///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <vector>

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

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:
        // Kolor tła
        wxColour m_background_color;
        // Wielkosc miniaturek
        static constexpr int miniaturka_size_x{150};
        static constexpr int miniaturka_size_y{120};
    
    
        // Panel ze zdjeciem glownym
        wxScrolledWindow* main_panel;
    
        // Miniaturki
        wxImage *m_no_photo_selected;
        wxImage *m_main;
        wxImage *m_main_copy;
        std::vector<wxImage *> m_miniaturka;
    
        // Menu boczne
        wxPanel * m_miniaturki;
		wxButton* m_wczytaj_1;
		wxButton* m_wybierz_1;
		wxButton* m_wczytaj_2;
		wxButton* m_wybierz_2;
		wxButton* m_wczytaj_3;
		wxButton* m_wybierz_3;
		wxButton* m_wczytaj_4;
		wxButton* m_wybierz_4;
		wxButton* m_wczytaj_5;
		wxButton* m_wybierz_5;
        // Zmienna ktora mowi ktora miniaturka jest wybrana aktualnie, jeszcze nie wiem czy sie przyda w ogole xd
        int m_which_min;
        wxRadioButton *m_Radio_1;
        wxRadioButton *m_Radio_2;
        wxRadioButton *m_Radio_3;
        wxRadioButton *m_Radio_4;
        wxRadioButton *m_Radio_5;
        // Wybór powiększenia
        std::vector<wxRadioButton *> m_Radio_powiekszenie;
    
    
        // OBSŁUGA ZDARZEN
        /** Wybranie konkretnej miniaturki na tło
         *  powinno załadować miniaturkę do głównego wxImgage - m_main
         *  sprawdzic jakie powiekszenie jest wybrane - tj. zaktualizowac tlo
         *  ustawic scrollBars
         *  na końcu wykonac rysowanie od poczatku
         **/
        void Radio_Button_clic(wxCommandEvent& event);
    
        /** Metody te powinny skopiowac oryginalne zdjecie do kopii
         *  kopie przeskalowac zgodnie z wybranym powiekszeniem
         *  ustawic scrollBars
         *  na końcu wykonac rysowanie od poczatku
         **/
        void m_Radio_powiekszenie_1_clic(wxCommandEvent& event);
        void m_Radio_powiekszenie_2_clic(wxCommandEvent& event);
        void m_Radio_powiekszenie_3_clic(wxCommandEvent& event);
        void m_Radio_powiekszenie_4_clic(wxCommandEvent& event);
    
        /**
         * Wykonuje rysowanie panelu z m_main_copy
         * wczesniej wysrodkowuje bitmape
         **/
        void WxPanel_Repaint( wxPaintEvent& event );
    
        /**
         * Odswieża panel z miniaturkami
         * jedyne co robi to rysuje miniaturki od nowa
         **/
        void WxPanelMiniaturek_Repaint( wxPaintEvent& event );
    
        /**
         * Wczytaj : powinno wczytac do wybranej miniaturki zdjecie
         *  po wczytaniu, sprawdzic czy jest wybrana na tło, oraz z jakim powiększeniem - czyli zaktualizowac tło
         *  ustawic scrollBars
         *  na końcu wykonac rysowanie od poczatku
         **/
        void m_wczytaj_1_click( wxCommandEvent& event );
        void m_wybierz_1_click( wxCommandEvent& event );
        void m_wczytaj_2_click( wxCommandEvent& event );
        void m_wybierz_2_click( wxCommandEvent& event );
        void m_wczytaj_3_click( wxCommandEvent& event );
        void m_wybierz_3_click( wxCommandEvent& event );
        void m_wczytaj_4_click( wxCommandEvent& event );
        void m_wybierz_4_click( wxCommandEvent& event );
        void m_wczytaj_5_click( wxCommandEvent& event );
        void m_wybierz_5_click( wxCommandEvent& event );
    
    
        void Repaint();
        void Repaint_miniatures();
        void Repaint_minature( wxImage* miniaturka, wxClientDC *dc, wxSize main_panel_size, int which_min);
        void wczytaj( int which_button );
        void wybierz( int which_button );
        void zaladuj_miniaturke();
        void zaktualizuj_powiekszenie();
        void dopasuj_szerokosc();
        void dopasuj_wysokosc();
        void zmiesc_na_ekranie();
        void na_maksa();
    
    
        // Skalowanie do wielkosci miniaturki z zachowaniem proporcji
        wxSize skalowanie_do_rozmiaru_z_zachowaniem_proporcji(wxSize rozmiar, wxSize do_skalowania);
        wxPoint wysrodkowanie(wxSize size, int width, int height);
	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1120, 629 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame();

};

