#include "draw_board_pane.h"

DrawBoardPane::DrawBoardPane(wxWindow *parent) : wxPanel(parent) {}

void DrawBoardPane::paintEvent(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    render(dc);
}

void DrawBoardPane::paintNow() {
    wxClientDC dc(this);
    render(dc);
}

void DrawBoardPane::render(wxDC &dc) {
    dc.SetBackground(*wxGREY_BRUSH);
    dc.Clear();
    drawGameField(dc);
}

void DrawBoardPane::setGameField(GameField *gameField) {
    _gameField = gameField;
}

void DrawBoardPane::drawGameField(wxDC &dc) {
    drawGitter(dc);
    std::vector<std::vector<bool>> *field = _gameField->getField();
    for (int i = 0; i < field->size(); i++) {
        for (int j = 0; j < field->at(i).size(); j++) {
            if (field->at(i).at(j)) {
                drawCube(dc, i * Config::CELL_SIZE, j * Config::CELL_SIZE, Config::CELL_SIZE, Config::CELL_SIZE);
            }
        }
    }
}

void DrawBoardPane::drawGitter(wxDC &dc) {
    for (int i = 0; i < 50; i++) {
        dc.DrawLine(i * Config::CELL_SIZE, 0, i * Config::CELL_SIZE, 600);
    }
    for (int i = 0; i < 50; i++) {
        dc.DrawLine(0, i * Config::CELL_SIZE, 600, i * Config::CELL_SIZE);
    }
}

void DrawBoardPane::drawCube(wxDC &dc, int posX, int posY, int sizeX, int sizeY) {
    dc.SetPen(*wxWHITE_PEN);
    dc.SetBrush(*wxBLACK_BRUSH);
    dc.DrawRectangle(posX, posY, sizeX, sizeY);
}