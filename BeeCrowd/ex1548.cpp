#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n;

    //itera sobre a quantidade de casos de teste
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        vector<int> filaOriginal(m);
        int cont = 0;

        //le a fila [i]
        for(int j = 0; j < m; j++) cin >> filaOriginal[j];
        
        //crio uma nova fila, com o objetivo de ordená-la e comparar com a original
        vector<int> filaOrdenada(m);
        
        //copio a original na nova fila
        for(int j = 0; j < m; j++) filaOrdenada[j] = filaOriginal[j];
        
        //ordeno a nova fila
        sort(filaOrdenada.begin(), filaOrdenada.end(), greater<int>());
        
        //se os elementos das mesmas posições forem iguais, acrescenta +1 no contador
        for(int j = 0; j < m; j++) if(filaOriginal[j] == filaOrdenada[j]) cont++;
        cout << cont << endl;
    }
    return 0;
}