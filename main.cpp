//
//  main.cpp
//  Projekt
//
//  Created by Michał Wojtasik on 19/05/2019.
//  Copyright © 2019 Michał Wojtasik. All rights reserved.
//

#include "MyFrame.h"
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
    MyFrame *frame = new MyFrame(NULL, wxID_ANY, "Okno główne");
    frame->Show(true);
    return true;
}
