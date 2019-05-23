///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyFrame.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    // Minimalne rozmiary okna
	this->SetSizeHints( wxSize(1120 , 629), wxDefaultSize );
    
    // Tworzenie miejsca na oryginaly wszystkich zdjec
    m_miniaturka_1 = new wxImage;
    m_miniaturka_2 = new wxImage;
    m_miniaturka_3 = new wxImage;
    m_miniaturka_4 = new wxImage;
    m_miniaturka_5 = new wxImage;
    m_main = new wxImage;
    m_main_copy = new wxImage;
    m_no_photo_selected = new wxImage;
    
    // kolor tła
    m_background_color = wxColour(150,150,150);
    
    // Załadowanie obrazka z napisem No photo selected oraz ustawienie wszystkich miniaturek
    wxInitAllImageHandlers();
    wxLogNull logNo;
    m_no_photo_selected->LoadFile("/Users/michalwojtasik/Desktop/default.png");
    if(m_no_photo_selected->IsOk())
    {
        *m_miniaturka_1 = m_no_photo_selected->Copy();
        *m_miniaturka_2 = m_no_photo_selected->Copy();
        *m_miniaturka_3 = m_no_photo_selected->Copy();
        *m_miniaturka_4 = m_no_photo_selected->Copy();
        *m_miniaturka_5 = m_no_photo_selected->Copy();
        *m_main = m_no_photo_selected->Copy();
        *m_main_copy = m_no_photo_selected->Copy();
    }
    wxImage temp(*m_no_photo_selected);
//    wxSize temp_size = temp.GetSize();
    temp.Rescale(skalowanie_do_miniaturki(temp.GetSize().x, temp.GetSize().y).x, skalowanie_do_miniaturki(temp.GetSize().x, temp.GetSize().y).y);
    m_miniaturka_bitmap_1 = new wxStaticBitmap(this, 0, wxBitmap(temp), wxDefaultPosition, wxDefaultSize);
    m_miniaturka_bitmap_2 = new wxStaticBitmap(this, 0, wxBitmap(temp), wxDefaultPosition, wxDefaultSize);
    m_miniaturka_bitmap_3 = new wxStaticBitmap(this, 0, wxBitmap(temp), wxDefaultPosition, wxDefaultSize);
    m_miniaturka_bitmap_4 = new wxStaticBitmap(this, 0, wxBitmap(temp), wxDefaultPosition, wxDefaultSize);
    m_miniaturka_bitmap_5 = new wxStaticBitmap(this, 0, wxBitmap(temp), wxDefaultPosition, wxDefaultSize);
    m_miniaturka_bitmap_1->SetMinSize(wxSize(miniaturka_size_x, miniaturka_size_y));
    m_miniaturka_bitmap_2->SetMinSize(wxSize(miniaturka_size_x, miniaturka_size_y));
    m_miniaturka_bitmap_3->SetMinSize(wxSize(miniaturka_size_x, miniaturka_size_y));
    m_miniaturka_bitmap_4->SetMinSize(wxSize(miniaturka_size_x, miniaturka_size_y));
    m_miniaturka_bitmap_5->SetMinSize(wxSize(miniaturka_size_x, miniaturka_size_y));
//    m_miniaturka_bitmap_5->SetPosition(wysrodkowanie_miniaturki(temp_size.x, temp_size.y));
//    m_miniaturka_bitmap_5->SetPosition(wysrodkowanie_miniaturki(temp_size.x, temp_size.y));
//    m_miniaturka_bitmap_5->SetPosition(wysrodkowanie_miniaturki(temp_size.x, temp_size.y));
//    m_miniaturka_bitmap_5->SetPosition(wysrodkowanie_miniaturki(temp_size.x, temp_size.y));
//    m_miniaturka_bitmap_5->SetPosition(wysrodkowanie_miniaturki(temp_size.x, temp_size.y));

    // W cholerę sizersów i to wszystko inne
	wxBoxSizer* main_sizer;
	main_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* left_sizer;
	left_sizer = new wxBoxSizer( wxVERTICAL );

	main_panel = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    main_panel->SetScrollRate( 5, 5 );
    main_panel->SetScrollbars(20, 20, m_main->GetSize().x / 20.0, m_main->GetSize().y / 20.0);
	left_sizer->Add( main_panel, 1, wxEXPAND | wxALL, 0);


	main_sizer->Add( left_sizer, 1, wxEXPAND);

	wxBoxSizer* right_sizer;
	right_sizer = new wxBoxSizer( wxVERTICAL );
    
    wxBoxSizer* right_sizer_with_minatures;
    right_sizer_with_minatures = new wxBoxSizer( wxVERTICAL );
    right_sizer_with_minatures->Add( m_miniaturka_bitmap_1, 0, wxALL|wxEXPAND, 1);
    right_sizer_with_minatures->Add( m_miniaturka_bitmap_2, 0, wxALL|wxEXPAND, 1);
    right_sizer_with_minatures->Add( m_miniaturka_bitmap_3, 0, wxALL|wxEXPAND, 1);
    right_sizer_with_minatures->Add( m_miniaturka_bitmap_4, 0, wxALL|wxEXPAND, 1);
    right_sizer_with_minatures->Add( m_miniaturka_bitmap_5, 0, wxALL|wxEXPAND, 1);
    
    wxStaticBoxSizer* right_sizer_with_big_menu;
    right_sizer_with_big_menu = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Dostosuj powiększenie")), wxVERTICAL );
    right_sizer_with_big_menu->SetMinSize(100, 629);
    
    m_Radio_powiekszenie_1 = new wxRadioButton(this, wxID_ANY, _("100%"), wxDefaultPosition, wxDefaultSize, 0 );
    right_sizer_with_big_menu->Add( m_Radio_powiekszenie_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie_2 = new wxRadioButton(this, wxID_ANY, _("Dopasuj szerokość"), wxDefaultPosition, wxDefaultSize, 0 );
    right_sizer_with_big_menu->Add( m_Radio_powiekszenie_2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie_3 = new wxRadioButton(this, wxID_ANY, _("Dopasuj wysokość"), wxDefaultPosition, wxDefaultSize, 0 );
    right_sizer_with_big_menu->Add( m_Radio_powiekszenie_3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie_4 = new wxRadioButton(this, wxID_ANY, _("Zmieść na ekranie"), wxDefaultPosition, wxDefaultSize, 0 );
    right_sizer_with_big_menu->Add( m_Radio_powiekszenie_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie_1->SetValue(true);
    
    
//    m_miniaturki = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
//    m_miniaturki->SetMinSize(wxSize(152, 607));
//    right_sizer_with_minatures->Add(m_miniaturki, 0, wxEXPAND);

	wxBoxSizer* sizer_1;
	sizer_1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_1;
	buttons_1 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Miniaturka 1")), wxVERTICAL );
    buttons_1->SetMinSize(100, miniaturka_size_y + 1);

	m_wczytaj_1 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( m_wczytaj_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

	m_wybierz_1 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( m_wybierz_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

    m_Radio_1 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    m_Radio_1->SetValue(true);
    buttons_1->Add( m_Radio_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

	sizer_1->Add( buttons_1, 0, wxALL);


	right_sizer->Add( sizer_1, 0, wxALL);

	wxBoxSizer* sizer_2;
	sizer_2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_2;
	buttons_2 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Miniaturka 2")), wxVERTICAL );
    buttons_2->SetMinSize(100, miniaturka_size_y + 1);

	m_wczytaj_2 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_2->Add( m_wczytaj_2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

	m_wybierz_2 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_2->Add( m_wybierz_2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );
    
    m_Radio_2 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_2->Add( m_Radio_2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


	sizer_2->Add( buttons_2, 0, wxALL);


	right_sizer->Add( sizer_2, 0, wxALL);

	wxBoxSizer* sizer_3;
	sizer_3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_3;
	buttons_3 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Miniaturka 3")), wxVERTICAL );
    buttons_3->SetMinSize(100, miniaturka_size_y + 1);

	m_wczytaj_3 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_3->Add( m_wczytaj_3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

	m_wybierz_3 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_3->Add( m_wybierz_3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );
    
    m_Radio_3 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_3->Add( m_Radio_3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


	sizer_3->Add( buttons_3, 0, wxALL);


	right_sizer->Add( sizer_3, 0, wxALL);

	wxBoxSizer* sizer_4;
	sizer_4 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_4;
	buttons_4 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Miniaturka 4")), wxVERTICAL );
    buttons_4->SetMinSize(100, miniaturka_size_y + 1);

	m_wczytaj_4 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_4->Add( m_wczytaj_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

	m_wybierz_4 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_4->Add( m_wybierz_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );
    
    m_Radio_4 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_4->Add( m_Radio_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


	sizer_4->Add( buttons_4, 0, wxALL);


	right_sizer->Add( sizer_4, 0, wxALL);

	wxBoxSizer* sizer_5;
	sizer_5 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_5;
	buttons_5 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Miniaturka 5")), wxVERTICAL );
    buttons_5->SetMinSize(100, miniaturka_size_y + 1);

	m_wczytaj_5 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_5->Add( m_wczytaj_5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

	m_wybierz_5 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_5->Add( m_wybierz_5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );
    
    m_Radio_5 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_5->Add( m_Radio_5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


	sizer_5->Add( buttons_5, 0, wxEXPAND);


	right_sizer->Add( sizer_5, 0, wxEXPAND);

    main_sizer->Add( right_sizer_with_minatures, 0, wxEXPAND);
	main_sizer->Add( right_sizer, 0, wxEXPAND);
    main_sizer->Add( right_sizer_with_big_menu, 0, wxEXPAND);


	this->SetSizer( main_sizer );
	this->Layout();
	this->Centre( wxBOTH );
    this->SetBackgroundColour(m_background_color);
    main_panel->SetBackgroundColour(m_background_color);
    
    // obsługa zdarzeń
    m_Radio_1->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_2->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_3->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_4->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_5->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    
    m_Radio_powiekszenie_1->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_1_clic ), NULL, this );
    m_Radio_powiekszenie_2->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_2_clic ), NULL, this );
    m_Radio_powiekszenie_3->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_3_clic ), NULL, this );
    m_Radio_powiekszenie_4->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_4_clic ), NULL, this );
    
    m_wczytaj_1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_1_click ), NULL, this );
    m_wybierz_1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_1_click ), NULL, this );
    m_wczytaj_2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_2_click ), NULL, this );
    m_wybierz_2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_2_click ), NULL, this );
    m_wczytaj_3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_3_click ), NULL, this );
    m_wybierz_3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_3_click ), NULL, this );
    m_wczytaj_4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_4_click ), NULL, this );
    m_wybierz_4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_4_click ), NULL, this );
    m_wczytaj_5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_5_click ), NULL, this );
    m_wybierz_5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_5_click ), NULL, this );
    
    main_panel->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
//    m_miniaturki->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturek_Repaint ), NULL, this );
}

MyFrame::~MyFrame()
{
    m_Radio_1->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_2->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_3->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_4->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    m_Radio_5->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    
    m_Radio_powiekszenie_1->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_1_clic ), NULL, this );
    m_Radio_powiekszenie_2->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_2_clic ), NULL, this );
    m_Radio_powiekszenie_3->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_3_clic ), NULL, this );
    m_Radio_powiekszenie_4->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_4_clic ), NULL, this );
    
    m_wczytaj_1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_1_click ), NULL, this );
    m_wybierz_1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_1_click ), NULL, this );
    m_wczytaj_2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_2_click ), NULL, this );
    m_wybierz_2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_2_click ), NULL, this );
    m_wczytaj_3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_3_click ), NULL, this );
    m_wybierz_3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_3_click ), NULL, this );
    m_wczytaj_4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_4_click ), NULL, this );
    m_wybierz_4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_4_click ), NULL, this );
    m_wczytaj_5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wczytaj_5_click ), NULL, this );
    m_wybierz_5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::m_wybierz_5_click ), NULL, this );
    
    main_panel->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
//    m_miniaturki->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturek_Repaint ), NULL, this );
}

void MyFrame::m_wczytaj_1_click( wxCommandEvent& event ) { wczytaj(1); }
void MyFrame::m_wybierz_1_click( wxCommandEvent& event ) {}
void MyFrame::m_wczytaj_2_click( wxCommandEvent& event ) { wczytaj(2); }
void MyFrame::m_wybierz_2_click( wxCommandEvent& event ) {}
void MyFrame::m_wczytaj_3_click( wxCommandEvent& event ) { wczytaj(3); }
void MyFrame::m_wybierz_3_click( wxCommandEvent& event ) {}
void MyFrame::m_wczytaj_4_click( wxCommandEvent& event ) { wczytaj(4); }
void MyFrame::m_wybierz_4_click( wxCommandEvent& event ) {}
void MyFrame::m_wczytaj_5_click( wxCommandEvent& event ) { wczytaj(5); }
void MyFrame::m_wybierz_5_click( wxCommandEvent& event ) {}


//void MyFrame::WxPanelMiniaturek_Repaint( wxPaintEvent& event )
//{
//    Repaint_miniatures();
//}

//void MyFrame::Repaint_miniatures()
//{
////    wxClientDC dc(m_miniaturki);
////    dc.Clear();
////    int x, y;
////    main_panel->GetSize(&x, &y);
////    dc.SetBrush(wxBrush(*wxWHITE));
////    dc.DrawRectangle(0, 0, miniaturka_size_x + 2, miniaturka_size_y * 5 + 7);
////    dc.SetBrush(wxBrush(*wxBLACK));
////    dc.DrawLine(0, 1 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 1 * (miniaturka_size_y + 1) + 1);
////    dc.DrawLine(0, 2 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 2 * (miniaturka_size_y + 1) + 1);
////    dc.DrawLine(0, 3 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 3 * (miniaturka_size_y + 1) + 1);
////    dc.DrawLine(0, 4 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 4 * (miniaturka_size_y + 1) + 1);
////    Repaint_minature(m_miniaturka_1, &dc, wxSize(x, y), 1);
////    Repaint_minature(m_miniaturka_2, &dc, wxSize(x, y), 2);
////    Repaint_minature(m_miniaturka_3, &dc, wxSize(x, y), 3);
////    Repaint_minature(m_miniaturka_4, &dc, wxSize(x, y), 4);
////    Repaint_minature(m_miniaturka_5, &dc, wxSize(x, y), 5);
//}

void MyFrame::WxPanel_Repaint( wxPaintEvent& event )
{
    Repaint();
}

//void MyFrame::Repaint_minature( wxImage* miniaturka, wxClientDC *dc, wxSize main_panel_size, int which_min)
//{
////    if ( miniaturka->IsOk() )
////    {
////        wxImage temp = miniaturka->Copy();
////        temp.Rescale(miniaturka_size_x, miniaturka_size_y);
////        dc->DrawBitmap(wxBitmap(temp), 1, which_min * (miniaturka_size_y + 1) - miniaturka_size_y + 1);
////    }
//}



void MyFrame::Radio_Button_clic(wxCommandEvent& event)
{
    aktualizuj_tlo();
    Repaint();
}


void MyFrame::m_Radio_powiekszenie_1_clic(wxCommandEvent& event)
{
    na_maksa();
}

void MyFrame::m_Radio_powiekszenie_2_clic(wxCommandEvent& event)
{
    dopasuj_szerokosc();
}

void MyFrame::m_Radio_powiekszenie_3_clic(wxCommandEvent& event)
{
    dopasuj_wysokosc();
}

void MyFrame::m_Radio_powiekszenie_4_clic(wxCommandEvent& event)
{
    zmiesc_na_ekranie();
}

void MyFrame::dopasuj_szerokosc()
{
    this->Maximize();
    int x, y;
    main_panel->GetSize(&x, &y);
    double scale = m_main->GetSize().x / x;
    *m_main_copy = m_main->Copy();
    m_main_copy->Rescale(x, m_main->GetSize().x / scale);
}
void MyFrame::dopasuj_wysokosc()
{
    *m_main_copy = m_main->Copy();
}
void MyFrame::zmiesc_na_ekranie()
{
    *m_main_copy = m_main->Copy();
}
void MyFrame::na_maksa()
{
    *m_main_copy = m_main->Copy();
}

wxSize MyFrame::skalowanie_do_miniaturki(int width, int height)
{
    double scale;
    if(width > height)
    {
        scale = width / static_cast<double>(miniaturka_size_x);
        return wxSize(miniaturka_size_x, height / scale);
    } else
    {
        scale = height / static_cast<double>(miniaturka_size_y);
        return wxSize(width / scale, miniaturka_size_y);
    }
}

wxPoint MyFrame::wysrodkowanie_miniaturki(int width, int height)
{
    if (width == miniaturka_size_x)
    {
        return wxPoint(0, (miniaturka_size_y - height) / 2.0);
    } else
    {
        return wxPoint((miniaturka_size_x - width) / 2.0, 0);
    }
}

void MyFrame::aktualizuj_tlo()
{
    if(m_Radio_1->GetValue() && m_miniaturka_1->IsOk())
    {
        *m_main = m_miniaturka_1->Copy();
        main_panel->SetScrollbars(20, 20, m_main->GetSize().x / 20.0 , m_main->GetSize().y / 20.0);
        m_which_min = 1;
    }
    if(m_Radio_2->GetValue() && m_miniaturka_2->IsOk())
    {
        *m_main = m_miniaturka_2->Copy();
        main_panel->SetScrollbars(20, 20, m_main->GetSize().x / 20.0 , m_main->GetSize().y / 20.0);
        m_which_min = 2;
    }
    if(m_Radio_3->GetValue() && m_miniaturka_3->IsOk())
    {
        *m_main = m_miniaturka_3->Copy();
        main_panel->SetScrollbars(20, 20, m_main->GetSize().x / 20.0 , m_main->GetSize().y / 20.0);
        m_which_min = 3;
    }
    if(m_Radio_4->GetValue() && m_miniaturka_4->IsOk())
    {
        *m_main = m_miniaturka_4->Copy();
        main_panel->SetScrollbars(20, 20, m_main->GetSize().x / 20.0 , m_main->GetSize().y / 20.0);
        m_which_min = 4;
    }
    if(m_Radio_5->GetValue() && m_miniaturka_5->IsOk())
    {
        *m_main = m_miniaturka_5->Copy();
        main_panel->SetScrollbars(20, 20, m_main->GetSize().x / 20.0 , m_main->GetSize().y / 20.0);
        m_which_min = 5;
    }
    
    if(m_Radio_powiekszenie_1->GetValue()) na_maksa();
    if(m_Radio_powiekszenie_2->GetValue()) dopasuj_szerokosc();
    if(m_Radio_powiekszenie_3->GetValue()) dopasuj_wysokosc();
    if(m_Radio_powiekszenie_4->GetValue()) zmiesc_na_ekranie();
}

void MyFrame::Repaint()
{
    wxClientDC dc(main_panel);
    dc.Clear();
    int x, y;
    main_panel->DoPrepareDC(dc);
    main_panel->GetSize(&x, &y);
    
    if ( m_main_copy->IsOk() ) {
        dc.DrawBitmap(wxBitmap(*m_main_copy), 0, 0);
    }
}

void MyFrame::wczytaj( int which_button )
{
    wxImage new_image;
    wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
    if (WxOpenFileDialog.ShowModal() == wxID_OK){
        new_image.LoadFile(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);
        if(new_image.IsOk()){
            if(which_button == 1)
            {
                *m_miniaturka_1 = new_image.Copy();
                wxSize resize = skalowanie_do_miniaturki(m_miniaturka_1->GetSize().x, m_miniaturka_1->GetSize().y);
                wxImage temp(*m_miniaturka_1);
                temp.Rescale(resize.x, resize.y);
                //                m_miniaturka_bitmap_1->SetPosition(wysrodkowanie_miniaturki(resize.x, resize.y));
                m_miniaturka_bitmap_1->SetBitmap(wxBitmap(temp));
            }
            if(which_button == 2)
            {
                *m_miniaturka_2 = new_image.Copy();
                wxSize resize = skalowanie_do_miniaturki(m_miniaturka_2->GetSize().x, m_miniaturka_2->GetSize().y);
                wxImage temp(*m_miniaturka_2);
                temp.Rescale(resize.x, resize.y);
                //                m_miniaturka_bitmap_2->SetPosition(wysrodkowanie_miniaturki(resize.x, resize.y));
                m_miniaturka_bitmap_2->SetBitmap(wxBitmap(temp));
            }
            if(which_button == 3)
            {
                *m_miniaturka_3 = new_image.Copy();
                wxSize resize = skalowanie_do_miniaturki(m_miniaturka_3->GetSize().x, m_miniaturka_3->GetSize().y);
                wxImage temp(*m_miniaturka_3);
                temp.Rescale(resize.x, resize.y);
                //                m_miniaturka_bitmap_3->SetPosition(wysrodkowanie_miniaturki(resize.x, resize.y));
                m_miniaturka_bitmap_3->SetBitmap(wxBitmap(temp));
            }
            if(which_button == 4)
            {
                *m_miniaturka_4 = new_image.Copy();
                wxSize resize = skalowanie_do_miniaturki(m_miniaturka_4->GetSize().x, m_miniaturka_4->GetSize().y);
                wxImage temp(*m_miniaturka_4);
                temp.Rescale(resize.x, resize.y);
                //                m_miniaturka_bitmap_4->SetPosition(wysrodkowanie_miniaturki(resize.x, resize.y));
                m_miniaturka_bitmap_4->SetBitmap(wxBitmap(temp));
            }
            if(which_button == 5)
            {
                *m_miniaturka_5 = new_image.Copy();
                wxSize resize = skalowanie_do_miniaturki(m_miniaturka_5->GetSize().x, m_miniaturka_5->GetSize().y);
                wxImage temp(*m_miniaturka_5);
                temp.Rescale(resize.x, resize.y);
                //                m_miniaturka_bitmap_5->SetPosition(wysrodkowanie_miniaturki(resize.x, resize.y));
                m_miniaturka_bitmap_5->SetBitmap(wxBitmap(temp));
            }
        }
    }
    aktualizuj_tlo();
    //Repaint_miniatures();
    Repaint();
}

