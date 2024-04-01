#pragma once

#include <thread>

#include <wx/wx.h>

#include "draw_board_pane.h"
#include "gamefield.h"


class App : public wxApp {
   public:
    bool OnInit();
    int countLivingNeighbors(std::vector<std::vector<bool>> *grid, int row, int col);
    void runApp();
    std::vector<std::vector<bool>> getNextGeneration(std::vector<std::vector<bool>> *grid);

   private:
    wxFrame *_mainFrame;
    DrawBoardPane *_drawBoardPane;
    GameField *_gameField;
};