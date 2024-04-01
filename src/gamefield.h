#pragma once

#include <vector>

class GameField {
   public:
    GameField(int width, int height);
    std::vector<std::vector<bool>>* getField();
    void setNode(int x, int y, bool value);
    void setEverySecondNodeToTrue();
    void setField(std::vector<std::vector<bool>> field);
    void setBlinker();
    void createField();
    void setStartingFigure();
    void setGlider();
    void setPentaDecathlon();

   private:
    std::vector<std::vector<bool>> field;
    int width;
    int height;

};