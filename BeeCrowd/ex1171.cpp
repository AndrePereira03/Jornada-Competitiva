#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> ocorrencia;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        ocorrencia[val]++;
    }
    for(const pair<const int, int>& par :ocorrencia)
        cout << par.first << " aparece " << par.second << " vez(es)" << endl;
    return 0;
}