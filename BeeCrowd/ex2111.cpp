#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    bool primeiroCaso = true;

    while(cin >> n)
    {
        int abaco5[2][9] = {{1,1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,0,0,0}};
        int abaco1[5][9] = {{0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0,0}};
        
        if (!primeiroCaso) cout << endl;
        primeiroCaso = false;

        long long divisor = 1;
        for(int coluna = 8; coluna >= 0; coluna--)
        {
            int digito = (n / divisor) % 10;

            if (digito >= 5)
            {
                abaco5[0][coluna] = 0;
                abaco5[1][coluna] = 1;
            }

            int contas1 = digito % 5;
            for (int i = 0; i < contas1; i++) abaco1[i][coluna] = 1; 
            
            divisor *= 10;
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 9; j++) cout << abaco5[i][j];
            cout << endl;
        }

        cout << "---------" << endl;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 9; j++) cout << abaco1[i][j];
            cout << endl;
        }
    }
    return 0;
}