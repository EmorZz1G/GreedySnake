#include <deque>
#include "map.h"
#include "game.h"
#include "food.h"
#include "snake.h"
#include "iostream"
int Node::getX()//��ȡX
{
    return x;
}
int Node::getY()//��ȡY
{
    return y;
}
void Snake::initSnake()//��ʼ����
{
    setColor(0x4);
    std::deque<Node>::iterator it = snake.begin();
    for(; it!=snake.end(); it++)
        printCircle(it->getX(),it->getY());
}
void Node::_clear()//��װ ��
{
    _printNone();
}
void Node::_printNone()//��
{
    pos(x,y);
    std::cout<<"  ";
}
void Node::_printBasic()//��װ ����
{
    pos(x,y);
    std::cout<<"��";
}
void Node::_printCircle()//��װ
{
    pos(x, y);
    std::cout <<"��";// "��" ;
}
void Node::_printStar()//��װ ����
{
    pos(x,y);
    std::cout<<"��";//"��";
}
void Snake::_move(Direction x,Food &_f,int flag=0)//�ƶ�
{//flag Ϊ �Ƿ�Ϊϡ��ʳ��
    //head = snake.front();
    setColor(0x4);
    if(flag==0)
    {
        switch(x)
        {
        case UP:
            if(x==DOWN)return;
            if(!getFood(_f,Node(head.getX(),head.getY()-1)))
            {//û�гԵ�ʳ��
                snake.back()._clear();
                snake.pop_back();
                snake.push_front(Node(head.getX(),head.getY()-1));
                head = snake.front();
                head._printCircle();
            }//�Ե���
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
void Snake::normalMove(Food _f,int flag=0)//�������ƶ���ͷ������β����
{
    if(flag==0)
        _move(direction,_f,flag);
    else
        _move(direction,_f,flag);
}
bool Snake::overEdge()//����
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
bool Snake::hitItself()//ײ������
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
bool Snake::getFood(Food & _f,Node _n)//�Ե�ʳ��
{
    if(_f._food==_n)
        return 1;
    return 0;
}

