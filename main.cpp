#include"simulated_annealing.h"
#include"GA.h"

int main() {
	srand((unsigned)time(NULL));
	Queen queen;
	Queen* q = &queen;
	q->random_initial_pailie();
	q->fill();
	int switch_num;
	cout<<"������һ�����֣�0��ʾ��ģ���˻��㷨����˻ʺ����⣬"<<"\n"<<"�����ʾ���Ŵ��㷨�������"<<endl;
	cin >> switch_num;
	if (switch_num == 0) {
		cout << "ģ���˻��㷨������⣺" << "\n";
		Simulated_Annealing(q);
		q->display();
		
	}
	else {
		cout << "�Ŵ��㷨������⣺" << "\n";
		int p_size = 20, num = 10000;//��Ⱥ��С��������ģ
		float rate = 0.1;
		vector<string> p(p_size);

		for (int i = 0; i < p_size; i++) {
			q->random_initial_pailie();
			q->fill();
			p[i] = q->get_pailie();
		}
		/*					//ȡ��ע�Ͳ��ּ���ִ�в��Բ��������Բ�ͬ�����µ��ҵ���ĸ��ʡ�
		int find=0,sum=0;
		float find_rate = 0.0;
		for (int i = 0; i < 10; i++) {							//����֮ǰ���õĲ�����ѭ��10�֣���������Ч�ʡ�
			int s = Genetic_Algorithm(p, rate, num, q);
			if (s != 10000) {
				find++;
				sum += s;
			}

		}
		find_rate = find / 10.0;
		cout << "�������" << rate << "��Ⱥ��С��" << p_size << endl;
		cout << "�ҵ���:" << find_rate<<endl;
		cout << "�ҵ���ƽ������:" << sum / find<<endl;
		*/
		int s = Genetic_Algorithm(p, rate, num, q);		//����һ���Ŵ��㷨������
		q->set_pailie(p[0]);
		q->fill();
		q->display();
	}
	int stop;
	cin >> stop;			//���ڷ�ֹcmd�Զ��˳�
	return 1;
}