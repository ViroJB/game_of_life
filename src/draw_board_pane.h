#pragma once

#include <wx/wx.h>

#include "gamefield.h"

class DrawBoardPane : public wxPanel {
   public:
    DrawBoardPane(wxWindow *parent);

    void paintEvent(wxPaintEvent &evt);
    void paintNow();

    void render(wxDC &dc);

    void setGameField(GameField *gameField);
    void drawCube(wxDC &dc, int posX, int posY, int sizeX, int sizeY);
    void drawGameField(wxDC &dc);

    DECLARE_EVENT_TABLE()

    private:
    GameField *_gameField;
};