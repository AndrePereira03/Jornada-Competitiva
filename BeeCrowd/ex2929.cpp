#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        //minimo eh uma pilha aux, q guarda o menor valor da pilha principal
        stack<int> pilha, minimo;
        for (int i = 0; i < n; ++i)
        {
            string operacao;
            cin >> operacao;
            if (operacao == "PUSH")
            {
                int v;
                cin >> v;
                pilha.push(v);
                // Se a pilha de min estiver vazia ou o novo elemento for <= ao atual min, tb coloca na pilha "min"
                if (minimo.empty() || v <= minimo.top()) minimo.push(v);
            }
            else if (operacao == "POP")
            {
                if (pilha.empty()) cout << "EMPTY\n";
                else
                {
                    // Se o elemento removido for o menor atual, tb remove da pilha de min
                    if (pilha.top() == minimo.top()) minimo.pop();
                    pilha.pop();
                }
            }
            else if (operacao == "MIN")
            {
                if (pilha.empty()) cout << "EMPTY\n";
                else cout << minimo.top() << "\n";
            }
        }
    }
    return 0;
}
