#include "data_struct.h"

void Queen::initial()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            queen[i][j] = 0;
        }
}
}

void Queen::fill() {
    initial();
    int i, j = 0;
    for (i = 0; i < 8; i++) {
        j = pailie[i];
        queen[j][i] = 1;
    }
}

void Queen::random_initial_pailie()
{
    int i, random;
    for (i = 0; i < 8; i++) {
        random = rand() % 8;
        pailie[i] = random;
    }
}

void Queen::display()
{
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            cout << queen[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Queen::display_hx()
{
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 9; j++) {
            cout << hx[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Queen::set_pailie(string pl)
{
    int i;
    for (i = 0; i < 8; i++) {
        pailie[i] = pl[i] - '0';
    }
   /* if (i < 8) {
        for (; i < 8; i++) {
            pailie[i] = 0;
        }
        cout << "×Ö·û´®ÊäÈëÓÐÎó";
    }*/
}

string Queen::get_pailie()
{
    int i;
    string pl="";
    for (i = 0; i < 8; i++) {
        pl +='0'+pailie[i];
    }
    pl[i] = '\0';
    return pl;
}

bool Queen::check()
{
    int i,j;
    for (i = 0; i < 8; i++) {
        for (j = i + 1; j < 8; j++) {
            if((pailie[i]==pailie[j])||(pailie[i]-pailie[j]==i-j)|| (pailie[i] - pailie[j] == j-i))
                return false;
        }
    }
    return true;
}

int Queen::hx_attack()
{
    int i, j,n=0;
    for (i = 0; i < 8; i++) {
        for (j = i + 1; j < 8; j++) {
            if ((pailie[i] == pailie[j]))
                n++;
            if ((pailie[i] - pailie[j] == i - j) || (pailie[i] - pailie[j] == j - i))
                n++;
        }
    }
    return n;
}

int Queen::hx_not_attack()
{
    int i, j, n = 0;
    for (i = 0; i < 8; i++) {
        for (j = i + 1; j < 8; j++) {
            if ((pailie[i] != pailie[j]) && (pailie[i] - pailie[j] != i - j) && (pailie[i] - pailie[j] != j - i))
                n++;
        }
    }
    return n;
    
}

int Queen::count_attack(int x,int y)
{
    int i, j,n=0;
    for (i = 0; i < 8; i++) {
        j = pailie[i];
        if ((x - y == i - j) || (x - y == j - i) || (y == j))
            n++;
    }
    return n;
}
