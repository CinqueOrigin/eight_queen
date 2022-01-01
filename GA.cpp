#include "GA.h"
#include<vector>
string Select_Random(vector<string>& p, Queen* queen)
{
    int total = 0;
    vector<int>hx(p.size());
    vector<int>ran;

    for (int i = 0; i < p.size(); i++) {    //求出每个的评估函数值以及他们的和。
        queen->set_pailie(p[i]);
        queen->fill();
        hx[i] = queen->hx_not_attack();
        total += hx[i];
    }

    for (int i = 0; i < p.size(); i++) {        //加权将他们加入到一个数组中，相当于转盘法选择
        for (int j = 0; j < hx[i]; j++)
            ran.push_back(i);
    }

    int random = rand() % total;
    return p[ran[random]];
}

void Crossover(string x, string y,string& c1,string&c2)
{
        int point1, point2;
        int temp;
        do {
            point1 = (rand() % 7) + 1;
            point2 = (rand() % 7) + 1;
        } while (point1 == point2);
        if (point1 > point2) {
            temp = point2;
            point2 = point1;
            point1 = temp;
        }
        c1 = x.substr(0, point1) + y.substr(point1, point2 - point1) + x.substr(point2);
        c2 = y.substr(0, point1) + x.substr(point1, point2 - point1) + y.substr(point2);
    return;
}

bool Mutate(string& x, float rate, Queen* queen)
{
    string new_x = x;
    for (int i = 0; i < x.length(); i++) {
        if (((float)(rand() % 10000) / 10000.0) < rate) {//以一定的变异概率变异
            new_x[i] = '0' + (rand() % 8);
        }
        queen->set_pailie(new_x);
        queen->fill();
        x = new_x;
    }
    return true;
}

void Display_Population(const vector<string>& p,Queen*queen)
{
    for (auto str : p) {
        int i = 1;
        queen->set_pailie(str);
        queen->fill();
        cout << str << ":" << queen->hx_not_attack() << "\t";
        if (i % 10 == 0)cout << endl;
        i++;
}
    cout << endl;
}

int Genetic_Algorithm(vector<string>& p, float rate,int num,Queen*queen)
{
    vector<string>old_population = p;
    vector<string>new_population(p.size());
    vector<string>new_temp(2);
    int generation = 0;
    int n;
    for (n = 0; n < num; n++) {
        for (int i = 0; i < p.size(); i++) {
            string x = Select_Random(old_population, queen);
            string y = Select_Random(old_population, queen);

            string c1 = "";
            string c2 = "";
            int random_cross = rand() % 1000;
            if (random_cross < 600) {
                Crossover(x, y, c1, c2);
                Mutate(c1, rate, queen);
                Mutate(c2, rate, queen);
            }
            else {
                c1 = x;
                Mutate(c1, rate, queen);
                c2 = y;
                Mutate(c2, rate, queen);
            }
            new_temp[0] = c1;
            new_temp[1] = c2;
            int hx1, hx2;
            queen->set_pailie(c1);
            queen->fill();
            hx1 = queen->hx_not_attack();   //子代个体1的适应值
            queen->set_pailie(c2);
            queen->fill();
            hx2 = queen->hx_not_attack();   //子代个体2的适应值
            int random_temp = 0;
            if (hx1 < hx2)random_temp = 1;  //选择子代个体中适应值较高的个体
            else random_temp = 0;
            queen->set_pailie(new_temp[random_temp]);
            queen->fill();
                if (queen->check()) {
                    p[0] = new_temp[random_temp];
                    cout << "本次遗传算法成功找到了解！" << endl;
                    cout << "本次经历了" << n << "代。" << endl;
                    return n;
                }
                new_population[i] = new_temp[random_temp];
        }
        old_population = new_population;
        if ((n + 1) % 20 == 0)                             //每隔二十代便展示一次当前种群
        {
            cout << "第" << n + 1 << "代" << ":" << endl;
            Display_Population(old_population, queen);
        }
    }
    p = old_population;
    cout << "经历" <<n<< "代，仍然没有找到解，目前最近似的解为:" << endl;
    return 10000;
}
