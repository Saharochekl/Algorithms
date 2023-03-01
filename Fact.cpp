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

big_integer factor(big_integer a)
{
    big_integer res = 1;
    for (big_integer i = 2; i <= a; ++i)
    {
        res*=i;
    }
    return res;
}

big_integer gcd(big_integer a, big_integer b)
{
    if(a == 0 || b == 0)
    {
        return (a+b);
    }
    if(a > b)
    {
        return gcd(a - b, b);
    }
    else
    {
        return gcd(a, b - a);
    }
}

big_integer powmod(big_integer a, big_integer x, big_integer p)
{
    big_integer result = 1;

    while(x > 0)
    {
        if (x%2==0)
        {
            x /= 2;
            a *= a % p;
        }
        else
        {
            x--;
            result *= a % p;
        }
    }

    return result % p;
}

big_integer pollard(big_integer n, big_integer N)
{
    big_integer b;
    big_integer p;
    big_integer tmp;
    tmp = 2;
    bool fl = false;
    while ((tmp < n) && (!fl))
    {
        for (big_integer i = 1; i < N; ++i)
        {
            b = powmod(tmp, i, n);
            p = gcd(b, n);
            if(p!=1 && p!=n)
            {
                fl = true;
                p = gcd(b, n);
            }
            if(fl)
            {
                break;
            }
        }
        tmp+=1;
    }
    if(fl)
    {
        return p;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int N, n;
    cin >> n;
    cin >> N;
    big_integer x, y, res;
    x = n;
    y = N;
    res = pollard(x, y);
    cout << res;
}