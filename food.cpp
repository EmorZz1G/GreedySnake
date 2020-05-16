#include "map.h"
#include "game.h"
#include "food.h"
#include "snake.h"
#include <iostream>
#include <stdio.h>
void Food::drawFood(Snake &_s)//普通食物
{
    setColor(0x8);
    _rand:
        int tmp_x = rand()%(MAX_X-4)+4;
        int tmp_y = rand()%(MAX_Y-3)+2;
        if(tmp_x%2==1) tmp_x++;
        //if(tmp_y%2==1) tmp_y--;
        Node _f(tmp_x,tmp_y);
        std::deque<Node>::iterator it = _s.snake.begin();
        for(;it!=_s.snake.end();it++)
        {
            if(_f==*it)
                goto _rand;
        }
        _food.x=tmp_x;
        _food.y=tmp_y;
        _food._printStar();
        //pos(80,16);
        //printf("[%d,%d]",tmp_x,tmp_y);
}
void Food::drawBiliFood(Snake& _s,int &len)//绘制限时食物
{
    //len = 42;
    setColor(0x9);
    pos(10,MAX_Y+2);
    std::cout << "------------------------------------------" ;//进度条
    //progress_bar = 42;
    _rand:
        int tmp_x = rand()%(MAX_X-2)+2;
        int tmp_y = rand()%(MAX_Y-3)+2;
        if(tmp_x%2==1) tmp_x--;
        //if(tmp_y%2==1) tmp_y--;
        Node _f(tmp_x,tmp_y);
        std::deque<Node>::iterator it = _s.snake.begin();
        for(;it!=_s.snake.end();it++)
        {
            if(_f==*it||_f==this->_food)
                goto _rand;
        }
        //Food *retF=new Food();
        //retF->
        _food=_f;
        //retF->
        setBili(1);
        //retF->
        setScore(2);
        _f._printStar();
        //std::cout<<"hhhh";
        //return retF;
}
void Food::flashBiliFood(int &len)//闪烁食物
{
    len -= 1;
    pos(len+10,MAX_Y+2);
    std::cout<<" ";
    if(len==0){
            this->_food._printNone();
            setBili(0);
            //delete this;
    }
}
