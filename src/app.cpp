#include "app.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    _mainFrame = new wxFrame(nullptr, wxID_ANY, "test", wxPoint(50, 50), wxSize(700, 700));
    _mainFrame->SetMinSize(wxSize(700, 700));

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_ANY, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    _mainFrame->SetMenuBar(menuBar);

    _drawBoardPane = new DrawBoardPane(_mainFrame);

    // wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    // sizer->Add(drawBoardPane, 1, wxEXPAND);
    // mainFrame->SetSizer(sizer);
    // mainFrame->SetAutoLayout(true);

    _mainFrame->SetStatusBar(new wxStatusBar(_mainFrame, wxID_ANY));
    _mainFrame->Show();

    _gameField = new GameField(50, 50);
    _gameField->createField();
    // _gameField->setStartingFigure();
    // _gameField->setBlinker();
    // _gameField->setGlider();
    _gameField->setPentaDecathlon();
    // _gameField->setEverySecondNodeToTrue();
    _drawBoardPane->setGameField(_gameField);
    _drawBoardPane->paintNow();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // runApp();
    // std::thread(&App::runApp, this);
    std::thread t1(&App::runApp, this);
    t1.detach();
    return true;
}

void App::runApp() {
    while (true) {
        _gameField->setField(getNextGeneration(_gameField->getField()));
        _drawBoardPane->paintNow();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int App::countLivingNeighbors(std::vector<std::vector<bool>> *grid, int row, int col) {
    int livingNeighbors = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int newRow = row + i;
            int newCol = col + j;
            if (newRow < 0 || newRow >= grid->size() || newCol < 0 || newCol >= grid->at(0).size()) {
                continue;
            }
            if (grid->at(newRow).at(newCol)) {
                livingNeighbors++;
            }
        }
    }
    return livingNeighbors;
}

std::vector<std::vector<bool>> App::getNextGeneration(std::vector<std::vector<bool>> *grid) {
    std::vector<std::vector<bool>> newGrid;
    for (int i = 0; i < grid->size(); i++) {
        std::vector<bool> row;
        for (int j = 0; j < grid->at(i).size(); j++) {
            int livingNeighbors = countLivingNeighbors(grid, i, j);
            if (grid->at(i).at(j)) {
                if (livingNeighbors < 2 || livingNeighbors > 3) {
                    row.push_back(false);
                } else {
                    row.push_back(true);
                }
            } else {
                if (livingNeighbors == 3) {
                    row.push_back(true);
                } else {
                    row.push_back(false);
                }
            }
        }
        newGrid.push_back(row);
    }
    return newGrid;
}

BEGIN_EVENT_TABLE(DrawBoardPane, wxPanel)
// catch paint events
EVT_PAINT(DrawBoardPane::paintEvent)
END_EVENT_TABLE()
