#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "map.h"
#include "game.h"
#include "food.h"
#include "snake.h"
#include <deque>
#include "stdlib.h"
class Food;
class Control;
class Map;
class Node
{
public:
    int x,y;

    Node(int _x,int _y=6)
    {
        x=_x;
        y=_y;
    }
    Node() {}
    int getX();
    int getY();
    void _clear();
    void _printNone();
    void _printBasic();
    void _printCircle();
    void _printStar();
    bool operator==(Node &other)
    {
        if(this->getX()==other.getX()&&this->getY()==other.getY())
            return 1;
        return 0;
    }
};
class Snake:public Node{
public:
    enum Direction {UP, DOWN, LEFT, RIGHT};
    friend class Food;
    friend class Node;
    friend class Map;
    int death;
    int gets;
    Snake()
    {
        snake.push_back(Node(14, 9));
        snake.push_back(Node(14, 10));
        snake.push_back(Node(14, 11));
        head = snake.front();
        direction = UP;
        death = 0;
        eat = 0;
        gets =0;
    }
    void initSnake();
    void _move(Direction,Food&,int flag);
    bool overEdge();
    bool hitItself();
    bool getFood(Food&,Node);
    void normalMove(Food ,int flag);
    int getGets(){return gets;}
    int getEat(){return eat;}
    Node& getHead(){return head;}
    bool isDead()
    {
        if(overEdge()||hitItself())
        {
            death = 1;
            return 1;
        }
        return 0;
    }
    Direction direction;
private:
    std::deque<Node> snake;

    Node head;
    int eat;
};
#endif // SNAKE_H_INCLUDED
