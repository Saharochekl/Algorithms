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
using namespace std;

void ar_print(int y, int Y[]) //выводит одномерный массив
{
    for (int i = 0; i < y; i++)
    {
        cout << Y[i] << " ";
    }
}

void ar_scan(int y, int Y[]) //считывает одномерный массив
{
    for (int i = 0; i < y; i++)
    {
        cin >> Y[i];
    }

}

bool even(int x) //проверяет чётность
{
    return (bool) (fmod(x, 2));
}

int main()
{
    int n, k = 0;
    cin >> n;
    int ar[n];
    ar_scan(n, ar);
    for(int i = 0; i < n; ++i)
    {
        if(ar[i] != i + 1)
        {
            ar[ar[i] - 1] = ar[i];
            ar[i] = i + 1;
            k++;
        }
    }
    if(even(k))
    {
        cout << "чётная";
    }
    else
    {
        cout << "нечётная";
    }
    return 0;
}