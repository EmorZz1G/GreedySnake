#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <windows.h>
#include "map.h"
#include "game.h"
#include "food.h"
#include "snake.h"
void SetWindowSize(int cols, int lines);
void setColor(int colorId);
void setBackColor();
class Game{
private:
    int Gets=0;
    int speed = 700;
    int len=42;
    int flag= 0;
    int ch;
    int key;
    double len_time;
    double flash_time;
    double must_food;
    double start;
public:
    void play();
    void select();
    void GameOver();
    void control();
    void upDate(Snake &);
    bool hitBlocks(Map&,Snake&);
    bool isDead2(Map &_m,Snake &_s)
    {
        if(hitBlocks(_m,_s))
        {
            return 1;
        }
        return 0;
    }
};
#endif // GAME_H_INCLUDED
