#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*numero de cidades
    quantidade de pessoas
    altura de cada uma das pessoas*/

    int nCidades;
    int nPessoas;
    
    cin >> nCidades;
    for(int i = 0; i < nCidades; i++)
    {
        cin >> nPessoas;
        vector <int> alturas(nPessoas);
        for(int j = 0; j < nPessoas; j++)
        {
            cin >> alturas[j];
        }
        sort(alturas.begin(), alturas.end());
        for(int k = 0; k < nPessoas; k++)
        {
            cout << alturas[k] << " ";
        }
        cout << endl;
    }
    return 0;
}