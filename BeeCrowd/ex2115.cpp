#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        vector<pair<int, int>> tarefas(N); // disponibilidade, processamento
        for (int i = 0; i < N; ++i) cin >> tarefas[i].first >> tarefas[i].second;
        // Ordena por tempo de disponibilidade
        sort(tarefas.begin(), tarefas.end());
        int tempo = 1;
        for (int i = 0; i < N; ++i) // Espera até a tarefa estar disponível
        {
            if (tempo < tarefas[i].first) tempo = tarefas[i].first;
            tempo += tarefas[i].second; // Processa a tarefa
        }
        cout << tempo << endl;
    }
    return 0;
}