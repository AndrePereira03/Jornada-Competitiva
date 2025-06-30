#include <bits/stdc++.h>
using namespace std;

const int INF = 999999999;

/*
Usamos programação dinâmica para calcular o menor custo de compra dos itens da lista, seguindo
a ordem exata. Percorremos os produtos do mercado e, para cada possível quantidade de itens da
lista já comprados, decidimos entre AVANCAR ou COMPRAR O ITEM ATUAL SE CORRESPONDER AO PROXIMO
DA LISTA, e claro, atualizamos o custo mínimo. Se não for possível comprar todos os itens na
ordem, imprime "Impossible".
*/

int main()
{
    while (true)
    {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        vector<int> lista(m);
        for (int i = 0; i < m; ++i) cin >> lista[i];

        vector<pair<int, double>> mercado(n);
        for (int i = 0; i < n; ++i) cin >> mercado[i].first >> mercado[i].second;

        vector<vector<double>> dp(m+1, vector<double>(n+1, 1e18));
        dp[0][0] = 0;

        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i <= m; ++i)
            {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
                if (i < m && mercado[j].first == lista[i])
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + mercado[j].second);
            }
        }

        double resposta = dp[m][n];
        if (resposta > INF) cout << "Impossible" << endl;
        else cout << fixed << setprecision(2) << resposta << endl;
    }
    return 0;
}
