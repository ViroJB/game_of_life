#pragma once

#include <vector>
#include <string>

class GameField {
   public:
    GameField(int width, int height);

    void resetField();
    std::vector<std::vector<bool>>* getField();
    void setField(std::vector<std::vector<bool>> field);
    void setNode(int x, int y, bool value);

    void setStartingFigure(std::string figure);
    void loadStartingFigure();
    void setBlinker();
    void setGlider();
    void setPentaDecathlon();

   private:
    std::vector<std::vector<bool>> _field;
    int _width;
    int _height;

    std::string _startingFigure = "blinker";
};