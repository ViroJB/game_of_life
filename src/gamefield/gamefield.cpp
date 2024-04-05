#include "gamefield.h"

GameField::GameField(int width, int height) : _width(width), _height(height) {
    resetField();
}

void GameField::resetField() {
    _field.clear();
    for (int i = 0; i < _width; i++) {
        std::vector<bool> row;
        for (int j = 0; j < _height; j++) {
            row.push_back(false);
        }
        _field.push_back(row);
    }

    // load starting figure here for now
    loadStartingFigure();
}

std::vector<std::vector<bool>>* GameField::getField() { return &_field; }

void GameField::setField(std::vector<std::vector<bool>> field) { this->_field = field; }

void GameField::setNode(int x, int y, bool value) { _field[x][y] = value; }

void GameField::setStartingFigure(std::string figure) {
    _startingFigure = figure;
}

void GameField::loadStartingFigure() {
    if(_startingFigure == "blinker")
        setBlinker();
    else if(_startingFigure == "glider")
        setGlider();

    else if(_startingFigure == "pentaDecathlon")
        setPentaDecathlon();
    else
        setBlinker();
}

void GameField::setBlinker() {
    _field[1][1] = true;
    _field[1][2] = true;
    _field[1][3] = true;
}

void GameField::setGlider() {
    _field[1][2] = true;
    _field[2][3] = true;
    _field[3][1] = true;
    _field[3][2] = true;
    _field[3][3] = true;
} 

void GameField::setPentaDecathlon() {
    for (int i = -1; i < 11; ++i) {
        _field[17][18 + i] = true;  // oberste Reihe
        _field[18][18 + i] = true;  // mittlere Reihe
        _field[19][18 + i] = true;  // unterste Reihe
        if (i != -1 && i != 5 && i != 10) {
            _field[16][18 + i] = true;  // Zellen oben links
            _field[20][18 + i] = true;  // Zellen unten links
        }
        if (i != -1 && i != 10) {
            _field[16][18 + i + 1] = true;  // Zellen oben rechts
            _field[20][18 + i + 1] = true;  // Zellen unten rechts
        }
    }

    // field[4][1] = true;
    // field[4][2] = true;
    // field[4][3] = true;
    // field[4][4] = true;
    // field[4][5] = true;
    // field[5][6] = true
}