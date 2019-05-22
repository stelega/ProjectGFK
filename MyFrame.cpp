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
	this->SetSizeHints( wxSize(1120 , 670), wxDefaultSize );
    m_miniaturka_1 = new wxImage;
    m_miniaturka_2 = new wxImage;
    m_miniaturka_3 = new wxImage;
    m_miniaturka_4 = new wxImage;
    m_miniaturka_5 = new wxImage;
    m_main = new wxImage;

	wxBoxSizer* main_sizer;
	main_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* left_sizer;
	left_sizer = new wxBoxSizer( wxVERTICAL );

	main_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    main_panel->SetBackgroundColour(*wxWHITE);
	left_sizer->Add( main_panel, 1, wxEXPAND | wxALL, 5);


	main_sizer->Add( left_sizer, 3, wxEXPAND);

	wxBoxSizer* right_sizer;
	right_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* sizer_1;
	sizer_1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_1;
	buttons_1 = new wxBoxSizer( wxVERTICAL );

	m_wczytaj_1 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( m_wczytaj_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_wybierz_1 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( m_wybierz_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

    m_Radio_1 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_1->Add( m_Radio_1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	sizer_1->Add( buttons_1, 0, wxALL);

	m_miniature_1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize(150, 120), wxTAB_TRAVERSAL );
    m_miniature_1->SetBackgroundColour(*wxWHITE);
	sizer_1->Add( m_miniature_1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	right_sizer->Add( sizer_1, 0, wxALL);

	wxBoxSizer* sizer_2;
	sizer_2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_2;
	buttons_2 = new wxBoxSizer( wxVERTICAL );

	m_wczytaj_2 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_2->Add( m_wczytaj_2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_wybierz_2 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_2->Add( m_wybierz_2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    
    m_Radio_2 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_2->Add( m_Radio_2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	sizer_2->Add( buttons_2, 0, wxALL);

	m_miniature_2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize(150, 120), wxTAB_TRAVERSAL );
    m_miniature_2->SetBackgroundColour(*wxWHITE);
	sizer_2->Add( m_miniature_2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	right_sizer->Add( sizer_2, 0, wxALL);

	wxBoxSizer* sizer_3;
	sizer_3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_3;
	buttons_3 = new wxBoxSizer( wxVERTICAL );

	m_wczytaj_3 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_3->Add( m_wczytaj_3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_wybierz_3 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_3->Add( m_wybierz_3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    
    m_Radio_3 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_3->Add( m_Radio_3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	sizer_3->Add( buttons_3, 0, wxALL);

	m_miniature_3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize(150, 120), wxTAB_TRAVERSAL );
    m_miniature_3->SetBackgroundColour(*wxWHITE);
	sizer_3->Add( m_miniature_3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	right_sizer->Add( sizer_3, 0, wxALL);

	wxBoxSizer* sizer_4;
	sizer_4 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_4;
	buttons_4 = new wxBoxSizer( wxVERTICAL );

	m_wczytaj_4 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_4->Add( m_wczytaj_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_wybierz_4 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_4->Add( m_wybierz_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    
    m_Radio_4 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_4->Add( m_Radio_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	sizer_4->Add( buttons_4, 0, wxALL);

	m_miniature_4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize(150, 120), wxTAB_TRAVERSAL );
    m_miniature_4->SetBackgroundColour(*wxWHITE);
	sizer_4->Add( m_miniature_4, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	right_sizer->Add( sizer_4, 0, wxALL);

	wxBoxSizer* sizer_5;
	sizer_5 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_5;
	buttons_5 = new wxBoxSizer( wxVERTICAL );

	m_wczytaj_5 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_5->Add( m_wczytaj_5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_wybierz_5 = new wxButton( this, wxID_ANY, wxT("m_wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_5->Add( m_wybierz_5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
    
    m_Radio_5 = new wxRadioButton(this, wxID_ANY, _("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    buttons_5->Add( m_Radio_5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	sizer_5->Add( buttons_5, 0, wxALL);

	m_miniature_5 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize(150, 120), wxTAB_TRAVERSAL );
    m_miniature_5->SetBackgroundColour(*wxWHITE);
	sizer_5->Add( m_miniature_5, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	right_sizer->Add( sizer_5, 0, wxALL);

	main_sizer->Add( right_sizer, 0, wxALL);


	this->SetSizer( main_sizer );
	this->Layout();
	this->Centre( wxBOTH );
    
    this->SetBackgroundColour(wxColour(150, 150, 150));
    
    m_Radio_1->Connect( wxEVT_RADIOBUTTON, wxCommandEventHandler( MyFrame::Radio_Button_clic ), NULL, this );
    
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
    m_miniature_1->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_2->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_3->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_4->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_5->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
}

MyFrame::~MyFrame()
{
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
    m_miniature_1->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_2->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_3->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_4->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
    m_miniature_5->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanel_Repaint ), NULL, this );
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

void MyFrame::wczytaj( int which_button )
{
    wxImage new_image;
    wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
    if (WxOpenFileDialog.ShowModal() == wxID_OK){
        wxInitAllImageHandlers();
        new_image.LoadFile(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);
        if(new_image.IsOk()){
            if(which_button == 1)
            {
                *m_miniaturka_1 = new_image.Copy();
                Repaint_minature(m_miniature_1);
            }
            if(which_button == 2)
            {
                std::cout << "Dotrało" << std::endl;
                *m_miniaturka_2 = new_image.Copy();
                Repaint_minature(m_miniature_2);
            }
            if(which_button == 3)
            {
                *m_miniaturka_3 = new_image.Copy();
                Repaint_minature(m_miniature_3);
            }
            if(which_button == 4)
            {
                *m_miniaturka_4 = new_image.Copy();
                Repaint_minature(m_miniature_4);
            }
            if(which_button == 5)
            {
                *m_miniaturka_5 = new_image.Copy();
                Repaint_minature(m_miniature_5);
            }
        }
    }
}

void MyFrame::WxPanel_Repaint( wxPaintEvent& event )
{
    Repaint_minature(m_miniature_1);
    Repaint_minature(m_miniature_2);
    Repaint_minature(m_miniature_3);
    Repaint_minature(m_miniature_4);
    Repaint_minature(m_miniature_5);
    Repaint();
}

//void MyFrame::WxPanel_Repaint_1( wxPaintEvent& event ){ Repaint_minature(m_miniature_1); }
//void MyFrame::WxPanel_Repaint_2( wxPaintEvent& event ){ Repaint_minature(m_miniature_2); }
//void MyFrame::WxPanel_Repaint_3( wxPaintEvent& event ){ Repaint_minature(m_miniature_3); }
//void MyFrame::WxPanel_Repaint_4( wxPaintEvent& event ){ Repaint_minature(m_miniature_4); }
//void MyFrame::WxPanel_Repaint_5( wxPaintEvent& event ){ Repaint_minature(m_miniature_5); }

void MyFrame::Repaint_minature( wxPanel* panel)
{
    wxClientDC dc1(panel);
    wxBufferedDC dc(&dc1);
    dc.Clear();
    int x, y;
    panel->GetSize(&x, &y);
    if (m_miniaturka_1->IsOk()) {
        wxImage temp = m_miniaturka_1->Copy();
        temp.Rescale(x, y);
        wxBitmap *bitmap = new wxBitmap(temp);
        dc.DrawBitmap(*bitmap, 0, 0);
    }
    Repaint();
}

void MyFrame::Repaint()
{
    wxClientDC dc1(main_panel);
    wxBufferedDC dc(&dc1);
    dc.Clear();
    int x, y;
    main_panel->GetSize(&x, &y);
    if (m_main->IsOk()) {
        wxImage temp = m_main->Copy();
        temp.Rescale(x, y);
        wxBitmap *bitmap = new wxBitmap(temp);
        dc.DrawBitmap(*bitmap, 0, 0);
    }
}

void MyFrame::Radio_Button_clic(wxCommandEvent& event)
{
    if(m_Radio_1->GetValue() && m_miniaturka_1->IsOk())
         *m_main = m_miniaturka_1->Copy();
    if(m_Radio_2->GetValue() && m_miniaturka_2->IsOk())
        *m_main = m_miniaturka_2->Copy();
    if(m_Radio_3->GetValue() && m_miniaturka_3->IsOk())
        *m_main = m_miniaturka_3->Copy();
    if(m_Radio_4->GetValue() && m_miniaturka_4->IsOk())
        *m_main = m_miniaturka_4->Copy();
    if(m_Radio_5->GetValue() && m_miniaturka_5->IsOk())
        *m_main = m_miniaturka_5->Copy();
    Repaint();
}
