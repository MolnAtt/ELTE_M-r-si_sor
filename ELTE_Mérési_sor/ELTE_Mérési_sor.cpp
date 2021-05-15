// ELTE_Mérési_sor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

struct Input
{
    static const int n_MAX = 100000;
    int n;
    int e[n_MAX];
};


Input Beolvas()
{
    Input be;
//    cerr << "Adja meg, hogy hany meresi eredmenyet kivan rogziteni! \n";
    cin >> be.n;
    for (int i = 0; i < be.n; i++)
    {
//        cerr << "Az " << i + 1 << ". meresi eredmeny: ";
        cin >> be.e[i];
    }
    return be;
}

int Feldolgoz(Input be)
{
    unordered_map<int, int> ny; // nyilvántartás
    int ei = be.e[0]; // futó változó, tömb i-edik eleme.
    int max = 0; 
    int result = ei;

    ny[ei] = 0;

    for (int i = 1; i < be.n; i++)
    {
        ei = be.e[i];
        if (ny.find(ei) == ny.end())
            ny[ei] = i;
        else if (i - ny[ei] > max)
        {
            max = i - ny[ei];
            result = ei;
        }
    }

    return result;
}

void Kiir(int ki)
{
//    cerr << "--------------------\n";
//    cerr << "azon meresi eredmeny, amelynek elso es utolso elofordulasa kozott a legnagyobb a tavolsag: \n";
    cout << ki;
}

int main()
{
    Kiir(Feldolgoz(Beolvas()));
}
