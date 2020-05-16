#include "map.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "game.h"
#include "food.h"
#include "snake.h"
void pos(int x,int y)//光标移动
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄
    SetConsoleCursorPosition(hOutput, pos);//百度的，我也不太懂
}
void printBasic(int x,int y)//方块
{
    pos(x,y);
    std::cout<<"■";
}
void printStar(int x,int y)//星星
{
    pos(x,y);
    std::cout<<"★";//"★";
}
void printNone(int x,int y)//空
{
    pos(x,y);
    std::cout<<"  ";
}
void creatMap(int init=0){//初始MAP
    setColor(0x2);
    for(int i = 2;i<=MAX_X;i+=2)
    {
        printBasic(i,1);
    }
    for(int i = 1;i<=MAX_Y;i++)
    {
        printBasic(2,i);
        printBasic(MAX_X,i);
        if(init==0)Sleep(10);
    }
    for(int i = 2;i<=MAX_X;i+=2)
    {
        printBasic(i,MAX_Y);
    }
}
void creatMap_In(Map _m)//障碍
{
    setColor(0x5);
    std::vector<Node>::iterator it = _m._map.begin();
    for(;it!=_m._map.end();it++)
    {
        it->_printBasic();
    }
}
void printCircle(int x,int y)//输出圆形
{
    pos(x, y);
    std::cout << "●";//"●" ;
}
