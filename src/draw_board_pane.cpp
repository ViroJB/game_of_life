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

void DrawBoardPane::drawCube(wxDC &dc, int posX, int posY, int sizeX, int sizeY) {
    dc.SetPen(*wxWHITE_PEN);
    dc.SetBrush(*wxBLACK_BRUSH);
    dc.DrawRectangle(posX, posY, sizeX, sizeY);
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
    std::vector<std::vector<bool>> *field = _gameField->getField();
    for (int i = 0; i < field->size(); i++) {
        for (int j = 0; j < field->at(i).size(); j++) {
            if (field->at(i).at(j)) {
                drawCube(dc, i * 12, j * 12, 12, 12);
            }
        }
    }
}