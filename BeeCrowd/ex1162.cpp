#include <bits/stdc++.h>
using namespace std;

int troca(vector<int> ordem)
{
    int n = ordem.size();
    int trocas = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(ordem[j] > ordem[j + 1])
            {
                swap(ordem[j], ordem[j + 1]);
                trocas++;
            }
        }
    }
    return trocas;
}

int main()
{
    int ntrens, nvagoes;
    cin >> ntrens;
    for(int i = 0; i < ntrens; i++)
    {
        cin >> nvagoes;
        vector <int> ordem(nvagoes);
        for(int j =0; j < nvagoes; j++)
        {
            cin >> ordem[j];
        }
        cout << "Optimal train swapping takes " << troca(ordem) << " swaps." << endl;
    }
    return 0;
}