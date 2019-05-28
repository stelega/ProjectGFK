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

	/* dostosowywanie rozmiaru */
	virtual void adjustEvent(wxCommandEvent& event);

	void Repaint();
	void Repaint_miniatures();
	void Repaint_minature(wxImage* miniaturka, wxClientDC *dc, wxSize main_panel_size, int which_min);
	void wczytaj(int which_button);
	void wybierz(int which_button);
	void zaladuj_miniaturke();
	void zaktualizuj_powiekszenie();
	void dopasuj_szerokosc();
	void dopasuj_wysokosc();
	void zmiesc_na_ekranie();
	void na_maksa();

	void WxPanelMiniaturek_Repaint(wxPaintEvent& event);
	void WxPanel_Repaint(wxPaintEvent& event);

	// Skalowanie do wielkosci miniaturki z zachowaniem proporcji
	wxSize skalowanie_do_rozmiaru_z_zachowaniem_proporcji(wxSize rozmiar, wxSize do_skalowania);
	wxPoint wysrodkowanie(wxSize size, int width, int height);


private:
	// Miniaturki
	wxImage *m_no_photo_selected;
	wxImage *m_main;
	wxImage *m_main_copy;
	std::vector<wxImage *> m_miniaturka;

	std::vector<wxRadioButton *> m_Radio;
	std::vector<wxRadioButton *> m_Radio_powiekszenie;

	static constexpr int miniaturka_size_x{ 150 };
	static constexpr int miniaturka_size_y{ 120 };


};
