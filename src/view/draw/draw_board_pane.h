#pragma once

#include <wx/wx.h>

#include "../../gamefield/gamefield.h"
#include "../../config/config.h"

class DrawBoardPane : public wxPanel {
   public:
    DrawBoardPane(wxWindow *parent);

    void paintEvent(wxPaintEvent &evt);
    void paintNow();
    void render(wxDC &dc);

    void setGameField(GameField *gameField);
    void drawGameField(wxDC &dc);

    void drawGitter(wxDC &dc);
    void drawCube(wxDC &dc, int posX, int posY, int sizeX, int sizeY);

    DECLARE_EVENT_TABLE()

    private:
    GameField *_gameField;
};