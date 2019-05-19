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
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* main_sizer;
	main_sizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* left_sizer;
	left_sizer = new wxBoxSizer( wxVERTICAL );

	main_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	left_sizer->Add( main_panel, 1, wxEXPAND | wxALL, 5 );


	main_sizer->Add( left_sizer, 3, wxEXPAND, 5 );

	wxBoxSizer* right_sizer;
	right_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* sizer_1;
	sizer_1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_1;
	buttons_1 = new wxBoxSizer( wxVERTICAL );

	wczytaj_1 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( wczytaj_1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wybierz_1 = new wxButton( this, wxID_ANY, wxT("wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_1->Add( wybierz_1, 0, wxALL, 5 );


	sizer_1->Add( buttons_1, 1, wxEXPAND, 5 );

	miniature_1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sizer_1->Add( miniature_1, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	right_sizer->Add( sizer_1, 1, wxEXPAND, 5 );

	wxBoxSizer* sizer_2;
	sizer_2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_2;
	buttons_2 = new wxBoxSizer( wxVERTICAL );

	wczytaj_2 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_2->Add( wczytaj_2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wybierz_2 = new wxButton( this, wxID_ANY, wxT("wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_2->Add( wybierz_2, 0, wxALL, 5 );


	sizer_2->Add( buttons_2, 1, wxEXPAND, 5 );

	miniature_2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sizer_2->Add( miniature_2, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	right_sizer->Add( sizer_2, 1, wxEXPAND, 5 );

	wxBoxSizer* sizer_3;
	sizer_3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_3;
	buttons_3 = new wxBoxSizer( wxVERTICAL );

	wczytaj_3 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_3->Add( wczytaj_3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wybierz_3 = new wxButton( this, wxID_ANY, wxT("wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_3->Add( wybierz_3, 0, wxALL, 5 );


	sizer_3->Add( buttons_3, 1, wxEXPAND, 5 );

	miniature_3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sizer_3->Add( miniature_3, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	right_sizer->Add( sizer_3, 1, wxEXPAND, 5 );

	wxBoxSizer* sizer_4;
	sizer_4 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_4;
	buttons_4 = new wxBoxSizer( wxVERTICAL );

	wczytaj_4 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_4->Add( wczytaj_4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wybierz_4 = new wxButton( this, wxID_ANY, wxT("wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_4->Add( wybierz_4, 0, wxALL, 5 );


	sizer_4->Add( buttons_4, 1, wxEXPAND, 5 );

	miniature_4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sizer_4->Add( miniature_4, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	right_sizer->Add( sizer_4, 1, wxEXPAND, 5 );

	wxBoxSizer* sizer_5;
	sizer_5 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* buttons_5;
	buttons_5 = new wxBoxSizer( wxVERTICAL );

	wczytaj_5 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_5->Add( wczytaj_5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wybierz_5 = new wxButton( this, wxID_ANY, wxT("wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	buttons_5->Add( wybierz_5, 0, wxALL, 5 );


	sizer_5->Add( buttons_5, 1, wxEXPAND, 5 );

	miniature_5 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	sizer_5->Add( miniature_5, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	right_sizer->Add( sizer_5, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* miniature_sizer;
	miniature_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	wybierz_main = new wxButton( this, wxID_ANY, wxT("wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( wybierz_main, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	main_miniature = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer15->Add( main_miniature, 2, wxEXPAND|wxALL|wxALIGN_RIGHT, 5 );


	miniature_sizer->Add( bSizer15, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	right_sizer->Add( miniature_sizer, 1, wxEXPAND, 5 );


	main_sizer->Add( right_sizer, 1, wxEXPAND, 5 );


	this->SetSizer( main_sizer );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame::~MyFrame()
{
}
