#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <windows.h>
#include "map.h"
#include "game.h"
#include "food.h"
#include "snake.h"
#define MAX_X 60
#define MAX_Y 26
#include <queue>
class Map:public Node{
public:
    std::vector<Node> _map;
    Map(){
    _map.push_back(Node(10,8));
    _map.push_back(Node(10,9));
    _map.push_back(Node(12,20));
    _map.push_back(Node(4,11));
    _map.push_back(Node(4,9));
    _map.push_back(Node(4,10));
    _map.push_back(Node(6,9));
    _map.push_back(Node(20,11));
    _map.push_back(Node(20,21));
    _map.push_back(Node(20,22));
    _map.push_back(Node(20,23));
    _map.push_back(Node(20,24));
    }
};
void creatMap(int);
void pos(int,int);
void printBasic(int,int);
void printCircle(int,int);
void printNone(int,int);
void printStar(int,int);
void creatMap_In(Map _m);
#endif // MAP_H_INCLUDED
