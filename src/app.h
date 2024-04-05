#pragma once

#include <thread>
#include <atomic>
#include <string>

#include <wx/wx.h>

#include "view/main_frame.h"
#include "view/draw/draw_board_pane.h"
#include "gamefield/gamefield.h"
#include "config/config.h"

class App : public wxApp {
   public:
    bool OnInit();
    void runApp();

    void onStartSimulationClicked(wxCommandEvent &event);
    void onStopSimulationClicked(wxCommandEvent &event);
    void onFigureGliderClicked(wxCommandEvent &event);
    void onFigureBlinkerClicked(wxCommandEvent &event);
    void onFigurePentaDecathlonClicked(wxCommandEvent &event);
    void onGameSpeed1Clicked(wxCommandEvent &event);
    void onGameSpeed2Clicked(wxCommandEvent &event);
    void onGameSpeed3Clicked(wxCommandEvent &event);

    int countLivingNeighbors(std::vector<std::vector<bool>> *grid, int row, int col);
    std::vector<std::vector<bool>> getNextGeneration(std::vector<std::vector<bool>> *grid);

    void onResetFieldClicked(wxCommandEvent &event);

    void onExit(wxCommandEvent &event);

   private:
    MainFrame *_mainFrame;
    DrawBoardPane *_drawBoardPane;
    GameField *_gameField;

    std::atomic<bool> _isSimulationRunning = true;
    int _currentGameSpeed = Config::GAME_SPEED_1;
};