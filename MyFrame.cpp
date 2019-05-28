#include "MyFrame.h"

MyFrame::MyFrame(wxWindow * parent) : GeneratedFrame(parent, wxID_ANY, "Okno g³ówne") {
	// Tworzenie miejsca na oryginaly wszystkich zdjec
	for (int i = 0; i < 5; i++) {
		m_miniaturka.push_back(new wxImage);
	}

	m_main = new wxImage;
	m_main_copy = new wxImage;
	m_no_photo_selected = new wxImage;

	// Za³adowanie obrazka z napisem No photo selected oraz ustawienie wszystkich miniaturek
	wxInitAllImageHandlers();
	wxLogNull logNo;
	m_no_photo_selected->LoadFile("C:/Users/Stanis³aw/Desktop/xd.png");
	if (m_no_photo_selected->IsOk())
	{
		for (auto miniaturka : m_miniaturka) {
			*miniaturka = m_no_photo_selected->Copy();
		}
		
		*m_main = m_no_photo_selected->Copy();
		*m_main_copy = m_no_photo_selected->Copy();
	}

	m_Radio.push_back(background_min1);
	m_Radio.push_back(background_min2);
	m_Radio.push_back(background_min3);
	m_Radio.push_back(background_min4);
	m_Radio.push_back(background_min5);




	
}

void MyFrame::loadImage1(wxCommandEvent& event) {
	wczytaj(1);
}
void MyFrame::loadImage2(wxCommandEvent& event) {
	wczytaj(2);
}
void MyFrame::loadImage3(wxCommandEvent& event) {
	wczytaj(3);
}
void MyFrame::loadImage4(wxCommandEvent& event) {
	wczytaj(4);
}
void MyFrame::loadImage5(wxCommandEvent& event) {
	wczytaj(5);
}



void MyFrame::backgroundDraw1(wxCommandEvent& event) {

}
void MyFrame::backgroundDraw2(wxCommandEvent& event) {

}
void MyFrame::backgroundDraw3(wxCommandEvent& event) {

}
void MyFrame::backgroundDraw4(wxCommandEvent& event) {

}
void MyFrame::backgroundDraw5(wxCommandEvent& event) {

}



void MyFrame::adjustEvent(wxCommandEvent& event) {

}


void MyFrame::dopasuj_szerokosc()
{
	int x, y;
	imageWindow->GetSize(&x, &y);
	*m_main_copy = m_main->Copy();
	m_main_copy->Rescale(x, (static_cast<double>(m_main_copy->GetSize().y) / static_cast<double>(m_main_copy->GetSize().x)) * static_cast<double>(x));
	imageWindow->SetScrollbars(0, 20, 0, m_main_copy->GetSize().y / 20.0);
}

void MyFrame::dopasuj_wysokosc()
{
	int x, y;
	imageWindow->GetSize(&x, &y);
	*m_main_copy = m_main->Copy();
	m_main_copy->Rescale((static_cast<double>(m_main_copy->GetSize().x) / static_cast<double>(m_main_copy->GetSize().y)) * static_cast<double>(y), y);
	imageWindow->SetScrollbars(20, 0, m_main_copy->GetSize().x / 20.0, 0);
}

void MyFrame::zmiesc_na_ekranie()
{
	*m_main_copy = m_main->Copy();
	wxSize skalowanie = skalowanie_do_rozmiaru_z_zachowaniem_proporcji(imageWindow->GetSize(), m_main_copy->GetSize());
	m_main_copy->Rescale(skalowanie.x, skalowanie.y);
	imageWindow->SetScrollbars(20, 20, m_main_copy->GetSize().x / 20.0, m_main_copy->GetSize().y / 20.0);
}

void MyFrame::na_maksa()
{
	*m_main_copy = m_main->Copy();
	imageWindow->SetScrollbars(20, 20, m_main_copy->GetSize().x / 20.0, m_main_copy->GetSize().y / 20.0);
}

wxSize MyFrame::skalowanie_do_rozmiaru_z_zachowaniem_proporcji(wxSize rozmiar, wxSize do_skalowania)
{
	if (static_cast<double>(do_skalowania.x) / static_cast<double>(rozmiar.x) > static_cast<double>(do_skalowania.y) / static_cast<double>(rozmiar.y))
		return wxSize(rozmiar.x, (static_cast<double>(do_skalowania.y) / static_cast<double>(do_skalowania.x)) * static_cast<double>(rozmiar.x));
	else
		return wxSize((static_cast<double>(do_skalowania.x) / static_cast<double>(do_skalowania.y)) * static_cast<double>(rozmiar.y), rozmiar.y);
}

wxPoint MyFrame::wysrodkowanie(wxSize size, int width, int height)
{
	int w = size.x, h = size.y;
	int x{}, y{};
	if (width < w) x = (w - width) / 2.0;
	if (height < h) y = (h - height) / 2.0;
	return wxPoint(x, y);
}


void MyFrame::zaladuj_miniaturke()
{
	for (int i = 0; i < 5; i++)
		if (m_Radio[i]->GetValue() && m_miniaturka[i]->IsOk())
			*m_main = m_miniaturka[i]->Copy();
}

void MyFrame::zaktualizuj_powiekszenie()
{
	if (m_Radio_powiekszenie[0]->GetValue()) na_maksa();
	if (m_Radio_powiekszenie[1]->GetValue()) dopasuj_szerokosc();
	if (m_Radio_powiekszenie[2]->GetValue()) dopasuj_wysokosc();
	if (m_Radio_powiekszenie[3]->GetValue()) zmiesc_na_ekranie();
}

void MyFrame::Repaint()
{
	wxClientDC dc1(imageWindow);
	wxBufferedDC dc(&dc1);
	dc.Clear();
	int x, y;
	imageWindow->DoPrepareDC(dc);
	imageWindow->GetSize(&x, &y);
	if (m_main_copy->IsOk()) {
		dc.DrawBitmap(wxBitmap(*m_main_copy), wysrodkowanie(wxSize(x, y), m_main_copy->GetSize().x, m_main_copy->GetSize().y));
	}
}

void MyFrame::wczytaj(int which_button)
{
	wxImage new_image;
	wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
	if (WxOpenFileDialog.ShowModal() == wxID_OK) {
		new_image.LoadFile(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);
		if (new_image.IsOk()) {
			*(m_miniaturka[which_button - 1]) = new_image.Copy();
		}
	}
	if (m_Radio[which_button - 1]->GetValue())
	{
		zaladuj_miniaturke();
		zaktualizuj_powiekszenie();
	}
	Repaint_miniatures();
	Repaint();
}

void MyFrame::Repaint_miniatures()
{
	wxClientDC dc(m_miniaturki);
	dc.Clear();
	int x, y;
	imageWindow->GetSize(&x, &y);
	dc.SetBrush(wxBrush(*wxWHITE));
	dc.DrawRectangle(0, 0, miniaturka_size_x + 2, miniaturka_size_y * 5 + 7);
	dc.SetBrush(wxBrush(*wxBLACK));
	dc.DrawLine(0, 1 * (miniaturka_size_y + 1) + 1, miniaturka_size_x, 1 * (miniaturka_size_y + 1) + 1);
	dc.DrawLine(0, 2 * (miniaturka_size_y + 1) + 1, miniaturka_size_x, 2 * (miniaturka_size_y + 1) + 1);
	dc.DrawLine(0, 3 * (miniaturka_size_y + 1) + 1, miniaturka_size_x, 3 * (miniaturka_size_y + 1) + 1);
	dc.DrawLine(0, 4 * (miniaturka_size_y + 1) + 1, miniaturka_size_x, 4 * (miniaturka_size_y + 1) + 1);
	for (int i = 0; i < 5; i++)
		Repaint_minature(m_miniaturka[i], &dc, wxSize(x, y), i + 1);
}

void MyFrame::Repaint_minature(wxImage* miniaturka, wxClientDC *dc, wxSize imageWindow_size, int which_min)
{
	if (miniaturka->IsOk())
	{
		wxImage temp = miniaturka->Copy();
		wxSize resize = skalowanie_do_rozmiaru_z_zachowaniem_proporcji(wxSize(miniaturka_size_x, miniaturka_size_y), miniaturka->GetSize());
		temp.Rescale(resize.x, resize.y);
		wxPoint wysr = wysrodkowanie(wxSize(miniaturka_size_x, miniaturka_size_y), resize.x, resize.y);
		dc->DrawBitmap(wxBitmap(temp), 1 + wysr.x, which_min * (miniaturka_size_y + 1) - miniaturka_size_y + 1 + wysr.y);
	}
}


void MyFrame::WxPanelMiniaturek_Repaint(wxPaintEvent& event)
{
	Repaint_miniatures();
}

void MyFrame::WxPanel_Repaint(wxPaintEvent& event)
{
	Repaint();
}

