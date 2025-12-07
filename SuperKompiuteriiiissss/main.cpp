#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void Skaitymas(int& p, int& n, int& m);
void Skaiciavimai(int p, int n, int m, int& t);
void Rasymas(int t);

int main()
{
    int p, n, m, t=0;

    Skaitymas(p, n, m);
    Skaiciavimai(p, n, m, t);
    Rasymas(t);

    return 0;
}

void Skaitymas(int& p, int& n, int& m){
    ifstream fd("data.txt");

    fd >> p >> n >> m;

    fd.close();
}

void Skaiciavimai(int p, int n, int m, int& t){
    int A[10^8];
    int tp = p;

    for(int i = 0; i < m; i++){
        A[i] = 2;
    }

    while(n+m*2 > 0){
    tp = p;
        if(m > 0){
            for(int i = 0; i < m; i++){
                if(A[i] > 0){
                    A[i] -= 1;
                    tp--;
                }
                if (A[i] == 0){
                    for(int j = i; j < m; j++){
                        A[j] = A[j+1];
                    }
                    m--;
                }
            }
        }
        for(int i = 0; i < tp; i++){
            if(n > 0){
                n -= tp;
            }
        }
        t++;
    }
}

void Rasymas(int t){
    ofstream fr("rez.txt");

    fr << t << endl;

    fr.close();
}
