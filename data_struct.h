#pragma once
#include<iostream>
#include<cstringt.h>
#include<random>
#include<ctime>
#include<conio.h>
using namespace std;

class Queen {
public:
	bool queen[8][8] = {0};
	int pailie[8] = {0};				//棋盘的排列，如pailie[x]=y表示第x+1列的皇后的位置是第y行
	int hx[8][8] = {0};					//评估函数
	void initial();
	void fill();
	void random_initial_pailie();
	void display();
	void display_hx();
	void set_pailie(string pl);
	string get_pailie();
	bool check();		//检验八皇后是否满足要求
	int hx_attack();
	int hx_not_attack();
	int count_attack(int x,int y);
};
