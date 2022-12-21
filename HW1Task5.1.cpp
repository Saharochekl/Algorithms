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

int main()
{
    int n;
    cin >> n;
    int ar1[n], ar2[n], res[n];
    ar_scan(n, ar1);
    ar_scan(n, ar2);
    for(int i = 0;i < n; ++i)
    {
        res[i] = ar1[ar2[i] - 1];
    }
    ar_print(n, res);
    return 0;
}