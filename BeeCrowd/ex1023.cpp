#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, caso = 1;
    while ( (cin >> N) && N != 0 ) {
        if (caso > 1) 
            cout << "\n";

        vector<int> consumos(201, 0);
        long long totalPessoas = 0;
        long long totalConsumo = 0;

        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            totalPessoas += X;
            totalConsumo  += Y;
            consumos[Y / X] += X;
        }

        cout << "Cidade# " << caso++ << ":\n";
        bool primeiro = true;
        for (int m = 0; m <= 200; m++) {
            if (consumos[m] > 0) {
                if (!primeiro) 
                    cout << " ";
                cout << consumos[m] << "-" << m;
                primeiro = false;
            }
        }
        cout << "\n";

        double media = floor((100.0 * totalConsumo) / totalPessoas) / 100.0;
        cout << "Consumo medio: "
             << fixed << setprecision(2)
             << media << " m3.\n";
    }

    return 0;
}