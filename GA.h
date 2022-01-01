#pragma once
#include"data_struct.h"
#include<iostream>
using namespace std;

string Select_Random(vector<string>& p, Queen* queen);
void Crossover(string x, string y, string& c1, string& c2);
bool Mutate(string& x, float rate, Queen* queen);
void Display_Population(const vector<string>& p, Queen* queen);
int Genetic_Algorithm(vector<string>& p, float rate, int num,Queen* queen);
