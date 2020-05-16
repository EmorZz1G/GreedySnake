#include "game.h"
#include "map.h"
#include <windows.h>
#include "food.h"
#include "snake.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;
void SetWindowSize(int cols, int lines)//���ÿ���̨���ڴ�С
{
    system("title ̰����");//���ô��ڱ���
    char cmd[100];
    sprintf(cmd, "path=%path%c:\Windows\System32\;\nmode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
    //sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
    //vc++
    system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}
void setColor(int colorId)//���������ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorId);
}
void setBackColor()//�����ı�����ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}
bool Game::hitBlocks(Map &_m,Snake &_s)//�����ϰ�
{
    std::vector<Node>::iterator it = _m._map.begin();
    for(; it!=_m._map.end(); it++)
    {
        if(_s.getHead()==*it)
            return 1;
    }
    return 0;
}
void Game::control()//���̿���
{
    select();
    play();
}
#if 1
void Game::select()//ѡ�����
{
    system("cls");
    /*��ʼ������ѡ��*/
    setColor(0x4);
    //pos(13, 26);
    pos(20,3);
    std::cout<<"GreedySnake";
    pos(20,5);
    std::cout<<"Version 1.2";
    setColor(3);
    pos(6, 10);
    std::cout << "��ѡ����Ϸ�Ѷȣ�" ;
    pos(6, 11);
    std::cout << "(���¼�ѡ��,�س�ȷ��)" ;
    pos(35, 13);
    setBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
    std::cout << "��ģʽ" ;
    pos(35, 15);
    setColor(3);
    std::cout << "��ͨģʽ" ;
    pos(35, 17);
    std::cout << "����ģʽ" ;
    pos(35, 19);
    std::cout << "����ģʽ" ;
    Gets = 0;
    /*���·����ѡ��ģ��*/
    int ch;//��¼����ֵ
    key = 1;//��¼ѡ�����ʼѡ���һ��
    bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
    while ((ch = getch()))
    {
        switch (ch)//��������
        {
        case 72://UP�Ϸ����
            if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
            {
                switch (key)
                {
                case 2:
                    pos(35, 13);//����ѡ�������ñ���ɫ
                    setBackColor();
                    std::cout << "��ģʽ" ;

                    pos(35, 15);//����ѡ����ȡ���ұ���ɫ
                    setColor(3);
                    std::cout << "��ͨģʽ" ;
                    pos(0,26);
                    --key;
                    break;
                case 3:
                    pos(35, 15);
                    setBackColor();
                    std::cout << "��ͨģʽ" ;

                    pos(35, 17);
                    setColor(3);
                    std::cout << "����ģʽ" ;
                    pos(0,26);
                    --key;
                    break;
                case 4:
                    pos(35, 17);
                    setBackColor();
                    std::cout << "����ģʽ" ;

                    pos(35, 19);
                    setColor(3);
                    std::cout << "����ģʽ" ;
                    pos(0,26);
                    --key;
                    break;
                }
            }
            break;

        case 80://DOWN�·����
            if (key < 4)
            {
                switch (key)
                {
                case 1:
                    pos(35, 15);
                    setBackColor();
                    std::cout << "��ͨģʽ" ;
                    pos(35, 13);
                    setColor(3);
                    std::cout << "��ģʽ" ;
                    pos(0,26);
                    ++key;
                    break;
                case 2:
                    pos(35, 17);
                    setBackColor();
                    std::cout << "����ģʽ" ;
                    pos(35, 15);
                    setColor(3);
                    std::cout << "��ͨģʽ" ;
                    pos(0,26);
                    ++key;
                    break;
                case 3:
                    pos(35, 19);
                    setBackColor();
                    std::cout << "����ģʽ" ;
                    pos(35, 17);
                    setColor(3);
                    std::cout << "����ģʽ" ;
                    pos(0,26);
                    ++key;
                    break;
                }
            }
            break;

        case 13://Enter�س���
            flag = true;
            break;
        default://��Ч����
            break;
        }
        if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
    }

    switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
    {
    case 1:
        speed = 700;
        //Map cmap;
        break;
    case 2:
        speed = 500;
        break;
    case 3:
        speed = 300;
        break;
    case 4:
        speed = 600;
        break;
    default:
        break;
    }
    system("cls");
}
#endif
void Game::upDate(Snake &_s)//��������
{
    setColor(0x9);
    pos(80,8);
    Gets = _s.getGets();
    std::cout<<"Socre: "<<Gets;
    pos(80,10);
    std::cout<<"Eat: "<<_s.getEat();
    pos(79,13);
    setColor(0x4);
    std::cout<<"GreedySnake";
    pos(79,15);
    std::cout<<"Version 1.2";
    pos(0,26);
}//��������
void Game::play()//����Ϸ
{
    SetWindowSize(MAX_X,MAX_Y+10);
    creatMap(0);
    Map cmap;

    Snake csnake;
    csnake.initSnake();
    Food cfood;
    Food cfood2;
    upDate(csnake);
    srand(time(NULL));
    cfood.drawFood(csnake);
    start = clock();
    flash_time=clock();
    if(key==2)
    {
        creatMap_In(cmap);
    }
    while(1)
    {
        if(kbhit())
        {
            ch = getch();
            if(ch==72)
            {
                //if(csnake.direction==Snake::UP)goto no_move;
                csnake._move(Snake::UP,cfood,0);
                if(flag==1)
                    csnake._move(Snake::UP,cfood2,flag);
            }
            else if(ch==80)
            {
                //if(csnake.direction==Snake::DOWN)goto no_move;
                csnake._move(Snake::DOWN,cfood,0);
                if(flag==1)
                    csnake._move(Snake::DOWN,cfood2,flag);
            }
            else if(ch==75)
            {
                //if(csnake.direction==Snake::LEFT)goto no_move;
                csnake._move(Snake::LEFT,cfood,0);
                if(flag==1)
                    csnake._move(Snake::LEFT,cfood2,flag);
            }
            else if(ch==77)
            {
                //if(csnake.direction==Snake::RIGHT)goto no_move;
                csnake._move(Snake::RIGHT,cfood,0);
                if(flag==1)
                    csnake._move(Snake::RIGHT,cfood2,flag);
            }
            if(csnake.isDead())
                break;
            if(key==2&&isDead2(cmap,csnake))
            {
                csnake.death =1;
                break;
            }
            upDate(csnake);
            if(Gets==1)must_food =clock();
			pos(0, 26);
        }
        no_move:
        if(clock()-must_food>=speed*10+2000)
        {
            //pos(80,17);
            //cout<<must_food;
            cfood._food._printNone();
            cfood.drawFood(csnake);
            must_food =clock();
        }
        if(csnake.getEat()%3==2&&flag==0)
        {
            //exfood = cfood.drawBiliFood(csnake,len);
            cfood2.drawBiliFood(csnake,len);
            //exfood = &cfood2;
            //exfood.drawBiliFood();
            //exfood._food._printStar();
            len_time = clock();
            flag =1;
        }
        if(clock()-start>=speed)
        {
            csnake.normalMove(cfood,0);
            if(flag==1)
            {
                csnake.normalMove(cfood2,flag);
            }//cout<<"sfaf";}
            start = clock();
			pos(0, 26);
        }
#if 1
        if(flag==1&&clock()-len_time>=speed/3)
        {
            if(flag==1)
                cfood2.flashBiliFood(len);
            len_time = clock();
            //Sleep(100);
            if(len==0)
            {
                flag = 0;
                len =42;
            }
        }
        if(clock()-flash_time>=15000)
        {
            creatMap(0);
            if(key==2)
            {
                creatMap_In(cmap);
            }
            flash_time=clock();
        }
#endif
    }
    if(csnake.death)
    {

        GameOver();
    }
}//����Ϸ

void Game::GameOver()//��Ϸ��������
{
    /*������Ϸ��������*/
    system("cls");
    Sleep(500);
    setColor(11);
    pos(10, 8);
    std::cout << " -------------------------------------------" ;
    Sleep(30);
    pos(9, 9);
    std::cout << " ��               Game Over !!!              ��" ;
    Sleep(30);
    pos(9, 10);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    pos(9, 11);
    std::cout << " ��              ���ź��������              ��" ;
    Sleep(30);
    pos(9, 12);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    pos(9, 13);
    std::cout << " ��             ��ķ���Ϊ��                 ��" ;
    pos(36, 13);
    std::cout << Gets*10 ;
    Sleep(30);
    pos(9, 14);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    pos(9, 15);
    std::cout << " ��   �Ƿ�����һ�֣�                         ��" ;
    Sleep(30);
    pos(9, 16);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    pos(9, 17);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    pos(9, 18);
    std::cout << " ��     �ţ��õ�             ������Ϸ�����  ��" ;
    Sleep(30);
    pos(9, 19);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    pos(9, 20);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    pos(10, 21);
    std::cout << " -------------------------------------------" ;

    Sleep(100);
    pos(16, 18);
    setBackColor();
    std::cout << "�ţ��õ�" ;
    pos(0, 31);

    /*ѡ�񲿷�*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = getch()))
    {
        switch (ch)
        {
        case 75://LEFT
            if (tmp_key > 1)
            {
                pos(16, 18);
                setBackColor();
                std::cout << "�ţ��õ�" ;
                pos(37, 18);
                setColor(11);
                std::cout << "������Ϸ�����" ;
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                pos(37, 18);
                setBackColor();
                std::cout << "������Ϸ�����" ;
                pos(16, 18);
                setColor(11);
                std::cout << "�ţ��õ�" ;
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        pos(0, 31);
        if (flag)
        {
            break;
        }
    }

    setColor(11);
    switch (tmp_key)
    {
    case 1:
        control();//���¿�ʼ
    case 2:
        //return 2;//�˳���Ϸ
        exit(0);
    default:
        return;
    }
}//��Ϸ��������
