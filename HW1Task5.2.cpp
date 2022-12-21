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
    int ar[n], res[n];
    ar_scan(n, ar);
    for(int i = 0;i < n; ++i)
    {
        res[ar[i] - 1] = i+1;
    }
    ar_print(n, res);
    return 0;
}