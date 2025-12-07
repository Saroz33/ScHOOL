#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void Skaitymas(int& n, int Si[], int Vi[]);
void Skaiciavimai(int n, int Si[], int Vi[], int& AT, int& MT, int& LT);
void Rasymas(int AT, int MT, int LT);

int main()
{
    int n, Si[1500], Vi[4000];
    int AT = 0, MT = 0, LT = 0;

    Skaitymas(n, Si, Vi);
    Skaiciavimai(n, Si, Vi, AT, MT, LT);
    Rasymas(AT, MT, LT);

    return 0;
}

void Skaitymas(int& n, int Si[], int Vi[]){
    ifstream fd("data.txt");

    fd >> n;
    for(int i = 0; i < n; i++){
        fd >> Si[i] >> Vi[i];
    }

    fd.close();
}

void Skaiciavimai(int n, int Si[], int Vi[], int& AT, int& MT, int& LT){
    int Aks[5], Akt[5], Mks[5], Mkt[5];
    int Asum = 0, Msum = 0, Amax = 0, Mmax = 0;
    int Avyn = 0, Mvyn = 0, Abug = 0, Mbug = 0, Asir = 0, Msir = 0, Akry = 0, Mkry = 0;
    int round = 0;

    round = n/10;

for(int k = 0; k < round; k++){

    for(int i = 0; i < 5; i++){
        Aks[i] = Si[i];
        Akt[i] = Vi[i];
    }
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < n; i++){
            Si[i] = Si[i+1];
            Vi[i] = Vi[i+1];
        }
    }

    for(int i = 0; i < 5; i++){
        Mks[i] = Si[i];
        Mkt[i] = Vi[i];
    }
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < n; i++){
            Si[i] = Si[i+1];
            Vi[i] = Vi[i+1];
        }
    }

        n -= 10;

        for(int i = 0; i < 5; i++){
            Asum += Aks[i];
            Msum += Mks[i];

            if(Aks[i] > Amax){
                Amax = Aks[i];
            }
            if(Mks[i] > Mmax){
                Mmax = Mks[i];
            }

            if(Akt[i] == 1){
                Avyn++;
            } else if(Akt[i] == 2){
                Abug++;
            } else if(Akt[i] == 3){
                Asir++;
            } else if(Akt[i] == 4){
                Akry++;
            }

            if(Mkt[i] == 1){
                Mvyn++;
            } else if(Mkt[i] == 2){
                Mbug++;
            } else if(Mkt[i] == 3){
                Msir++;
            } else if(Mkt[i] == 4){
                Mkry++;
            }
        }

        if(Asum > Msum){
            AT++;
        } else if(Msum > Asum){
            MT++;
        } else {
            if(Amax > Mmax){
                AT++;
            } else if(Mmax > Amax){
                MT++;
            } else {
                if(Avyn > Mvyn){
                    AT++;
                } else if(Mvyn > Avyn){
                    MT++;
                } else {
                    if(Abug > Mbug){
                        AT++;
                    } else if(Mbug > Abug){
                        MT++;
                    } else {
                        if(Asir > Msir){
                            AT++;
                        } else if(Msir > Asir){
                            MT++;
                        } else {
                            if(Akry > Mkry){
                                AT++;
                            } else if(Mkry > Akry){
                                MT++;
                            } else {
                                LT++;
                            }
                        }
                    }
                }
            }
        }
        Asum = 0;
        Msum = 0;
        Amax = 0;
        Mmax = 0;
        Avyn = 0;
        Mvyn = 0;
        Abug = 0;
        Mbug = 0;
        Asir = 0;
        Msir = 0;
        Akry = 0;
        Mkry = 0;
    }
}

void Rasymas(int AT, int MT, int LT){
    ofstream fr("rez.txt");

    fr << AT << endl;
    fr << MT << endl;
    fr << LT << endl;

    fr.close();
}

