#include"simulated_annealing.h"
#include"GA.h"

int main() {
	srand((unsigned)time(NULL));
	Queen queen;
	Queen* q = &queen;
	q->random_initial_pailie();
	q->fill();
	int switch_num;
	cout<<"请输入一个数字，0表示用模拟退火算法解决八皇后问题，"<<"\n"<<"否则表示用遗传算法解决问题"<<endl;
	cin >> switch_num;
	if (switch_num == 0) {
		cout << "模拟退火算法解决问题：" << "\n";
		Simulated_Annealing(q);
		q->display();
		
	}
	else {
		cout << "遗传算法解决问题：" << "\n";
		int p_size = 20, num = 10000;//种群大小和世代规模
		float rate = 0.1;
		vector<string> p(p_size);

		for (int i = 0; i < p_size; i++) {
			q->random_initial_pailie();
			q->fill();
			p[i] = q->get_pailie();
		}
		/*					//取消注释部分即可执行测试操作，测试不同参数下的找到解的概率。
		int find=0,sum=0;
		float find_rate = 0.0;
		for (int i = 0; i < 10; i++) {							//根据之前设置的参数，循环10轮，测试求解的效率。
			int s = Genetic_Algorithm(p, rate, num, q);
			if (s != 10000) {
				find++;
				sum += s;
			}

		}
		find_rate = find / 10.0;
		cout << "变异概率" << rate << "种群大小：" << p_size << endl;
		cout << "找到率:" << find_rate<<endl;
		cout << "找到的平均代数:" << sum / find<<endl;
		*/
		int s = Genetic_Algorithm(p, rate, num, q);		//进行一次遗传算法的搜索
		q->set_pailie(p[0]);
		q->fill();
		q->display();
	}
	int stop;
	cin >> stop;			//用于防止cmd自动退出
	return 1;
}