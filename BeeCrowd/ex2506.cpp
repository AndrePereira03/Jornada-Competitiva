#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    while (cin >> N)
    {
        vector<int> chegada(N), critico(N);
        for (int i = 0; i < N; ++i)
        {
            int H, M, C;
            cin >> H >> M >> C;
            //calcula chegada e tempo para o estado ficar critico
            chegada[i] = (H - 7) * 60 + M;
            critico[i] = chegada[i] + C;
        }
        int tempo = 0; // início às 7:00
        int pacientesCriticos = 0;
        for (int i = 0; i < N; ++i)
        {
            // prox horário exato de 30 em 30min
            tempo = max(tempo, chegada[i]);
            
            //arredonda para cima o proximo slot de 30min
            if (tempo % 30 != 0) tempo += 30 - (tempo % 30);
            
            // se ficar crítico antes de ser atendido
            if (critico[i] < tempo) pacientesCriticos++;

            //avança o tempo para o proximo atendimento
            tempo += 30;
        }
        cout << pacientesCriticos << endl;
    }
    return 0;
}