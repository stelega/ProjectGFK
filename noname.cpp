///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

GeneratedFrame::GeneratedFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxSize( 1530,642 ), wxDefaultSize );
    
    wxBoxSizer* mainSizer;
    mainSizer = new wxBoxSizer( wxHORIZONTAL );
    
    wxBoxSizer* imageSizer;
    imageSizer = new wxBoxSizer( wxVERTICAL );
    
    imageSizer->SetMinSize( wxSize( 1000,800 ) );
    imageWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    imageWindow->SetScrollRate( 5, 5 );
    imageWindow->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
    imageWindow->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
    
    imageSizer->Add( imageWindow, 1, wxEXPAND | wxALL, 5 );
    
    
    mainSizer->Add( imageSizer, 1, wxEXPAND, 5 );
    
    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );
    
    bSizer15->SetMinSize( wxSize( 152,607 ) );
    m_miniaturki = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    m_miniaturki->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Arial") ) );
    m_miniaturki->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
    m_miniaturki->SetMinSize( wxSize( 152,607 ) );
    m_miniaturki->SetMaxSize( wxSize( 1000,1000 ) );
    
    bSizer15->Add( m_miniaturki, 1, wxEXPAND | wxALL, 5 );
    
    
    mainSizer->Add( bSizer15, 1, wxEXPAND, 5 );
    
    wxBoxSizer* buttonSizer;
    buttonSizer = new wxBoxSizer( wxVERTICAL );
    
    buttonSizer->SetMinSize( wxSize( 100,607 ) );
    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer( wxHORIZONTAL );
    
    bSizer5->SetMinSize( wxSize( -1,1 ) );
    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer( wxVERTICAL );
    
    bSizer14->SetMinSize( wxSize( -1,124 ) );
    m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Miniaturka 1"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText1->Wrap( -1 );
    m_staticText1->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Arial") ) );
    
    bSizer14->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
    
    load_min1 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer14->Add( load_min1, 0, wxALIGN_CENTER|wxALL, 5 );
    
    background_min1 = new wxRadioButton( this, wxID_ANY, wxT("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer14->Add( background_min1, 0, wxALIGN_CENTER|wxALL, 5 );
    
    
    bSizer5->Add( bSizer14, 1, wxFIXED_MINSIZE, 5 );
    
    
    buttonSizer->Add( bSizer5, 0, wxFIXED_MINSIZE, 5 );
    
    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxHORIZONTAL );
    
    wxBoxSizer* bSizer141;
    bSizer141 = new wxBoxSizer( wxVERTICAL );
    
    bSizer141->SetMinSize( wxSize( -1,124 ) );
    m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Miniaturka 2"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText11->Wrap( -1 );
    m_staticText11->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Arial") ) );
    
    bSizer141->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );
    
    load_min2 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer141->Add( load_min2, 0, wxALIGN_CENTER|wxALL, 5 );
    
    background_min2 = new wxRadioButton( this, wxID_ANY, wxT("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer141->Add( background_min2, 0, wxALIGN_CENTER|wxALL, 5 );
    
    
    bSizer6->Add( bSizer141, 1, wxFIXED_MINSIZE, 5 );
    
    
    buttonSizer->Add( bSizer6, 0, wxFIXED_MINSIZE, 5 );
    
    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer( wxHORIZONTAL );
    
    bSizer7->SetMinSize( wxSize( -1,1 ) );
    wxBoxSizer* bSizer142;
    bSizer142 = new wxBoxSizer( wxVERTICAL );
    
    bSizer142->SetMinSize( wxSize( -1,124 ) );
    m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Miniaturka 3"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText12->Wrap( -1 );
    m_staticText12->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Arial") ) );
    
    bSizer142->Add( m_staticText12, 0, wxALIGN_CENTER|wxALL, 5 );
    
    load_min3 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer142->Add( load_min3, 0, wxALIGN_CENTER|wxALL, 5 );
    
    background_min3 = new wxRadioButton( this, wxID_ANY, wxT("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer142->Add( background_min3, 0, wxALIGN_CENTER|wxALL, 5 );
    
    
    bSizer7->Add( bSizer142, 0, wxFIXED_MINSIZE, 5 );
    
    
    buttonSizer->Add( bSizer7, 0, wxFIXED_MINSIZE, 5 );
    
    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer( wxHORIZONTAL );
    
    wxBoxSizer* bSizer143;
    bSizer143 = new wxBoxSizer( wxVERTICAL );
    
    bSizer143->SetMinSize( wxSize( -1,124 ) );
    m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Miniaturka 4"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText13->Wrap( -1 );
    m_staticText13->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Arial") ) );
    
    bSizer143->Add( m_staticText13, 0, wxALIGN_CENTER|wxALL, 5 );
    
    load_min4 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer143->Add( load_min4, 0, wxALIGN_CENTER|wxALL, 5 );
    
    background_min4 = new wxRadioButton( this, wxID_ANY, wxT("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer143->Add( background_min4, 0, wxALIGN_CENTER|wxALL, 5 );
    
    
    bSizer8->Add( bSizer143, 1, wxFIXED_MINSIZE, 5 );
    
    
    buttonSizer->Add( bSizer8, 0, wxFIXED_MINSIZE, 5 );
    
    wxBoxSizer* bSizer9;
    bSizer9 = new wxBoxSizer( wxHORIZONTAL );
    
    wxBoxSizer* bSizer144;
    bSizer144 = new wxBoxSizer( wxVERTICAL );
    
    m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Miniaturka 5"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText14->Wrap( -1 );
    m_staticText14->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Arial") ) );
    
    bSizer144->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );
    
    load_min5 = new wxButton( this, wxID_ANY, wxT("wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer144->Add( load_min5, 0, wxALIGN_CENTER|wxALL, 5 );
    
    background_min5 = new wxRadioButton( this, wxID_ANY, wxT("Jako tło"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer144->Add( background_min5, 0, wxALIGN_CENTER|wxALL, 5 );
    
    
    bSizer9->Add( bSizer144, 0, wxFIXED_MINSIZE, 5 );
    
    
    buttonSizer->Add( bSizer9, 1, wxFIXED_MINSIZE, 5 );
    
    
    mainSizer->Add( buttonSizer, 0, wxFIXED_MINSIZE, 5 );
    
    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer( wxVERTICAL );
    
    bSizer4->SetMinSize( wxSize( 150,800 ) );
    wxString adjust_boxChoices[] = { wxT("100%"), wxT("Dopasuj szerokość"), wxT("Dopasuj wysokość"), wxT("Zmieść na ekranie") };
    int adjust_boxNChoices = sizeof( adjust_boxChoices ) / sizeof( wxString );
    adjust_box = new wxRadioBox( this, wxID_ANY, wxT("Dostosuj powiększenie"), wxDefaultPosition, wxDefaultSize, adjust_boxNChoices, adjust_boxChoices, 1, wxRA_SPECIFY_COLS );
    adjust_box->SetSelection( 0 );
    bSizer4->Add( adjust_box, 0, wxALIGN_CENTER|wxALL, 5 );
    
    wxString chooseShapeBoxChoices[] = { wxT("Krzywa łamana"), wxT("Dowolna krzywa"), wxT("Kwadrat") };
    int chooseShapeBoxNChoices = sizeof( chooseShapeBoxChoices ) / sizeof( wxString );
    chooseShapeBox = new wxRadioBox( this, wxID_ANY, wxT("Wybierz krzywą"), wxDefaultPosition, wxDefaultSize, chooseShapeBoxNChoices, chooseShapeBoxChoices, 1, wxRA_SPECIFY_COLS );
    chooseShapeBox->SetSelection( 0 );
    bSizer4->Add( chooseShapeBox, 0, wxALIGN_CENTER|wxALL, 5 );
    
    startCutButton = new wxButton( this, wxID_ANY, wxT("Zacznij wycinać"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer4->Add( startCutButton, 0, wxALIGN_CENTER|wxALL, 5 );
    
    wxStaticBoxSizer* sbSizer1;
    sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Wycinanie") ), wxVERTICAL );
    
    sbSizer1->SetMinSize( wxSize( 100,100 ) );
    wxString m_choice1Choices[] = { wxT("Zdjęcie 1"), wxT("Zdjęcie 2"), wxT("Zdjęcie 3"), wxT("Zdjęcie 4"), wxT("Zdjęcie 5") };
    int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
    m_choice1 = new wxChoice( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
    m_choice1->SetSelection( 0 );
    sbSizer1->Add( m_choice1, 0, wxALIGN_CENTER|wxALL, 5 );
    
    
    bSizer4->Add( sbSizer1, 0, wxALIGN_CENTER, 5 );
    
    endCutButton = new wxButton( this, wxID_ANY, wxT("Zakończ wycinać"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer4->Add( endCutButton, 0, wxALIGN_CENTER|wxALL, 5 );
    
    
    mainSizer->Add( bSizer4, 1, wxEXPAND, 5 );
    
    
    this->SetSizer( mainSizer );
    this->Layout();
    
    this->Centre( wxBOTH );
    
    // Connect Events
    load_min1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage1 ), NULL, this );
    background_min1->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw1 ), NULL, this );
    load_min2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage2 ), NULL, this );
    background_min2->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw2 ), NULL, this );
    load_min3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage3 ), NULL, this );
    background_min3->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw3 ), NULL, this );
    load_min4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage4 ), NULL, this );
    background_min4->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw4 ), NULL, this );
    load_min5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage5 ), NULL, this );
    background_min5->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw5 ), NULL, this );
    adjust_box->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GeneratedFrame::adjustEvent ), NULL, this );
}

GeneratedFrame::~GeneratedFrame()
{
    // Disconnect Events
    load_min1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage1 ), NULL, this );
    background_min1->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw1 ), NULL, this );
    load_min2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage2 ), NULL, this );
    background_min2->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw2 ), NULL, this );
    load_min3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage3 ), NULL, this );
    background_min3->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw3 ), NULL, this );
    load_min4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage4 ), NULL, this );
    background_min4->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw4 ), NULL, this );
    load_min5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GeneratedFrame::loadImage5 ), NULL, this );
    background_min5->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( GeneratedFrame::backgroundDraw5 ), NULL, this );
    adjust_box->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GeneratedFrame::adjustEvent ), NULL, this );
    
}
