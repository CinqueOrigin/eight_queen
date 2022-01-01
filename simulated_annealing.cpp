#include"simulated_annealing.h"


bool Simulated_Annealing(Queen* queen) {

	int steps=0,steps_sa= 0;
	double T = 5;		//��ʼ���¶ȺͲ���
	string old_pailie = queen->get_pailie();
	string new_pailie = old_pailie;
	int old_hx = 0;
	int new_hx = 0;		//��ʼ���¾���������/����
	do {
		steps++;
		old_hx = queen->hx_not_attack();
		if (queen->check()) {		//���ɹ��˳�
			steps_sa += steps;
			cout << "�Ѿ��ҵ������һ���⣡" << "����ģ���˻�����������" << steps_sa<< "\n";
			cout << "��ʱ���¶ȣ�" << T << "\n";
			cout << "�������İ˻ʺ������һ����Ϊ��" << "\n";
			return true;
		}
		T = 0.99*T;//����

		int y = rand() % 8;
		int x = 0;
		while (1) {
			x = rand() % 8;
			if (x != old_pailie[y] - '0')
				break;
		}				//����ı�ĳһ�еĻʺ��λ��
		new_pailie = old_pailie;
		new_pailie[y] = x + '0';
		queen->set_pailie(new_pailie);		//ΪĿǰ��״̬ȡ�µ�ֵ
		queen->fill();
		new_hx = queen->hx_not_attack();
		int delta = 0;//�����ֵ
		delta = new_hx - old_hx;

		if (delta > 0)			//�����º��״̬���ã���ʹ�ø��º��״̬
			old_pailie = new_pailie;
		else {					//��һ�������¿���ʹ�ø��º�Ľϲ��״̬
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
	
	cout << "����һ���¶��޶���Ȼû���ҵ��⣬����ģ���˻�ʧ�ܣ�" << "\n";
	cout << "�����������ò�����" << steps<<"\n";
	cout << "��ʱ���¶ȣ�" << T << "\n";
	cout << "Ŀǰ����������õİ˻ʺ�״̬��" << "\n";
	return false;
}


