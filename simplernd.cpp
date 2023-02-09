//
// Created by zuha on 07.02.2023.
//
#include <iostream>
#include <random>
#include <cstdlib>
#include <list>
#include <ctime>
#include <functional>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "bignum.h"


using namespace std;

int RandN(int min, int max) //плохо выдаёт рандомное значение в диапазоне
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int RndInt(int min, int max) //Выдаёт рандомное значение в заданном диапазоне
{
    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число - формула
    int num = min + rand() % (max - min + 1);

    return num;
}
void ar_true(int a, bool A[])
{
    for (int i = 0; i < a; ++i)
    {
        A[i] = true;
    }
}
void distribution(int k, int D[], int N[])
{
    bool fl[31];
    ar_true(31, fl);
    fl[0] = false;
    int i = 0;
    int tmp;
    while ( i <= k-1)
    {
        tmp = RndInt(0, 30);
        if(fl[tmp])
        {
            D[i] = N[tmp];
            fl[tmp] = false;
            cout << i+1 << " == " << D[i] << endl;
            i++;
        }
    }
}

big_integer N_count(big_integer n, int D[], big_integer a, int k)
{
    for (int i = 0; i < k; ++i)
    {
        n*= D[i];
    }
    while (n < a-1)
    {
        int i = RndInt(0, 30);
        n*=D[i];

    }
    return n;
}

int Log_Big_int(big_integer n, big_integer bi)
{
    int minVal = 1;
    big_integer tmp = bi.pow(minVal);
    while(n > tmp)
    {
        minVal+=1;
        tmp = bi.pow(minVal);
    }
    return minVal;
}


int main()
{
    big_integer bi("2");
    big_integer a = bi.pow(123);
    big_integer b = bi.pow(128);
    big_integer n = 1;
    big_integer temp1;
    big_integer temp2;
    big_integer temp3;
    int N[31] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127};
    int k;
    k = RndInt(0, 15) + 5;
    cout << "k = "<< k << endl;
    int D[k];
    D[0]=2;
    distribution(k, D, N);
    n = N_count(n, D, a, k);
    n++;
    cout << "n = " << n << endl;
    int L;
    L = Log_Big_int(n, bi);
    cout << "L = "<< L << endl;
    for (int j = 2; j < L+1; ++j)
    {
        for (int l = 0; l < k; ++l)
        {
            string sj = to_string(j);
            big_integer big(sj);
            temp3 = (n-1)/D[l];
            temp1 = j;
            big_integer tmp = temp3%n;
            big_integer f = temp1%n;
            if(( tmp != 1) && (f == 1))
            {
                cout << "простое";
                return 0;
            }
        }
    }
    cout << "составное";
    return 0;
}