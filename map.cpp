#include "map.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "game.h"
#include "food.h"
#include "snake.h"
void pos(int x,int y)//����ƶ�
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//���ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ��
    SetConsoleCursorPosition(hOutput, pos);//�ٶȵģ���Ҳ��̫��
}
void printBasic(int x,int y)//����
{
    pos(x,y);
    std::cout<<"��";
}
void printStar(int x,int y)//����
{
    pos(x,y);
    std::cout<<"��";//"��";
}
void printNone(int x,int y)//��
{
    pos(x,y);
    std::cout<<"  ";
}
void creatMap(int init=0){//��ʼMAP
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
void creatMap_In(Map _m)//�ϰ�
{
    setColor(0x5);
    std::vector<Node>::iterator it = _m._map.begin();
    for(;it!=_m._map.end();it++)
    {
        it->_printBasic();
    }
}
void printCircle(int x,int y)//���Բ��
{
    pos(x, y);
    std::cout << "��";//"��" ;
}
