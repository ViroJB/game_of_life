#include "main_frame.h"

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {

    wxMenu *menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuSimulation = new wxMenu;
    menuSimulation->Append(10, "&Continue");
    menuSimulation->Append(11, "&Pause");
    // menuSimulation->Append(12, "&Clear Field");
    menuSimulation->AppendSeparator();
    menuSimulation->Append(13, "&Reset", "Resets the field with the selected figure.");

    _menuSpeed = new wxMenu;
    // wxMenuItem *speed1 = menuSpeed->Append(14, "&1x");
    _menuSpeed->AppendCheckItem(14, "&1x")->Check(true);
    _menuSpeed->AppendCheckItem(15, "&2x");
    _menuSpeed->AppendCheckItem(16, "&3x");

    _menuFigures = new wxMenu;
    _menuFigures->AppendCheckItem(17, "&Blinker")->Check(true);
    _menuFigures->AppendCheckItem(18, "&Glider");
    _menuFigures->AppendCheckItem(19, "&PentaDecathlon");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuSimulation, "&Simulation");
    menuBar->Append(_menuSpeed, "&Speed");
    menuBar->Append(_menuFigures, "&Figures");

    SetMenuBar(menuBar);
    CreateStatusBar();
}

// return the game speed menu
wxMenu *MainFrame::getMenuSpeed() {
    return _menuSpeed;
}

wxMenu *MainFrame::getMenuFigures() {
    return _menuFigures;
}

BEGIN_EVENT_TABLE(DrawBoardPane, wxPanel)
// catch paint events
EVT_PAINT(DrawBoardPane::paintEvent)
END_EVENT_TABLE()