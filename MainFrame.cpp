//
//  MainFrame.cpp
//  Projekt
//
//  Created by Michał Wojtasik on 22/05/2019.
//  Copyright © 2019 Michał Wojtasik. All rights reserved.
//

#include "MainFrame.hpp"

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxSize(0 , 0), wxDefaultSize );
    m_main = new wxImage;
    m_background_color = wxColour(150,150,150);
    
    wxBoxSizer* main_sizer;
    main_sizer = new wxBoxSizer( wxVERTICAL );
    
    main_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    main_panel->SetBackgroundColour(*wxWHITE);
    main_sizer->Add( main_panel, 1, wxEXPAND | wxALL, 0);
    
    this->SetSizer( main_sizer );
    this->Layout();
    this->Centre( wxBOTH );
    
    main_panel->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::WxPanel_Repaint ), NULL, this );
}

MainFrame::~MainFrame()
{
    main_panel->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::WxPanel_Repaint ), NULL, this );
}


void MainFrame::WxPanel_Repaint( wxPaintEvent& event )
{
    Repaint();
}


void MainFrame::Repaint()
{
    
}

