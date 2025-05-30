#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q, e;
    cin >> q >> e;

    vector<int> doisDias(e);
    for (int i = 0; i < e; i++) cin >> doisDias[i];

    vector<int> visitados;

    for (int i = 0; i < q; i++)
    {
        int id;
        cin >> id;

        if (find(visitados.begin(), visitados.end(), id) != visitados.end()) cout << "0\n";
        else
        {
            visitados.push_back(id);
            if (find(doisDias.begin(), doisDias.end(), id) != doisDias.end()) cout << "0\n";
            else cout << "1\n";
        }
    }
    return 0;
}