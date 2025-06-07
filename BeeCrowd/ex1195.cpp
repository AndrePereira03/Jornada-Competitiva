#include <bits/stdc++.h>

using namespace std;

struct No
{
    int val;
    No *esq, *dir;
    No(int v) : val(v), esq(nullptr), dir(nullptr) {}
};

//insere no
void inserir(No* &raiz, int v)
{
    if (!raiz) raiz = new No(v);
    else if (v < raiz->val) inserir(raiz->esq, v);
    else inserir(raiz->dir, v);
}

//visita primeiro no atual antes dos filhos
void preOrdem(No* raiz, vector<int>& caminhoPercorrido)
{
    if (!raiz) return;
    caminhoPercorrido.push_back(raiz->val);
    preOrdem(raiz->esq, caminhoPercorrido);
    preOrdem(raiz->dir, caminhoPercorrido);
}

//visita "normal"
void emOrdem(No* raiz, vector<int>& caminhoPercorrido)
{
    if (!raiz) return;
    emOrdem(raiz->esq, caminhoPercorrido);
    caminhoPercorrido.push_back(raiz->val);
    emOrdem(raiz->dir, caminhoPercorrido);
}

//visita os filhos e depois o no atual
void posOrdem(No* raiz, vector<int>& caminhoPercorrido)
{
    if (!raiz) return;
    posOrdem(raiz->esq, caminhoPercorrido);
    posOrdem(raiz->dir, caminhoPercorrido);
    caminhoPercorrido.push_back(raiz->val);
}

int main() {
    int C, n;
    cin >> C;
    for (int caso = 1; caso <= C; ++caso)
    {
        cin >> n;
        No* raiz = nullptr;
        
        //le os valores e insere cada um
        for (int i = 0, x; i < n; ++i)
        {
            cin >> x;
            inserir(raiz, x);
        }
        
        //vetor armazena os percursos; linhas seguintes executam
        vector<int> preOrd, emOrd, posOrd;
        preOrdem(raiz, preOrd);
        emOrdem(raiz, emOrd);
        posOrdem(raiz, posOrd);

        cout << "Case " << caso << ":\n";
        cout << "Pre.:";
        for (auto v : preOrd) cout << " " << v;
        cout << "\nIn..:";
        for (auto v : emOrd) cout << " " << v;
        cout << "\nPost:";
        for (auto v : posOrd) cout << " " << v;
        cout << "\n\n";
    }
    return 0;
}