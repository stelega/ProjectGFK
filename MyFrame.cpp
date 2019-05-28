#include "MyFrame.h"

int MyFrame::helpfull = 0;

MyFrame::MyFrame(wxWindow * parent) : GeneratedFrame(parent, wxID_ANY, "Okno g≥Ûwne") {
    // Tworzenie miejsca na oryginaly wszystkich zdjec
    scale_x = 1;
    scale_y = 1;
    for (int i = 0; i < 5; i++) {
        m_miniaturka.push_back(new wxImage);
    }
    
    // kolor tła
    m_background_color = wxColour(150,150,150);
    
    m_main = new wxImage;
    m_image_to_print = new wxImage;
    m_no_photo_selected = new wxImage;
    m_background_image = new wxImage;
    m_choice1->Disable();
    
    background_min1->SetValue(true);
    adjust_box->SetSelection(3);
    
    imageWindow->wxWindowBase::SetBackgroundColour(m_background_color);
    m_miniaturki->wxWindowBase::SetBackgroundColour(m_background_color);
    this->wxWindowBase::SetBackgroundColour(m_background_color);
    
    // Za≥adowanie obrazka z napisem No photo selected oraz ustawienie wszystkich miniaturek
    wxInitAllImageHandlers();
    wxLogNull logNo;
    m_no_photo_selected->LoadFile("/Users/michalwojtasik/Desktop/default.png");
    if (m_no_photo_selected->IsOk())
    {
        for (auto miniaturka : m_miniaturka) {
            *miniaturka = m_no_photo_selected->Copy();
        }
        
        *m_main = m_no_photo_selected->Copy();
        *m_image_to_print = m_no_photo_selected->Copy();
        *m_background_image = m_no_photo_selected->Copy();
    }
    
    m_Radio.push_back(background_min1);
    m_Radio.push_back(background_min2);
    m_Radio.push_back(background_min3);
    m_Radio.push_back(background_min4);
    m_Radio.push_back(background_min5);
    
    m_kwadraty.push_back(m_kwadrat_1);
    m_kwadraty.push_back(m_kwadrat_2);
    m_kwadraty.push_back(m_kwadrat_3);
    m_kwadraty.push_back(m_kwadrat_4);
    m_kwadraty.push_back(m_kwadrat_5);
    
    m_choice1->Connect( wxEVT_CHOICE, wxCommandEventHandler( MyFrame::choiceButtonClic ), NULL, this );
    
    imageWindow->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame::Mouse_Left_Down ), NULL, this );
    imageWindow->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame::Mouse_Move ), NULL, this );
    imageWindow->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniaturki->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturek_Repaint ), NULL, this );
    
    startCutButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::start_cut_button_clic ), NULL, this );
    endCutButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::end_cut_button_clic ), NULL, this );
    
    zaktualizuj_powiekszenie();
}


MyFrame::~MyFrame()
{
    imageWindow->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame::Mouse_Left_Down ), NULL, this );
    imageWindow->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MyFrame::Mouse_Move ), NULL, this );
    imageWindow->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniaturki->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturek_Repaint ), NULL, this );
    
    startCutButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::start_cut_button_clic ), NULL, this );
    endCutButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::end_cut_button_clic ), NULL, this );
}

void MyFrame::choiceButtonClic(wxCommandEvent& event)
{
    Repaint();
}

void MyFrame::start_cut_button_clic(wxCommandEvent& event)
{
    m_choice1->Enable();
    //adjust_box->Disable();
    Repaint();
}

void MyFrame::end_cut_button_clic(wxCommandEvent& event)
{
    m_choice1->Disable();
    adjust_box->Enable();
    Repaint();
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
    wybierz_tlo();
}
void MyFrame::backgroundDraw2(wxCommandEvent& event) {
    wybierz_tlo();
}
void MyFrame::backgroundDraw3(wxCommandEvent& event) {
    wybierz_tlo();
}
void MyFrame::backgroundDraw4(wxCommandEvent& event) {
    wybierz_tlo();
}
void MyFrame::backgroundDraw5(wxCommandEvent& event) {
    wybierz_tlo();
}



void MyFrame::adjustEvent(wxCommandEvent& event) {
    zaktualizuj_powiekszenie();
}


void MyFrame::Mouse_Move(wxMouseEvent& event)
{
    int shape_selection = chooseShapeBox->GetSelection();
    int miniature_selection = m_choice1->GetSelection();
    
    //std::cout << imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY())).x << std::endl;
    
    //sprawdzamy, czy aktualnie mysz byla kliknieta nieparzystą ilośc razy
    if(helpfull % 2 == 1)
    {
        int square_count = (int)m_kwadraty[miniature_selection].size();
        if(shape_selection == 2)
        {
            *m_kwadraty[miniature_selection][square_count - 3] = imageWindow->CalcUnscrolledPosition(wxPoint(m_kwadraty[miniature_selection][square_count - 4]->x, event.GetY()));
            *m_kwadraty[miniature_selection][square_count - 2] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()));
            *m_kwadraty[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), m_kwadraty[miniature_selection][square_count - 4]->y));
        }
    }
    
    Repaint();
}

void MyFrame::Mouse_Left_Down(wxMouseEvent& event)
{
    int shape_selection = chooseShapeBox->GetSelection();
    int miniature_selection = m_choice1->GetSelection();
    if(m_choice1->IsEnabled() == false) return;
    helpfull++;
    // Jezeli chcemy narysowac kwadrat
    if(shape_selection == 2)
    {
        //sprawdzamy, czy aktualnie mysz byla kliknieta parzystą, czy nieparzystą ilośc razy
        int square_count = (int)m_kwadraty[miniature_selection].size();
        //std::cout << square_count << std::endl;
        if(helpfull % 2 == 1)
        {
            for(int i = 0 ; i < 4 ; i++)
            {
                m_kwadraty[miniature_selection].push_back(new wxPoint(event.GetX(), event.GetY()));
                *m_kwadraty[miniature_selection][square_count + i] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()));
            }
        }
        else
        {
            *m_kwadraty[miniature_selection][square_count - 3] = imageWindow->CalcUnscrolledPosition(wxPoint(m_kwadraty[miniature_selection][square_count - 4]->x, event.GetY()));
            *m_kwadraty[miniature_selection][square_count - 2] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()));
            *m_kwadraty[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), m_kwadraty[miniature_selection][square_count - 4]->y));
        }
    }

    Repaint();
}

void MyFrame::uzupelnij_bitmape()
{
    
}

void MyFrame::rysuj_kwadrat(wxDC& dc)
{
    dc.SetBrush(wxBrush(*wxBLACK));
    int miniature_selection = m_choice1->GetSelection();
    int rect_count = m_kwadraty[miniature_selection].size() / 4.0;
    std::vector<wxPoint *> points;
    points.push_back(new wxPoint());
    points.push_back(new wxPoint());
    points.push_back(new wxPoint());
    points.push_back(new wxPoint());
    for(int i = 0 ; i < rect_count ; i++)
    {
        std::cout << scale_x << std::endl;
        *points[0] = *m_kwadraty[miniature_selection][0 + (i * 4)];
        *points[1] = *m_kwadraty[miniature_selection][1 + (i * 4)];
        *points[2] = *m_kwadraty[miniature_selection][2 + (i * 4)];
        *points[3] = *m_kwadraty[miniature_selection][3 + (i * 4)];
        std::cout << points[0]->x << "    ";
        int selection = adjust_box->GetSelection();
        if(selection == 0)
        {
            for(auto point : points)
            {
                int x = point->x;
                int y = point->y;
                *point = wxPoint(x * scale_x, y * scale_y);
            }
        }
        if(selection == 1)
        {
            
        }
        if(selection == 2)
        {
        }
        std::cout << points[0]->x << std::endl;
        dc.DrawLine(*points[0], *points[1]);
        dc.DrawLine(*points[0], *points[3]);
        dc.DrawLine(*points[1], *points[2]);
        dc.DrawLine(*points[2], *points[3]);
    }
}

void MyFrame::rysuj_krzywa_zamknieta(){}
void MyFrame::rysuj_krzywa_zamknieta_gladka(){}

void MyFrame::wybierz_tlo(){
    zaladuj_miniaturke();
    zaktualizuj_powiekszenie();
    Repaint();
}


void MyFrame::dopasuj_szerokosc()
{
    int x, y;
    imageWindow->GetSize(&x, &y);
    *m_image_to_print = m_main->Copy();
    *m_background_image = m_main->Copy();
    
    m_image_to_print->Rescale(x, (static_cast<double>(m_image_to_print->GetSize().y) / static_cast<double>(m_image_to_print->GetSize().x)) * static_cast<double>(x));
    imageWindow->SetScrollbars(0, 20, 0, m_image_to_print->GetSize().y / 20.0);
}

void MyFrame::dopasuj_wysokosc()
{
    int x, y;
    imageWindow->GetSize(&x, &y);
    *m_image_to_print = m_main->Copy();
    *m_background_image = m_main->Copy();
    m_image_to_print->Rescale((static_cast<double>(m_image_to_print->GetSize().x) / static_cast<double>(m_image_to_print->GetSize().y)) * static_cast<double>(y), y);
    imageWindow->SetScrollbars(20, 0, m_image_to_print->GetSize().x / 20.0, 0);
}

void MyFrame::zmiesc_na_ekranie()
{
    scale_x = 1;
    scale_y = 1;
    *m_image_to_print = m_main->Copy();
    *m_background_image = m_main->Copy();
    wxSize skalowanie = skalowanie_do_rozmiaru_z_zachowaniem_proporcji(imageWindow->GetSize(), m_image_to_print->GetSize());
    m_image_to_print->Rescale(skalowanie.x, skalowanie.y);
    imageWindow->SetScrollbars(20, 20, m_image_to_print->GetSize().x / 20.0, m_image_to_print->GetSize().y / 20.0);
}

void MyFrame::na_maksa()
{
    *m_image_to_print = m_main->Copy();
    *m_background_image = m_main->Copy();
    wxSize skalowanie = skalowanie_do_rozmiaru_z_zachowaniem_proporcji(imageWindow->GetSize(), m_image_to_print->GetSize());
    scale_x = static_cast<double>(m_image_to_print->GetSize().x) / static_cast<double>(skalowanie.x);
    scale_y = static_cast<double>(m_image_to_print->GetSize().y) / static_cast<double>(skalowanie.y);
    imageWindow->SetScrollbars(20, 20, m_image_to_print->GetSize().x / 20.0, m_image_to_print->GetSize().y / 20.0);
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
    int selection = adjust_box->GetSelection();
    if(selection == 0)
        na_maksa();
    if(selection == 1)
        dopasuj_szerokosc();
    if(selection == 2)
        dopasuj_wysokosc();
    if(selection == 3)
        zmiesc_na_ekranie();
    Repaint();
}

void MyFrame::Repaint()
{
    wxClientDC dc1(imageWindow);
    wxBufferedDC dc(&dc1);
    dc.Clear();
    int x, y;
    imageWindow->DoPrepareDC(dc);
    imageWindow->GetSize(&x, &y);
    if (m_image_to_print->IsOk()) {
        dc.DrawBitmap(wxBitmap(*m_image_to_print), wysrodkowanie(wxSize(x, y), m_image_to_print->GetSize().x, m_image_to_print->GetSize().y));
    }
    
    int selection = chooseShapeBox->GetSelection();
    if(selection == 2 )
    {
        rysuj_kwadrat(dc);
    }
    //dc.DrawRectangle(wxPoint(1000, 600), wxSize(100, 100));
    
    
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

