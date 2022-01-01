#include"simulated_annealing.h"


bool Simulated_Annealing(Queen* queen) {

	int steps=0,steps_sa= 0;
	double T = 5;		//初始化温度和步数
	string old_pailie = queen->get_pailie();
	string new_pailie = old_pailie;
	int old_hx = 0;
	int new_hx = 0;		//初始化新旧评估函数/排列
	do {
		steps++;
		old_hx = queen->hx_not_attack();
		if (queen->check()) {		//检测成功退出
			steps_sa += steps;
			cout << "已经找到问题的一个解！" << "本次模拟退火搜索步数：" << steps_sa<< "\n";
			cout << "此时的温度：" << T << "\n";
			cout << "搜索到的八皇后问题的一个解为：" << "\n";
			return true;
		}
		T = 0.99*T;//降温

		int y = rand() % 8;
		int x = 0;
		while (1) {
			x = rand() % 8;
			if (x != old_pailie[y] - '0')
				break;
		}				//随机改变某一列的皇后的位置
		new_pailie = old_pailie;
		new_pailie[y] = x + '0';
		queen->set_pailie(new_pailie);		//为目前的状态取新的值
		queen->fill();
		new_hx = queen->hx_not_attack();
		int delta = 0;//计算差值
		delta = new_hx - old_hx;

		if (delta > 0)			//若更新后的状态更好，则使用更新后的状态
			old_pailie = new_pailie;
		else {					//在一定概率下可以使用更新后的较差的状态
			float random = ((float)(rand() % 1000))/1000;
			float prob = exp(delta / T);
			if (random < prob)
				old_pailie = new_pailie;
			else {
				queen->set_pailie(old_pailie);
				queen->fill();
			}
		}
	} while (T>0.0000001);
	
	cout << "低于一定温度限度仍然没有找到解，本次模拟退火失败！" << "\n";
	cout << "本次搜索所用步数：" << steps<<"\n";
	cout << "此时的温度：" << T << "\n";
	cout << "目前搜索到的最好的八皇后状态：" << "\n";
	return false;
}


