#include <bits/stdc++.h>

using namespace std;

struct Pais
{
    string nome;
    int ouro, prata, bronze;    
    Pais(string n, int o, int p, int b) : nome(n), ouro(o), prata(p), bronze(b) {}
};

bool vencedor(const Pais& a, const Pais& b)
{
    if(a.ouro != b.ouro) return a.ouro > b.ouro;
    if(a.prata != b.prata) return a.prata > b.prata;
    if(a.bronze != b.bronze) return a.bronze > b.bronze;
    return a.nome < b.nome;
}

int main()
{
    int n;
    cin >> n;
    vector<Pais> paises;
    for(int i = 0; i < n; i++)
    {
        string nome;
        int o, p, b;
        cin >> nome >> o >> p >> b;
        paises.emplace_back(nome, o, p, b);
    }
    sort(paises.begin(), paises.end(), vencedor);
    for(const Pais& pais : paises)
        cout << pais.nome << " " << pais.ouro << " " << pais.prata << " " << pais.bronze << endl;
    return 0;
}