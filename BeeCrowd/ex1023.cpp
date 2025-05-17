#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
        quantidade de imoveis
        par: quantidade de moradores imovel consumo total de agua
        final da entrada é representado por 0 
    */
    int qtdImoveis;
    int qtdMoradores;
    int consumoTotal;

    cin >> qtdImoveis;
    while (qtdImoveis != 0)
    {
        vector<tuple<int, int>> tupla;
        for(int i = 1; i < qtdImoveis + 1; i++)
        {
            cin >> qtdMoradores >> consumoTotal;
            tupla[i] = {qtdMoradores, consumoTotal};
        }

        for(int i = 1; i < qtdImoveis + 1; i++)
        {
            cout << "Cidade# " << i << ":" << '\n';
            cout << get<1>(tupla[i])
        }
        
        cin >> qtdImoveis;
    }



    return 0;
}