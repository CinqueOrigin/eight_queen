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
	int pailie[8] = {0};				//���̵����У���pailie[x]=y��ʾ��x+1�еĻʺ��λ���ǵ�y��
	int hx[8][8] = {0};					//��������
	void initial();
	void fill();
	void random_initial_pailie();
	void display();
	void display_hx();
	void set_pailie(string pl);
	string get_pailie();
	bool check();		//����˻ʺ��Ƿ�����Ҫ��
	int hx_attack();
	int hx_not_attack();
	int count_attack(int x,int y);
};
