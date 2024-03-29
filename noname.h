///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/scrolwin.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/radiobox.h>
#include <wx/choice.h>
#include <wx/statbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GeneratedFrame
///////////////////////////////////////////////////////////////////////////////
class GeneratedFrame : public wxFrame 
{
	private:
	
	protected:
		wxScrolledWindow* imageWindow;
		wxPanel* m_miniaturki;
		wxStaticText* m_staticText1;
		wxButton* load_min1;
		wxRadioButton* background_min1;
		wxStaticText* m_staticText11;
		wxButton* load_min2;
		wxRadioButton* background_min2;
		wxStaticText* m_staticText12;
		wxButton* load_min3;
		wxRadioButton* background_min3;
		wxStaticText* m_staticText13;
		wxButton* load_min4;
		wxRadioButton* background_min4;
		wxStaticText* m_staticText14;
		wxButton* load_min5;
		wxRadioButton* background_min5;
		wxRadioBox* adjust_box;
		wxRadioBox* chooseShapeBox;
		wxButton* startCutButton;
		wxChoice* m_choice1;
		wxButton* endCutButton;
		wxButton* saveToFileButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void loadImage1( wxCommandEvent& event ) { event.Skip(); }
		virtual void backgroundDraw1( wxCommandEvent& event ) { event.Skip(); }
		virtual void loadImage2( wxCommandEvent& event ) { event.Skip(); }
		virtual void backgroundDraw2( wxCommandEvent& event ) { event.Skip(); }
		virtual void loadImage3( wxCommandEvent& event ) { event.Skip(); }
		virtual void backgroundDraw3( wxCommandEvent& event ) { event.Skip(); }
		virtual void loadImage4( wxCommandEvent& event ) { event.Skip(); }
		virtual void backgroundDraw4( wxCommandEvent& event ) { event.Skip(); }
		virtual void loadImage5( wxCommandEvent& event ) { event.Skip(); }
		virtual void backgroundDraw5( wxCommandEvent& event ) { event.Skip(); }
		virtual void adjustEvent( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GeneratedFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1530,643 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GeneratedFrame();
	
};

#endif //__NONAME_H__
