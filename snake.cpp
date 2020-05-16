#include <deque>
#include "map.h"
#include "game.h"
#include "food.h"
#include "snake.h"
#include "iostream"
int Node::getX()//获取X
{
    return x;
}
int Node::getY()//获取Y
{
    return y;
}
void Snake::initSnake()//初始化蛇
{
    setColor(0x4);
    std::deque<Node>::iterator it = snake.begin();
    for(; it!=snake.end(); it++)
        printCircle(it->getX(),it->getY());
}
void Node::_clear()//封装 空
{
    _printNone();
}
void Node::_printNone()//空
{
    pos(x,y);
    std::cout<<"  ";
}
void Node::_printBasic()//封装 方块
{
    pos(x,y);
    std::cout<<"■";
}
void Node::_printCircle()//封装
{
    pos(x, y);
    std::cout <<"●";// "●" ;
}
void Node::_printStar()//封装 星星
{
    pos(x,y);
    std::cout<<"★";//"★";
}
void Snake::_move(Direction x,Food &_f,int flag=0)//移动
{//flag 为 是否为稀有食物
    //head = snake.front();
    setColor(0x4);
    if(flag==0)
    {
        switch(x)
        {
        case UP:
            if(x==DOWN)return;
            if(!getFood(_f,Node(head.getX(),head.getY()-1)))
            {//没有吃到食物
                snake.back()._clear();
                snake.pop_back();
                snake.push_front(Node(head.getX(),head.getY()-1));
                head = snake.front();
                head._printCircle();
            }//吃到了
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                _f.drawFood(*this);
                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        case DOWN:
            if(x==UP)return;
            if(!getFood(_f,Node(head.getX(),head.getY()+1)))
            {
                snake.back()._clear();
                snake.pop_back();
                snake.push_front(Node(head.getX(),head.getY()+1));
                head = snake.front();
                head._printCircle();
            }
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                _f.drawFood(*this);
                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        case LEFT:
            if(x==RIGHT)return;
            if(!getFood(_f,Node(head.getX()-2,head.getY())))
            {
                snake.back()._clear();
                snake.pop_back();
                snake.push_front(Node(head.getX()-2,head.getY()));
                head = snake.front();
                head._printCircle();
            }
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                _f.drawFood(*this);
                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        case RIGHT:
            if(x==LEFT)return;
            if(!getFood(_f,Node(head.getX()+2,head.getY())))
            {
                snake.back()._clear();
                snake.pop_back();
                snake.push_front(Node(head.getX()+2,head.getY()));
                head = snake.front();
                head._printCircle();
            }
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                _f.drawFood(*this);
                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        }
    }
    else
    {
        switch(x)
        {
        case UP:
            if(x==DOWN)return;
            if(!getFood(_f,Node(head.getX(),head.getY()-1)))
            {

            }
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                //_f.drawFood(*this);

                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        case DOWN:
            if(x==UP)return;
            if(!getFood(_f,Node(head.getX(),head.getY()+1)))
            {

            }
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                //_f.drawFood(*this);
                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        case LEFT:
            if(x==RIGHT)return;
            if(!getFood(_f,Node(head.getX()-2,head.getY())))
            {

            }
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                //_f.drawFood(*this);
                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        case RIGHT:
            if(x==LEFT)return;
            if(!getFood(_f,Node(head.getX()+2,head.getY())))
            {

            }
            else
            {
                snake.push_front(_f._food);
                head = snake.front();
                head._printCircle();
                //_f.drawFood(*this);
                gets+=_f.getScore();
                eat++;
            }
            direction = x;
            break;
        }
    }
}
void Snake::normalMove(Food _f,int flag=0)//蛇正常移动，头增长，尾缩短
{
    if(flag==0)
        _move(direction,_f,flag);
    else
        _move(direction,_f,flag);
}
bool Snake::overEdge()//出界
{
    //for(int i = 0;i<=MAX_X;i+=2)
    //if(head.getX()==i&&(head.getY()==0||head.getY()==MAX_Y);
    if(head.getY()<=0||head.getY()>=MAX_Y)
        return 1;
    //for(int i = 1;i<MAX_Y;i++)
    if(head.getX()<=2||head.getX()>=MAX_X)
        return 1;
    return 0;
}
bool Snake::hitItself()//撞到自身
{
    std::deque<Node>::iterator it = snake.begin();
    it++;
    head = snake.front();
    for(; it!=snake.end(); it++)
    {
        if(head==*it)
            return 1;
    }
    return 0;
}
bool Snake::getFood(Food & _f,Node _n)//吃到食物
{
    if(_f._food==_n)
        return 1;
    return 0;
}

