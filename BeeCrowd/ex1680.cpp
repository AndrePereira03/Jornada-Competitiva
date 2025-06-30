#include <bits/stdc++.h>

using namespace std;

/*A ideia é simular o caminho seguindo cada letra da string. Começando na posição inicial,
indo para a direita. A cada etapa, movemos 10 unidades na direção atual e depois ajustamos
conforme a letra (horario ou antihorario), por meio da busca exaustiva.*/

struct Direcao
{
    int dx, dy;
};
const Direcao dirs[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

int main()
{
    string s;
    while (getline(cin, s))
    {
        int x = 300, y = 420;
        int direcao = 0;
        vector<pair<int,int>> pts = { {x, y} };
        for (char c : s)
        {
            if (c == 'A') direcao = (direcao + 1) % 4;
            else if (c == 'V') direcao = (direcao + 3) % 4;
            x += dirs[direcao].dx * 10;
            y += dirs[direcao].dy * 10;
            pts.emplace_back(x, y);
        }

        cout << pts[0].first << ' ' << pts[0].second << " moveto\n";
        for (size_t i = 1; i < pts.size(); ++i) {
            cout << pts[i].first << ' ' << pts[i].second << " lineto\n";
        }
        cout << "stroke\nshowpage\n";
    }
    return 0;
}