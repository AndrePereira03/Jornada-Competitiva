#include <bits/stdc++.h>

using namespace std;

//representacao de cada fucnionario [tempo livre, indice]
typedef pair<long long, int> Funcionario;

int main()
{
    int n; //funcionarios
    int m; //clientes
    int tempoTotal = 0;
    cin >> n >> m;
    vector <int> c(m); //c_j representa a qtd do item j na cesta c
    vector <int> v(n);//tempo gasto pelo funcionario i pro-
    
    for(int i = 0; i < n; i++) cin >> v[i]; //tempo gasto funcionario i
    for(int i = 0; i < m; i++) cin >> c[i]; //intens cesta cliente j
    
    //min heap por tempo_livre, depois indice
    priority_queue<Funcionario, vector<Funcionario>, greater<Funcionario>> fila;
    for(int i = 0; i < n; ++i) fila.push(Funcionario(0, i));
    long long tempo_final = 0;
    
    // simulo o atendimento de cada cliente no melhor caixa
    for(int i = 0; i < m; ++i)
    {
        //pego o funcionario que fica livre mais cedo
        Funcionario atual = fila.top();
        fila.pop();
        long long tempoLivre = atual.first; 
        int indiceFunc = atual.second;
        
        //tempo que esse cliente leva para ser atendido por esse funcioanrio
        long long tempo_atend = 1LL * v[indiceFunc] * c[i];
        //tempo que o funcionario ficara livre
        long long novo_livre = tempoLivre + tempo_atend;
        //atualiza o tempo final
        tempo_final = max(tempo_final, novo_livre);
        //coloca o funcionario de volta na fila, com o seu novo tempo livre
        fila.push(Funcionario(novo_livre, indiceFunc));
    }
    cout << tempo_final << "\n";
    return 0;
}