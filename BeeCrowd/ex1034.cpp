#include <bits/stdc++.h>

using namespace std;

/*
Calculamos o número mínimo de blocos necessários para atingir exatamente o comprimento desejado,
testamos todas as combinações possíveis de blocos com programação dinâmica para evitar repetições
desnecessárias. Armazenamos, tambem, para cada comprimento parcial, a melhor solução já encontrada
até aquele ponto, construindo a resposta ótima a partir de incrmentos.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, M;
        cin >> n >> M;
        vector<int> blocos(n);
        for (int i = 0; i < n; ++i) cin >> blocos[i];
        const int INF = 999999999;
        vector<int> dp(M + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= M; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i >= blocos[j]) dp[i] = min(dp[i], dp[i - blocos[j]] + 1);
            }
        }
        cout << dp[M] << endl;
    }
    return 0;
}
