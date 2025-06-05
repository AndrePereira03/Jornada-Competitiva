#include <bits/stdc++.h>

using namespace std;

//
typedef pair<long long, int> Funcionario;

int main()
{
    int n; //funcionarios
    int m; //clientes
    int tempoTotal = 0;
    cin >> n >> m;
    vector <int> c(m); //c_j representa a qtd do item j na cesta c
    vector <int> v(n);//tempo gasto pelo funcionario i pro-
    
    for(int i = 0; i < n; i++) cin >> v[i];//tempo gasto funcionario i
    for(int i = 0; i < m; i++) cin >> c[i];
    priority_queue<Funcionario, vector<Funcionario>, greater<Funcionario>> fila;
    for(int i = 0; i < n; i++) fila.push({0, i});
    for(int i = 0; i < m; ++i)
    {
        auto [livre, idx] = fila.top(); fila.pop();
        int tempo atend
    }
    return 0;
}