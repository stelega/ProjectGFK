//
//  main.cpp
//  Projekt
//
//  Created by Michał Wojtasik on 19/05/2019.
//  Copyright © 2019 Michał Wojtasik. All rights reserved.
//

#include"MainFrame.hpp"
#include"MenuFrame.hpp"
// #include"MyFrameFunctionality.h"
#include <wx/wxprec.h>
#include <wx/wx.h>

class App : public wxApp{
    
public:
    virtual bool OnInit();
    virtual int OnExit()
    { return 0; }
    
};

wxIMPLEMENT_APP(App);


bool App::OnInit(){
    MainFrame *frame = new MainFrame(NULL, wxID_ANY, "Okno główne");
    MenuFrame *frame1 = new MenuFrame(NULL, wxID_ANY, "Menu");
    frame->Show(true);
    frame1->Show(true);
    return true;
}
