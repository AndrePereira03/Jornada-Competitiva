#include <bits/stdc++.h>

using namespace std;

/*
A ideia eh testar todos os lugares possíveis no cinema onde o grupo pode sentar junto, verificando
rapidamente se há assentos livres e suficientes em cada região. escolhemos o menor espaço possível
onde todos consigam sentar próximos uns dos outros.
*/

int main() {
    int r, c, k;
    while (cin >> r >> c >> k && (r || c || k)) {
        vector<string> mat(r);
        for (int i = 0; i < r; ++i) cin >> mat[i];

        vector<vector<int>> livres(r+1, vector<int>(c+1, 0));
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                livres[i][j] = livres[i-1][j] + livres[i][j-1] - livres[i-1][j-1] + (mat[i-1][j-1] == '.');

        int ans = r*c+1;

        for (int x1 = 0; x1 < r; ++x1)
        {
            for (int x2 = x1; x2 < r; ++x2)
            {
                int l = 0;
                for (int r = 0; r < c; ++r)
                {
                    auto livres_janela = [&](int l, int r)
                    {
                        return livres[x2+1][r+1] - livres[x1][r+1] - livres[x2+1][l] + livres[x1][l];
                    };
                    while (l <= r && livres_janela(l, r) >= k)
                    {
                        ans = min(ans, (x2-x1+1)*(r-l+1));
                        ++l;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
