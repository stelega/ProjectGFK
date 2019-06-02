#include "MyFrame.h"

MyFrame::MyFrame(wxWindow * parent) : GeneratedFrame(parent, wxID_ANY, "Okno g≥Ûwne") {
    // Tworzenie miejsca na oryginaly wszystkich zdjec
    which_min = 0;
    m_helpfull = 0;
    m_scaleX = 1;
    m_scaleY = 1;
    for (int i = 0; i < 5; i++) {
        m_miniaturka.push_back(new wxImage);
    }
    
    // kolor tła
    m_backgroundColor = wxColour(150,150,150);
    
    m_main = new wxImage;
    m_ImageToPrint = new wxImage;
    m_noSelectedPhoto = new wxImage;
    m_BackgroundImage = new wxImage;
    m_choice1->Disable();
    
    background_min1->SetValue(true);
    adjust_box->SetSelection(3);
    
    imageWindow->wxWindowBase::SetBackgroundColour(m_backgroundColor);
    m_miniaturki->wxWindowBase::SetBackgroundColour(m_backgroundColor);
    this->wxWindowBase::SetBackgroundColour(m_backgroundColor);
    
    // Za≥adowanie obrazka z napisem No photo selected oraz ustawienie wszystkich miniaturek
    wxInitAllImageHandlers();
    wxLogNull logNo;
    m_noSelectedPhoto->LoadFile("/Users/michalwojtasik/Desktop/default.png");
    if (m_noSelectedPhoto->IsOk())
    {
        for (auto miniaturka : m_miniaturka) {
            *miniaturka = m_noSelectedPhoto->Copy();
        }
        
        *m_main = m_noSelectedPhoto->Copy();
        *m_ImageToPrint = m_noSelectedPhoto->Copy();
        *m_BackgroundImage = m_noSelectedPhoto->Copy();
    }
    
    m_Radio.push_back(background_min1);
    m_Radio.push_back(background_min2);
    m_Radio.push_back(background_min3);
    m_Radio.push_back(background_min4);
    m_Radio.push_back(background_min5);
    
    m_kwadraty.push_back(m_kwadrat1);
    m_kwadraty.push_back(m_kwadrat2);
    m_kwadraty.push_back(m_kwadrat3);
    m_kwadraty.push_back(m_kwadrat4);
    m_kwadraty.push_back(m_kwadrat5);
    
    m_kwadratyCopy.push_back(m_kwadrat1Copy);
    m_kwadratyCopy.push_back(m_kwadrat2Copy);
    m_kwadratyCopy.push_back(m_kwadrat3Copy);
    m_kwadratyCopy.push_back(m_kwadrat4Copy);
    m_kwadratyCopy.push_back(m_kwadrat5Copy);
    
    
    
    m_choice1->Connect( wxEVT_CHOICE, wxCommandEventHandler( MyFrame::choiceButtonClic ), NULL, this );
    
    imageWindow->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame::mouseLeftDown ), NULL, this );
    imageWindow->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame::mouseMove ), NULL, this );
    imageWindow->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelRepaint ), NULL, this );
    m_miniaturki->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturekRepaint ), NULL, this );
    
    startCutButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::startCutButtonClic ), NULL, this );
    endCutButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::endCutButtonClic ), NULL, this );
    
    m_startSize = std::vector<wxSize> (5, wxSize(0,0));
    m_actualSize = std::vector<wxSize> (5, wxSize(0,0));
    m_startCenter = std::vector<wxPoint> (5, wxPoint(0,0));
    m_actualCenter = std::vector<wxPoint> (5, wxPoint(0,0));
    if(m_noSelectedPhoto->IsOk())
    {
        for(auto seg : m_startSize)
            seg = scaleWithProportion(imageWindow->GetSize(), m_noSelectedPhoto->GetSize());
        for(auto seg : m_startCenter)
            seg = centering(imageWindow->GetSize(), m_noSelectedPhoto->GetSize().x, m_noSelectedPhoto->GetSize().y);
    }
    m_actualSize = m_startSize;
    m_actualCenter = m_startCenter;
    
    updateMain();
}


MyFrame::~MyFrame()
{
    imageWindow->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame::mouseLeftDown ), NULL, this );
    imageWindow->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MyFrame::mouseMove ), NULL, this );
    imageWindow->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelRepaint ), NULL, this );
    m_miniaturki->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturekRepaint ), NULL, this );
    
    startCutButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::startCutButtonClic ), NULL, this );
    endCutButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::endCutButtonClic ), NULL, this );
}


void MyFrame::WxPanelMiniaturekRepaint(wxPaintEvent& event)
{
    repaintMiniatures();
}

void MyFrame::WxPanelRepaint(wxPaintEvent& event)
{
    repaint();
}


void MyFrame::choiceButtonClic(wxCommandEvent& event)
{
    updateMain();
    repaint();
}

void MyFrame::startCutButtonClic(wxCommandEvent& event)
{
    m_choice1->Enable();
    updateMain();
    repaint();
}

void MyFrame::endCutButtonClic(wxCommandEvent& event)
{
    m_choice1->Disable();
    updateMain();
    repaint();
}

void MyFrame::loadImage1(wxCommandEvent& event) {
    load(1);
}
void MyFrame::loadImage2(wxCommandEvent& event) {
    load(2);
}
void MyFrame::loadImage3(wxCommandEvent& event) {
    load(3);
}
void MyFrame::loadImage4(wxCommandEvent& event) {
    load(4);
}
void MyFrame::loadImage5(wxCommandEvent& event) {
    load(5);
}



void MyFrame::backgroundDraw1(wxCommandEvent& event) {
    which_min = 0;
    chooseBackground();
}
void MyFrame::backgroundDraw2(wxCommandEvent& event) {
    which_min = 1;
    chooseBackground();
}
void MyFrame::backgroundDraw3(wxCommandEvent& event) {
    which_min = 2;
    chooseBackground();
}
void MyFrame::backgroundDraw4(wxCommandEvent& event) {
    which_min = 3;
    chooseBackground();
}
void MyFrame::backgroundDraw5(wxCommandEvent& event) {
    which_min = 4;
    chooseBackground();
}



void MyFrame::adjustEvent(wxCommandEvent& event) {
    updateMain();
}


void MyFrame::mouseMove(wxMouseEvent& event)
{
    int shape_selection = chooseShapeBox->GetSelection();
    int miniature_selection = m_choice1->GetSelection();
    //sprawdzamy, czy aktualnie mysz byla kliknieta nieparzystą ilośc razy
    if(m_helpfull % 2 == 1)
    {
        int square_count = (int)m_kwadraty[miniature_selection].size();
        if(shape_selection == 2)
        {
            int shiftX = m_actualCenter[m_choice1->GetSelection()].x;
            int shiftY = m_actualCenter[m_choice1->GetSelection()].y;
            *m_kwadraty[miniature_selection][square_count - 3] = imageWindow->CalcUnscrolledPosition(wxPoint(m_kwadraty[miniature_selection][square_count - 4]->x, event.GetY() - shiftY));
            *m_kwadraty[miniature_selection][square_count - 2] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, event.GetY() - shiftY));
            *m_kwadraty[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, m_kwadraty[miniature_selection][square_count - 4]->y));
            m_kwadratyCopy[miniature_selection][square_count - 3] = imageWindow->CalcUnscrolledPosition(wxPoint(m_kwadraty[miniature_selection][square_count - 4]->x, event.GetY() - shiftY));
            m_kwadratyCopy[miniature_selection][square_count - 2] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, event.GetY() - shiftY));
            m_kwadratyCopy[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, m_kwadraty[miniature_selection][square_count - 4]->y));
        }
        repaint();
    }
    
}

void MyFrame::mouseLeftDown(wxMouseEvent& event)
{
    int shape_selection = chooseShapeBox->GetSelection();
    int miniature_selection = m_choice1->GetSelection();
    if(m_choice1->IsEnabled() == false) return;
    // Jezeli chcemy narysowac kwadrat
    if(shape_selection == 2)
    {
        m_helpfull++;
        //sprawdzamy, czy aktualnie mysz byla kliknieta parzystą, czy nieparzystą ilośc razy
        int square_count = (int)m_kwadraty[miniature_selection].size();
        //std::cout << square_count << std::endl;
        if(m_helpfull % 2 == 1)
        {
            for(int i = 0 ; i < 4 ; i++)
            {
                m_kwadraty[miniature_selection].push_back(new wxPoint(event.GetX() - m_actualCenter[m_choice1->GetSelection()].x, event.GetY() - m_actualCenter[m_choice1->GetSelection()].y ));
                m_kwadratyCopy[miniature_selection].push_back(wxPoint(event.GetX() - m_actualCenter[m_choice1->GetSelection()].x, event.GetY()  - m_actualCenter[m_choice1->GetSelection()].y));
                *m_kwadraty[miniature_selection][square_count + i] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - m_actualCenter[m_choice1->GetSelection()].x, event.GetY() - m_actualCenter[m_choice1->GetSelection()].y ));
                m_kwadratyCopy[miniature_selection][square_count + i] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - m_actualCenter[m_choice1->GetSelection()].x, event.GetY() - m_actualCenter[m_choice1->GetSelection()].y ));
            }
        }
        else
        {
            int shiftX = m_actualCenter[m_choice1->GetSelection()].x;
            int shiftY = m_actualCenter[m_choice1->GetSelection()].y;
            *m_kwadraty[miniature_selection][square_count - 3] = imageWindow->CalcUnscrolledPosition(wxPoint(m_kwadraty[miniature_selection][square_count - 4]->x, event.GetY() - shiftY));
            *m_kwadraty[miniature_selection][square_count - 2] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, event.GetY() - shiftY));
            *m_kwadraty[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, m_kwadraty[miniature_selection][square_count - 4]->y));
            m_kwadratyCopy[miniature_selection][square_count - 3] = imageWindow->CalcUnscrolledPosition(wxPoint(m_kwadraty[miniature_selection][square_count - 4]->x, event.GetY() - shiftY));
            m_kwadratyCopy[miniature_selection][square_count - 2] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, event.GetY() - shiftY));
            m_kwadratyCopy[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX() - shiftX, m_kwadraty[miniature_selection][square_count - 4]->y));
        }
    }

    repaint();
}

void MyFrame::transformRectangleVector()
{
    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j < m_kwadratyCopy[i].size() ; j++)
        {
            m_kwadratyCopy[i][j] = wxPoint((m_kwadraty[i][j]->x - m_actualCenter[m_choice1->GetSelection()].x) * m_scaleX + m_actualCenter[m_choice1->GetSelection()].x, (m_kwadraty[i][j]->y - m_actualCenter[m_choice1->GetSelection()].y) * m_scaleY  + m_actualCenter[m_choice1->GetSelection()].y);
        }
    }
}

void MyFrame::uzupelnij_bitmape()
{
    // dla wycietych kwadratow
    wxSize imageSize = m_ImageToPrint->GetSize();
    
    unsigned char *backgroundPixels = m_ImageToPrint->GetData();
    unsigned char *new_data = new unsigned char[3 * imageSize.x * imageSize.y];
    
    for(int x = 0 ; x < imageSize.x ; x++)
    {
        for(int y = 0 ; y < imageSize.y ; y++)
        {
            new_data[3 * (imageSize.x * y + x) + 0] = backgroundPixels[3 * (imageSize.x * y + x) + 0];
            new_data[3 * (imageSize.x * y + x) + 1] = backgroundPixels[3 * (imageSize.x * y + x) + 1];
            new_data[3 * (imageSize.x * y + x) + 2] = backgroundPixels[3 * (imageSize.x * y + x) + 2];
        }
    }
    
    
    for(int i = 0 ; i < 5 ; i++)
    {
        int countRect = static_cast<int>(m_kwadraty[i].size()) / 4;
        wxImage temp = m_miniaturka[i]->Copy();
        updateSizeOfPhoto(temp);
        unsigned char *pixels = temp.GetData();
        for(int j = 0 ; j < countRect ; j++)
        {
            int x1 = m_kwadraty[i][j * 4]->x < m_kwadraty[i][j * 4 + 2]->x ? m_kwadraty[i][j * 4]->x : m_kwadraty[i][j * 4 + 2]->x;
            int x2 = m_kwadraty[i][j * 4]->x < m_kwadraty[i][j * 4 + 2]->x ? m_kwadraty[i][j * 4 + 2]->x : m_kwadraty[i][j * 4]->x;
            int y1 = m_kwadraty[i][j * 4]->y < m_kwadraty[i][j * 4 + 2]->y ? m_kwadraty[i][j * 4]->y : m_kwadraty[i][j * 4 + 2]->y;
            int y2 = m_kwadraty[i][j * 4]->y < m_kwadraty[i][j * 4 + 2]->y ? m_kwadraty[i][j * 4 + 2]->y : m_kwadraty[i][j * 4]->y;
            for(int x = 0 ; x < imageSize.x ; x++)
            {
                for(int y = 0 ; y < imageSize.y ; y++)
                {
                    if( x1 < x && x < x2 && y1 < y && y < y2  )
                    {
                        new_data[3 * (imageSize.x * y + x) + 0] = pixels[3 * (imageSize.x * y + x) + 0];
                        new_data[3 * (imageSize.x * y + x) + 1] = pixels[3 * (imageSize.x * y + x) + 1];
                        new_data[3 * (imageSize.x * y + x) + 2] = pixels[3 * (imageSize.x * y + x) + 2];
                    }
                }
            }
        }
    }
    
    m_ImageToPrint->SetData(new_data);
}

void MyFrame::drawRectangle(wxDC& dc)
{
    dc.SetBrush(wxBrush(*wxRED));
    int shiftX = m_actualCenter[m_choice1->GetSelection()].x;
    int shiftY = m_actualCenter[m_choice1->GetSelection()].y;
    int miniature_selection = m_choice1->GetSelection();
    int rect_count = m_kwadraty[miniature_selection].size() / 4.0;
    wxPoint point1, point2, point3, point4;
    for(int i = 0 ; i < rect_count ; i++)
    {
        point1 = wxPoint(m_kwadratyCopy[miniature_selection][0 + (i * 4)].x + shiftX, m_kwadratyCopy[miniature_selection][0 + (i * 4)].y + shiftY);
        point2 = wxPoint(m_kwadratyCopy[miniature_selection][1 + (i * 4)].x + shiftX, m_kwadratyCopy[miniature_selection][1 + (i * 4)].y + shiftY);
        point3 = wxPoint(m_kwadratyCopy[miniature_selection][2 + (i * 4)].x + shiftX, m_kwadratyCopy[miniature_selection][2 + (i * 4)].y + shiftY);
        point4 = wxPoint(m_kwadratyCopy[miniature_selection][3 + (i * 4)].x + shiftX, m_kwadratyCopy[miniature_selection][3 + (i * 4)].y + shiftY);
        
        dc.DrawLine(point1, point2);
        dc.DrawLine(point1, point4);
        dc.DrawLine(point2, point3);
        dc.DrawLine(point3, point4);
    }
}

//void MyFrame::drawBrokenCurve(){}
//void MyFrame::drawBrokenCurve_gladka(){}

void MyFrame::chooseBackground(){
    loadMinature();
    updateMain();
    repaint();
}


void MyFrame::fitWidth(wxImage &image)
{
    int x, y;
    imageWindow->GetSize(&x, &y);
    image.Rescale(x, (static_cast<double>(m_ImageToPrint->GetSize().y) / static_cast<double>(m_ImageToPrint->GetSize().x)) * static_cast<double>(x));
    imageWindow->SetScrollbars(0, 20, 0, m_ImageToPrint->GetSize().y / 20.0);
}

void MyFrame::fitHeight(wxImage &image)
{
    int x, y;
    imageWindow->GetSize(&x, &y);
    image.Rescale((static_cast<double>(m_ImageToPrint->GetSize().x) / static_cast<double>(m_ImageToPrint->GetSize().y)) * static_cast<double>(y), y);
    imageWindow->SetScrollbars(20, 0, m_ImageToPrint->GetSize().x / 20.0, 0);
}

void MyFrame::fitOnScreen(wxImage &image)
{
    wxSize size = scaleWithProportion(imageWindow->GetSize(), m_ImageToPrint->GetSize());
    image.Rescale(size.x, size.y);
    imageWindow->SetScrollbars(20, 20, m_ImageToPrint->GetSize().x / 20.0, m_ImageToPrint->GetSize().y / 20.0);
}

void MyFrame::fullSize(wxImage &image)
{
    imageWindow->SetScrollbars(20, 20, m_ImageToPrint->GetSize().x / 20.0, m_ImageToPrint->GetSize().y / 20.0);
}

wxSize MyFrame::scaleWithProportion(wxSize rozmiar, wxSize do_skalowania)
{
    if (static_cast<double>(do_skalowania.x) / static_cast<double>(rozmiar.x) > static_cast<double>(do_skalowania.y) / static_cast<double>(rozmiar.y))
        return wxSize(rozmiar.x, (static_cast<double>(do_skalowania.y) / static_cast<double>(do_skalowania.x)) * static_cast<double>(rozmiar.x));
    else
        return wxSize((static_cast<double>(do_skalowania.x) / static_cast<double>(do_skalowania.y)) * static_cast<double>(rozmiar.y), rozmiar.y);
}

wxPoint MyFrame::centering(wxSize size, int width, int height)
{
    int w = size.x, h = size.y;
    int x{}, y{};
    if (width < w) x = (w - width) / 2.0;
    if (height < h) y = (h - height) / 2.0;
    return wxPoint(x, y);
}


void MyFrame::loadMinature()
{
    for (int i = 0; i < 5; i++)
        if (m_Radio[i]->GetValue() && m_miniaturka[i]->IsOk())
            *m_BackgroundImage = m_miniaturka[i]->Copy();
}

void MyFrame::updateMain()
{
    if(m_choice1->IsEnabled() && m_miniaturka[m_choice1->GetSelection()]->IsOk())
        *m_ImageToPrint = m_miniaturka[m_choice1->GetSelection()]->Copy();
    else
    {
        if(m_BackgroundImage->IsOk())
            *m_ImageToPrint = m_BackgroundImage->Copy();
    }
    
    updateSizeOfPhoto(*m_ImageToPrint);
    updateActualSizeAndCenter();
    
    if(m_choice1->IsEnabled())
    {
        updateSizeOfPhoto(*m_ImageToPrint);
        updateActualSizeAndCenter();
        m_scaleX = m_actualSize[m_choice1->GetSelection()].x / static_cast<double>(m_startSize[m_choice1->GetSelection()].x);
        m_scaleY = m_actualSize[m_choice1->GetSelection()].y / static_cast<double>(m_startSize[m_choice1->GetSelection()].y);
    }
    else
    {
        m_scaleX = m_actualSize[which_min].x / static_cast<double>(m_startSize[which_min].x);
        m_scaleY = m_actualSize[which_min].y / static_cast<double>(m_startSize[which_min].y);
        uzupelnij_bitmape();
    }
    
    transformRectangleVector();
    repaint();
}

void MyFrame::updateActualSizeAndCenter()
{
    if(m_choice1->IsEnabled())
    {
        if(m_ImageToPrint->IsOk())
            m_actualSize[m_choice1->GetSelection()] = m_ImageToPrint->GetSize();
        m_actualCenter[m_choice1->GetSelection()] = centering(imageWindow->GetSize(), m_actualSize[m_choice1->GetSelection()].x, m_actualSize[m_choice1->GetSelection()].y);
    }
    else
    {
        if(m_ImageToPrint->IsOk())
            m_actualSize[which_min] = m_ImageToPrint->GetSize();
        m_actualCenter[which_min] = centering(imageWindow->GetSize(), m_actualSize[which_min].x, m_actualSize[which_min].y);
    }
}

void MyFrame::updateSizeOfPhoto(wxImage &image)
{
    int selection = adjust_box->GetSelection();
    if(selection == 0)
        fullSize(image);
    if(selection == 1)
        fitWidth(image);
    if(selection == 2)
        fitHeight(image);
    if(selection == 3)
        fitOnScreen(image);
}

void MyFrame::repaint()
{
    wxClientDC dc(imageWindow);
    //wxBufferedDC dc(&dc1);
    dc.Clear();
    imageWindow->DoPrepareDC(dc);
    int x, y;
    imageWindow->GetSize(&x, &y);
    if (m_ImageToPrint->IsOk())
    {
        if(m_choice1->IsEnabled())
            dc.DrawBitmap(wxBitmap(*m_ImageToPrint), m_actualCenter[m_choice1->GetSelection()]);
        else
            dc.DrawBitmap(wxBitmap(*m_ImageToPrint), m_actualCenter[which_min]);
    }
    
    int selection = chooseShapeBox->GetSelection();
    if(selection == 2 && m_choice1->IsEnabled())
    {
        drawRectangle(dc);
    }
}

void MyFrame::load(int which_button)
{
    wxImage new_image;
    wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
    if (WxOpenFileDialog.ShowModal() == wxID_OK) {
        new_image.LoadFile(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);
        if (new_image.IsOk()) {
            *(m_miniaturka[which_button - 1]) = new_image.Copy();
            m_startSize[which_button - 1] = scaleWithProportion(imageWindow->GetSize(), new_image.GetSize());
            m_startCenter[which_button - 1] = centering(imageWindow->GetSize(), m_startSize[which_button - 1].x, m_startSize[which_button - 1].y);
        }
    }
    if (m_Radio[which_button - 1]->GetValue() || m_choice1->IsEnabled())
    {
        loadMinature();
        updateMain();
    }
    repaintMiniatures();
    repaint();
}

void MyFrame::repaintMiniatures()
{
    wxClientDC dc(m_miniaturki);
    dc.Clear();
    int x, y;
    imageWindow->GetSize(&x, &y);
    dc.SetBrush(wxBrush(*wxWHITE));
    dc.DrawRectangle(0, 0, m_miniaturkaSizeX + 2, m_miniaturkaSizeY * 5 + 7);
    dc.SetBrush(wxBrush(*wxBLACK));
    dc.DrawLine(0, 1 * (m_miniaturkaSizeY + 1) + 1, m_miniaturkaSizeX, 1 * (m_miniaturkaSizeY + 1) + 1);
    dc.DrawLine(0, 2 * (m_miniaturkaSizeY + 1) + 1, m_miniaturkaSizeX, 2 * (m_miniaturkaSizeY + 1) + 1);
    dc.DrawLine(0, 3 * (m_miniaturkaSizeY + 1) + 1, m_miniaturkaSizeX, 3 * (m_miniaturkaSizeY + 1) + 1);
    dc.DrawLine(0, 4 * (m_miniaturkaSizeY + 1) + 1, m_miniaturkaSizeX, 4 * (m_miniaturkaSizeY + 1) + 1);
    for (int i = 0; i < 5; i++)
        repaintMinature(m_miniaturka[i], &dc, wxSize(x, y), i + 1);
}

void MyFrame::repaintMinature(wxImage* miniaturka, wxClientDC *dc, wxSize imageWindow_size, int which_min)
{
    if (miniaturka->IsOk())
    {
        wxImage temp = miniaturka->Copy();
        wxSize resize = scaleWithProportion(wxSize(m_miniaturkaSizeX, m_miniaturkaSizeY), miniaturka->GetSize());
        temp.Rescale(resize.x, resize.y);
        wxPoint wysr = centering(wxSize(m_miniaturkaSizeX, m_miniaturkaSizeY), resize.x, resize.y);
        dc->DrawBitmap(wxBitmap(temp), 1 + wysr.x, which_min * (m_miniaturkaSizeY + 1) - m_miniaturkaSizeY + 1 + wysr.y);
    }
}


