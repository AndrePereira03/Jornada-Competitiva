#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        unordered_map<long long, int> freq; // hash_map: contagem de ocorrências
        for (int i = 0; i < n; ++i)
        {
            long long num;
            cin >> num;
            freq[num]++;
        }
        // procura o número com contagem ímpar
        for (auto atual = freq.begin(); atual != freq.end(); ++atual)
        {
            if (atual->second % 2 == 1)
            {
                cout << atual->first << endl;
                break;
            }
        }
    }
    return 0;
}