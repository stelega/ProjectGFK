//
//  MenuFrame.hpp
//  Projekt
//
//  Created by Michał Wojtasik on 22/05/2019.
//  Copyright © 2019 Michał Wojtasik. All rights reserved.
//

#ifndef MenuFrame_hpp
#define MenuFrame_hpp

#include <iostream>

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

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MenuFrame
///////////////////////////////////////////////////////////////////////////////
class MenuFrame : public wxFrame
{
private:
    wxColour m_background_color;
    static constexpr int miniaturka_size_x{150};
    static constexpr int miniaturka_size_y{120};
    
    // Menu górne
    wxStaticText *m_text_gornego_menu;
    
    // Miniaturki
    wxImage *m_no_photo_selected;
    wxImage *m_main;
    wxImage *m_miniaturka_1;
    wxImage *m_miniaturka_2;
    wxImage *m_miniaturka_3;
    wxImage *m_miniaturka_4;
    wxImage *m_miniaturka_5;
    
    // Menu boczne
    wxPanel* main_panel;
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
    int m_which_min;
    wxRadioButton *m_Radio_1;
    wxRadioButton *m_Radio_2;
    wxRadioButton *m_Radio_3;
    wxRadioButton *m_Radio_4;
    wxRadioButton *m_Radio_5;
    
    void Radio_Button_clic(wxCommandEvent& event);
    
    // RYSOWANIE
    void Repaint();
    void Repaint_minature( wxImage* miniaturka, wxBufferedDC *dc, wxSize main_panel_size, int which_min);
    void WxPanel_Repaint( wxPaintEvent& event );
    
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
    
    void wczytaj( int which_button );
    void wybierz( int which_button );
    
public:
    
    MenuFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300, 750 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    
    ~MenuFrame();
    
};



#endif /* MenuFrame_hpp */
