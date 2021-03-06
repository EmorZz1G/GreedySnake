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
void SetWindowSize(int cols, int lines)//设置控制台窗口大小
{
    system("title 贪吃蛇");//设置窗口标题
    char cmd[100];
    sprintf(cmd, "path=%path%c:\Windows\System32\;\nmode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    //sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    //vc++
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}
void setColor(int colorId)//设置输出颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorId);
}
void setBackColor()//设置文本背景色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}
bool Game::hitBlocks(Map &_m,Snake &_s)//碰到障碍
{
    std::vector<Node>::iterator it = _m._map.begin();
    for(; it!=_m._map.end(); it++)
    {
        if(_s.getHead()==*it)
            return 1;
    }
    return 0;
}
void Game::control()//流程控制
{
    select();
    play();
}
#if 1
void Game::select()//选择界面
{
    system("cls");
    /*初始化界面选项*/
    setColor(0x4);
    //pos(13, 26);
    pos(20,3);
    std::cout<<"GreedySnake";
    pos(20,5);
    std::cout<<"Version 1.2";
    setColor(3);
    pos(6, 10);
    std::cout << "请选择游戏难度：" ;
    pos(6, 11);
    std::cout << "(上下键选择,回车确认)" ;
    pos(35, 13);
    setBackColor();//第一个选项设置背景色以表示当前选中
    std::cout << "简单模式" ;
    pos(35, 15);
    setColor(3);
    std::cout << "普通模式" ;
    pos(35, 17);
    std::cout << "困难模式" ;
    pos(35, 19);
    std::cout << "炼狱模式" ;
    Gets = 0;
    /*上下方向键选择模块*/
    int ch;//记录键入值
    key = 1;//记录选中项，初始选择第一个
    bool flag = false;//记录是否键入Enter键标记，初始置为否
    while ((ch = getch()))
    {
        switch (ch)//检测输入键
        {
        case 72://UP上方向键
            if (key > 1)//当此时选中项为第一项时，UP上方向键无效
            {
                switch (key)
                {
                case 2:
                    pos(35, 13);//给待选中项设置背景色
                    setBackColor();
                    std::cout << "简单模式" ;

                    pos(35, 15);//将已选中项取消我背景色
                    setColor(3);
                    std::cout << "普通模式" ;
                    pos(0,26);
                    --key;
                    break;
                case 3:
                    pos(35, 15);
                    setBackColor();
                    std::cout << "普通模式" ;

                    pos(35, 17);
                    setColor(3);
                    std::cout << "困难模式" ;
                    pos(0,26);
                    --key;
                    break;
                case 4:
                    pos(35, 17);
                    setBackColor();
                    std::cout << "困难模式" ;

                    pos(35, 19);
                    setColor(3);
                    std::cout << "炼狱模式" ;
                    pos(0,26);
                    --key;
                    break;
                }
            }
            break;

        case 80://DOWN下方向键
            if (key < 4)
            {
                switch (key)
                {
                case 1:
                    pos(35, 15);
                    setBackColor();
                    std::cout << "普通模式" ;
                    pos(35, 13);
                    setColor(3);
                    std::cout << "简单模式" ;
                    pos(0,26);
                    ++key;
                    break;
                case 2:
                    pos(35, 17);
                    setBackColor();
                    std::cout << "困难模式" ;
                    pos(35, 15);
                    setColor(3);
                    std::cout << "普通模式" ;
                    pos(0,26);
                    ++key;
                    break;
                case 3:
                    pos(35, 19);
                    setBackColor();
                    std::cout << "炼狱模式" ;
                    pos(35, 17);
                    setColor(3);
                    std::cout << "困难模式" ;
                    pos(0,26);
                    ++key;
                    break;
                }
            }
            break;

        case 13://Enter回车键
            flag = true;
            break;
        default://无效按键
            break;
        }
        if (flag) break;//输入Enter回车键确认，退出检查输入循环
    }

    switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快
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
void Game::upDate(Snake &_s)//更新数据
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
}//更新数据
void Game::play()//玩游戏
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
}//玩游戏

void Game::GameOver()//游戏结束界面
{
    /*绘制游戏结束界面*/
    system("cls");
    Sleep(500);
    setColor(11);
    pos(10, 8);
    std::cout << " -------------------------------------------" ;
    Sleep(30);
    pos(9, 9);
    std::cout << " ┃               Game Over !!!              ┃" ;
    Sleep(30);
    pos(9, 10);
    std::cout << " ┃                                          ┃" ;
    Sleep(30);
    pos(9, 11);
    std::cout << " ┃              很遗憾！你挂了              ┃" ;
    Sleep(30);
    pos(9, 12);
    std::cout << " ┃                                          ┃" ;
    Sleep(30);
    pos(9, 13);
    std::cout << " ┃             你的分数为：                 ┃" ;
    pos(36, 13);
    std::cout << Gets*10 ;
    Sleep(30);
    pos(9, 14);
    std::cout << " ┃                                          ┃" ;
    Sleep(30);
    pos(9, 15);
    std::cout << " ┃   是否再来一局？                         ┃" ;
    Sleep(30);
    pos(9, 16);
    std::cout << " ┃                                          ┃" ;
    Sleep(30);
    pos(9, 17);
    std::cout << " ┃                                          ┃" ;
    Sleep(30);
    pos(9, 18);
    std::cout << " ┃     嗯，好的             垃圾游戏，告辞  ┃" ;
    Sleep(30);
    pos(9, 19);
    std::cout << " ┃                                          ┃" ;
    Sleep(30);
    pos(9, 20);
    std::cout << " ┃                                          ┃" ;
    Sleep(30);
    pos(10, 21);
    std::cout << " -------------------------------------------" ;

    Sleep(100);
    pos(16, 18);
    setBackColor();
    std::cout << "嗯，好的" ;
    pos(0, 31);

    /*选择部分*/
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
                std::cout << "嗯，好的" ;
                pos(37, 18);
                setColor(11);
                std::cout << "垃圾游戏，告辞" ;
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                pos(37, 18);
                setBackColor();
                std::cout << "垃圾游戏，告辞" ;
                pos(16, 18);
                setColor(11);
                std::cout << "嗯，好的" ;
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
        control();//重新开始
    case 2:
        //return 2;//退出游戏
        exit(0);
    default:
        return;
    }
}//游戏结束界面
