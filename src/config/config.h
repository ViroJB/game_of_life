#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
   public:
    static const std::string APP_NAME;
    static const int WINDOW_SIZE_X;
    static const int WINDOW_SIZE_Y;
    static const int CELL_SIZE;
    static const int GAME_SPEED_1;
    static const int GAME_SPEED_2;
    static const int GAME_SPEED_3;
};

#endif  // CONFIG_H