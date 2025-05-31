#include <bits/stdc++.h>

using namespace std;

struct Pais
{
    string nome;
    int ouro, prata, bronze;
    Pais(string n, int o, int p, int b) : nome(n), ouro(o), prata(p), bronze(b) {}
};

bool vencedor(const Pais& a, const Pais& b) {
    if (a.ouro != b.ouro) return a.ouro > b.ouro;
    if (a.prata != b.prata) return a.prata > b.prata;
    if (a.bronze != b.bronze) return a.bronze > b.bronze;
    return a.nome < b.nome;
}

int main() {
    map<string, vector<int>> quadro;

    string prova, ouro, prata, bronze;
    while (getline(cin, prova))
    {
        getline(cin, ouro);
        getline(cin, prata);
        getline(cin, bronze);

        if (quadro[ouro].size() < 3) quadro[ouro].resize(3, 0);
        if (quadro[prata].size() < 3) quadro[prata].resize(3, 0);
        if (quadro[bronze].size() < 3) quadro[bronze].resize(3, 0);
        
        quadro[ouro][0]++;
        quadro[prata][1]++;
        quadro[bronze][2]++;

        
        if (quadro[ouro].empty()) quadro[ouro] = {0, 0, 0}, quadro[ouro][0] = 1;
        if (quadro[prata].empty()) quadro[prata] = {0, 0, 0}, quadro[prata][1] = 1;
        if (quadro[bronze].empty()) quadro[bronze] = {0, 0, 0}, quadro[bronze][2] = 1;
    }

    vector<Pais> paises;
    for (auto& it : quadro) paises.emplace_back(it.first, it.second[0], it.second[1], it.second[2]);

    sort(paises.begin(), paises.end(), vencedor);

    cout << "Quadro de Medalhas\n";
    for (auto& p : paises) cout << p.nome << " " << p.ouro << " " << p.prata << " " << p.bronze << "\n";

    return 0;
}