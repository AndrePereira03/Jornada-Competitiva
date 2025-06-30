#include <bits/stdc++.h>
using namespace std;

// retorna o maior salto
int calc(const vector<pair<char, int>>& pedras, int pula)
{
    int ultima = 0, resultado = 0;
    int n = pedras.size();
    for (int i = 1; i < n; ++i)
    {
        if (i == pula) continue; //ignora pedra pulada
        resultado = max(resultado, pedras[i].second - pedras[ultima].second);
        ultima = i;
    }
    return resultado;
}

int main()
{
    int t, caso = 1;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<pair<char, int>> pedras;
        pedras.push_back({'B', 0});
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            char tipo = s[0];
            int pos = stoi(s.substr(2));
            pedras.push_back({tipo, pos});
        }
        pedras.push_back({'B', d});

        int resposta = 0x3f3f3f3f;

        for (int i = 1; i < pedras.size()-1; ++i)
        {
            if (pedras[i].first != 'S') continue;
            int ida = calc(pedras, i);
            int volta = calc(pedras, i);
            resposta = min(resposta, max(ida, volta));
        }
        resposta = min(resposta, calc(pedras, -1));
        cout << "Case " << caso++ << ": " << resposta << "\n";
    }
    return 0;
}