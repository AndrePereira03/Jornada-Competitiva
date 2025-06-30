#include <bits/stdc++.h>

using namespace std;

/*
Para cada valor possível de k (base da pirâmide), verifica se é possível comprar pelo menos o volume
necessário usando programação dinâmica de mochila. O maior k possível é a resposta.
*/

int main()
{
    int n, b;
    cin >> n >> b;
    vector<int> v(n), p(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> p[i];

    const int MAX_VOLUME = 99999999;
    
    vector<int> volumeOptimo(MAX_VOLUME, INT_MAX);
    volumeOptimo[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int vol = MAX_VOLUME - 1; vol >= v[i]; --vol)
        {
            if (volumeOptimo[vol - v[i]] != INT_MAX)
                volumeOptimo[vol] = min(volumeOptimo[vol], volumeOptimo[vol - v[i]] + p[i]);
        }
    }

    int resposta = 0;
    for (int k = 1; ; ++k)
    {
        int maximo = k * (k + 1) / 2;
        if (maximo >= MAX_VOLUME) break;
        if (volumeOptimo[maximo] <= b) resposta = k;
        else break;
    }
    cout << resposta << endl;
    return 0;
}