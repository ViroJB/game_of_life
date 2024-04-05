#include "app.h"


wxIMPLEMENT_APP(App);
// TODO adjustable speed
bool App::OnInit() {
    _mainFrame = new MainFrame(Config::APP_NAME, wxPoint(50, 50), wxSize(Config::WINDOW_SIZE_X, Config::WINDOW_SIZE_Y));
    _mainFrame->SetMinSize(wxSize(Config::WINDOW_SIZE_X, Config::WINDOW_SIZE_Y));

    // bind buttons and stuff
    _mainFrame->Bind(wxEVT_MENU, &App::onExit, this, wxID_EXIT);
    _mainFrame->Bind(wxEVT_MENU, &App::onStartSimulationClicked, this, 10);
    _mainFrame->Bind(wxEVT_MENU, &App::onStopSimulationClicked, this, 11);
    _mainFrame->Bind(wxEVT_MENU, &App::onResetFieldClicked, this, 13);
    _mainFrame->Bind(wxEVT_MENU, &App::onFigureBlinkerClicked, this, 17);
    _mainFrame->Bind(wxEVT_MENU, &App::onFigureGliderClicked, this, 18);
    _mainFrame->Bind(wxEVT_MENU, &App::onGameSpeed1Clicked, this, 14);
    _mainFrame->Bind(wxEVT_MENU, &App::onGameSpeed2Clicked, this, 15);
    _mainFrame->Bind(wxEVT_MENU, &App::onGameSpeed3Clicked, this, 16); 
    _mainFrame->Show();
    _mainFrame->getMenuSpeed()->FindItem(14)->Check(true);

    _gameField = new GameField(50, 50);

    _drawBoardPane = new DrawBoardPane(_mainFrame);
    _drawBoardPane->setGameField(_gameField);
    _drawBoardPane->paintNow();

    std::thread t1(&App::runApp, this);
    t1.detach();
    return true;
}

void App::runApp() {
    int iteration = 0;
    auto time = std::chrono::high_resolution_clock::now();
    while (true) {
        if(_isSimulationRunning.load() == false) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            continue;
        }
        _gameField->setField(getNextGeneration(_gameField->getField()));
        _drawBoardPane->paintNow();
        std::this_thread::sleep_for(std::chrono::milliseconds(_currentGameSpeed));
        iteration++;

        // for fps
        if (std::chrono::high_resolution_clock::now() - time > std::chrono::milliseconds(1000)) {
            std::string fps = "FPS: " + std::to_string(iteration);
            if (_mainFrame->GetStatusBar()->GetStatusText().empty()) {
                _mainFrame->SetStatusText(fps);
            }
            time = std::chrono::high_resolution_clock::now();
            iteration = 0;
        }
    }
}

void App::onStartSimulationClicked(wxCommandEvent &event) {
    _isSimulationRunning.store(true);
}
void App::onStopSimulationClicked(wxCommandEvent &event) {
    _isSimulationRunning.store(false);
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

void App::onResetFieldClicked(wxCommandEvent &event) {
    _gameField->resetField();
    _drawBoardPane->paintNow();
}

void App::onFigureBlinkerClicked(wxCommandEvent &event) {
    _gameField->setStartingFigure("blinker");
    _mainFrame->getMenuFigures()->FindItem(17)->Check(true);
    _mainFrame->getMenuFigures()->FindItem(18)->Check(false);
    onResetFieldClicked(event);
}

void App::onFigureGliderClicked(wxCommandEvent &event) {
    _gameField->setStartingFigure("glider");
    _mainFrame->getMenuFigures()->FindItem(17)->Check(false);
    _mainFrame->getMenuFigures()->FindItem(18)->Check(true);
    onResetFieldClicked(event);
}


void App::onGameSpeed1Clicked(wxCommandEvent &event) {
    _currentGameSpeed = Config::GAME_SPEED_1;
    _mainFrame->getMenuSpeed()->FindItem(14)->Check(true);
    _mainFrame->getMenuSpeed()->FindItem(15)->Check(false);
    _mainFrame->getMenuSpeed()->FindItem(16)->Check(false);
}

void App::onGameSpeed2Clicked(wxCommandEvent &event) {
    _currentGameSpeed = Config::GAME_SPEED_2;
    _mainFrame->getMenuSpeed()->FindItem(14)->Check(false);
    _mainFrame->getMenuSpeed()->FindItem(15)->Check(true);
    _mainFrame->getMenuSpeed()->FindItem(16)->Check(false);
}

void App::onGameSpeed3Clicked(wxCommandEvent &event) {
    _currentGameSpeed = Config::GAME_SPEED_3;
    _mainFrame->getMenuSpeed()->FindItem(14)->Check(false);
    _mainFrame->getMenuSpeed()->FindItem(15)->Check(false);
    _mainFrame->getMenuSpeed()->FindItem(16)->Check(true);
}

void App::onExit(wxCommandEvent &event) { 
    _mainFrame->Close(true); 
    _isSimulationRunning.store(false);
    this->Exit();
}