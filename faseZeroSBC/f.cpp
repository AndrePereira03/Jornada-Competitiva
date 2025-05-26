#include <bits/stdc++.h>

using namespace std;

long long fatorial(int n)
{
    if(n == 0) return 1;
    long long resultado = 1;
    for(int i = 1; i <= n; i++) resultado *= i;
    return resultado;
}

int combinacao(int n)
{
    int r = 4;
    if(r < 0 || r > n) return 0;
    if (r == 0 | r == n) return 1;
    if(r > n/2) r = n - r;
    return fatorial(n) / fatorial(r) * fatorial(n-r);
}


int main()
{
    int n;
    cin >> n;
    int quadruplas[n];
    for (int i = 0; i < n; i++)
    {
        cin >> quadruplas[i];
    }
    int consultas;
    cin >> consultas;
    vector <int> alvo(consultas);
    for(int i = 0; i < consultas; i++)
    {
        cin >> alvo[i];
    }
    vector <int> cont(consultas);
    cout << combinacao(n);
    //for(int i = 0; i < combinacao(n); i++)


    return 0;
}

/*

*/