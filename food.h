#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED
#include "map.h"
#include "game.h"
#include "food.h"
#include "snake.h"
class Node;
class Snake;
class Food:public Node{
private:
    int score;
    int isBiling;
    int cnt;
public:
    Node _food;
    Food(){score=1;isBiling=0;cnt=0;}
    void drawFood(Snake &);
    void setBili(int x){isBiling =x;}
    void setScore(int x){score=x;}
    int isBili(){return isBiling;}
    int getScore(){return score;}
    void drawBiliFood(Snake &,int&);
    void flashBiliFood(int &);
    friend class Node;
    friend class Snake;
};

#endif // FOOD_H_INCLUDED

