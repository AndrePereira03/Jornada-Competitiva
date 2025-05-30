#include <bits/stdc++.h>

using namespace std;

int main()
{
    int qtd_habitantes, qtd_consultas;
    
    while(cin >> qtd_habitantes >> qtd_consultas)
    {
        vector <int> notas(qtd_habitantes);
        for(int i = 0; i < qtd_habitantes; i++)
        {
            cin >> notas[i];
        }
        sort(notas.begin(), notas.end(), greater<int>());
        for(int i = 0; i < qtd_consultas; i++)
        {
            int posicao;
            cin >> posicao;
            cout << notas[posicao - 1] << endl;
        }
    }

    return 0;
}