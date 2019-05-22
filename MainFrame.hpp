//
//  MainFrame.hpp
//  Projekt
//
//  Created by Michał Wojtasik on 22/05/2019.
//  Copyright © 2019 Michał Wojtasik. All rights reserved.
//

#ifndef MainFrame_hpp
#define MainFrame_hpp

#include <stdio.h>

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
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
private:
    wxColour m_background_color;
    wxImage *m_main;
    wxPanel* main_panel;
    // RYSOWANIE
    void Repaint();
    void WxPanel_Repaint( wxPaintEvent& event );
public:
    
    MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1120, 750 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    
    ~MainFrame();
    
};



#endif /* MainFrame_hpp */
