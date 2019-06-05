#include "MyFrame.h"

MyFrame::MyFrame(wxWindow * parent) : GeneratedFrame(parent, wxID_ANY, "Okno g≥Ûwne") {
    // Tworzenie miejsca na oryginaly wszystkich zdjec
    which_min = 0;
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
    adjust_box->SetSelection(0);
    
    imageWindow->wxWindowBase::SetBackgroundColour(m_backgroundColor);
    m_miniaturki->wxWindowBase::SetBackgroundColour(m_backgroundColor);
    this->wxWindowBase::SetBackgroundColour(m_backgroundColor);
    
    // Za≥adowanie obrazka z napisem No photo selected oraz ustawienie wszystkich miniaturek
    wxInitAllImageHandlers();
    wxLogNull logNo;
    m_noSelectedPhoto->LoadFile("default.png");
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
    
    m_kwadraty = std::vector<std::vector<wxPoint *>> (5);
    m_kwadratyCopy = std::vector<std::vector<wxPoint>> (5);
    m_fragments = std::vector<std::vector<wxImage *>> (5);
    m_fragmentsCopy = std::vector<std::vector<wxImage>> (5);
    m_fragmentsPosition = std::vector<std::vector<wxPoint>> (5);
    m_fragmentsScale = std::vector<std::vector<int>> (5);
    
    m_choice1->Connect( wxEVT_CHOICE, wxCommandEventHandler( MyFrame::choiceButtonClic ), NULL, this );
    
    imageWindow->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MyFrame::mouseLeftUp ), NULL, this );
    imageWindow->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame::mouseLeftDown ), NULL, this );
    imageWindow->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame::mouseMove ), NULL, this );
    imageWindow->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelRepaint ), NULL, this );
    m_miniaturki->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::WxPanelMiniaturekRepaint ), NULL, this );
    
    startCutButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::startCutButtonClic ), NULL, this );
    endCutButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::endCutButtonClic ), NULL, this );
    
    jakie_powiekszenie_podczas_rysowania = std::vector<std::vector<int>> (5);

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

	for (int i = 0; i < 5; i++) {
		delete m_miniaturka[i];
	}

	delete m_main;
	delete m_ImageToPrint;
	delete m_noSelectedPhoto;
	delete m_BackgroundImage;

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
    transformFragments();
    repaint();
}


void MyFrame::mouseMove(wxMouseEvent& event)
{
    int shape_selection = chooseShapeBox->GetSelection();
    int miniature_selection = m_choice1->GetSelection();
    int square_count = (int)m_kwadraty[miniature_selection].size();
    if(shape_selection == 2 && square_count > 1 && event.LeftIsDown() )
    {
        *m_kwadraty[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()));
        m_kwadratyCopy[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()));
    }
    repaint();
}

void MyFrame::mouseLeftDown(wxMouseEvent& event)
{
    int shape_selection = chooseShapeBox->GetSelection();
    int miniature_selection = m_choice1->GetSelection();
    int whichAdjust = adjust_box->GetSelection();
    if(m_choice1->IsEnabled() == false) return;
    // Jezeli chcemy narysowac kwadrat
    if(shape_selection == 2)
    {
        for(int i = 0 ; i < 2 ; i++)
        {
            jakie_powiekszenie_podczas_rysowania[miniature_selection].push_back(whichAdjust);
            m_kwadraty[miniature_selection].push_back(new wxPoint(imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()))));
            m_kwadratyCopy[miniature_selection].push_back(wxPoint(imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()))));
        }
    }
    repaint();
}

void MyFrame::mouseLeftUp(wxMouseEvent& event)
{
    int shape_selection = chooseShapeBox->GetSelection();
    int miniature_selection = m_choice1->GetSelection();
    int square_count = (int)m_kwadraty[miniature_selection].size();
    if(shape_selection == 2 && square_count > 1)
    {
        *m_kwadraty[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()));
        m_kwadratyCopy[miniature_selection][square_count - 1] = imageWindow->CalcUnscrolledPosition(wxPoint(event.GetX(), event.GetY()));
        cutRectangleFragment(miniature_selection, adjust_box->GetSelection());
    }
    repaint();
}

void MyFrame::cutRectangleFragment(int whichMinature, int whichAdjust)
{
    unsigned char *data{};
    int minSize{};
    unsigned long rectCount = (m_kwadraty[whichMinature].size());
    wxPoint center;
    wxSize size = wxSize(fabs(m_kwadraty[whichMinature][rectCount - 2]->x - m_kwadraty[whichMinature][rectCount - 1]->x), fabs(m_kwadraty[whichMinature][rectCount - 2]->y - m_kwadraty[whichMinature][rectCount - 1]->y));
    wxPoint point = wxPoint(*m_kwadraty[whichMinature][rectCount - 2]);
    
    unsigned char *new_data = static_cast<unsigned char *>(malloc(sizeof(char) * 3 * size.x * size.y));
//    unsigned char *alphaData = static_cast<unsigned char *>(malloc(sizeof(char) * 3 * size.x * size.y));
    
    wxImage temp = *m_miniaturka[whichMinature];
    
    if(temp.IsOk())
    {
        updateSizeOfPhoto(temp, whichAdjust);
        data = temp.GetData();
        minSize = temp.GetWidth();
        center = centering(imageWindow->GetSize(), minSize, temp.GetHeight());
    }
    
    for(int x = 0 ; x < size.x ; x++)
    {
        for(int y = 0 ; y < size.y ; y++)
        {
            new_data[3 * (size.x * y + x) + 0] = data[3 * (minSize * (point.y + y - center.y) + (point.x + x - center.x)) + 0];
            new_data[3 * (size.x * y + x) + 1] = data[3 * (minSize * (point.y + y - center.y) + (point.x + x - center.x)) + 1];
            new_data[3 * (size.x * y + x) + 2] = data[3 * (minSize * (point.y + y - center.y) + (point.x + x - center.x)) + 2];
        }
    }
    
    wxImage *fragment = new wxImage(size, true);
    if(fragment->IsOk())
        fragment->SetData(new_data);
    m_fragments[whichMinature].push_back(fragment);
    m_fragmentsCopy[whichMinature].push_back(*fragment);
    m_fragmentsPosition[whichMinature].push_back(point);
    m_fragmentsScale[whichMinature].push_back(whichAdjust);
}

void MyFrame::transformFragments()
{
    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j < m_fragments[i].size() ; j++)
        {
            m_fragmentsCopy[i][j] = *m_fragments[i][j];
            double scaleX{}, scaleY{};
            wxPoint begin, end;
            center(m_fragmentsScale[i][j], adjust_box->GetSelection(), *m_miniaturka[which_min], &begin, &end);
            scale(m_fragmentsScale[i][j], adjust_box->GetSelection(), *m_miniaturka[which_min], &scaleX, &scaleY);
            m_fragmentsPosition[i][j] = wxPoint((m_fragmentsPosition[i][j].x - begin.x) / scaleX + end.x,(m_fragmentsPosition[i][j].y - begin.y) / scaleY + end.y);
            
            m_fragmentsCopy[i][j].Rescale(m_fragmentsCopy[i][j].GetWidth() / scaleX, m_fragmentsCopy[i][j].GetHeight() / scaleY);
        }
    }
}

void MyFrame::transformRectangleVector()
{
    int actualAdjust = adjust_box->GetSelection();
    for(int i = 0 ; i < 5 ; i++)
    {
        for(int j = 0 ; j < m_kwadratyCopy[i].size() / 2 ; j++)
        {
            int p = jakie_powiekszenie_podczas_rysowania[i][j];
            double scaleX, scaleY;
            wxPoint begin, end;
            
            scale(p, actualAdjust, *m_miniaturka[i], &scaleX, &scaleY);
            center(p, actualAdjust, *m_miniaturka[i], &begin, &end);
            
            std::cout << p << "  " << actualAdjust  << std::endl;
//            std::cout << scaleX  << std::endl;
            
            m_kwadratyCopy[i][j] = wxPoint((m_kwadraty[i][j]->x - begin.x) / scaleX + end.x, (m_kwadraty[i][j]->y - begin.y) / scaleY  + end.y);
            m_kwadratyCopy[i][j * 2] = wxPoint((m_kwadraty[i][j * 2]->x - begin.x) / scaleX + end.x, (m_kwadraty[i][j * 2]->y - begin.y) / scaleY  + end.y);
        }
    }
}


void MyFrame::scale(int fromWhichAdjus, int toWhichAdjust, wxImage whichImage, double *scaleX, double *scaleY)
{
    wxImage temp;
    if(whichImage.IsOk())
        temp = whichImage.Copy();
    switch (fromWhichAdjus) {
        case 1:
            fitWidth(temp);
            break;
        case 2:
            fitHeight(temp);
            break;
        case 3:
            fitOnScreen(temp);
            break;
        default:
            break;
    }
    
    wxSize begin = temp.GetSize();
    if(whichImage.IsOk())
        temp = whichImage.Copy();
    
    switch (toWhichAdjust) {
        case 1:
            fitWidth(temp);
            break;
        case 2:
            fitHeight(temp);
            break;
        case 3:
            fitOnScreen(temp);
            break;
        default:
            break;
    }
    
    wxSize end = temp.GetSize();
    *scaleX = begin.x / static_cast<double>(end.x);
    *scaleY = begin.y / static_cast<double>(end.y);
}

void MyFrame::center(int fromWhichAdjus, int toWhichAdjust, wxImage whichImage, wxPoint *begin, wxPoint *end)
{
    wxImage temp;
    if(whichImage.IsOk())
        temp = whichImage.Copy();
    switch (fromWhichAdjus) {
        case 1:
            fitWidth(temp);
            break;
        case 2:
            fitHeight(temp);
            break;
        case 3:
            fitOnScreen(temp);
            break;
        default:
            break;
    }
    
    *begin = centering(imageWindow->GetSize(), temp.GetWidth(), temp.GetHeight());
    
    if(whichImage.IsOk())
        temp = whichImage.Copy();
    
    switch (toWhichAdjust) {
        case 1:
            fitWidth(temp);
            break;
        case 2:
            fitHeight(temp);
            break;
        case 3:
            fitOnScreen(temp);
            break;
        default:
            break;
    }
    
    *end = centering(imageWindow->GetSize(), temp.GetWidth(), temp.GetHeight());
}

void MyFrame::drawRectangle(wxDC& dc)
{
    dc.SetBrush(wxBrush(*wxRED));
    int miniature_selection = m_choice1->GetSelection();
    int rect_count = m_kwadraty[miniature_selection].size() / 2.0;
    wxPoint point1, point2, point3, point4;
    for(int i = 0 ; i < rect_count ; i++)
    {
        point1 = wxPoint(m_kwadratyCopy[miniature_selection][0 + (i * 2)].x, m_kwadratyCopy[miniature_selection][0 + (i * 2)].y);
        point2 = wxPoint(m_kwadratyCopy[miniature_selection][0 + (i * 2)].x, m_kwadratyCopy[miniature_selection][1 + (i * 2)].y);
        point3 = wxPoint(m_kwadratyCopy[miniature_selection][1 + (i * 2)].x, m_kwadratyCopy[miniature_selection][1 + (i * 2)].y);
        point4 = wxPoint(m_kwadratyCopy[miniature_selection][1 + (i * 2)].x, m_kwadratyCopy[miniature_selection][0 + (i * 2)].y);
        
        dc.DrawLine(point1, point2);
        dc.DrawLine(point1, point4);
        dc.DrawLine(point2, point3);
        dc.DrawLine(point3, point4);
    }
}

//void MyFrame::drawBrokenCurve(){}
//void MyFrame::drawBrokenCurve_gladka(){}



void MyFrame::fitWidth(wxImage &image)
{
    int x, y;
    imageWindow->GetSize(&x, &y);
    image.Rescale(x, (static_cast<double>(m_ImageToPrint->GetSize().y) / static_cast<double>(m_ImageToPrint->GetSize().x)) * static_cast<double>(x));
}

void MyFrame::fitHeight(wxImage &image)
{
    int x, y;
    imageWindow->GetSize(&x, &y);
    image.Rescale((static_cast<double>(m_ImageToPrint->GetSize().x) / static_cast<double>(m_ImageToPrint->GetSize().y)) * static_cast<double>(y), y);
}

void MyFrame::fitOnScreen(wxImage &image)
{
    wxSize size = scaleWithProportion(imageWindow->GetSize(), m_ImageToPrint->GetSize());
    image.Rescale(size.x, size.y);
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


void MyFrame::updateMain()
{
    if(m_choice1->IsEnabled() && m_miniaturka[m_choice1->GetSelection()]->IsOk())
    {
        *m_ImageToPrint = m_miniaturka[m_choice1->GetSelection()]->Copy();
        updateSizeOfPhoto(*m_ImageToPrint, adjust_box->GetSelection());
        transformRectangleVector();
    }
    else
    {
        *m_ImageToPrint = m_BackgroundImage->Copy();
        updateSizeOfPhoto(*m_ImageToPrint, adjust_box->GetSelection());
        transformRectangleVector();
    }
    imageWindow->SetScrollbars(20, 20, m_ImageToPrint->GetSize().x / 20.0, m_ImageToPrint->GetSize().y / 20.0);
}



void MyFrame::updateSizeOfPhoto(wxImage &image, int whichAdjust)
{
    if(whichAdjust == 1)
        fitWidth(image);
    if(whichAdjust == 2)
        fitHeight(image);
    if(whichAdjust == 3)
        fitOnScreen(image);
}

void MyFrame::repaint()
{
    wxClientDC dc1(imageWindow);
    wxBufferedDC dc(&dc1);
    dc.Clear();
    imageWindow->DoPrepareDC(dc);
    
    wxPoint center = centering(imageWindow->GetSize(), m_ImageToPrint->GetWidth(), m_ImageToPrint->GetHeight());
    
    int x, y;
    imageWindow->GetSize(&x, &y);
    if (m_ImageToPrint->IsOk())
    {
        if(m_choice1->IsEnabled())
            dc.DrawBitmap(wxBitmap(*m_ImageToPrint), center);
        else
        {
            dc.DrawBitmap(wxBitmap(*m_ImageToPrint), center);
            for(int i = 0 ; i < 5 ; i++)
                for(int j = 0 ; j < m_fragments[i].size() ; j++)
                    if(m_fragmentsCopy[i][j].IsOk())
                        dc.DrawBitmap(wxBitmap(m_fragmentsCopy[i][j]), m_fragmentsPosition[i][j]);
        }
    }
    //drawRectangle(dc);
    int selection = chooseShapeBox->GetSelection();
    if(selection == 2 && m_choice1->IsEnabled())
    {
        drawRectangle(dc);
    }
}

void MyFrame::load(int which_button)
{
    for(auto x : m_kwadraty[which_button - 1])
        delete x;
    for(auto x : m_fragments[which_button - 1])
        delete x;
    m_fragments[which_button - 1].clear();
    m_fragmentsCopy[which_button - 1].clear();
    m_kwadraty[which_button - 1].clear();
    m_kwadratyCopy[which_button - 1].clear();
    m_fragmentsPosition[which_button - 1].clear();
    jakie_powiekszenie_podczas_rysowania[which_button - 1].clear();
    
    wxImage new_image;
    wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
    if (WxOpenFileDialog.ShowModal() == wxID_OK) {
        new_image.LoadFile(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);

        if (new_image.IsOk() && new_image.GetWidth() >= 4500 && new_image.GetHeight() >= 3500) {
            *(m_miniaturka[which_button - 1]) = new_image.Copy();

			if (m_Radio[which_button - 1]->GetValue() || m_choice1->IsEnabled())
			{
				chooseBackground();
			}

			repaintMiniatures();
			repaint();
        }

		else {
			wxMessageBox(wxT("Wczytany obraz musi byc rozmiaru co najmniej 4500 x 3500 pikseli!"), wxT("Bledny rozmiar obrazka"));
			load(which_button);
		}
    }
	
}

void MyFrame::loadMinature()
{
    for (int i = 0; i < 5; i++)
        if (m_Radio[i]->GetValue() && m_miniaturka[i]->IsOk())
            *m_BackgroundImage = m_miniaturka[i]->Copy();
}

void MyFrame::chooseBackground(){
    *m_BackgroundImage = m_miniaturka[which_min]->Copy();
    if(!m_choice1->IsEnabled())
    {
        *m_ImageToPrint = m_BackgroundImage->Copy();
        updateSizeOfPhoto(*m_ImageToPrint, adjust_box->GetSelection());
    }
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


