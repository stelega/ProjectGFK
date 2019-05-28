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
    for(int i = 0 ; i < 5 ; i++)
        m_miniaturka.push_back(new wxImage);
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
        for(auto miniaturka : m_miniaturka)
            *miniaturka = m_no_photo_selected->Copy();
        *m_main = m_no_photo_selected->Copy();
        *m_main_copy = m_no_photo_selected->Copy();
    }

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
    
    wxBoxSizer* right_sizer_with_big_menu;
    right_sizer_with_big_menu = new wxBoxSizer( wxVERTICAL );
    right_sizer_with_big_menu->SetMinSize(100, 629);
    
    wxStaticBoxSizer *powiekszenia = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Dostosuj powiększenie")), wxVERTICAL );
    
    m_Radio_powiekszenie.push_back(new wxRadioButton(this, wxID_ANY, _("100%"), wxDefaultPosition, wxDefaultSize, 0 ));
    powiekszenia->Add( m_Radio_powiekszenie[0], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie.push_back(new wxRadioButton(this, wxID_ANY, _("Dopasuj szerokość"), wxDefaultPosition, wxDefaultSize, 0 ));
    powiekszenia->Add( m_Radio_powiekszenie[1], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie.push_back(new wxRadioButton(this, wxID_ANY, _("Dopasuj wysokość"), wxDefaultPosition, wxDefaultSize, 0 ));
    powiekszenia->Add( m_Radio_powiekszenie[2], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie.push_back(new wxRadioButton(this, wxID_ANY, _("Zmieść na ekranie"), wxDefaultPosition, wxDefaultSize, 0 ));
    powiekszenia->Add( m_Radio_powiekszenie[3], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    wxStaticBoxSizer *wycinanie = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Dostosuj powiększenie")), wxVERTICAL );
    
    right_sizer_with_big_menu->Add( powiekszenia, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    
    m_Radio_powiekszenie[3]->SetValue(true);
    
    
    m_miniaturki = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    m_miniaturki->SetMinSize(wxSize(152, 607));
    right_sizer_with_minatures->Add(m_miniaturki, 0, wxEXPAND);

	wxBoxSizer* sizer_1;
	sizer_1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_1;
	buttons_1 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Miniaturka 1")), wxVERTICAL );
    buttons_1->SetMinSize(100, miniaturka_size_y + 1);

	m_wczytaj_1 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( m_wczytaj_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

	m_wybierz_1 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( m_wybierz_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

    m_Radio.push_back(new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP ));
    m_Radio[0]->SetValue(true);
    buttons_1->Add( m_Radio[0], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );

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
    
    m_Radio.push_back(new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttons_2->Add( m_Radio[1], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


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
    
    m_Radio.push_back(new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttons_3->Add( m_Radio[2], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


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
    
    m_Radio.push_back(new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttons_4->Add( m_Radio[3], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


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
    
    m_Radio.push_back(new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 ));
    buttons_5->Add( m_Radio[4], 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 2 );


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
    for(auto Radio : m_Radio)
        Radio->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    
    m_Radio_powiekszenie[0]->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_1_clic ), NULL, this );
    m_Radio_powiekszenie[1]->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_2_clic ), NULL, this );
    m_Radio_powiekszenie[2]->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_3_clic ), NULL, this );
    m_Radio_powiekszenie[3]->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_4_clic ), NULL, this );
    
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
    m_miniaturki->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturek_Repaint ), NULL, this );
    zaktualizuj_powiekszenie();
}

MyFrame::~MyFrame()
{
    for(auto Radio : m_Radio)
        Radio->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    
    m_Radio_powiekszenie[0]->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_1_clic ), NULL, this );
    m_Radio_powiekszenie[1]->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_2_clic ), NULL, this );
    m_Radio_powiekszenie[2]->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_3_clic ), NULL, this );
    m_Radio_powiekszenie[3]->Disconnect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::m_Radio_powiekszenie_4_clic ), NULL, this );
    
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
    m_miniaturki->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturek_Repaint ), NULL, this );
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

void MyFrame::WxPanelMiniaturek_Repaint( wxPaintEvent& event )
{
    Repaint_miniatures();
}

void MyFrame::WxPanel_Repaint( wxPaintEvent& event )
{
    Repaint();
}



void MyFrame::Radio_Button_clic(wxCommandEvent& event)
{
    zaladuj_miniaturke();
    zaktualizuj_powiekszenie();
    Repaint();
}


void MyFrame::m_Radio_powiekszenie_1_clic(wxCommandEvent& event)
{
    na_maksa();
    Repaint();
}

void MyFrame::m_Radio_powiekszenie_2_clic(wxCommandEvent& event)
{
    dopasuj_szerokosc();
    Repaint();
}

void MyFrame::m_Radio_powiekszenie_3_clic(wxCommandEvent& event)
{
    dopasuj_wysokosc();
    Repaint();
}

void MyFrame::m_Radio_powiekszenie_4_clic(wxCommandEvent& event)
{
    zmiesc_na_ekranie();
    Repaint();
}

void MyFrame::dopasuj_szerokosc()
{
    int x, y;
    main_panel->GetSize(&x, &y);
    *m_main_copy = m_main->Copy();
    m_main_copy->Rescale( x, (static_cast<double>(m_main_copy->GetSize().y) / static_cast<double>(m_main_copy->GetSize().x)) * static_cast<double>(x));
    main_panel->SetScrollbars(0, 20, 0 , m_main_copy->GetSize().y / 20.0);
}

void MyFrame::dopasuj_wysokosc()
{
    int x, y;
    main_panel->GetSize(&x, &y);
    *m_main_copy = m_main->Copy();
    m_main_copy->Rescale( (static_cast<double>(m_main_copy->GetSize().x) / static_cast<double>(m_main_copy->GetSize().y)) * static_cast<double>(y) , y);
    main_panel->SetScrollbars(20, 0, m_main_copy->GetSize().x / 20.0 ,0);
}

void MyFrame::zmiesc_na_ekranie()
{
    *m_main_copy = m_main->Copy();
    wxSize skalowanie = skalowanie_do_rozmiaru_z_zachowaniem_proporcji(main_panel->GetSize(), m_main_copy->GetSize());
    m_main_copy->Rescale(skalowanie.x, skalowanie.y);
    main_panel->SetScrollbars(20, 20, m_main_copy->GetSize().x / 20.0 , m_main_copy->GetSize().y / 20.0);
}

void MyFrame::na_maksa()
{
    *m_main_copy = m_main->Copy();
    main_panel->SetScrollbars(20, 20, m_main_copy->GetSize().x / 20.0 , m_main_copy->GetSize().y / 20.0);
}

wxSize MyFrame::skalowanie_do_rozmiaru_z_zachowaniem_proporcji(wxSize rozmiar, wxSize do_skalowania)
{
    if( static_cast<double>(do_skalowania.x) / static_cast<double>(rozmiar.x) > static_cast<double>(do_skalowania.y) / static_cast<double>(rozmiar.y) )
        return wxSize( rozmiar.x, (static_cast<double>(do_skalowania.y) / static_cast<double>(do_skalowania.x)) * static_cast<double>(rozmiar.x) );
    else
        return wxSize( (static_cast<double>(do_skalowania.x) / static_cast<double>(do_skalowania.y)) * static_cast<double>(rozmiar.y) , rozmiar.y );
}

wxPoint MyFrame::wysrodkowanie(wxSize size, int width, int height)
{
    int w = size.x, h = size.y;
    int x{}, y{};
    if(width < w) x = (w - width) / 2.0;
    if(height < h) y = (h - height) / 2.0;
    return wxPoint(x, y);
}


void MyFrame::zaladuj_miniaturke()
{
    for(int i = 0 ; i < 5 ; i++)
        if(m_Radio[i]->GetValue() && m_miniaturka[i]->IsOk())
            *m_main = m_miniaturka[i]->Copy();
}

void MyFrame::zaktualizuj_powiekszenie()
{
    if(m_Radio_powiekszenie[0]->GetValue()) na_maksa();
    if(m_Radio_powiekszenie[1]->GetValue()) dopasuj_szerokosc();
    if(m_Radio_powiekszenie[2]->GetValue()) dopasuj_wysokosc();
    if(m_Radio_powiekszenie[3]->GetValue()) zmiesc_na_ekranie();
}

void MyFrame::Repaint()
{
    wxClientDC dc1(main_panel);
    wxBufferedDC dc(&dc1);
    dc.Clear();
    int x, y;
    main_panel->DoPrepareDC(dc);
    main_panel->GetSize(&x, &y);
    if ( m_main_copy->IsOk() ) {
        dc.DrawBitmap(wxBitmap(*m_main_copy), wysrodkowanie(wxSize(x,y), m_main_copy->GetSize().x, m_main_copy->GetSize().y) );
    }
}

void MyFrame::wczytaj( int which_button )
{
    wxImage new_image;
    wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
    if (WxOpenFileDialog.ShowModal() == wxID_OK){
        new_image.LoadFile(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);
        if(new_image.IsOk()){
            *(m_miniaturka[which_button - 1]) = new_image.Copy();
        }
    }
    if(m_Radio[which_button - 1]->GetValue())
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
    main_panel->GetSize(&x, &y);
    dc.SetBrush(wxBrush(*wxWHITE));
    dc.DrawRectangle(0, 0, miniaturka_size_x + 2, miniaturka_size_y * 5 + 7);
    dc.SetBrush(wxBrush(*wxBLACK));
    dc.DrawLine(0, 1 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 1 * (miniaturka_size_y + 1) + 1);
    dc.DrawLine(0, 2 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 2 * (miniaturka_size_y + 1) + 1);
    dc.DrawLine(0, 3 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 3 * (miniaturka_size_y + 1) + 1);
    dc.DrawLine(0, 4 * (miniaturka_size_y + 1) + 1, miniaturka_size_x , 4 * (miniaturka_size_y + 1) + 1);
    for(int i = 0 ; i < 5 ; i++)
        Repaint_minature(m_miniaturka[i], &dc, wxSize(x, y), i + 1);
}

void MyFrame::Repaint_minature( wxImage* miniaturka, wxClientDC *dc, wxSize main_panel_size, int which_min)
{
    if ( miniaturka->IsOk() )
    {
        wxImage temp = miniaturka->Copy();
        wxSize resize = skalowanie_do_rozmiaru_z_zachowaniem_proporcji(wxSize(miniaturka_size_x, miniaturka_size_y), miniaturka->GetSize());
        temp.Rescale(resize.x, resize.y);
        wxPoint wysr = wysrodkowanie(wxSize(miniaturka_size_x, miniaturka_size_y), resize.x, resize.y);
        dc->DrawBitmap(wxBitmap(temp), 1 + wysr.x, which_min * (miniaturka_size_y + 1) - miniaturka_size_y + 1 + wysr.y);
    }
}

