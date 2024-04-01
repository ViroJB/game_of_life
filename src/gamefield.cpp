#include "gamefield.h"

GameField::GameField(int width, int height) : width(width), height(height) {}

void GameField::createField() {
    for (int i = 0; i < width; i++) {
        std::vector<bool> row;
        for (int j = 0; j < height; j++) {
            row.push_back(false);
        }
        field.push_back(row);
    }
}

std::vector<std::vector<bool>>* GameField::getField() { return &field; }

void GameField::setField(std::vector<std::vector<bool>> field) { this->field = field; }

void GameField::setNode(int x, int y, bool value) { field[x][y] = value; }

void GameField::setEverySecondNodeToTrue() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                field[i][j] = true;
            }
        }
    }
}

void GameField::setStartingFigure() {
    field[1][1] = true;
    field[1][2] = true;
    field[1][3] = true;
    field[2][3] = true;
    field[3][2] = true;
}

void GameField::setBlinker() {
    field[1][1] = true;
    field[1][2] = true;
    field[1][3] = true;
}

void GameField::setGlider() {
    field[1][2] = true;
    field[2][3] = true;
    field[3][1] = true;
    field[3][2] = true;
    field[3][3] = true;
}

void GameField::setPentaDecathlon() {
    for (int i = 0; i < 11; ++i) {
        field[18][18 + i] = true;  // oberste Reihe
        field[19][18 + i] = true;  // mittlere Reihe
        field[20][18 + i] = true;  // unterste Reihe
        if (i != 0 && i != 5 && i != 10) {
            field[17][18 + i] = true;  // Zellen oben links
            field[21][18 + i] = true;  // Zellen unten links
        }
        if (i != 0 && i != 10) {
            field[17][18 + i + 1] = true;  // Zellen oben rechts
            field[21][18 + i + 1] = true;  // Zellen unten rechts
        }
    }

    // field[5][1] = true;
    // field[5][2] = true;
    // field[5][3] = true;
    // field[5][4] = true;
    // field[5][5] = true;
    // field[5][6] = true;
    // field[5][7] = true;
    // field[5][8] = true;
    // field[5][9] = true;
    // field[5][10] = true;
    // field[6][6] = true;
    // field[7][1] = true;
    // field[7][2] = true;
    // field[7][3] = true;
    // field[7][4] = true;
    // field[7][5] = true;
    // field[7][6] = true;
    // field[7][7] = true;
    // field[7][8] = true;
    // field[7][9] = true;
    // field[7][10] = true;
}