#include <bits/stdc++.h>

using namespace std;

bool ehPrimo(int n)
{
    int i = n/2;
    while(n % i != 0)
    {
        if(i == 1) return 1;
        i--;
    }
    return 0;
}



int main()
{
    /*double n;
    cin >> n;
    n *= 1000000*8;
    cout << (int)round(log2(n));
    return 0;*/
    
    /*int n;
    cin >> n;
    cout << ehPrimo(n);*/
    /*int n;
    cin >>n;
    int maiormdc = n/2;
    while(n % maiormdc != 0)
    {
        maiormdc--;
    }
    cout << maiormdc;*/
    int n;
    cin >> n;
    cout << log2(n);
}
