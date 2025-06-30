#include <bits/stdc++.h>

using namespace std;

/*
Primeiro, vamos buscar ordenar as tarefas pelo maior valor de lucro e tentar agendar cada uma o
mais próximo possível do seu prazo final, ocupando horários livres. Assim, escolhemos sempre as
tarefas mais lucrativas para executar primeiro, minimizando o dinheiro perdido.
*/

struct Tarefa
{
    int valor, tempo;
    // ordena primeiro pelo maior valor, se empate maior tempo
    bool operator<(const Tarefa& outra) const
    {
        return valor < outra.valor || (valor == outra.valor && tempo < outra.tempo);
    }
};

int main()
{
    int n, h;
    while (cin >> n >> h) {
        vector<Tarefa> tarefas(n);
        int soma = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> tarefas[i].valor >> tarefas[i].tempo;
            soma += tarefas[i].valor;
        }

        sort(tarefas.begin(), tarefas.end(), [](const Tarefa &a, const Tarefa &b)
        {
            if (a.valor != b.valor) return a.valor > b.valor;
            return a.tempo > b.tempo;
        });

        vector<bool> ocupado(h + 1, false);
        int ganho = 0;
        for (const auto& t : tarefas)
        {
            // Encontra o último tempo disponível para executar a tarefa antes do deadline
            for (int j = t.tempo; j >= 1; --j)
            {
                if (!ocupado[j])
                {
                    ocupado[j] = true;
                    ganho += t.valor;
                    break;
                }
            }
        }
        cout << soma - ganho << endl; // dinheiro perdido
    }
    return 0;
}
